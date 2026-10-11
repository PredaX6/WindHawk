// ==WindhawkMod==
// @id              mica-explorer
// @name            Mica Explorer
// @description     Apply five Blur and Mica styles to Windows 11 File Explorer.
// @version         1.1.0
// @author          TeddySlexique
// @github          https://github.com/PredaX6/WindHawk
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -ldwmapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Mica Explorer

Choose a background style for Windows 11 File Explorer:
- **Défaut Blur** — AccentBlurBehind composition effect.
- **Mica clair** — standard native Mica.
- **Mica accentué** — Mica with immersive dark mode.
- **Mica Alt clair** — native tabbed-window backdrop.
- **Mica Alt accentué** — Mica Alt with immersive dark mode.

The exact appearance depends on Windows and its personalization settings.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- material: mica
  $name: Style de transparence
  $description: Choisissez l'effet appliqué à l'arrière-plan de l'Explorateur.
  $options:
  - blur: Défaut Blur
  - mica: Mica clair
  - micaAccent: Mica accentué
  - micaAlt: Mica Alt clair
  - micaAltAccent: Mica Alt accentué
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <dwmapi.h>
#include <windhawk_utils.h>

#include <cwchar>

namespace {

enum class Material {
    Blur,
    Mica,
    MicaAccent,
    MicaAlt,
    MicaAltAccent,
};

Material g_material = Material::Mica;

// Undocumented User32 composition API used by Glass Explorer's Blur style.
enum ACCENT_STATE {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_BLURBEHIND = 3,
};

struct ACCENT_POLICY {
    int AccentState;
    int AccentFlags;
    int GradientColor;
    int AnimationId;
};

enum WINDOWCOMPOSITIONATTRIB {
    WCA_ACCENT_POLICY = 19,
};

struct WINDOWCOMPOSITIONATTRIBDATA {
    WINDOWCOMPOSITIONATTRIB Attribute;
    PVOID Data;
    SIZE_T SizeOfData;
};

using SetWindowCompositionAttribute_t =
    BOOL(WINAPI*)(HWND, WINDOWCOMPOSITIONATTRIBDATA*);
SetWindowCompositionAttribute_t SetWindowCompositionAttribute_Original = nullptr;

using DwmSetWindowAttribute_t = decltype(&DwmSetWindowAttribute);
DwmSetWindowAttribute_t DwmSetWindowAttribute_Original = nullptr;

void SetBackdropType(HWND hwnd, int backdropType) {
    if (DwmSetWindowAttribute_Original) {
        DwmSetWindowAttribute_Original(hwnd, DWMWA_SYSTEMBACKDROP_TYPE,
                                       &backdropType, sizeof(backdropType));
    } else {
        DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &backdropType,
                              sizeof(backdropType));
    }
}

Material LoadMaterial() {
    PCWSTR value = Wh_GetStringSetting(L"material");
    Material material = Material::Mica;

    if (value && _wcsicmp(value, L"blur") == 0) {
        material = Material::Blur;
    } else if (value && _wcsicmp(value, L"micaAccent") == 0) {
        material = Material::MicaAccent;
    } else if (value && _wcsicmp(value, L"micaAlt") == 0) {
        material = Material::MicaAlt;
    } else if (value && _wcsicmp(value, L"micaAltAccent") == 0) {
        material = Material::MicaAltAccent;
    }

    if (value) {
        Wh_FreeStringSetting(value);
    }

    return material;
}

bool IsExplorerWindow(HWND hwnd) {
    if (!IsWindow(hwnd)) {
        return false;
    }

    WCHAR className[64]{};
    if (!GetClassNameW(hwnd, className, ARRAYSIZE(className))) {
        return false;
    }

    return _wcsicmp(className, L"CabinetWClass") == 0;
}

void ApplyMaterial(HWND hwnd) {
    if (!IsExplorerWindow(hwnd)) {
        return;
    }

    if (g_material == Material::Blur) {
        // Disable DWM's Mica/SystemBackdrop first, then apply AccentBlurBehind.
        const int backdropType = DWMSBT_NONE;
        SetBackdropType(hwnd, backdropType);

        if (SetWindowCompositionAttribute_Original) {
            ACCENT_POLICY policy{};
            policy.AccentState = ACCENT_ENABLE_BLURBEHIND;
            WINDOWCOMPOSITIONATTRIBDATA data{
                WCA_ACCENT_POLICY, &policy, sizeof(policy)};
            SetWindowCompositionAttribute_Original(hwnd, &data);
        }
        return;
    }

    // Do not leave AccentBlurBehind active when switching to a DWM material.
    if (SetWindowCompositionAttribute_Original) {
        ACCENT_POLICY policy{};
        policy.AccentState = ACCENT_DISABLED;
        WINDOWCOMPOSITIONATTRIBDATA data{
            WCA_ACCENT_POLICY, &policy, sizeof(policy)};
        SetWindowCompositionAttribute_Original(hwnd, &data);
    }

    const bool isAlt = g_material == Material::MicaAlt ||
                       g_material == Material::MicaAltAccent;
    const bool isAccent = g_material == Material::MicaAccent ||
                          g_material == Material::MicaAltAccent;

    // Accent variants use immersive dark mode for a distinct darker appearance.
    const BOOL darkMode = isAccent ? TRUE : FALSE;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode,
                          sizeof(darkMode));

    const int backdropType = isAlt ? DWMSBT_TABBEDWINDOW : DWMSBT_MAINWINDOW;
    SetBackdropType(hwnd, backdropType);
}

BOOL CALLBACK EnumExplorerWindowsProc(HWND hwnd, LPARAM) {
    ApplyMaterial(hwnd);
    return TRUE;
}


HRESULT WINAPI DwmSetWindowAttribute_Hook(HWND hwnd,
                                          DWORD attribute,
                                          LPCVOID value,
                                          DWORD valueSize) {
    if (attribute == DWMWA_SYSTEMBACKDROP_TYPE && IsExplorerWindow(hwnd)) {
        // Keep the chosen style even if Explorer requests another backdrop.
        ApplyMaterial(hwnd);
        return S_OK;
    }

    return DwmSetWindowAttribute_Original(hwnd, attribute, value, valueSize);
}

using CreateWindowExW_t = decltype(&CreateWindowExW);
CreateWindowExW_t CreateWindowExW_Original = nullptr;

HWND WINAPI CreateWindowExW_Hook(DWORD exStyle,
                                 LPCWSTR className,
                                 LPCWSTR windowName,
                                 DWORD style,
                                 int x,
                                 int y,
                                 int width,
                                 int height,
                                 HWND parent,
                                 HMENU menu,
                                 HINSTANCE instance,
                                 LPVOID parameter) {
    HWND hwnd = CreateWindowExW_Original(
        exStyle, className, windowName, style, x, y, width, height, parent,
        menu, instance, parameter);

    if (hwnd) {
        ApplyMaterial(hwnd);
    }

    return hwnd;
}

}  // namespace

BOOL Wh_ModInit() {
    g_material = LoadMaterial();

    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (user32) {
        SetWindowCompositionAttribute_Original =
            reinterpret_cast<SetWindowCompositionAttribute_t>(
                GetProcAddress(user32, "SetWindowCompositionAttribute"));
    }

    WindhawkUtils::SetFunctionHook(DwmSetWindowAttribute,
                                   DwmSetWindowAttribute_Hook,
                                   &DwmSetWindowAttribute_Original);
    WindhawkUtils::SetFunctionHook(CreateWindowExW, CreateWindowExW_Hook,
                                   &CreateWindowExW_Original);

    EnumWindows(EnumExplorerWindowsProc, 0);
    return TRUE;
}

void Wh_ModSettingsChanged() {
    g_material = LoadMaterial();
    EnumWindows(EnumExplorerWindowsProc, 0);
}
