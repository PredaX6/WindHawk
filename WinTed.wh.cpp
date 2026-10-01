// ==WindhawkMod==
// @id winted
// @name WinTed
// @description Fenêtres Windows translucides avec Blur (AccentBlurBehind) à 50 %.
// @version 1.0.0
// @author Teddy
// @github https://github.com/PredaX6
// @include *
// @compilerOptions -ldwmapi
// ==/WindhawkMod==

#include <windows.h>
#include <dwmapi.h>

constexpr DWORD WCA_ACCENT_POLICY = 19;
constexpr int ACCENT_ENABLE_ACRYLICBLURBEHIND = 4;

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

static SetWindowCompositionAttribute_t SetWindowCompositionAttribute_Original = nullptr;

static void ApplyWinTed(HWND hWnd) {
    if (!hWnd || !IsWindow(hWnd) || !SetWindowCompositionAttribute_Original)
        return;

    // Étend le frame DWM à toute la fenêtre : barre de titre + contenu.
    MARGINS margins = {-1, -1, -1, -1};
    DwmExtendFrameIntoClientArea(hWnd, &margins);

    ACCENT_POLICY accent = {};
    accent.AccentState = ACCENT_ENABLE_ACRYLICBLURBEHIND;

    // AABBGGRR : 0x80 = 50 % d'opacité du calque.
    accent.GradientColor = 0x80000000;

    WINDOWCOMPOSITIONATTRIBDATA data = {};
    data.Attrib = WCA_ACCENT_POLICY;
    data.pvData = &accent;
    data.cbData = sizeof(accent);

    SetWindowCompositionAttribute_Original(hWnd, &data);

    SetWindowPos(
        hWnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOACTIVATE | SWP_FRAMECHANGED);

    RedrawWindow(
        hWnd, nullptr, nullptr,
        RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
}

using CreateWindowExW_t = decltype(&CreateWindowExW);
static CreateWindowExW_t CreateWindowExW_Original = nullptr;

static HWND WINAPI CreateWindowExW_Hook(
    DWORD dwExStyle,
    LPCWSTR lpClassName,
    LPCWSTR lpWindowName,
    DWORD dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent,
    HMENU hMenu,
    HINSTANCE hInstance,
    LPVOID lpParam) {

    HWND hWnd = CreateWindowExW_Original(
        dwExStyle, lpClassName, lpWindowName, dwStyle,
        X, Y, nWidth, nHeight, hWndParent, hMenu,
        hInstance, lpParam);

    if (hWnd)
        ApplyWinTed(hWnd);

    return hWnd;
}

BOOL Wh_ModInit() {
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (!user32)
        return FALSE;

    SetWindowCompositionAttribute_Original =
        reinterpret_cast<SetWindowCompositionAttribute_t>(
            GetProcAddress(user32, "SetWindowCompositionAttribute"));

    if (!SetWindowCompositionAttribute_Original)
        return FALSE;

    return Wh_SetFunctionHook(
        reinterpret_cast<void*>(CreateWindowExW),
        reinterpret_cast<void*>(CreateWindowExW_Hook),
        reinterpret_cast<void**>(&CreateWindowExW_Original));
}

void Wh_ModUninit() {
}
