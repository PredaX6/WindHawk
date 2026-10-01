// ==WindhawkMod==
// @id winted
// @name WinTed
// @description Windows 11 25H2 : fenêtres Explorer translucides avec Blur (AccentBlurBehind) à 50 %.
// @version 1.2.0
// @author Teddy
// @github https://github.com/PredaX6
// @include explorer.exe
// @architecture x86-64
// @compilerOptions -ldwmapi
// ==/WindhawkMod==

#include <windows.h>
#include <dwmapi.h>

constexpr DWORD WCA_ACCENT_POLICY = 19;
constexpr int ACCENT_ENABLE_BLURBEHIND = 3;
constexpr DWORD DWMWA_SYSTEMBACKDROP_TYPE_VALUE = 38;
constexpr int DWMSBT_AUTO_VALUE = 0;

struct ACCENT_POLICY {
    int AccentState;
    int AccentFlags;
    int GradientColor;
    int AnimationId;
};

struct WINDOWCOMPOSITIONATTRIBDATA {
    DWORD Attrib;
    PVOID pvData;
    SIZE_T cbData;
};

using SetWindowCompositionAttribute_t =
    BOOL(WINAPI*)(HWND, WINDOWCOMPOSITIONATTRIBDATA*);

static SetWindowCompositionAttribute_t g_SetWindowCompositionAttribute = nullptr;

static void ApplyWinTed(HWND hWnd) {
    if (!hWnd || !IsWindow(hWnd) || !g_SetWindowCompositionAttribute)
        return;

    const MARGINS margins = {-1, -1, -1, -1};
    DwmExtendFrameIntoClientArea(hWnd, &margins);

    HRGN blurRegion = CreateRectRgn(0, 0, -1, -1);

    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
    blur.fEnable = TRUE;
    blur.hRgnBlur = blurRegion;

    DwmEnableBlurBehindWindow(hWnd, &blur);

    if (blurRegion)
        DeleteObject(blurRegion);

    const int backdrop = DWMSBT_AUTO_VALUE;
    DwmSetWindowAttribute(
        hWnd,
        DWMWA_SYSTEMBACKDROP_TYPE_VALUE,
        &backdrop,
        sizeof(backdrop));

    ACCENT_POLICY accent = {};
    accent.AccentState = ACCENT_ENABLE_BLURBEHIND;
    accent.AccentFlags = 0;
    accent.GradientColor = 0x80000000;
    accent.AnimationId = 0;

    WINDOWCOMPOSITIONATTRIBDATA data = {};
    data.Attrib = WCA_ACCENT_POLICY;
    data.pvData = &accent;
    data.cbData = sizeof(accent);

    g_SetWindowCompositionAttribute(hWnd, &data);

    SetWindowPos(
        hWnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOACTIVATE | SWP_FRAMECHANGED);

    RedrawWindow(
        hWnd, nullptr, nullptr,
        RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
}

static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM) {
    if (!IsWindowVisible(hWnd))
        return TRUE;

    DWORD processId = 0;
    GetWindowThreadProcessId(hWnd, &processId);

    if (processId == GetCurrentProcessId() &&
        GetWindow(hWnd, GW_OWNER) == nullptr) {
        ApplyWinTed(hWnd);
    }

    return TRUE;
}

using CreateWindowExW_t = decltype(&CreateWindowExW);
static CreateWindowExW_t CreateWindowExW_Original = nullptr;

static HWND WINAPI CreateWindowExW_Hook(
    DWORD exStyle, LPCWSTR className, LPCWSTR windowName,
    DWORD style, int x, int y, int width, int height,
    HWND parent, HMENU menu, HINSTANCE instance, LPVOID param) {

    HWND hWnd = CreateWindowExW_Original(
        exStyle, className, windowName, style,
        x, y, width, height,
        parent, menu, instance, param);

    if (hWnd && !parent)
        ApplyWinTed(hWnd);

    return hWnd;
}

BOOL Wh_ModInit() {
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (!user32)
        return FALSE;

    g_SetWindowCompositionAttribute =
        reinterpret_cast<SetWindowCompositionAttribute_t>(
            GetProcAddress(user32, "SetWindowCompositionAttribute"));

    if (!g_SetWindowCompositionAttribute)
        return FALSE;

    EnumWindows(EnumWindowsProc, 0);

    return Wh_SetFunctionHook(
        reinterpret_cast<void*>(CreateWindowExW),
        reinterpret_cast<void*>(CreateWindowExW_Hook),
        reinterpret_cast<void**>(&CreateWindowExW_Original));
}

void Wh_ModUninit() {
}
