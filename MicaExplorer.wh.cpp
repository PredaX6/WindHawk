// ==WindhawkMod==
// @id              mica-explorer
// @name            Mica Explorer
// @description     Apply six Blur and Mica styles to Windows 11 File Explorer.
// @version         1.2.6
// @author          TeddySlexique
// @github          https://github.com/PredaX6/WindHawk
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -lcomctl32 -ldwmapi -lgdi32
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Mica Explorer

Choose a background style for Windows 11 File Explorer:
- **Transparent Blur** — standard AccentBlurBehind composition effect.
- **Blur** — acrylic blur with a lower tint opacity, where supported by Windows.
- **Clair Blur** — acrylic blur with a softer, lighter tint.
- **Acrylique sombre (style menu Démarrer)** — dark-tinted acrylic intended to approximate the Start menu backdrop.
- **Mica accentué** — Mica with immersive dark mode.
- **Mica Alt accentué** — Mica Alt with immersive dark mode.

The exact appearance depends on Windows and its personalization settings.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- material: micaAccent
  $name: Style de transparence
  $description: Choisissez l'effet appliqué à l'arrière-plan de l'Explorateur.
  $options:
  - blur: Transparent Blur
  - blurTransparent: Blur
  - blurSoft: Clair Blur
  - startMenu: Acrylique sombre (style menu Démarrer)
  - micaAccent: Mica accentué
  - micaAltAccent: Mica Alt accentué
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <commctrl.h>
#include <dwmapi.h>
#include <windhawk_utils.h>

#include <cwchar>

namespace {

enum class Material {
    Blur,
    BlurTransparent,
    BlurSoft,
    StartMenu,
    MicaAccent,
    MicaAltAccent,
};

Material g_material = Material::MicaAccent;

// Undocumented User32 composition API used by Glass Explorer's Blur style.
enum ACCENT_STATE {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_BLURBEHIND = 3,
    ACCENT_ENABLE_ACRYLICBLURBEHIND = 4,
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

using DwmExtendFrameIntoClientArea_t = decltype(&DwmExtendFrameIntoClientArea);
DwmExtendFrameIntoClientArea_t DwmExtendFrameIntoClientArea_Original = nullptr;

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
    Material material = Material::MicaAccent;

    if (value && _wcsicmp(value, L"blur") == 0) {
        material = Material::Blur;
    } else if (value && _wcsicmp(value, L"blurTransparent") == 0) {
        material = Material::BlurTransparent;
    } else if (value && _wcsicmp(value, L"blurSoft") == 0) {
        material = Material::BlurSoft;
    } else if (value && _wcsicmp(value, L"startMenu") == 0) {
        material = Material::StartMenu;
    } else if (value && _wcsicmp(value, L"micaAccent") == 0) {
        material = Material::MicaAccent;
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

void TriggerWindowCompositionUpdate(HWND hwnd) {
    WINDOWPOS windowPos{};
    windowPos.hwnd = hwnd;
    windowPos.flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE;
    SendMessageW(hwnd, WM_WINDOWPOSCHANGED, 0, reinterpret_cast<LPARAM>(&windowPos));
    SendMessageW(hwnd, WM_DWMCOMPOSITIONCHANGED, 0, 0);
    RedrawWindow(hwnd, nullptr, nullptr,
                 RDW_INVALIDATE | RDW_ERASE | RDW_FRAME | RDW_ALLCHILDREN);
}

// Match Glass Explorer's working AccentBlurBehind setup. The DWM blur-behind
// region prevents the extended frame from being drawn over the accent material.
void SetAccentBlurBehind(HWND hwnd, bool enable, int gradientColor = 0x3A232323) {
    HRGN region = enable ? CreateRectRgn(0, 0, -1, -1) : nullptr;
    DWM_BLURBEHIND blurBehind{};
    blurBehind.dwFlags = DWM_BB_ENABLE | (enable ? DWM_BB_BLURREGION : 0u);
    blurBehind.fEnable = enable;
    blurBehind.hRgnBlur = region;
    DwmEnableBlurBehindWindow(hwnd, &blurBehind);
    if (region) {
        DeleteObject(region);
    }

    if (SetWindowCompositionAttribute_Original) {
        ACCENT_POLICY policy{};
        policy.AccentState = enable ? ACCENT_ENABLE_ACRYLICBLURBEHIND : ACCENT_DISABLED;
        policy.GradientColor = enable ? gradientColor : 0;
        WINDOWCOMPOSITIONATTRIBDATA data{
            WCA_ACCENT_POLICY, &policy, sizeof(policy)};
        SetWindowCompositionAttribute_Original(hwnd, &data);
    }

    if (!enable && DwmSetWindowAttribute_Original) {
        // Restore the backdrop brush that WinUI/Explorer normally owns.
        const BOOL useHostBackdropBrush = TRUE;
        DwmSetWindowAttribute_Original(hwnd, DWMWA_USE_HOSTBACKDROPBRUSH,
                                       &useHostBackdropBrush,
                                       sizeof(useHostBackdropBrush));
    }
}

void ApplyMaterial(HWND hwnd) {
    if (!IsExplorerWindow(hwnd)) {
        return;
    }

    // Also apply this to already-existing Explorer windows, not only future
    // DwmExtendFrameIntoClientArea calls.
    if (DwmExtendFrameIntoClientArea_Original) {
        const MARGINS fullWindowMargins{-1, -1, -1, -1};
        DwmExtendFrameIntoClientArea_Original(hwnd, &fullWindowMargins);
    }

    const bool isBlur = g_material == Material::Blur ||
                        g_material == Material::BlurTransparent ||
                        g_material == Material::BlurSoft ||
                        g_material == Material::StartMenu;
    if (isBlur) {
        // Use the same sequence as Glass Explorer: disable the DWM system
        // backdrop, allow the full-window blur-behind region, then apply acrylic.
        const int backdropType = DWMSBT_NONE;
        SetBackdropType(hwnd, backdropType);

        const BOOL disableDwmTransitions = FALSE;
        if (DwmSetWindowAttribute_Original) {
            DwmSetWindowAttribute_Original(
                hwnd, DWMWA_TRANSITIONS_FORCEDISABLED,
                &disableDwmTransitions, sizeof(disableDwmTransitions));
        }

        int gradientColor = 0x3A232323;
        if (g_material == Material::BlurTransparent) {
            gradientColor = 0x66000000;
        } else if (g_material == Material::BlurSoft) {
            gradientColor = static_cast<int>(0x99E8E8E8);
        } else if (g_material == Material::StartMenu) {
            gradientColor = static_cast<int>(0xCC232323);
        }

        SetAccentBlurBehind(hwnd, true, gradientColor);
        TriggerWindowCompositionUpdate(hwnd);
        return;
    }

    // Remove both AccentBlurBehind layers before restoring a DWM material.
    SetAccentBlurBehind(hwnd, false);

    const bool isAlt = g_material == Material::MicaAltAccent;
    const bool isAccent = g_material == Material::MicaAccent ||
                          g_material == Material::MicaAltAccent;

    // Accent variants use immersive dark mode for a distinct darker appearance.
    const BOOL darkMode = isAccent ? TRUE : FALSE;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode,
                          sizeof(darkMode));

    const int backdropType = isAlt ? DWMSBT_TABBEDWINDOW : DWMSBT_MAINWINDOW;
    SetBackdropType(hwnd, backdropType);
    TriggerWindowCompositionUpdate(hwnd);
}

BOOL CALLBACK EnumExplorerWindowsProc(HWND hwnd, LPARAM) {
    ApplyMaterial(hwnd);
    return TRUE;
}


HRESULT WINAPI DwmExtendFrameIntoClientArea_Hook(HWND hwnd,
                                                  const MARGINS* margins) {
    if (IsExplorerWindow(hwnd)) {
        // DWM backdrops are otherwise easily hidden by Explorer's opaque
        // client area. Extend the DWM frame through the whole window so the
        // selected material can be visible behind the Explorer content.
        const MARGINS fullWindowMargins{-1, -1, -1, -1};
        return DwmExtendFrameIntoClientArea_Original(hwnd, &fullWindowMargins);
    }

    return DwmExtendFrameIntoClientArea_Original(hwnd, margins);
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

// Reapply the material when Explorer actually shows a newly created window.
// Explorer can reset its DWM/accent state after CreateWindowExW returns.
constexpr UINT_PTR kMaterialSubclassId = 0x4D455850;

LRESULT CALLBACK ExplorerWindowSubclassProc(HWND hwnd,
                                             UINT message,
                                             WPARAM wParam,
                                             LPARAM lParam,
                                             UINT_PTR subclassId,
                                             DWORD_PTR) {
    // Set the material before the default show/position processing begins,
    // so DWM has the best chance of using it for the opening animation.
    if ((message == WM_SHOWWINDOW && wParam) ||
        (message == WM_WINDOWPOSCHANGED && lParam &&
         (reinterpret_cast<const WINDOWPOS*>(lParam)->flags & SWP_SHOWWINDOW))) {
        ApplyMaterial(hwnd);
    }

    const LRESULT result = DefSubclassProc(hwnd, message, wParam, lParam);

    if (message == WM_NCDESTROY) {
        RemoveWindowSubclass(hwnd, ExplorerWindowSubclassProc, subclassId);
    }

    return result;
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

    if (hwnd && IsExplorerWindow(hwnd)) {
        // Apply once after creation and attach a show-time callback so the
        // final material is restored after Explorer finishes window setup.
        ApplyMaterial(hwnd);
        SetWindowSubclass(hwnd, ExplorerWindowSubclassProc,
                          kMaterialSubclassId, 0);
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
    WindhawkUtils::SetFunctionHook(DwmExtendFrameIntoClientArea,
                                   DwmExtendFrameIntoClientArea_Hook,
                                   &DwmExtendFrameIntoClientArea_Original);
    WindhawkUtils::SetFunctionHook(CreateWindowExW, CreateWindowExW_Hook,
                                   &CreateWindowExW_Original);

    EnumWindows(EnumExplorerWindowsProc, 0);
    return TRUE;
}

void Wh_ModSettingsChanged() {
    g_material = LoadMaterial();
    EnumWindows(EnumExplorerWindowsProc, 0);
}
