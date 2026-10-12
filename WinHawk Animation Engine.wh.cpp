// ==WindhawkMod==
// @id              winhawk-animation-engine
// @name            WinHawk Animation Engine
// @description     Configurable window open, close, minimize and restore/maximize animations.
// @version         0.1.0
// @author          PredaX6
// @include         *
// @compilerOptions -lgdi32 -luser32 -ldwmapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# WinHawk Animation Engine

Adds configurable overlay animations for classic Win32 windows:
- Opening / showing a window
- Closing a window
- Minimizing a window
- Restoring / maximizing a window

Each animation has its own enable switch, duration, scale and easing curve.
The effect uses a captured window image in a temporary, non-activating overlay.
Some apps (especially UWP/WinUI, protected surfaces, hardware video, and windows
that do not respond to classic Win32 APIs) may not be captured or animated.
This initial version does not replace every compositor-level Windows animation
path. Avoid running it alongside other window-animation mods.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- open_enabled:
  - name: Animate opening
  - type: bool
  - default: true
- open_duration:
  - name: Opening duration (ms)
  - type: int
  - default: 220
  - min: 50
  - max: 1500
- open_scale:
  - name: Opening start scale (%)
  - type: int
  - default: 82
  - min: 10
  - max: 100
- open_easing:
  - name: Opening easing
  - type: select
  - default: easeOut
  - options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
- close_enabled:
  - name: Animate closing
  - type: bool
  - default: true
- close_duration:
  - name: Closing duration (ms)
  - type: int
  - default: 180
  - min: 50
  - max: 1500
- close_scale:
  - name: Closing end scale (%)
  - type: int
  - default: 82
  - min: 10
  - max: 100
- close_easing:
  - name: Closing easing
  - type: select
  - default: easeIn
  - options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
- minimize_enabled:
  - name: Animate minimizing
  - type: bool
  - default: true
- minimize_duration:
  - name: Minimize duration (ms)
  - type: int
  - default: 260
  - min: 50
  - max: 1500
- minimize_scale:
  - name: Minimize end scale (%)
  - type: int
  - default: 18
  - min: 10
  - max: 100
- minimize_easing:
  - name: Minimize easing
  - type: select
  - default: easeIn
  - options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
- restore_enabled:
  - name: Animate restore / maximize
  - type: bool
  - default: true
- restore_duration:
  - name: Restore / maximize duration (ms)
  - type: int
  - default: 240
  - min: 50
  - max: 1500
- restore_scale:
  - name: Restore / maximize start scale (%)
  - type: int
  - default: 82
  - min: 10
  - max: 100
- restore_easing:
  - name: Restore / maximize easing
  - type: select
  - default: easeOut
  - options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
*/


#include <windows.h>
#include <dwmapi.h>
#include <algorithm>
#include <atomic>
#include <cmath>
#include <new>
#include <cwchar>

struct AnimationSettings {
    bool enabled;
    int duration;
    int scale;
    int easing; // 0 linear, 1 ease-out, 2 ease-in-out
};

static AnimationSettings g_open{true, 220, 82, 1};
static AnimationSettings g_close{true, 180, 82, 0};
static AnimationSettings g_minimize{true, 260, 18, 0};
static AnimationSettings g_restore{true, 240, 82, 1};
static std::atomic<bool> g_unloading{false};
static ATOM g_overlayClass = 0;

using ShowWindow_t = decltype(&ShowWindow);
using DefWindowProcW_t = decltype(&DefWindowProcW);
static ShowWindow_t ShowWindow_Original;
static DefWindowProcW_t DefWindowProcW_Original;

struct AnimationJob {
    HBITMAP bitmap;
    RECT rect;
    AnimationSettings settings;
    bool opening;
};

static int ClampInt(int value, int low, int high) {
    return (std::max)(low, (std::min)(high, value));
}

static float Ease(float t, int easing) {
    t = (std::max)(0.0f, (std::min)(1.0f, t));
    switch (easing) {
    case 1: return t * t;
    case 2: return 1.0f - (1.0f - t) * (1.0f - t);
    case 3: return t * t * (3.0f - 2.0f * t);
    default: return t;
    }
}

static bool IsEligibleWindow(HWND hwnd) {
    if (!IsWindow(hwnd) || GetAncestor(hwnd, GA_ROOT) != hwnd) return false;
    if (GetWindow(hwnd, GW_OWNER) != nullptr) return false;
    if (GetWindowLongPtrW(hwnd, GWL_EXSTYLE) & WS_EX_TOOLWINDOW) return false;
    RECT rc{};
    if (!GetWindowRect(hwnd, &rc)) return false;
    return rc.right - rc.left >= 80 && rc.bottom - rc.top >= 60;
}

static HBITMAP CaptureWindow(HWND hwnd, RECT* outRect) {
    if (!IsEligibleWindow(hwnd) || !GetWindowRect(hwnd, outRect)) return nullptr;
    int width = outRect->right - outRect->left;
    int height = outRect->bottom - outRect->top;
    if (width <= 0 || height <= 0 || width > 8192 || height > 8192) return nullptr;

    HDC screen = GetDC(nullptr);
    if (!screen) return nullptr;
    HDC memory = CreateCompatibleDC(screen);
    HBITMAP bitmap = CreateCompatibleBitmap(screen, width, height);
    if (!memory || !bitmap) {
        if (bitmap) DeleteObject(bitmap);
        if (memory) DeleteDC(memory);
        ReleaseDC(nullptr, screen);
        return nullptr;
    }
    HGDIOBJ old = SelectObject(memory, bitmap);
    PatBlt(memory, 0, 0, width, height, BLACKNESS);
    BOOL captured = PrintWindow(hwnd, memory, 2 /* PW_RENDERFULLCONTENT */);
    if (!captured) {
        captured = BitBlt(memory, 0, 0, width, height, screen,
                          outRect->left, outRect->top, SRCCOPY);
    }
    SelectObject(memory, old);
    DeleteDC(memory);
    ReleaseDC(nullptr, screen);
    if (!captured) {
        DeleteObject(bitmap);
        return nullptr;
    }
    return bitmap;
}

static DWORD WINAPI AnimationThread(void* parameter) {
    AnimationJob* job = static_cast<AnimationJob*>(parameter);
    if (!job) return 0;
    HBITMAP bitmap = job->bitmap;
    RECT rect = job->rect;
    AnimationSettings settings = job->settings;
    bool opening = job->opening;
    delete job;

    if (g_unloading.load() || !bitmap) {
        if (bitmap) DeleteObject(bitmap);
        return 0;
    }

    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    HWND overlay = CreateWindowExW(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
        MAKEINTATOM(g_overlayClass), L"", WS_POPUP,
        rect.left, rect.top, width, height, nullptr, nullptr,
        GetModuleHandleW(nullptr), nullptr);
    if (!overlay) {
        DeleteObject(bitmap);
        return 0;
    }

    HDC screen = GetDC(nullptr);
    HDC source = screen ? CreateCompatibleDC(screen) : nullptr;
    HGDIOBJ oldBitmap = source ? SelectObject(source, bitmap) : nullptr;
    if (!screen || !source || !oldBitmap) {
        if (oldBitmap && source) SelectObject(source, oldBitmap);
        if (source) DeleteDC(source);
        if (screen) ReleaseDC(nullptr, screen);
        DestroyWindow(overlay);
        DeleteObject(bitmap);
        return 0;
    }

    ShowWindow(overlay, SW_SHOWNOACTIVATE);
    int duration = ClampInt(settings.duration, 50, 1500);
    int endScale = ClampInt(settings.scale, 10, 100);
    ULONGLONG started = GetTickCount64();
    for (;;) {
        if (g_unloading.load()) break;
        float t = static_cast<float>(GetTickCount64() - started) / duration;
        if (t >= 1.0f) t = 1.0f;
        float eased = Ease(t, settings.easing);
        float scale = opening
            ? (endScale / 100.0f + (1.0f - endScale / 100.0f) * eased)
            : (1.0f + (endScale / 100.0f - 1.0f) * eased);
        BYTE alpha = static_cast<BYTE>(255.0f * (1.0f - eased));
        int frameWidth = (std::max)(1, static_cast<int>(width * scale));
        int frameHeight = (std::max)(1, static_cast<int>(height * scale));
        POINT destination{rect.left + (width - frameWidth) / 2,
                          rect.top + (height - frameHeight) / 2};
        SIZE size{frameWidth, frameHeight};
        POINT sourcePoint{0, 0};
        BLENDFUNCTION blend{AC_SRC_OVER, 0, alpha, 0};
        if (!UpdateLayeredWindow(overlay, screen, &destination, &size,
                                 source, &sourcePoint, 0, &blend, ULW_ALPHA)) {
            break;
        }
        if (t >= 1.0f) break;
        DwmFlush();
        Sleep(1);
    }

    SelectObject(source, oldBitmap);
    DeleteDC(source);
    ReleaseDC(nullptr, screen);
    DestroyWindow(overlay);
    DeleteObject(bitmap);
    return 0;
}

static void StartAnimation(HWND hwnd, const AnimationSettings& settings, bool opening,
                           HBITMAP captured = nullptr, const RECT* capturedRect = nullptr) {
    if (!settings.enabled || g_unloading.load()) {
        if (captured) DeleteObject(captured);
        return;
    }
    RECT rect{};
    HBITMAP bitmap = captured;
    if (!bitmap) bitmap = CaptureWindow(hwnd, &rect);
    else if (capturedRect) rect = *capturedRect;
    if (!bitmap) return;

    auto* job = new (std::nothrow) AnimationJob{bitmap, rect, settings, opening};
    if (!job) {
        DeleteObject(bitmap);
        return;
    }
    HANDLE thread = CreateThread(nullptr, 0, AnimationThread, job, 0, nullptr);
    if (thread) CloseHandle(thread);
    else {
        DeleteObject(bitmap);
        delete job;
    }
}

static AnimationSettings ReadSettings(const wchar_t* prefix) {
    AnimationSettings s{};
    wchar_t key[64]{};
    wcscpy_s(key, _countof(key), prefix);
    wcscat_s(key, _countof(key), L"_enabled");
    s.enabled = Wh_GetIntSetting(key) != 0;
    wcscpy_s(key, _countof(key), prefix);
    wcscat_s(key, _countof(key), L"_duration");
    s.duration = ClampInt(Wh_GetIntSetting(key), 50, 1500);
    wcscpy_s(key, _countof(key), prefix);
    wcscat_s(key, _countof(key), L"_scale");
    s.scale = ClampInt(Wh_GetIntSetting(key), 10, 100);
    wcscpy_s(key, _countof(key), prefix);
    wcscat_s(key, _countof(key), L"_easing");
    PCWSTR easing = Wh_GetStringSetting(key);
    s.easing = 0;
    if (easing && wcscmp(easing, L"easeIn") == 0) s.easing = 1;
    else if (easing && wcscmp(easing, L"easeOut") == 0) s.easing = 2;
    else if (easing && wcscmp(easing, L"easeInOut") == 0) s.easing = 3;
    if (easing) Wh_FreeStringSetting(easing);
    return s;
}

static void LoadSettings() {
    g_open = ReadSettings(L"open");
    g_close = ReadSettings(L"close");
    g_minimize = ReadSettings(L"minimize");
    g_restore = ReadSettings(L"restore");
}

BOOL WINAPI ShowWindow_Hook(HWND hwnd, int command) {
    bool wasIconic = IsIconic(hwnd) != FALSE;
    bool minimizing = command == SW_MINIMIZE || command == SW_SHOWMINIMIZED ||
                      command == SW_SHOWMINNOACTIVE || command == SW_FORCEMINIMIZE;
    RECT minimizeRect{};
    HBITMAP minimizeBitmap = nullptr;
    if (minimizing && g_minimize.enabled) {
        minimizeBitmap = CaptureWindow(hwnd, &minimizeRect);
    }

    BOOL result = ShowWindow_Original(hwnd, command);

    if (minimizing) {
        if (minimizeBitmap) {
            StartAnimation(hwnd, g_minimize, false, minimizeBitmap, &minimizeRect);
        }
        return result;
    }

    if (command == SW_SHOW || command == SW_SHOWNORMAL || command == SW_SHOWDEFAULT ||
        command == SW_RESTORE || command == SW_SHOWMAXIMIZED) {
        if (IsEligibleWindow(hwnd)) {
            StartAnimation(hwnd, (wasIconic || command == SW_SHOWMAXIMIZED ||
                                  command == SW_RESTORE) ? g_restore : g_open, true);
        }
    }
    return result;
}

LRESULT WINAPI DefWindowProcW_Hook(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_SYSCOMMAND) {
        UINT command = static_cast<UINT>(wParam) & 0xFFF0;
        if ((command == SC_MINIMIZE && g_minimize.enabled) ||
            (command == SC_CLOSE && g_close.enabled)) {
            RECT rc{};
            HBITMAP bitmap = CaptureWindow(hwnd, &rc);
            LRESULT result = DefWindowProcW_Original(hwnd, message, wParam, lParam);
            if (bitmap) StartAnimation(hwnd,
                command == SC_MINIMIZE ? g_minimize : g_close, false, bitmap, &rc);
            return result;
        }
        if (command == SC_RESTORE || command == SC_MAXIMIZE) {
            LRESULT result = DefWindowProcW_Original(hwnd, message, wParam, lParam);
            if (IsEligibleWindow(hwnd)) StartAnimation(hwnd, g_restore, true);
            return result;
        }
    }
    if (message == WM_CLOSE && g_close.enabled) {
        RECT rc{};
        HBITMAP bitmap = CaptureWindow(hwnd, &rc);
        LRESULT result = DefWindowProcW_Original(hwnd, message, wParam, lParam);
        if (bitmap) StartAnimation(hwnd, g_close, false, bitmap, &rc);
        return result;
    }
    return DefWindowProcW_Original(hwnd, message, wParam, lParam);
}

BOOL Wh_ModInit() {
    WNDCLASSW wc{};
    wc.lpfnWndProc = DefWindowProcW;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = L"WinHawkAnimationEngineOverlay";
    g_overlayClass = RegisterClassW(&wc);
    if (!g_overlayClass && GetLastError() != ERROR_CLASS_ALREADY_EXISTS) return FALSE;

    LoadSettings();
    if (!Wh_SetFunctionHook((void*)ShowWindow, (void*)ShowWindow_Hook,
                            (void**)&ShowWindow_Original)) {
        UnregisterClassW(MAKEINTATOM(g_overlayClass), wc.hInstance);
        return FALSE;
    }
    if (!Wh_SetFunctionHook((void*)DefWindowProcW, (void*)DefWindowProcW_Hook,
                            (void**)&DefWindowProcW_Original)) {
        Wh_Log(L"Failed to hook DefWindowProcW");
        return FALSE;
    }
    Wh_Log(L"WinHawk Animation Engine initialized");
    return TRUE;
}

void Wh_ModSettingsChanged() {
    LoadSettings();
}

void Wh_ModUninit() {
    g_unloading.store(true);
    if (g_overlayClass) {
        UnregisterClassW(MAKEINTATOM(g_overlayClass), GetModuleHandleW(nullptr));
        g_overlayClass = 0;
    }
}
