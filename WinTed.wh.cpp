// ==WindhawkMod==
// @id winted
// @name WinTed
// @description Windows 11 25H2 : thème Translucent Explorer 11 avec choix du type de transparence.
// @version 1.4.2
// @author Teddy
// @github https://github.com/PredaX6
// @include explorer.exe
// @architecture x86-64
// @compilerOptions -ldwmapi -lgdi32
// ==/WindhawkMod==

// ==WindhawkModSettings==
/*
- transparencyType: default
  $name: Type de transparence
  $description: Choisissez le rendu de transparence de l'Explorateur.
  $options:
    - default: Par défaut
    - blur: Blur (AccentBlurBehind)
    - acrylic: Acrylic (SystemBackdrop)
    - mica: Mica (SystemBackdrop)
    - micaAlt: MicaAlt (SystemBackdrop)
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <dwmapi.h>

constexpr DWORD WCA_ACCENT_POLICY = 19;
constexpr int ACCENT_ENABLE_BLURBEHIND = 3;

// Windows 11 25H2.
constexpr DWORD DWMWA_SYSTEMBACKDROP_TYPE_VALUE = 38;

// DWM_SYSTEMBACKDROP_TYPE:
// 0 = Auto
// 1 = None
// 2 = Mica
// 3 = Acrylic
// 4 = MicaAlt
constexpr int DWMSBT_MICA_VALUE = 2;
constexpr int DWMSBT_ACRYLIC_VALUE = 3;
constexpr int DWMSBT_MICAALT_VALUE = 4;

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
static wchar_t g_TransparencyType[32] = L"default";

static void ApplyAccentBlur(HWND hWnd) {
    HRGN blurRegion = CreateRectRgn(0, 0, -1, -1);

    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
    blur.fEnable = TRUE;
    blur.hRgnBlur = blurRegion;

    DwmEnableBlurBehindWindow(hWnd, &blur);

    if (blurRegion)
        DeleteObject(blurRegion);

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
}

static void SetSystemBackdrop(HWND hWnd, int backdrop) {
    DwmSetWindowAttribute(
        hWnd,
        DWMWA_SYSTEMBACKDROP_TYPE_VALUE,
        &backdrop,
        sizeof(backdrop));
}

static void DisableAccentBlur(HWND hWnd) {
    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE;
    blur.fEnable = FALSE;
    DwmEnableBlurBehindWindow(hWnd, &blur);

    ACCENT_POLICY accent = {};
    accent.AccentState = 0;

    WINDOWCOMPOSITIONATTRIBDATA data = {};
    data.Attrib = WCA_ACCENT_POLICY;
    data.pvData = &accent;
    data.cbData = sizeof(accent);

    g_SetWindowCompositionAttribute(hWnd, &data);
}

static void ApplyWinTed(HWND hWnd) {
    if (!hWnd || !IsWindow(hWnd) || !g_SetWindowCompositionAttribute)
        return;

    // Étend le rendu DWM jusque sous la barre de titre et les bordures.
    const MARGINS margins = {-1, -1, -1, -1};
    DwmExtendFrameIntoClientArea(hWnd, &margins);

    // Chaque mode est maintenant réellement exclusif.
    DisableAccentBlur(hWnd);

    if (wcscmp(g_TransparencyType, L"blur") == 0) {
        // Blur = AccentBlurBehind uniquement.
        const int autoBackdrop = 0;
        SetSystemBackdrop(hWnd, autoBackdrop);
        ApplyAccentBlur(hWnd);
    } else if (wcscmp(g_TransparencyType, L"acrylic") == 0) {
        // Acrylic = Desktop Acrylic (SystemBackdrop).
        SetSystemBackdrop(hWnd, DWMSBT_ACRYLIC_VALUE);
    } else if (wcscmp(g_TransparencyType, L"mica") == 0) {
        // Mica = Mica standard (SystemBackdrop).
        SetSystemBackdrop(hWnd, DWMSBT_MICA_VALUE);
    } else if (wcscmp(g_TransparencyType, L"micaAlt") == 0) {
        // MicaAlt = Mica alternate (SystemBackdrop).
        SetSystemBackdrop(hWnd, DWMSBT_MICAALT_VALUE);
    } else {
        // Par défaut = le rendu natif du thème Translucent Explorer 11.
        // Le thème Translucent Explorer 11 utilise Acrylic comme effet de fond.
        SetSystemBackdrop(hWnd, DWMSBT_ACRYLIC_VALUE);
    }

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

    if (!Wh_GetStringSetting(
            L"transparencyType",
            g_TransparencyType,
            ARRAYSIZE(g_TransparencyType))) {
        wcscpy_s(g_TransparencyType, L"default");
    }

    EnumWindows(EnumWindowsProc, 0);

    return Wh_SetFunctionHook(
        reinterpret_cast<void*>(CreateWindowExW),
        reinterpret_cast<void*>(CreateWindowExW_Hook),
        reinterpret_cast<void**>(&CreateWindowExW_Original));
}

void Wh_ModUninit() {
}
