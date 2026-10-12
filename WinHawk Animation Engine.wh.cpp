// ==WindhawkMod==
// @id              winhawk-animation-engine
// @name            Moteur d’animation WinHawk
// @description     Animations configurables d’ouverture, de fermeture, de réduction et de restauration/agrandissement des fenêtres.
// @version         0.1.0
// @author          PredaX6
// @include         *
// @compilerOptions -lgdi32 -luser32 -ldwmapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Moteur d’animation WinHawk

Adds configurable overlay animations for classic Win32 windows:
- Ouverture / affichage d’une fenêtre
- Fermeture d’une fenêtre
- Réduction d’une fenêtre
- Restauration / agrandissement d’une fenêtre

Chaque animation possède ses propres options d’activation, de durée, d’échelle et de courbe d’accélération.
The effect uses a captured window image in a temporary, non-activating overlay.
Some apps (especially UWP/WinUI, protected surfaces, hardware video, and windows
that do not respond to classic Win32 APIs) may not be captured or animated.
This initial version does not replace every compositor-level Windows animation
path. Avoid running it alongside other window-animation mods.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- open_enabled: true
  $name: Animer l’ouverture
- open_duration: 220
  $name: Durée de l’ouverture (ms)
  #! $min: 50
  #! $max: 1500
- open_scale: 82
  $name: Échelle initiale à l’ouverture (%)
  #! $min: 10
  #! $max: 100
- open_easing: easeOut
  $name: Courbe d’animation à l’ouverture
  $options:
    - linear: Linéaire
    - easeIn: Accélération progressive
    - easeOut: Décélération progressive
    - easeInOut: Accélération puis décélération
- close_enabled: true
  $name: Animer la fermeture
- close_duration: 180
  $name: Durée de la fermeture (ms)
  #! $min: 50
  #! $max: 1500
- close_scale: 82
  $name: Échelle finale à la fermeture (%)
  #! $min: 10
  #! $max: 100
- close_easing: easeIn
  $name: Courbe d’animation à la fermeture
  $options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
- minimize_enabled: true
  $name: Animer la réduction
- minimize_duration: 260
  $name: Durée de la réduction (ms)
  #! $min: 50
  #! $max: 1500
- minimize_scale: 18
  $name: Échelle finale à la réduction (%)
  #! $min: 10
  #! $max: 100
- minimize_easing: easeIn
  $name: Courbe d’animation à la réduction
  $options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
- restore_enabled: true
  $name: Animer la restauration / l’agrandissement
- restore_duration: 240
  $name: Durée de la restauration / de l’agrandissement (ms)
  #! $min: 50
  #! $max: 1500
- restore_scale: 82
  $name: Échelle initiale à la restauration / à l’agrandissement (%)
  #! $min: 10
  #! $max: 100
- restore_easing: easeOut
  $name: Courbe d’animation à la restauration / à l’agrandissement
  $options:
    - linear: Linear
    - easeIn: Ease in
    - easeOut: Ease out
    - easeInOut: Ease in-out
*/
// ==/WindhawkModSettings==


#include <windows.h>
#include <dwmapi.h>
#ifndef DWMWA_CLOAK
#define DWMWA_CLOAK 13
#endif
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
static constexpr wchar_t kSysCommandAnimationProp[] =
    L"WinHawkAnimationEngine.SysCommandAnimation";

using ShowWindow_t = decltype(&ShowWindow);
using DefWindowProcW_t = decltype(&DefWindowProcW);
static ShowWindow_t ShowWindow_Original;
static DefWindowProcW_t DefWindowProcW_Original;

struct AnimationJob {
    HBITMAP bitmap;
    RECT rect;
    AnimationSettings settings;
    bool opening;
    HWND revealWindow;
    bool uncloaksTarget;
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

static HBITMAP CaptureWindow(HWND hwnd, RECT* outRect,
                             bool allowScreenFallback = true) {
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
    if (!captured && allowScreenFallback) {
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
    HWND revealWindow = job->revealWindow;
    bool uncloaksTarget = job->uncloaksTarget;
    delete job;

    auto revealTarget = [&]() {
        if (revealWindow && IsWindow(revealWindow)) {
            if (uncloaksTarget) {
                const BOOL cloak = FALSE;
                DwmSetWindowAttribute(revealWindow, DWMWA_CLOAK,
                                      &cloak, sizeof(cloak));
                DwmFlush();
            }
            SetWindowPos(revealWindow, nullptr, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                         SWP_NOACTIVATE | SWP_SHOWWINDOW);
        }
    };

    if (g_unloading.load() || !bitmap) {
        if (bitmap) DeleteObject(bitmap);
        revealTarget();
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
        revealTarget();
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
        revealTarget();
        return 0;
    }

    int duration = ClampInt(settings.duration, 50, 1500);
    int endScale = ClampInt(settings.scale, 10, 100);
    ULONGLONG started = GetTickCount64();
    bool overlayShown = false;
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
        if (!overlayShown) {
            ShowWindow(overlay, SW_SHOWNOACTIVATE);
            overlayShown = true;
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
    if (revealWindow) revealTarget();
    return 0;
}

static bool StartAnimation(HWND hwnd, const AnimationSettings& settings, bool opening,
                           HBITMAP captured = nullptr, const RECT* capturedRect = nullptr,
                           HWND revealWindow = nullptr, bool uncloaksTarget = false) {
    if (!settings.enabled || g_unloading.load()) {
        if (captured) DeleteObject(captured);
        return false;
    }
    RECT rect{};
    HBITMAP bitmap = captured;
    if (!bitmap) bitmap = CaptureWindow(hwnd, &rect);
    else if (capturedRect) rect = *capturedRect;
    if (!bitmap) return false;

    auto* job = new (std::nothrow) AnimationJob{
        bitmap, rect, settings, opening, revealWindow, uncloaksTarget};
    if (!job) {
        DeleteObject(bitmap);
        return false;
    }
    HANDLE thread = CreateThread(nullptr, 0, AnimationThread, job, 0, nullptr);
    if (thread) {
        CloseHandle(thread);
        return true;
    }
    DeleteObject(bitmap);
    delete job;
    return false;
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
    if (GetPropW(hwnd, kSysCommandAnimationProp)) {
        return ShowWindow_Original(hwnd, command);
    }

    bool wasIconic = IsIconic(hwnd) != FALSE;
    bool minimizing = command == SW_MINIMIZE || command == SW_SHOWMINIMIZED ||
                      command == SW_SHOWMINNOACTIVE || command == SW_FORCEMINIMIZE;
    RECT minimizeRect{};
    HBITMAP minimizeBitmap = nullptr;
    if (minimizing && g_minimize.enabled) {
        minimizeBitmap = CaptureWindow(hwnd, &minimizeRect);
    }

    const bool showCommand =
        command == SW_SHOW || command == SW_SHOWNORMAL ||
        command == SW_SHOWDEFAULT || command == SW_RESTORE ||
        command == SW_SHOWMAXIMIZED;
    const AnimationSettings* showSettings = nullptr;
    bool cloakedForAnimation = false;
    if (!minimizing && showCommand && IsEligibleWindow(hwnd)) {
        showSettings = (wasIconic || command == SW_SHOWMAXIMIZED ||
                        command == SW_RESTORE) ? &g_restore : &g_open;
        const bool needsVisualTransition =
            !IsWindowVisible(hwnd) || wasIconic ||
            command == SW_SHOWMAXIMIZED || command == SW_RESTORE;
        if (showSettings->enabled && needsVisualTransition) {
            const BOOL cloak = TRUE;
            if (SUCCEEDED(DwmSetWindowAttribute(
                    hwnd, DWMWA_CLOAK, &cloak, sizeof(cloak)))) {
                cloakedForAnimation = true;
                DwmFlush();
            }
        }
    }

    BOOL result = ShowWindow_Original(hwnd, command);

    if (minimizing) {
        if (minimizeBitmap) {
            StartAnimation(hwnd, g_minimize, false, minimizeBitmap, &minimizeRect);
        }
        return result;
    }

    if (cloakedForAnimation && showSettings) {
        DwmFlush();
        Sleep(20);
        RECT rc{};
        HBITMAP bitmap = CaptureWindow(hwnd, &rc, false);
        if (bitmap) {
            if (StartAnimation(hwnd, *showSettings, true, bitmap, &rc, hwnd, true)) {
                return result;
            }
        } else {
            const BOOL cloak = FALSE;
            DwmSetWindowAttribute(hwnd, DWMWA_CLOAK, &cloak, sizeof(cloak));
            DwmFlush();
            SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
                         SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                         SWP_NOACTIVATE | SWP_SHOWWINDOW);
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
            bool cloakedForAnimation = false;
            if (IsEligibleWindow(hwnd) && g_restore.enabled) {
                const BOOL cloak = TRUE;
                if (SUCCEEDED(DwmSetWindowAttribute(
                        hwnd, DWMWA_CLOAK, &cloak, sizeof(cloak)))) {
                    cloakedForAnimation = true;
                    DwmFlush();
                    SetPropW(hwnd, kSysCommandAnimationProp, (HANDLE)1);
                }
            }

            LRESULT result = DefWindowProcW_Original(hwnd, message, wParam, lParam);
            if (GetPropW(hwnd, kSysCommandAnimationProp)) {
                RemovePropW(hwnd, kSysCommandAnimationProp);
            }
            if (cloakedForAnimation) {
                DwmFlush();
                Sleep(20);
                RECT rc{};
                HBITMAP bitmap = CaptureWindow(hwnd, &rc, false);
                if (bitmap) {
                    if (StartAnimation(hwnd, g_restore, true, bitmap, &rc,
                                       hwnd, true)) {
                        return result;
                    }
                } else {
                    const BOOL cloak = FALSE;
                    DwmSetWindowAttribute(hwnd, DWMWA_CLOAK, &cloak, sizeof(cloak));
                    DwmFlush();
                    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
                                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                                 SWP_NOACTIVATE | SWP_SHOWWINDOW);
                }
            }
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
