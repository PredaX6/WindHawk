// ==WindhawkMod==
// @id winted
// @name WinTed
// @description Windows 11 25H2 : thème Translucent Explorer 11 avec choix du type de transparence.
// @version 1.4.7
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
constexpr int ACCENT_ENABLE_TRANSPARENTGRADIENT = 2;
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

using DwmSetWindowAttribute_t = decltype(&DwmSetWindowAttribute);
static DwmSetWindowAttribute_t DwmSetWindowAttribute_Original = nullptr;

static HRESULT WINAPI DwmSetWindowAttribute_Hook(
    HWND hWnd, DWORD attribute, LPCVOID value, DWORD size) {

    if (attribute == DWMWA_SYSTEMBACKDROP_TYPE &&
        hWnd && IsWindow(hWnd)) {

        int backdrop = 0; // Auto.

        if (wcscmp(g_TransparencyType, L"acrylic") == 0) {
            backdrop = DWMSBT_ACRYLIC_VALUE;
        } else if (wcscmp(g_TransparencyType, L"mica") == 0) {
            backdrop = DWMSBT_MICA_VALUE;
        } else if (wcscmp(g_TransparencyType, L"micaAlt") == 0) {
            backdrop = DWMSBT_MICAALT_VALUE;
        } else if (wcscmp(g_TransparencyType, L"default") == 0) {
            // The default is the original Translucent Explorer 11 look.
            backdrop = DWMSBT_ACRYLIC_VALUE;
        }

        return DwmSetWindowAttribute_Original(
            hWnd, attribute, &backdrop, sizeof(backdrop));
    }

    return DwmSetWindowAttribute_Original(hWnd, attribute, value, size);
}

static void SetAccentBlurBehind(HWND hWnd, bool enable) {
    HRGN region = enable ? CreateRectRgn(0, 0, -1, -1) : nullptr;

    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE | (enable ? DWM_BB_BLURREGION : 0);
    blur.fEnable = enable;
    blur.hRgnBlur = region;

    DwmEnableBlurBehindWindow(hWnd, &blur);

    if (region)
        DeleteObject(region);

    if (!enable) {
        // Restore the WinUI host backdrop when AccentBlurBehind is not used.
        BOOL useHostBackdropBrush = TRUE;
        DwmSetWindowAttribute(
            hWnd,
            DWMWA_USE_HOSTBACKDROPBRUSH,
            &useHostBackdropBrush,
            sizeof(useHostBackdropBrush));
        return;
    }

    constexpr int ACCENT_ENABLE_ACRYLICBLURBEHIND = 4;

    ACCENT_POLICY accent = {};
    accent.AccentState = ACCENT_ENABLE_ACRYLICBLURBEHIND;
    accent.AccentFlags = 0;
    accent.GradientColor = 0x3A232323;
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

static void DisableAccent(HWND hWnd) {
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

    const bool isDefault =
        wcscmp(g_TransparencyType, L"default") == 0;
    const bool isBlur =
        wcscmp(g_TransparencyType, L"blur") == 0;

    // Les modes SystemBackdrop ont chacun leur propre matériau DWM.
    // Le mode par défaut conserve le rendu historique de WinTed.
    if (isDefault || isBlur) {
        const MARGINS margins = {-1, -1, -1, -1};
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    } else {
        const MARGINS margins = {0, 0, 0, 0};
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    }

    if (isBlur) {
        // Blur : AccentBlurBehind réel, sans SystemBackdrop forcé.
        const int backdrop = 0; // DWMSBT_AUTO
        DwmSetWindowAttribute(
            hWnd, DWMWA_SYSTEMBACKDROP_TYPE,
            &backdrop, sizeof(backdrop));
        SetAccentBlurBehind(hWnd, true);
    } else if (wcscmp(g_TransparencyType, L"acrylic") == 0) {
        const int backdrop = DWMSBT_ACRYLIC_VALUE;
        DwmSetWindowAttribute(
            hWnd, DWMWA_SYSTEMBACKDROP_TYPE,
            &backdrop, sizeof(backdrop));
        SetAccentBlurBehind(hWnd, false);
    } else if (wcscmp(g_TransparencyType, L"mica") == 0) {
        const int backdrop = DWMSBT_MICA_VALUE;
        DwmSetWindowAttribute(
            hWnd, DWMWA_SYSTEMBACKDROP_TYPE,
            &backdrop, sizeof(backdrop));
        SetAccentBlurBehind(hWnd, false);
    } else if (wcscmp(g_TransparencyType, L"micaAlt") == 0) {
        const int backdrop = DWMSBT_MICAALT_VALUE;
        DwmSetWindowAttribute(
            hWnd, DWMWA_SYSTEMBACKDROP_TYPE,
            &backdrop, sizeof(backdrop));
        SetAccentBlurBehind(hWnd, false);
    } else {
        // Par défaut : même base que la version 1.3.0 fonctionnelle.
        const int backdrop = DWMSBT_ACRYLIC_VALUE;
        DwmSetWindowAttribute(
            hWnd, DWMWA_SYSTEMBACKDROP_TYPE,
            &backdrop, sizeof(backdrop));
        SetAccentBlurBehind(hWnd, true);
    }

    SetWindowPos(
        hWnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOACTIVATE | SWP_FRAMECHANGED);

    SendMessage(hWnd, WM_WINDOWPOSCHANGED, 0, 0);
    SendMessage(hWnd, WM_DWMCOMPOSITIONCHANGED, 0, 0);

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

    // Explorer peut réappliquer son propre SystemBackdrop après la création
    // de la fenêtre. On intercepte donc ses changements pour conserver le choix.
    if (!Wh_SetFunctionHook(
            reinterpret_cast<void*>(DwmSetWindowAttribute),
            reinterpret_cast<void*>(DwmSetWindowAttribute_Hook),
            reinterpret_cast<void**>(&DwmSetWindowAttribute_Original))) {
        return FALSE;
    }

    EnumWindows(EnumWindowsProc, 0);

    return Wh_SetFunctionHook(
        reinterpret_cast<void*>(CreateWindowExW),
        reinterpret_cast<void*>(CreateWindowExW_Hook),
        reinterpret_cast<void**>(&CreateWindowExW_Original));
}

void Wh_ModUninit() {
}
