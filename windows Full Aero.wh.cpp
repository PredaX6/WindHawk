// ==WindhawkMod==
// @id              translucent-windows
// @name            windows Full Aero
// @description     Windows Full Aero avec stylisation intégrée de l'Explorateur de fichiers Windows 11
// @version         1.8.2
// @author          Undisputed00x
// @github          https://github.com/Undisputed00x
// @include         *
// @compilerOptions -ldwmapi -luxtheme -lcomctl32 -lgdi32 -ld2d1 -lmsimg32 -lshcore -lversion -ffp-exception-behavior=maytrap
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*

### ⚠️ FAQ section below ⚠️
### ❗For any excluded process, if the global "New system colors" setting is enabled, please add the excluded processes to the process rules in the mod settings instead.❗

- ## Theme Customization
| **Default cleartype text** | **Greyscale text** |
|:---:|:---:|
| ![Cleartype](https://i.imgur.com/utajxyq.png) | ![Greyscale](https://i.imgur.com/0OelxZH.png) |

| **Default text** | **Alpha blended text** |
|:---:|:---:|
| ![Default](https://i.imgur.com/ZgrJMgP.png) | ![Composited](https://i.imgur.com/4lQU2a4.png) |

| **Default themed controls** | **Custom themed controls** |
|:---:|:---:|
| ![Default Theme](https://i.imgur.com/8hYI1DZ.png) | ![Custom Theme](https://i.imgur.com/vWbelew.png) |

- ## Translucent effects
| **Blur (AccentBlurBehind)** | **Acrylic (SystemBackdrop)** |
|:---:|:---:|
| ![AccentBlurBehind](https://i.imgur.com/tSf5ztk.png) | ![Acrylic SystemBackdrop](https://i.imgur.com/YNktLTu.png) |

| **Mica (SystemBackdrop)** | **MicaAlt (SystemBackdrop)** |
|:---:|:---:|
| ![Mica](https://i.imgur.com/1ciJJck.png) | ![MicaTabbed](https://i.imgur.com/5Dxj5PS.png) |

## Credits 
The custom theme is a close copy of the Rectify 11 theme created by [WinExperiments](https://github.com/WinExperiments).
#
The inspiration for this mod came from the awesome Windows effects customization projects of [Maplespe](https://github.com/Maplespe) and [ALTaleX531](https://github.com/ALTaleX531).
#
Thanks also to [m417z](https://github.com/m417z) for his help and input in completing the mod.

## FAQ

* ⚠️Use Windows 11 File Explorer Styler mod and select the Translucent Explorer11 theme
in order to get translucent WinUI parts of the new file explorer.⚠️

* ❗The new system colors setting option adjusts the [system colors](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsyscolor) 
in order to blend with the background translucency / custom theme rendering. 
This setting option overrides any process exclusion as these colors are applied system-wide using 
the [SetSysColor](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setsyscolors) API.
Intercepting and changing the system colors in a proper way is quite difficult, more details
in another software project that faced the same problem: https://github.com/namazso/SecureUxTheme/issues/9#issuecomment-611897882 ❗

* ⚠️Set a process rule in the mod's settings with custom theme rendering disabled, in order to reset (if possible) the custom system colors to default for the target process.⚠️

* ❗The Windows custom theme rendering also fixes invisible text by restoring alpha and modifying text colors.
Extending effects to the entire window can result in text being barely readable or even invisible in some cases. 
Enabling HDR, 10bit color depth output, having a black color, or a white background behind the window can cause this. 
This is because most GDI rendering operations ignore or do not preserve alpha values.❗

* ⚠️Prerequisited windows settings to enable the background effects⚠️
    - Transparency effects enabled
    - Energy saver disabled
#
* ⚠️The background effects do not affect most modern windows (UWP/WinUI), 
apps with different front-end rendering (e.g Qt, Electron, Chromium etc.. programs) and native windows with hardcoded colors.⚠️

* ⚠️If parts of the Windows UI colors remain modified after disabling the modification, this is happening when new system colors are applied in a selected Windows custom theme.
Changing the theme to the default and vice versa fixes the problem. As a last resort, you can delete the registry key HKEY_CURRENT_USER\Control Panel\Colors and reboot.⚠️

* ⚠️ARM64 system is only partially supported.⚠️

* ❕The blur effect may show a bleeding effect at the edges of a window when maximized or snapped to the edge of the screen. 
This is caused by default by the AccentBlur API.❕

* ✨The mod works best on the default dark theme.✨

## Explorateur de fichiers Windows 11

La personnalisation complète de l'Explorateur de fichiers Windows 11 est intégrée directement à ce mode. Il n'est plus nécessaire d'installer séparément Windows 11 File Explorer Styler.

*/

// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- RenderingMod:
    - ThemeBackground: TRUE
      $name: 🔷 Windows theme custom rendering
      $description: >-
       Modifies parts of the Windows theme using the Direct2D graphics API and modifies 
       Windows GDI text rendering by patching the alpha channel and adjusting text colors.
        ✨It is recommended to enable this with background translucent effects.
    - SysColors: FALSE
      $name: 🔷 New system colors
      $description: >-
       Modifies additional system UI colors by calling SetSysColors API. (Requires Windows theme custom rendering)
        ⚠️For issues with excluded processes, use process rules in mod's settings. For more refer to the FAQ.
    - AccentColorControls: TRUE
      $name: 🔷 Windows theme accent colorizer
      $description: >-
       Paint with accent color parts of windows theme. (Requires Windows theme custom rendering)
  $name: 🔶 Theme Customization
- BackgroundEffects:
    - type: acrylicblur
      $name: 🔷 Background effects
      $description: >-
        Windows 11 version >= 22621.xxx (22H2) is required for SystemBackdrop effects.
      $options:
      - none: Default
      - acrylicblur: Blur (AccentBlurBehind)
      - acrylicsystem: Acrylic (SystemBackdrop)
      - mica: Mica (SystemBackdrop)
      - mica_tabbed: MicaAlt (SystemBackdrop)
    - AccentBlurBehind: "3A232323"
      $name: 🔷 AccentBlurBehind color blend
      $description: >-
        Blending color with blur background.
        Color in hexadecimal ARGB format e.g. 3A232323
  $name: 🔶 Translucent Effects
- FlyoutsEffects: TRUE
  $name: 🔶 Flyout effects
  $description: >-
    Expand the effects to Win32 flyouts (context menus, dropdown menus, tooltips)
     ✨It is recommended to enable this with both background translucent effects and Windows theme custom rendering.
- RuledPrograms:
    - - target: "Notepad.exe"
        $name: 🔶 Process
        $description: >-
         Entries can be process names, paths or subdirectories for example:
          • Notepad.exe
          • C:\Program Files\Microsoft Office\root\Office16\EXCEL.EXE
          • C:\Users
      - RenderingMod:
          - ThemeBackground: FALSE
            $name: 🔷 Windows theme custom rendering
            $description: >-
              Modifies parts of the Windows theme using the Direct2D graphics API and modifies Windows GDI text rendering by patching the alpha channel and adjusting text colors.
               ✨It is recommended to enable this with background translucent effects.
          - AccentColorControls: FALSE
            $name: 🔷 Windows theme accent colorizer
            $description: >-
              Paint with accent color parts of windows theme. (Requires Windows theme custom rendering)
        $name: 🔶 Theme Customization
      - BackgroundEffects:
        - type: none
          $name: 🔷 Background translucent effects
          $description: >-
           Windows 11 version >= 22621.xxx (22H2) is required for SystemBackdrop effects.
          $options:
          - none: Default
          - acrylicblur: Blur (AccentBlurBehind)
          - acrylicsystem: Acrylic (SystemBackdrop)
          - mica: Mica (SystemBackdrop)
          - mica_tabbed: MicaAlt (SystemBackdrop)
        - AccentBlurBehind: "3A232323"
          $name: 🔷 AccentBlurBehind color blend
          $description: >-
           Blending color with blur background.
            Color in hexadecimal ARGB format e.g. 3A232323
        $name: 🔶 Translucent Effects
  $name: ⏩ Process Rules
  $description: >-
      Add rules to each specified process or processes from specific subdirectories
       ❗ Add process rules for the excluded process instead of using Windhawk's process exclusion when the "New system colors" global setting is enabled.


// ===== Stylisation intégrée de l'Explorateur de fichiers Windows 11 =====
- theme: ""
  $name: Thème
  $description: >-
    Themes are collections of styles. For details about the themes below, or for
    information about submitting your own theme, refer to the relevant section
    in the mod details.
  $options:
  - "": Aucun
  - Translucent Explorer11: Translucent Explorer11
  - MicaBar: MicaBar
  - NoCommandBar: NoCommandBar
  - Minimal Explorer11: Minimal Explorer11
  - Tabless: Tabless
  - Matter: Matter
  - WindowGlass: WindowGlass
  - AddressSearchOnly: AddressSearchOnly
  - TintedGlass: TintedGlass
  - LiquidGlass: LiquidGlass
  - MicaTabless: MicaTabless
  - OS26 Liquid Glass: OS26 Liquid Glass
  - OS26 Liquid Glass_variant_Compact: OS26 Liquid Glass (Compact)
  - ZEUSosX_044: ZEUSosX_044
  - Compact Explorer11: Compact Explorer11
  - Float: Float
- backgroundTranslucentEffect: ""
  $name: Effet d'arrière-plan translucide
  $description: >-
    The translucent effect to use for the File Explorer background. For
    additional translucent effects, check out the Translucent Windows mod.
  $options:
  - "": Par défaut pour le thème sélectionné
  - default: Par défaut de Windows
  - acrylicblur: Blur (AccentBlurBehind)
  - acrylic: Acrylique
  - mica: Mica
  - micaAlt: Mica Alt
  - none: Aucun
- backgroundTranslucentEffectRegion: ""
  $name: Effet d'arrière-plan translucide region
  $description: >-
    The region where the translucent background effect is applied.
  $options:
  - "": Entire window
  - explorerFrame: File Explorer frame only
- styleConstants: [""]
  $name: Constantes de style
  $description: >-
    Some themes support style constants for customization, such as colors. Refer
    to the theme page for available constants. For technical details, refer to
    the mod description.
- controlStyles:
  - - target: ""
      $name: Cible
    - styles: [""]
      $name: Styles
  $name: Styles des contrôles
- themeResourceVariables: [""]
  $name: Variables de ressources
  $description: >-
    Use "Key=Value" to override an existing resource with a new value.

    Use "Key@Dark=Value" or "Key@Light=Value" to define theme-aware resources
    that can be referenced with {ThemeResource Key} in styles.

    The ":=" syntax can be used to set a XAML value. For details, refer to the
    mod description.
- explorerFrameContainerHeight: 0
  $name: Hauteur du conteneur du cadre de l'Explorateur
  $description: >-
    The height of the explorer frame container which includes the tabs, the
    address bar, and the command bar, set to zero to use the default height.
- xamlDiagnosticsHandling: alert
  $name: Gestion du consommateur de diagnostics XAML
  $description: >-
    How to handle other programs (e.g. ExplorerBlurMica) that try to use XAML
    diagnostics. There can only be one consumer at a time. Block will prevent
    other programs from using it, which might break them. Allow will let them
    use it, which might break this mod.
  $options:
  - alert: Alerte (demander avant de bloquer)
  - block: Bloquer les autres consommateurs
  - allow: Autoriser les autres consommateurs
*/

// ==/WindhawkModSettings==

#include <windhawk_utils.h>

// Avoid a WinBase.h macro collision with the C++/WinRT headers.
#undef GetCurrentTime

#include <windowsx.h>
#include <dwmapi.h>
#include <vssym32.h>
#include <uxtheme.h>
#include <cmath>
#include <string>
#include <array>
#include <d2d1.h>
#include <wrl.h>
#include <ShellScalingApi.h>
#include <atomic>
#include <optional>
#include <vector>
#include <winrt/Microsoft.UI.Xaml.h>
#include <Unknwn.h>
#include <weakreference.h>
#include <winrt/base.h>
#include <ocidl.h>
#include <combaseapi.h>
#include <windhawk_utils.h>
#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <filesystem>
#include <limits>
#include <list>
#include <memory>
#include <mutex>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <initguid.h>
#include <commctrl.h>
#include <d2d1_1.h>
#include <dwmapi.h>
#include <roapi.h>
#include <shlwapi.h>
#include <uxtheme.h>
#include <vssym32.h>
#include <windows.graphics.effects.h>
#include <winstring.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Dispatching.h>
#include <winrt/Microsoft.UI.Text.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Effects.h>
#include <winrt/Windows.Networking.Connectivity.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.System.Power.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <xamlom.h>

#define RECTWIDTH(lprc)     ((lprc)->right - (lprc)->left)
#define RECTHEIGHT(lprc)    ((lprc)->bottom - (lprc)->top)

#ifdef _WIN64
#define THISCALL  __cdecl
#define _THISCALL L"__cdecl"
#else
#define THISCALL  __thiscall
#define _THISCALL L"__thiscall"
#endif

#ifdef _WIN64
#define STDCALL  __cdecl
#define _STDCALL L"__cdecl"
#else
#define STDCALL  __stdcall
#define _STDCALL L"__stdcall"
#endif

static constexpr UINT ENABLE = 1;
static constexpr UINT AUTO = 0; // DWMSBT_AUTO
//static constexpr UINT NONE = 1; // DWMSBT_NONE
static constexpr UINT MAINWINDOW = 2; // DWMSBT_MAINWINDOW
static constexpr UINT TRANSIENTWINDOW = 3; // DWMSBT_TRANSIENTWINDOW
static constexpr UINT TABBEDWINDOW = 4; // DWMSBT_TABBEDWINDOW

// Get DPI value from the primary monitor without dependance to DPI-aware API
// TODO: Get DPI per window monitor
UINT GetDpiFromMonitor()
{
    // Get monitor handle without the need of a window handle
    HMONITOR hPrimary = MonitorFromPoint({0, 0}, MONITOR_DEFAULTTOPRIMARY);
    UINT dpiX = USER_DEFAULT_SCREEN_DPI, dpiY = USER_DEFAULT_SCREEN_DPI;
    if (SUCCEEDED(GetDpiForMonitor(hPrimary, MDT_EFFECTIVE_DPI, &dpiX, &dpiY)))
        return dpiY;
    return USER_DEFAULT_SCREEN_DPI;
}
UINT g_Dpi = GetDpiFromMonitor();

typedef HRESULT(WINAPI* pDrawTextWithGlow)(HDC hdcMem, LPWSTR pszText, UINT cch, RECT* pRect, DWORD dwFlags, COLORREF crText,
                                          COLORREF crGlow, UINT nGlowRadius, UINT nGlowIntensity, BOOL fPreMultiply,
                                          DTT_CALLBACK_PROC pfnDrawTextCallback, LPARAM lParam);
static auto DrawTextWithGlow = (pDrawTextWithGlow)GetProcAddress(GetModuleHandle(L"uxtheme.dll"), MAKEINTRESOURCEA(126));

// Detects system dark/light theme mode
typedef BOOL(WINAPI* pShouldSystemUseDarkMode)();
static auto ShouldSystemUseDarkMode = (pShouldSystemUseDarkMode)GetProcAddress(GetModuleHandle(L"uxtheme.dll"), MAKEINTRESOURCEA(138));
BOOL g_IsSysThemeDarkMode = ShouldSystemUseDarkMode();

// Redirect per ruled program the system colors to hardcoded default ones 
// when custom system colors are applied in global settings.
BOOL g_DefaultSysColors = FALSE;
// Global system colors buffers like Windows does.
std::array<HBRUSH, COLOR_MENUBAR + 1> g_themeCachedCustomSysColorBrushes {nullptr};
std::array<HBRUSH, COLOR_MENUBAR + 1> g_themeCachedDefaultSysColorBrushes {nullptr};
SRWLOCK g_SysColorsLock = SRWLOCK_INIT;

// Helpers for resetting theming containers and attributes
std::wstring GetCurrentWindowsThemePath();
// Lock in order to safely reset theme cache and attributes on theme change
SRWLOCK g_ThemeChangeLock = SRWLOCK_INIT;
std::wstring g_LastThemePath = GetCurrentWindowsThemePath();

// Flag to prevent customizing text colors of Task Manager
BOOL g_InsideTaskMgrProc = FALSE;

BOOL g_InsideExplorerProc = FALSE;

using PUNICODE_STRING = PVOID;
constexpr auto MENUPOPUP_CLASS = L"#32768";
constexpr UINT THEMECLS_COMMONPROPS_PART = 0;

ATOM g_explorerStylerNoBackgroundEffectAtom = 0;

struct Settings{
    BOOL FillBg = FALSE;
    BOOL AccentColorize = FALSE;
    COLORREF AccentColor = 0xFFFFFFFF;
    BOOL TextAlphaBlend = FALSE;
    BOOL SetSystemColors = FALSE;
    COLORREF AccentBlurBehindClr = 0x00000000;
    BOOL FlyoutsEffects = FALSE;
    BOOL Unload = FALSE;

    enum BACKGROUNDTYPE
    {
        Default,
        AccentBlurBehind,
        AcrylicSystemBackdrop,
        Mica,
        MicaAlt,
    } BgType = Default;

} g_settings;

struct ACCENT_POLICY 
{
    INT AccentState;
    INT AccentFlags;
    INT GradientColor;
    INT AnimationId;
};

enum ACCENT_STATE
{
    ACCENT_STATE_DISABLED,
    ACCENT_STATE_ENABLE_GRADIENT,
    ACCENT_STATE_ENABLE_TRANSPARENTGRADIENT,
    ACCENT_STATE_ENABLE_BLURBEHIND,	// Removed in Windows 11 22H2+
    ACCENT_STATE_ENABLE_ACRYLICBLURBEHIND,
    ACCENT_STATE_ENABLE_HOSTBACKDROP,
    ACCENT_STATE_INVALID_STATE
};

enum ACCENT_FLAG
{
    ACCENT_FLAG_NONE,
    ACCENT_FLAG_ENABLE_MODERN_ACRYLIC_RECIPE = 1 << 1,	// Windows 11 22H2+
    ACCENT_FLAG_ENABLE_GRADIENT_COLOR = 1 << 1, // ACCENT_ENABLE_BLURBEHIND
    ACCENT_FLAG_ENABLE_FULLSCREEN = 1 << 2,
    ACCENT_FLAG_ENABLE_BORDER_LEFT = 1 << 5,
    ACCENT_FLAG_ENABLE_BORDER_TOP = 1 << 6,
    ACCENT_FLAG_ENABLE_BORDER_RIGHT = 1 << 7,
    ACCENT_FLAG_ENABLE_BORDER_BOTTOM = 1 << 8,
    ACCENT_FLAG_ENABLE_BLUR_RECT = 1 << 9,	// DwmpUpdateAccentBlurRect, it is conflicted with ACCENT_ENABLE_GRADIENT_COLOR when using ACCENT_ENABLE_BLURBEHIND
    ACCENT_FLAG_ENABLE_BORDER = ACCENT_FLAG_ENABLE_BORDER_LEFT | ACCENT_FLAG_ENABLE_BORDER_TOP 
    | ACCENT_FLAG_ENABLE_BORDER_RIGHT | ACCENT_FLAG_ENABLE_BORDER_BOTTOM
};

struct WINCOMPATTRDATA 
{
    DWORD Attrib;
    PVOID pvData;
    SIZE_T cbData;
};

enum WINDOWCOMPOSITIONATTRIB 
{
    WCA_UNDEFINED,
    WCA_NCRENDERING_ENABLED,
    WCA_NCRENDERING_POLICY,
    WCA_TRANSITIONS_FORCEDISABLED,
    WCA_ALLOW_NCPAINT,
    WCA_CAPTION_BUTTON_BOUNDS,
    WCA_NONCLIENT_RTL_LAYOUT,
    WCA_FORCE_ICONIC_REPRESENTATION,
    WCA_EXTENDED_FRAME_BOUNDS,
    WCA_HAS_ICONIC_BITMAP,
    WCA_THEME_ATTRIBUTES,
    WCA_NCRENDERING_EXILED,
    WCA_NCADORNMENTINFO,
    WCA_EXCLUDED_FROM_LIVEPREVIEW,
    WCA_VIDEO_OVERLAY_ACTIVE,
    WCA_FORCE_ACTIVEWINDOW_APPEARANCE,
    WCA_DISALLOW_PEEK,
    WCA_CLOAK,
    WCA_CLOAKED,
    WCA_ACCENT_POLICY,
    WCA_FREEZE_REPRESENTATION,
    WCA_EVER_UNCLOAKED,
    WCA_VISUAL_OWNER,
    WCA_HOLOGRAPHIC,
    WCA_EXCLUDED_FROM_DDA,
    WCA_PASSIVEUPDATEMODE,
    WCA_USEDARKMODECOLORS,
    WCA_CORNER_STYLE,
    WCA_PART_COLOR,
    WCA_DISABLE_MOVESIZE_FEEDBACK,
    WCA_LAST
};

typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);
auto SetWindowCompositionAttribute = (pSetWindowCompositionAttribute) GetProcAddress(GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute");

ID2D1Factory* g_d2dFactory = nullptr;

VOID InitDirect2D()
{
    if (!g_d2dFactory)
    {
        D2D1_FACTORY_OPTIONS options = {};
        D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, options, &g_d2dFactory);
    }
}

VS_FIXEDFILEINFO* GetModuleVersionInfo(HMODULE hModule, UINT *puPtrLen)
{
    void *pFixedFileInfo = nullptr;
    UINT uPtrLen = 0;

    HRSRC hResource =
        FindResourceW(hModule, MAKEINTRESOURCEW(VS_VERSION_INFO), RT_VERSION);
    if (hResource)
    {
        HGLOBAL hGlobal = LoadResource(hModule, hResource);
        if (hGlobal)
        {
            void *pData = LockResource(hGlobal);
            if (pData)
            {
                if (!VerQueryValueW(pData, L"\\", &pFixedFileInfo, &uPtrLen)
                || uPtrLen == 0)
                {
                    pFixedFileInfo = nullptr;
                    uPtrLen = 0;
                }
            }
        }
    }

    if (puPtrLen)
    {
        *puPtrLen = uPtrLen;
    }

    return (VS_FIXEDFILEINFO *)pFixedFileInfo;
}

/*
  * Loads comctl32.dll, version 6.0.
  * This uses an activation context that uses shell32.dll's manifest
  * to load 6.0, even in apps which don't have the proper manifest for
  * it.
  * From: https://github.com/ramensoftware/windhawk-mods/blob/main/mods/classic-list-group-fix.wh.cpp
*/
HMODULE LoadComCtlModule(void)
{
    HMODULE hShell32 = LoadLibraryW(L"shell32.dll");
    ACTCTXW actCtx = { sizeof(actCtx) };
    actCtx.dwFlags = ACTCTX_FLAG_RESOURCE_NAME_VALID | ACTCTX_FLAG_HMODULE_VALID;
    actCtx.lpResourceName = MAKEINTRESOURCEW(124);
    actCtx.hModule = hShell32;
    HANDLE hActCtx = CreateActCtxW(&actCtx);
    ULONG_PTR ulCookie;
    ActivateActCtx(hActCtx, &ulCookie);
    HMODULE hComCtl = LoadLibraryExW(L"comctl32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    /**
      * Certain processes will ignore the activation context and load
      * comctl32.dll 5.82 anyway. If that occurs, just reject it.
      */
    VS_FIXEDFILEINFO *pVerInfo = GetModuleVersionInfo(hComCtl, nullptr);
    if (!pVerInfo || HIWORD(pVerInfo->dwFileVersionMS) < 6)
    {
        FreeLibrary(hComCtl);
        hComCtl = NULL;
    }
    DeactivateActCtx(0, ulCookie);
    ReleaseActCtx(hActCtx);
    FreeLibrary(hShell32);
    return hComCtl;
}

using NtUserCreateWindowEx_t = HWND(WINAPI*)(DWORD, PUNICODE_STRING, LPCWSTR, PUNICODE_STRING, DWORD, LONG, LONG, LONG, LONG, HWND, HMENU, HINSTANCE, LPVOID, DWORD, DWORD, DWORD, VOID*);
NtUserCreateWindowEx_t NtUserCreateWindowEx_Original;

static decltype(&DwmExtendFrameIntoClientArea) DwmExtendFrameIntoClientArea_orig = nullptr;
static decltype(&DwmSetWindowAttribute) DwmSetWindowAttribute_orig = nullptr;

static decltype(&DrawTextW) DrawTextW_orig = nullptr;
static decltype(&ExtTextOutW) ExtTextOutW_orig = nullptr;
static decltype(&DrawThemeText) DrawThemeText_orig = nullptr;
static decltype(&DrawThemeTextEx) DrawThemeTextEx_orig = nullptr;

static decltype(&GetThemeColor) GetThemeColor_orig = nullptr;
static decltype(&DrawThemeBackground) DrawThemeBackground_orig = nullptr;
static decltype(&DrawThemeBackgroundEx) DrawThemeBackgroundEx_orig = nullptr;
static decltype(&GetThemeMargins) GetThemeMargins_orig = nullptr;
static decltype(&GetThemeTransitionDuration) GetThemeTransitionDuration_orig = nullptr;
static decltype (&GetThemeFont) GetThemeFont_orig = nullptr;
static decltype(&GetSysColor) GetSysColor_orig = GetSysColor; // Assign the pointer to the original function as we call HookedSysColor() even if the function isn't hooked.
static decltype(&GetSysColorBrush) GetSysColorBrush_orig = GetSysColorBrush;
static decltype(&FillRect) FillRect_orig = nullptr;
static decltype(&DrawThemeEdge) DrawThemeEdge_orig = nullptr;
static decltype(&DefWindowProcW) DefWindowProc_orig = nullptr;

VOID NewWindowShown(HWND);
VOID HandleEffects(HWND hWnd);

std::wstring GetWindowClass(HWND hWnd)
{
    if (!hWnd)
        return L"";
    WCHAR buffer[MAX_PATH];
    GetClassNameW(hWnd, buffer, MAX_PATH);
    return buffer;
}

BOOL IsWindowClass(HWND hWnd, LPCWSTR className)
{
    if (!hWnd)
        return FALSE;
    return GetWindowClass(hWnd) == className;
}


// Excel worksheet transparency support.
BOOL IsExcelProcess()
{
    WCHAR processPath[MAX_PATH] = {};

    if (!GetModuleFileNameW(nullptr, processPath, MAX_PATH))
        return FALSE;

    const WCHAR* fileName = wcsrchr(processPath, L'\\');
    fileName = fileName ? fileName + 1 : processPath;

    return _wcsicmp(fileName, L"EXCEL.EXE") == 0;
}

BOOL IsExcelWorksheetWindow(HWND hWnd)
{
    return IsExcelProcess() && IsWindowClass(hWnd, L"EXCEL7");
}

VOID ApplyExcelWorksheetTransparency(HWND hWnd)
{
    if (!IsExcelWorksheetWindow(hWnd))
        return;

    LONG_PTR exStyle = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);

    if (!(exStyle & WS_EX_LAYERED))
        SetWindowLongPtrW(hWnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED);

    SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    SetWindowPos(
        hWnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOACTIVATE | SWP_FRAMECHANGED
    );

    InvalidateRect(hWnd, nullptr, TRUE);
}

VOID RestoreExcelWorksheetTransparency(HWND hWnd)
{
    if (!IsExcelWorksheetWindow(hWnd))
        return;

    LONG_PTR exStyle = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);

    if (exStyle & WS_EX_LAYERED)
    {
        SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);
        SetWindowLongPtrW(hWnd, GWL_EXSTYLE, exStyle & ~WS_EX_LAYERED);
        SetWindowPos(
            hWnd, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
            SWP_NOACTIVATE | SWP_FRAMECHANGED
        );
    }
}

BOOL CALLBACK EnumExcelWorksheetProc(HWND hWnd, LPARAM)
{
    ApplyExcelWorksheetTransparency(hWnd);
    return TRUE;
}

VOID ApplyExcelWorksheetTransparencyToChildren(HWND hExcelWindow)
{
    if (!IsExcelProcess() || !hExcelWindow)
        return;

    EnumChildWindows(hExcelWindow, EnumExcelWorksheetProc, 0);
}

BOOL CALLBACK RestoreExcelWindowsProc(HWND hWnd, LPARAM)
{
    RestoreExcelWorksheetTransparency(hWnd);
    EnumChildWindows(hWnd, EnumExcelWorksheetProc, 0);
    return TRUE;
}

BOOL IsWindowCloaked(HWND hwnd) {
    BOOL isCloaked = FALSE;
    return SUCCEEDED(DwmGetWindowAttribute(hwnd, DWMWA_CLOAKED, &isCloaked,
                                           sizeof(isCloaked))) &&
           isCloaked;
}

BOOL isWindowFlyout(HWND hWnd)
{
    return IsWindowClass(hWnd, TOOLTIPS_CLASS) || IsWindowClass(hWnd, L"DropDown") || IsWindowClass(hWnd, L"ViewControlClass") 
           || IsWindowClass(hWnd, MENUPOPUP_CLASS) || IsWindowClass(hWnd, L"MicrosoftWindowsTooltip") ||IsWindowClass(hWnd, L"BaseBar"); // Support m417z Folder Hover Menu mod
}

BOOL IsWindowEligible(HWND hWnd) 
{       
    if (isWindowFlyout(hWnd) && g_settings.FlyoutsEffects)
        return TRUE;
    
    LONG_PTR styleEx = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);
    LONG_PTR style = GetWindowLongPtrW(hWnd, GWL_STYLE);
    
    HWND hParentWnd = GetAncestor(hWnd, GA_PARENT);
    if (hParentWnd && hParentWnd != GetDesktopWindow())
        return FALSE;
    
    BOOL hasTitleBar = (style & WS_CAPTION) == WS_CAPTION;
    BOOL hasCaptionButtons = (style & (WS_MINIMIZEBOX | WS_MAXIMIZEBOX)) != 0;
    BOOL hasSystemMenu = (style & WS_SYSMENU) != 0;
    BOOL hasThickFrame = (style & WS_THICKFRAME) == WS_THICKFRAME;
    BOOL isWindowCEF = (IsWindowClass(hWnd, L"Chrome_WidgetWin_1") || IsWindowClass(hWnd, L"Chrome_WidgetWin_0"));

    // https://devblogs.microsoft.com/oldnewthing/20200302-00/?p=103507
    // Allow containers of Windows Store apps (WinStore.exe, Settings.exe, etc.)
    // Allow also Chromium Embedded Framework (Brave.exe) created as cloaked.
    if (IsWindowCloaked(hWnd) && !IsWindowClass(hWnd, L"ApplicationFrameWindow") && !isWindowCEF)
        return FALSE;

    // Windows become disabled even when they are displayed (e.g. Recycle Bin) when a pop-up window opens in front.
    if (!IsWindowEnabled(hWnd) && !IsWindowVisible(hWnd))
        return FALSE;
    
    // Pass ineligible CEF windows like Discord/Vencord
    if (isWindowCEF && (hasCaptionButtons || hasTitleBar))
        return TRUE;
    // Fixes Snipping Tool recording
    if ((styleEx & WS_EX_NOACTIVATE) || (styleEx & WS_EX_TRANSPARENT))
        return FALSE;
    // Most top-level windows
    if ((style & WS_POPUPWINDOW) == WS_POPUPWINDOW || (style & WS_OVERLAPPEDWINDOW) == WS_OVERLAPPEDWINDOW 
       || (styleEx & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME) // || (styleEx & WS_EX_CONTROLPARENT) == WS_EX_CONTROLPARENT)
            return TRUE;
    // Overlapped windows like the Win32 progress window
    if (hasTitleBar && hasSystemMenu && (hasCaptionButtons || hasThickFrame))
        return TRUE;

    return FALSE;
}

std::wstring GetCurrentWindowsThemePath() 
{
    std::wstring themePath;
    HKEY hKey = nullptr;

    LSTATUS status = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
        0,
        KEY_READ,
        &hKey
    );

    if (status != ERROR_SUCCESS)
        return L"";

    // 2. Query the size of the string buffer first
    DWORD bufferSize = 0;
    status = RegQueryValueExW(
        hKey,
        L"CurrentTheme",
        nullptr,
        nullptr,
        nullptr, // Pass nullptr to just get the required size
        &bufferSize
    );

    // 3. Allocate the string buffer and fetch the actual data
    if (status == ERROR_SUCCESS && bufferSize > 0) 
    {
        // Resize our wstring to fit the data (bufferSize includes the null terminator)
        themePath.resize(bufferSize / sizeof(wchar_t) - 1);

        status = RegQueryValueExW(
            hKey,
            L"CurrentTheme",
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(&themePath[0]),
            &bufferSize
        );

        if (status != ERROR_SUCCESS)
            themePath.clear();
    }
    RegCloseKey(hKey);

    return themePath;
}

std::wstring GetProcStrFromPath(std::wstring path) {
    size_t pos = path.find_last_of(L"\\/");
    if (pos != std::wstring::npos && pos + 1 < path.length()) {
        path = path.substr(pos + 1);
    }

    if (!path.empty()) 
    {
        LCMapStringEx(
            LOCALE_NAME_USER_DEFAULT, 
            LCMAP_LOWERCASE,
            path.c_str(),
            path.length(),
            &path[0],
            path.length(),
            nullptr, nullptr, 0);
    }
    return path;
}

std::wstring GetCurrProcStr() {
    WCHAR modulePath[MAX_PATH];
    GetModuleFileNameW(NULL, modulePath, MAX_PATH);

    return GetProcStrFromPath(modulePath);
}

BOOL CheckExplorerProcess() {
    return GetCurrProcStr() == L"explorer.exe";
}

BOOL InTaskManagerProcess() {
    return GetCurrProcStr() == L"taskmgr.exe";
}

enum AccentColorShade
{
    SystemAccentColorLight3,
    SystemAccentColorLight2,
    SystemAccentColorLight1,
    SystemAccentColorBase,
    SystemAccentColorDark1,
    SystemAccentColorDark2,
    SystemAccentColorDark3,
    Unused,
    AccentColorCount
};

class AccentPalette
{
public:
    std::array<COLORREF, AccentColorCount> Colors{};
    BOOL LoadAccentPalette();
    AccentPalette()
    {
        if (!LoadAccentPalette())
            Colors.fill(GetSysColor(COLOR_HIGHLIGHT));
    }
};
AccentPalette g_AccentPalette;

BOOL AccentPalette::LoadAccentPalette()
{
    const LPCWSTR kAccentRegPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent";
    const LPCWSTR kAccentPaletteValue = L"AccentPalette";

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, kAccentRegPath, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return FALSE;

    BYTE data[32] = {};
    DWORD dataSize = sizeof(data);
    DWORD type = 0;

    if (RegQueryValueExW(hKey, kAccentPaletteValue, nullptr, &type, data, &dataSize) != ERROR_SUCCESS || type != REG_BINARY || dataSize < AccentColorCount * 4)
    {
        RegCloseKey(hKey);
        return FALSE;
    }

    RegCloseKey(hKey);

    for (INT i = 0; i < AccentColorCount; ++i)
    {
        DWORD color = *reinterpret_cast<DWORD*>(&data[i * 4]);
        Colors[i] = color;
    }
    return TRUE;
}

COLORREF GetAccentColor()
{
    // In some programs, e.g. snippingtool.exe, the default blue accent color is used instead of the Windows theme with DwmGetColorizationColor.
    // Use the immersive color API if available, fall back to DwmGetColorizationColor
    // https://github.com/ALTaleX531/TranslucentFlyouts/blob/017970cbac7b77758ab6217628912a8d551fcf7c/Common/ThemeHelper.hpp#L278
    static const auto s_GetImmersiveColorFromColorSetEx{reinterpret_cast<DWORD(WINAPI*)(DWORD dwImmersiveColorSet, DWORD dwImmersiveColorType, BOOL bIgnoreHighContrast, DWORD dwHighContrastCacheMode)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(95)))};
    static const auto s_GetImmersiveColorTypeFromName{reinterpret_cast<DWORD(WINAPI*)(LPCWSTR name)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(96)))};
    static const auto s_GetImmersiveUserColorSetPreference{reinterpret_cast<DWORD(WINAPI*)(BOOL bForceCheckRegistry, BOOL bSkipCheckOnFail)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(98)))};

    COLORREF AccentClr{ 0 };
    BOOL opaque = FALSE;
    
    if (s_GetImmersiveColorFromColorSetEx && s_GetImmersiveColorTypeFromName && s_GetImmersiveUserColorSetPreference) 
    {
        AccentClr = s_GetImmersiveColorFromColorSetEx(
            s_GetImmersiveUserColorSetPreference(FALSE, FALSE),
            s_GetImmersiveColorTypeFromName(L"ImmersiveStartHoverBackground"),
            TRUE,
            0
        );
        return RGB((AccentClr & 0xFF), (AccentClr >> 8) & 0xFF, (AccentClr >> 16) & 0xFF);
    }
    else if (SUCCEEDED(DwmGetColorizationColor(&AccentClr, &opaque)))
    {
        return RGB((AccentClr >> 16) & 0xFF, (AccentClr >> 8) & 0xFF,  AccentClr & 0xFF);
    }
    else
        return g_AccentPalette.Colors[SystemAccentColorBase];
}

D2D1_COLOR_F MyD2D1Color(BYTE A, BYTE R, BYTE G, BYTE B)
{
    return D2D1_COLOR_F{
        static_cast<FLOAT>(R) / 255.0f,
        static_cast<FLOAT>(G) / 255.0f,
        static_cast<FLOAT>(B) / 255.0f,
        static_cast<FLOAT>(A) / 255.0f
    };
}

D2D1_COLOR_F MyD2D1Color(BYTE R, BYTE G, BYTE B)
{
    return MyD2D1Color(255, R, G, B);
}

D2D1_COLOR_F IsAccentColorPossibleD2D(BYTE A, BYTE R, BYTE G, BYTE B, AccentColorShade AccentShade = SystemAccentColorBase)
{
    if (g_settings.AccentColorize)
    {       
        // Change light/dark accent shades to dark/light depending theme dark mode
        /* if (ShouldSystemUseDarkMode() && AccentShade > 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade);
        else if (!ShouldSystemUseDarkMode() && AccentShade < 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade); */
        R = GetRValue(g_AccentPalette.Colors[(INT)AccentShade]);
        G = GetGValue(g_AccentPalette.Colors[(INT)AccentShade]);
        B = GetBValue(g_AccentPalette.Colors[(INT)AccentShade]);
        return MyD2D1Color(A, R, G, B);
    }
    else
        return MyD2D1Color(A, R, G, B);
}

D2D1_COLOR_F IsAccentColorPossibleD2D(BYTE R, BYTE G, BYTE B, AccentColorShade AccentShade = SystemAccentColorBase)
{
    if (g_settings.AccentColorize)
    {   
        // Change light/dark accent shades to dark/light depending theme dark mode
        /* if (ShouldSystemUseDarkMode() && AccentShade > 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade);
        else if (!ShouldSystemUseDarkMode() && AccentShade < 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade); */
        R = GetRValue(g_AccentPalette.Colors[(INT)AccentShade]);
        G = GetGValue(g_AccentPalette.Colors[(INT)AccentShade]);
        B = GetBValue(g_AccentPalette.Colors[(INT)AccentShade]);
        return MyD2D1Color(255, R, G, B);
    }
    else
        return MyD2D1Color(R, G, B);
}

HRESULT WINAPI HookedDwmSetWindowAttribute(HWND hWnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute)
{    
    if(!IsWindowEligible(hWnd))
        return DwmSetWindowAttribute_orig(hWnd, dwAttribute, pvAttribute, cbAttribute);
    
    // Popup menus (#32768) pass here by default to paint 
    // handle by the internal uxtheme function CThemeMenuPopup::EnableRoundedCorners()
    if (IsWindowClass(hWnd, MENUPOPUP_CLASS) && g_settings.FlyoutsEffects && dwAttribute == DWMWA_WINDOW_CORNER_PREFERENCE) {
        UINT menuCornerRadius = DWMWCP_ROUND;
        return DwmSetWindowAttribute_orig(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &menuCornerRadius, sizeof(menuCornerRadius));
    }
    
    if ((dwAttribute == DWMWA_SYSTEMBACKDROP_TYPE || dwAttribute == DWMWA_USE_HOSTBACKDROPBRUSH) && g_settings.BgType != g_settings.Default)
    {
        if (g_settings.BgType == g_settings.AccentBlurBehind)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &AUTO, sizeof(UINT));
        if(g_settings.BgType == g_settings.AcrylicSystemBackdrop)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &TRANSIENTWINDOW, sizeof(UINT));
        else if(g_settings.BgType == g_settings.MicaAlt)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &TABBEDWINDOW, sizeof(UINT));
        else if(g_settings.BgType == g_settings.Mica)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &MAINWINDOW, sizeof(UINT));
    }
    
    return DwmSetWindowAttribute_orig(hWnd, dwAttribute, pvAttribute, cbAttribute);
}

HRESULT WINAPI HookedDwmExtendFrameIntoClientArea(HWND hWnd, const MARGINS* pMarInset)
{
    if(!IsWindowEligible(hWnd))
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, pMarInset);
    
    if(!IsWindowClass(hWnd, L"CASCADIA_HOSTING_WINDOW_CLASS")) {
        static const MARGINS margins = {-1, -1, -1, -1};
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, &margins);
    }
    else
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, pMarInset);
}

HWND WINAPI HookedNtUserCreateWindowEx(DWORD dwExStyle,
                                       PUNICODE_STRING UnsafeClassName,
                                       LPCWSTR         VersionedClass,
                                       PUNICODE_STRING UnsafeWindowName,
                                       DWORD           dwStyle,
                                       LONG            x,
                                       LONG            y,
                                       LONG            nWidth,
                                       LONG            nHeight,
                                       HWND            hWndParent,
                                       HMENU           hMenu,
                                       HINSTANCE       hInstance,
                                       LPVOID          lpParam,
                                       DWORD           dwShowMode,
                                       DWORD           dwUnknown1,
                                       DWORD           dwUnknown2,
                                       VOID*           qwUnknown3) 
{
    HWND hWnd = NtUserCreateWindowEx_Original(
        dwExStyle, UnsafeClassName, VersionedClass, UnsafeWindowName, dwStyle,
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam,
        dwShowMode, dwUnknown1, dwUnknown2, qwUnknown3);
    
    if(hWnd)
        NewWindowShown(hWnd);

    return hWnd;
}

std::wstring GetThemeClass(HTHEME hTheme) 
{
    typedef HRESULT(WINAPI* pGetThemeClass)(HTHEME, LPCTSTR, INT);
    static auto GetClassName = (pGetThemeClass)GetProcAddress(GetModuleHandleW(L"uxtheme"), MAKEINTRESOURCEA(74));

    std::wstring ret;
    if (GetClassName)
    {
        WCHAR buffer[255] = { 0 };
        HRESULT hr = GetClassName(hTheme, buffer, 255);
        return SUCCEEDED(hr) ? buffer : L"";
    }
    return ret;
}

// Alpha gamma correction LUT — built once at process startup.
// Applies sRGB inverse gamma ^(1/1.4) to coverage values, which:
// Brightens antialiased edge pixels
// Closely matches DrawTextWithGlow's CGamma table behavior
// Requires no RGB linearization — operates on alpha only
static std::array<BYTE, 256> g_textAlphaGammaLUT = {0};
VOID GenerateTextAlphaGammaLUT()
{
    for (INT i = 0; i < 256; ++i) 
    {
        FLOAT a = i * (1.0f / 255.0f);
        // a = 1.0 (white luma) -> gamma = 1.5
        // a = 0.0 (black luma) -> gamma = 1.2
        FLOAT gamma = 1.2f + (0.3f * a);
        // Apply the dynamic inverse gamma
        FLOAT g = powf(a, 1.0f / gamma);
        g_textAlphaGammaLUT[i] = (BYTE)(g * 255.0f + 0.5f);
    }
}

BOOL ExtTextOutBkPaint(HDC hdc, LPCRECT lprect, UINT options)
{
    if (!(options & ETO_OPAQUE)) 
        return TRUE;
        
    // Make opaque highlighted text background rectangle
    if (GetBkColor(hdc) == GetSysColor(COLOR_HIGHLIGHT)) 
    {
        BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
        HDC memDC = nullptr;
        HPAINTBUFFER hpb = BeginBufferedPaint(hdc, lprect, BPBF_TOPDOWNDIB, &params, &memDC); 
        if (!hpb) {
            Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
            return FALSE;
        }

        FillRect(memDC, lprect, GetSysColorBrush(COLOR_HIGHLIGHT));
        BufferedPaintMakeOpaque(hpb, lprect);

        if (FAILED(EndBufferedPaint(hpb, TRUE))) {
            Wh_Log(L"EndBufferedPaint failed error:0x%08x", GetLastError());
            return FALSE;
        }
    }
    else {
        HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
        FillRect(hdc, lprect, brush);
        DeleteObject(brush);
    }
    return TRUE;
}

BOOL ExtTextOutComposition(HDC hdc, HPAINTBUFFER hpb, LPCRECT pTextRect)
{
    RGBQUAD* pPixels = nullptr;
    INT rowWidth = 0; // stride
    if (FAILED(GetBufferedPaintBits(hpb, &pPixels, &rowWidth))) {
        EndBufferedPaint(hpb, FALSE);
        Wh_Log(L"Failed GetBufferedPaintBits error:0x%08x", GetLastError());
        return FALSE;
    }

    INT txtRcHeight = RECTHEIGHT(pTextRect);
    INT txtRcWidth = RECTWIDTH(pTextRect);
    
    BYTE pxBlue = GetBValue(GetTextColor(hdc));
    BYTE pxGreen = GetGValue(GetTextColor(hdc));
    BYTE pxRed = GetRValue(GetTextColor(hdc));
    
    // Alpha composition
    for (INT cy = 0; cy < txtRcHeight; ++cy) {
        RGBQUAD* row = pPixels + (cy * rowWidth);
        for (INT cx = 0; cx < txtRcWidth; ++cx) {
            RGBQUAD& px = row[cx];
            // Avoid background pixels
            if ((px.rgbBlue | px.rgbGreen | px.rgbRed) == 0)
                continue;
            
            // Greyscale alpha
            BYTE luma = (px.rgbBlue + (px.rgbGreen << 1) + px.rgbRed) >> 2;          
            // Gamma alpha correction
            BYTE txtA = g_textAlphaGammaLUT[luma];
            
            px.rgbBlue     = (pxBlue * txtA) >> 8;
            px.rgbGreen    = (pxGreen * txtA) >> 8;
            px.rgbRed      = (pxRed * txtA) >> 8;
            px.rgbReserved = txtA;
        }
    }
    
    return TRUE;
}

VOID ExtTextOutAlignRect(HDC hdc, POINT &point, SIZE textSize, UINT textAlignment)
{
    // TA_BASELINE's bits are a superset of TA_BOTTOM's, and TA_CENTER's are
    // a superset of TA_RIGHT's - mask the field and compare for equality
    // rather than testing individual bits, or TA_CENTER/TA_BASELINE get
    // misread as TA_RIGHT/TA_BOTTOM.
    UINT vAlign = textAlignment & (TA_BOTTOM | TA_BASELINE);
    UINT hAlign = textAlignment & (TA_RIGHT | TA_CENTER);
    if (vAlign == TA_BASELINE)
    {
        TEXTMETRIC tm;
        if (GetTextMetrics(hdc, &tm))
            point.y = point.y - tm.tmAscent;        
    }
    else if (vAlign == TA_BOTTOM)
        point.y = point.y - textSize.cy;

    if (hAlign == TA_CENTER)
        point.x = point.x - textSize.cx / 2;
    else if (hAlign == TA_RIGHT)
        point.x = point.x - textSize.cx;

    return;
}

VOID ExtTextOutDxWidth(UINT options, const INT* lpDx, UINT c, SIZE& textSize)
{    
    INT dx = 0;
    INT dy = 0;
    UINT stride = (options & ETO_PDY) ? 2 : 1;
    
    for (UINT i = 0; i < c; i++)
    {
        dx += lpDx[i * stride];
        if (options & ETO_PDY)
            dy += lpDx[i * stride + 1];
    }
    
    textSize.cx = std::max<LONG>(textSize.cx, dx);
    if (options & ETO_PDY)
        textSize.cy += abs(dy); // Expand height to encompass the vertical shifting
}

// Calculate text boundaries
BOOL ExtTextOutCalcRect(HDC hdc, POINT point, UINT options, RECT& textRect,
                        LPCRECT lprect, LPCWSTR lpString, UINT c, const INT* lpDx)
{
    SIZE textSize = {0};
    UINT ta = GetTextAlign(hdc);

    BOOL res = (options & ETO_GLYPH_INDEX)
        ? GetTextExtentPointI(hdc, (WORD*)lpString, c, &textSize)
        : GetTextExtentPoint32W(hdc, lpString, c, &textSize);
    if (!res)
        return FALSE;

    if (lpDx)
        ExtTextOutDxWidth(options, lpDx, c, textSize);
    if (ta)
        ExtTextOutAlignRect(hdc, point, textSize, ta);

    SetRect(&textRect, point.x, point.y, point.x + textSize.cx, point.y + textSize.cy);

    if (lprect) {
        if (options & ETO_CLIPPED)                        // GDI clips the glyphs to it
            IntersectRect(&textRect, &textRect, lprect);
        if (options & ETO_OPAQUE)                         // ...and fills it
            UnionRect(&textRect, &textRect, lprect);
    }

    return !IsRectEmpty(&textRect);
}

BOOL ExtTextOutShouldSkip(HDC hdc, UINT options, LPCRECT lprect, LPCWSTR lpString, INT c)
{
    if (!hdc || !lpString || !c || !options || GetTextAlign(hdc) & TA_UPDATECP)
        return TRUE;
    
    if (options & (ETO_OPAQUE | ETO_CLIPPED) && (!lprect || IsRectEmpty(lprect)))
        return TRUE;
    
    return FALSE;
}

BOOL WINAPI HookedExtTextOutW(
    HDC hdc,
    INT x,
    INT y,
    UINT options,
    LPCRECT lprect,
    LPCWSTR lpString,
    UINT c,
    const INT* lpDx)
{   
    if (ExtTextOutShouldSkip(hdc, options, lprect, lpString, c))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    RECT textRect {0};
    if (!ExtTextOutCalcRect(hdc, {x, y}, options, textRect, lprect, lpString, c, lpDx))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    if (!ExtTextOutBkPaint(hdc, lprect, options))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
            
    // https://devblogs.microsoft.com/oldnewthing/20110520-00/?p=10613
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
    params.dwFlags = BPPF_ERASE | BPPF_NOCLIP;
    BLENDFUNCTION blend = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    params.pBlendFunction = &blend;

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hdc, &textRect, BPBF_TOPDOWNDIB, &params, &memDC);
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
    }

    SelectObject(memDC, GetCurrentObject(hdc, OBJ_FONT));
    SetTextAlign(memDC, GetTextAlign(hdc));
    SetLayout(memDC, GetLayout(hdc));
    SetBkMode(memDC, TRANSPARENT);
    SetTextColor(memDC, RGB(255, 255, 255)); // White text mask

    // Remove default background painting operation, as it done by our ExtTextOutBkPaint helper
    WINBOOL res = ExtTextOutW_orig(memDC, x, y, options & ~ETO_OPAQUE, lprect, lpString, c, lpDx);

    // Text greyscale alpha composition
    if (!ExtTextOutComposition(hdc, hpb, &textRect))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    // EndBufferedPaint executes AlphaBlend only on DIBs otherwise applies BitBlt.
    if (FAILED(EndBufferedPaint(hpb, TRUE))) {
        Wh_Log(L"EndBufferedPaint failed error:0x%08x", GetLastError());
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
    }
    return res;
}

// Bypass alpha blending operation done by DrawTextWithGlow (e.g context menus, win32 adressbar) as it is done by our ExtTextOutW hook.
HRESULT WINAPI HookedDrawTextWithGlow(HDC hdcMem, LPWSTR pszText, UINT cch, RECT* pRect, DWORD dwFlags, COLORREF crText,
                                      COLORREF crGlow, UINT nGlowRadius, UINT nGlowIntensity, BOOL fPreMultiply,
                                      DTT_CALLBACK_PROC pfnDrawTextCallback, LPARAM lParam)
{
    if (pRect->right == pRect->left || pRect->bottom == pRect->top) { 
        if ((dwFlags & DT_CALCRECT) == 0)
            return DrawTextWithGlow(hdcMem, pszText, cch, pRect, dwFlags, crText, crGlow, nGlowRadius, nGlowIntensity, fPreMultiply, pfnDrawTextCallback, lParam);
    }

    // Do not mess with text using glow effects (if such exist in Win11)
    if (nGlowRadius > 0)
        return DrawTextWithGlow(hdcMem, pszText, cch, pRect, dwFlags, crText, crGlow, nGlowRadius, nGlowIntensity, fPreMultiply, pfnDrawTextCallback, lParam);

    SetTextColor(hdcMem, crText);
    SetBkColor(hdcMem, RGB(0, 0, 0));
    
    HRESULT hr = S_OK;
    
    if (pfnDrawTextCallback)
        hr = pfnDrawTextCallback(hdcMem, pszText, cch, pRect, dwFlags, lParam);
    else
        hr = DrawTextW(hdcMem, pszText, cch, pRect, dwFlags & ~DT_MODIFYSTRING);

    return hr;
}

INT WINAPI HookedDrawTextW(HDC hdc, LPCWSTR lpchText, INT cchText, LPRECT lprc, UINT format)
{   
    // Windows 11 context menus use Fluent icons as glyphs
    // Handled internally in the shell32 routine s_DrawGlyph()
    auto ContextMenuGlyphs = [&hdc, &lpchText]() {
        const WCHAR fluentIconGlyph_ChevronRightMed = 0xE974;
        const WCHAR fluentIconGlyph_ChevronLeftMed = 0xE973;
        const WCHAR fluentIconGlyph_AcceptMedium = 0xF78C;
        const WCHAR fluentIconGlyph_RadioBullet = 0xE915;
        
        if (*lpchText == fluentIconGlyph_ChevronRightMed || *lpchText == fluentIconGlyph_ChevronLeftMed 
            || *lpchText == fluentIconGlyph_AcceptMedium || *lpchText == fluentIconGlyph_RadioBullet)
                g_IsSysThemeDarkMode ? SetTextColor(hdc, RGB(255, 255, 255)) : SetTextColor(hdc, RGB(0, 0, 0));
    };

    // Catch and modify context menu fluent icons coloring
    if (cchText == 1)
        ContextMenuGlyphs();

    // Modify and convert hardcoded Syslink black text color into white (e.g. inside "Sharing" win32 Properties tab)
    if (!g_IsSysThemeDarkMode || (GetTextColor(hdc) & 0x00FFFFFF) != RGB(0, 0, 0))
        return DrawTextW_orig(hdc, lpchText, cchText, lprc, format);
    
    HWND hWnd = WindowFromDC(hdc);
    if (GetWindowClass(hWnd) == L"SysLink")
        SetTextColor(hdc, RGB(255, 255, 255));

    return DrawTextW_orig(hdc, lpchText, cchText, lprc, format);
}

HRESULT WINAPI HookedDrawThemeTextEx(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCWSTR pszText,
    INT cchText, DWORD dwTextFlags, LPRECT pRect, const DTTOPTS* pOptions)
{
    std::wstring ThemeClassName = GetThemeClass(hTheme);
    if (pOptions == nullptr) {
        DTTOPTS Options = { sizeof(DTTOPTS) };
        GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
        Options.dwFlags |= DTT_TEXTCOLOR;
        return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, &Options);
    }

    if ((pOptions->dwFlags & DTT_CALCRECT))
        return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, pOptions);
    
    DTTOPTS Options = { sizeof(DTTOPTS) };
    Options = *pOptions;
    GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
    Options.dwFlags |= DTT_TEXTCOLOR;
    return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, &Options);

}

HRESULT WINAPI HookedDrawThemeText(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCTSTR pszText,
    INT cchText, DWORD dwTextFlags, DWORD dwTextFlags2, LPCRECT pRect) 
{
    DTTOPTS Options = { sizeof(DTTOPTS) };
    RECT Rect = *pRect;

    GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
    HRESULT ret = HookedDrawThemeTextEx(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, &Rect, &Options);

    return ret;
}

// https://github.com/ramensoftware/windhawk-mods/blob/15e5d9838349e4b927ed8ac5433e9894ff6cda28/mods/uxtheme-hook.wh.cpp#L90
typedef VOID(CALLBACK *Element_PaintBgT)(class Element*, HDC , class Value*, LPRECT, LPRECT, LPRECT, LPRECT);
Element_PaintBgT Element_PaintBg;
VOID CALLBACK Element_PaintBgHook(class Element* This, HDC hdc, class Value* value, LPRECT pRect, LPRECT pClipRect, LPRECT pExcludeRect, LPRECT pTargetRect)
{   
    Element_PaintBg(This, hdc, value, pRect, pClipRect, pExcludeRect, pTargetRect);

    //unsigned char byteValue = *(reinterpret_cast<unsigned char*>(value) + 8);
    if ((INT)(*(DWORD *)value << 26) >> 26 != 9 )
    {
        auto v44 = *((__int64 *)value + 1);
        auto v45 = (v44+20)& 7;
        // 6-> selection
        // 3-> hovered stuff
        // 4-> cpanel top bar and side bar (white image)
        // 1-> some new cp page style (cp_hub_frame)
        if (v45 == 4)
            FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        else
            return;
    }
    else
        return;
}

VOID CplDuiHook()
{
    WindhawkUtils::SYMBOL_HOOK dui70dll_hooks[] =
    {
        {
            {
                L"public: void __cdecl DirectUI::Element::PaintBackground(struct HDC__ *,class DirectUI::Value *,struct tagRECT const &,struct tagRECT const &,struct tagRECT const &,struct tagRECT const &)"
            },
            &Element_PaintBg,
            Element_PaintBgHook,
            FALSE
        },
    };

    HMODULE hDui = LoadLibraryEx(L"dui70.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    WindhawkUtils::HookSymbols(hDui, dui70dll_hooks, ARRAYSIZE(dui70dll_hooks));
}

constexpr INT SysColorElements[] = {
	COLOR_SCROLLBAR ,
    COLOR_BACKGROUND ,
    COLOR_ACTIVECAPTION ,
    COLOR_INACTIVECAPTION ,
    COLOR_MENU ,
    COLOR_WINDOW ,
    COLOR_WINDOWFRAME ,
    COLOR_MENUTEXT ,
    COLOR_WINDOWTEXT ,
    COLOR_CAPTIONTEXT ,
    COLOR_ACTIVEBORDER ,
    COLOR_INACTIVEBORDER ,
    COLOR_APPWORKSPACE ,
    COLOR_HIGHLIGHT ,
    COLOR_HIGHLIGHTTEXT ,
    COLOR_BTNFACE ,
    COLOR_BTNSHADOW ,
    COLOR_GRAYTEXT ,
    COLOR_BTNTEXT ,
    COLOR_INACTIVECAPTIONTEXT ,
    COLOR_BTNHIGHLIGHT ,
    COLOR_3DDKSHADOW ,
    COLOR_3DLIGHT ,
    COLOR_INFOTEXT ,
    COLOR_INFOBK ,
    COLOR_GRADIENTACTIVECAPTION ,
    COLOR_GRADIENTINACTIVECAPTION ,
    COLOR_MENUHILIGHT ,
    COLOR_MENUBAR,
    COLOR_HOTLIGHT
};

HTHEME SetThemeHandle(HWND hWnd, HTHEME& hTheme, LPCWSTR themeclass)
{
    return hTheme = OpenThemeData(hWnd, themeclass);
}

VOID RevertSysColors()
{
    HTHEME hThemeSysMetrics = nullptr;
    if (!SetThemeHandle(nullptr, hThemeSysMetrics, L"sysmetrics"))
        return;
    
    COLORREF aNewColors[ARRAYSIZE(SysColorElements)];

    for (UINT i = 0; i < ARRAYSIZE(SysColorElements); i++) 
        aNewColors[i] = GetThemeSysColor(hThemeSysMetrics, i); 
    SetSysColors(ARRAYSIZE(SysColorElements), SysColorElements, aNewColors); 

    CloseThemeData(hThemeSysMetrics);
    hThemeSysMetrics = nullptr;
}

static COLORREF GetDefaultSysColor(INT nIndex)
{
    if (nIndex == COLOR_SCROLLBAR)
        return RGB(200, 200, 200);
    else if (nIndex == COLOR_BACKGROUND || nIndex == COLOR_MENUTEXT || nIndex == COLOR_WINDOWTEXT || nIndex == COLOR_CAPTIONTEXT
            || nIndex == COLOR_BTNTEXT || nIndex == COLOR_INACTIVECAPTIONTEXT || nIndex == COLOR_INFOTEXT)
                return RGB(0, 0, 0);
    else if (nIndex == COLOR_ACTIVECAPTION)
        return RGB(153, 180, 209);
    else if (nIndex == COLOR_INACTIVECAPTION)
        return RGB (191, 205, 219);
    else if (nIndex == COLOR_MENU || nIndex == COLOR_BTNFACE || nIndex == COLOR_MENUBAR)  
        return RGB(240, 240, 240);
    else if (nIndex == COLOR_WINDOW || nIndex == COLOR_BTNHIGHLIGHT || nIndex == COLOR_INFOBK || nIndex == COLOR_HIGHLIGHTTEXT)
        return RGB(255, 255, 255);
    else if (nIndex == COLOR_WINDOWFRAME)
        return RGB(100, 100, 100);
    else if (nIndex == COLOR_ACTIVEBORDER)
        return RGB(180, 180, 180);
    else if (nIndex == COLOR_INACTIVEBORDER)
        return RGB(244, 247, 252);
    else if (nIndex == COLOR_APPWORKSPACE)
        return RGB(171, 171, 171);
    else if (nIndex == COLOR_HIGHLIGHT || nIndex == COLOR_MENUHILIGHT)
        return RGB(0, 120, 212);
    else if (nIndex == COLOR_BTNSHADOW)
        return RGB(160, 160, 160);
    else if (nIndex == COLOR_GRAYTEXT)
        return RGB(109, 109, 109);
    else if (nIndex == COLOR_3DDKSHADOW)
        return RGB(105, 105, 105);
    else if (nIndex == COLOR_3DLIGHT)
        return RGB(227, 227, 227);
    else if (nIndex == COLOR_HOTLIGHT)
        return RGB(0, 102, 204);
    else if (nIndex == COLOR_GRADIENTACTIVECAPTION)
        return RGB(185, 209, 234);
    else if (nIndex == COLOR_GRADIENTINACTIVECAPTION)
        return RGB(215, 228, 242);
    
    return GetSysColor_orig(nIndex);
}

static COLORREF GetCustomSysColor(INT nIndex)
{
    if (nIndex == COLOR_SCROLLBAR || nIndex == COLOR_BACKGROUND || nIndex == COLOR_MENU || nIndex == COLOR_WINDOW || nIndex == COLOR_INACTIVEBORDER || nIndex == COLOR_INFOBK ||
        nIndex == COLOR_MENUBAR)
        return RGB(0, 0, 0);
    else if (nIndex == COLOR_GRADIENTACTIVECAPTION || nIndex == COLOR_INACTIVECAPTION)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 0, 0);
    else if (nIndex == COLOR_ACTIVECAPTION || nIndex == COLOR_GRADIENTINACTIVECAPTION)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(32, 32, 32);
    else if (nIndex == COLOR_ACTIVEBORDER)
        return RGB(32, 32, 32);
    else if (nIndex == COLOR_BTNSHADOW)
        return RGB(32, 32, 32);
    else if (nIndex == COLOR_WINDOWFRAME)
        return RGB(96, 96, 96);
    else if (nIndex == COLOR_BTNHIGHLIGHT)
        return RGB(64, 64, 64);
    else if (nIndex == COLOR_WINDOWTEXT)
        return RGB(240, 240, 240);
    else if (nIndex == COLOR_MENUTEXT || nIndex == COLOR_CAPTIONTEXT ||
             nIndex == COLOR_BTNTEXT || nIndex == COLOR_INFOTEXT || nIndex == COLOR_HIGHLIGHTTEXT)
        return RGB(255, 255, 255);
    else if (nIndex == COLOR_APPWORKSPACE)
        return RGB(8, 8, 8);
    else if (nIndex == COLOR_HIGHLIGHT || nIndex == COLOR_MENUHILIGHT)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 120, 215);
    else if (nIndex == COLOR_BTNFACE)
        return RGB(0, 0, 0);
    else if (nIndex == COLOR_GRAYTEXT)
        return RGB(128, 128, 128);
    else if (nIndex == COLOR_INACTIVECAPTIONTEXT)
        return RGB(160, 160, 160);
    else if (nIndex == COLOR_3DDKSHADOW)
        return RGB(16, 16, 16);
    else if (nIndex == COLOR_3DLIGHT)
        return RGB(4, 4, 4);
    else if (nIndex == COLOR_HOTLIGHT)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 148, 251);

    return GetSysColor_orig(nIndex);
}

COLORREF WINAPI HookedGetSysColor(INT nIndex) 
{
    if (g_DefaultSysColors)
        return GetDefaultSysColor(nIndex);
    else
        return GetCustomSysColor(nIndex);
}

HBRUSH WINAPI HookedGetSysColorBrush(INT nIndex) 
{
    if (nIndex < 0 || nIndex > COLOR_MENUBAR)
        return GetSysColorBrush_orig(nIndex);
    
    auto& cacheArray = g_DefaultSysColors ? g_themeCachedDefaultSysColorBrushes : g_themeCachedCustomSysColorBrushes;
    
    HBRUSH cachedBrush = cacheArray[nIndex];
    
    if (cachedBrush && GetObjectType(cachedBrush) == OBJ_BRUSH)
        return cachedBrush; 

    AcquireSRWLockExclusive(&g_SysColorsLock);
    
    HBRUSH& refSysBrush = cacheArray[nIndex];
    
    if (refSysBrush && GetObjectType(refSysBrush) != OBJ_BRUSH)
        refSysBrush = NULL; 

    if (!refSysBrush) {
        COLORREF color = HookedGetSysColor(nIndex);
        refSysBrush = CreateSolidBrush(color);
    }

    HBRUSH hbr = refSysBrush;
    ReleaseSRWLockExclusive(&g_SysColorsLock);
    
    return hbr;
}

VOID ColorizeSysColors()
{   
    // Stop recalling SetSysColors if syscolor changes have been applied.
    // SetSysColors redraws all top level windows causing flickering.
    if (GetSysColor_orig(COLOR_WINDOW) == RGB(0, 0, 0))
    {
        if (g_settings.AccentColorize && GetSysColor_orig(COLOR_HIGHLIGHT) == g_settings.AccentColor)
            return;
        else if (!g_settings.AccentColorize)
            return ;
    }
    
    COLORREF aNewColors[ARRAYSIZE(SysColorElements)];
    for (UINT i = 0; i < ARRAYSIZE(SysColorElements); i++)
        aNewColors[i] = GetCustomSysColor(SysColorElements[i]);
        
    SetSysColors(ARRAYSIZE(SysColorElements), SysColorElements, aNewColors);
}

HRESULT WINAPI HookedGetColorTheme(HTHEME hTheme, INT iPartId, INT iStateId, INT iPropId, COLORREF *pColor) 
{
    HRESULT hr = GetThemeColor_orig(hTheme, iPartId, iStateId, iPropId, pColor);
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ItemsView" && iPropId == TMT_TEXTCOLOR && ((iPartId == 4 && iStateId == 1) || iPartId == 5))
    {
        *pColor = (!g_IsSysThemeDarkMode && *pColor == 0x006D6D6D) ? RGB(0, 0, 0) : *pColor;
        return S_OK;
    }
    if (ThemeClassName == L"ListView" && iPropId == TMT_TEXTCOLOR && iPartId == LVP_LISTITEM)
    {
        *pColor = (g_IsSysThemeDarkMode && (iStateId == THEMECLS_COMMONPROPS_PART || iStateId == LISS_SELECTED)) ? RGB(255, 255, 255) : *pColor;
        *pColor = (!g_IsSysThemeDarkMode && *pColor == 0x006D6D6D) ? RGB(0, 0, 0) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"ListView" && iPartId == LVP_GROUPHEADER)
    {
        *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane" && (iPartId == 5 || iPartId == 7 || iPartId == 6) && iPropId == TMT_FILLCOLOR) {
        *pColor = (iPartId == 6) ? RGB(192, 192, 192) : RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane" && iPropId == TMT_TEXTCOLOR) {
        *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (iPropId == TMT_TEXTCOLOR && ThemeClassName == L"ControlPanel" && iPartId == CPANEL_HELPLINK) {
        *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
        return S_OK;
    }  
    else if (ThemeClassName == L"ControlPanelStyle" && iPropId == TMT_TEXTCOLOR)
    {
        if ((iPartId == CPANEL_BODYTITLE || iPartId == CPANEL_GROUPTEXT || iPartId == CPANEL_MESSAGETEXT 
            || iPartId == CPANEL_BODYTEXT || iPartId == CPANEL_TITLE || iPartId == CPANEL_CONTENTPANELABEL) && iStateId == 0)
        {
            *pColor =  (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId == CPANEL_SECTIONTITLELINK && (iStateId == CPCL_NORMAL || iStateId == CPCL_HOT))
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPCL_NORMAL) ? RGB(240, 255, 240) : RGB(224, 255, 224)) : *pColor;
            return S_OK;                   
        }
        else if (iPartId == CPANEL_CONTENTLINK || iPartId == CPANEL_HELPLINK)
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPHL_NORMAL) ? RGB(96, 205, 255) : (iStateId == CPHL_HOT) ? RGB(153, 236, 255) : 
                      (iStateId == CPHL_PRESSED) ? RGB(0, 148, 251) : RGB(96, 96, 96)) : *pColor;
            return S_OK;
        }
        else if (iPartId == CPANEL_TASKLINK) 
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPTL_NORMAL) ? RGB(190, 190, 190): (iStateId == CPTL_HOT) ? RGB(255, 255, 255) : 
                      (iStateId == CPTL_PRESSED) ? RGB(160, 160, 160) : (iStateId == CPTL_DISABLED) ? RGB(96, 96, 96) : RGB(255, 255, 255)) : *pColor;
            return S_OK;
        }
    }     
    else if (ThemeClassName == L"ControlPanelStyle" && iPropId == TMT_FILLCOLORHINT && (iPartId == CPANEL_CONTENTPANELINE && iStateId == 0))
    {
        *pColor = RGB(64, 64, 64);
        return S_OK;
    }
    else if (ThemeClassName == L"CommandModule" && iPropId == TMT_TEXTCOLOR)
    {
        // TASKBUTTON
        if(iPartId == 3 && iStateId == 1)
        {
            *pColor = *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        // LYBRARYPANETOPVIEW
        else if (iPartId == 9)
        {
            *pColor = (iStateId == 1) ? RGB(96, 205, 255) : (iStateId == 2) ? RGB(153, 236, 255) : (iStateId == 3) ? RGB(0, 148, 251) : RGB(96, 96, 96);
            return S_OK;
        }  
    }
    else if (ThemeClassName == L"TaskDialogStyle" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == TDLG_MAININSTRUCTIONPANE) {
            *pColor = RGB(96, 205, 255);
            return S_OK;
        }
        else if (iPartId == TDLG_CONTENTPANE || iPartId == TDLG_VERIFICATIONTEXT) {
            *pColor =  (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Button" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == BP_PUSHBUTTON && iStateId != PBS_DISABLED)
        {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId != BP_PUSHBUTTON)
        {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(192, 192, 192) : *pColor;
            return S_OK;
        }   
    }
    else if (ThemeClassName == L"Static")
    {
        *pColor = (g_IsSysThemeDarkMode && *pColor < RGB(16, 16, 16)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"TreeView" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Tab" && iPropId == TMT_TEXTCOLOR)
    {
        if (iStateId == CSTB_HOT)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(224, 224, 224) : *pColor;
        else if (iStateId == CSTB_SELECTED)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        else
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(192, 192, 192) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Edit" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == 1) {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId == THEMECLS_COMMONPROPS_PART) {
            *pColor = (g_IsSysThemeDarkMode && (*pColor & 0xff000000) == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Header" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"SearchEditBox" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (*pColor == 0x006d6d6d) ? ((g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0)) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Combobox" && iPropId == TMT_TEXTCOLOR)
    {
        if (iStateId != CBXS_DISABLED)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    
    else if (ThemeClassName == L"Menu" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == MENU_BARITEM && (iStateId != MBI_DISABLED && iStateId != MBI_DISABLEDPUSHED)) {
            *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        else if ((iPartId == MENU_POPUPITEM || iPartId == 27) && (iStateId != 3 && iStateId != 4)) {
            *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Menu" && (iPropId == TMT_FILLCOLOR || iPropId == TMT_FILLCOLORHINT))
    {
        *pColor = (g_settings.FlyoutsEffects) ? RGB(0, 0, 0) : (g_settings.FillBg) ? RGB(32, 32, 32) : *pColor;
        return S_OK;
    }
    else if ((ThemeClassName == L"Toolbar") && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == THEMECLS_COMMONPROPS_PART && iStateId != TS_DISABLED) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        if (iStateId == TS_DISABLED) {
            *pColor = RGB(128,128,128);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Tooltip" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId== TTP_STANDARD || iPartId == TTP_BALLOON) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        else if (iPartId == TTP_BALLOONTITLE) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(96, 205, 255) : *pColor;
            return hr;        
        }        
    }
    else if (ThemeClassName == L"DragDrop" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (iStateId == 1) ? ((g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96, 205, 255)) : RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"ChartView")
    {
        if ((iPartId == 29 || iPartId == 31 || iPartId == 32 || iPartId == 33) && iStateId == 1) {
            if (iPropId == TMT_FILLCOLOR)
                *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
            // Instead of the 1st byte of the DWORD/COLORREF variable, the last byte is used as the alpha of the fill color
            else if (iPropId == TMT_ALPHALEVEL)
                *pColor = RGB(255, 0, 0);
            return S_OK;
        }
        if ((iPartId == 34) && iStateId == 1) {
            if (iPropId == TMT_FILLCOLOR)
                *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
            else if (iPropId == TMT_ALPHALEVEL)
                *pColor = RGB(96, 0, 0);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"MonthCal") {
        return hr;
    }
    else if (ThemeClassName == L"AeroWizardStyle" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"ScrollbarStyle" && iPropId == TMT_FILLCOLORHINT)
    {
        *pColor = RGB(96, 96, 96);
        return S_OK;
    }
    else if (ThemeClassName == L"TaskManager")
    {
        switch (iPartId)
        {
            case 2: case 41:
            case 42:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(21, 21, 21) : *pColor;
                break;
            case 3: case 20:
            case 26:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(0, 0, 0) : *pColor;
                break;
            case 4:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(8, 4, 0) : *pColor;
                break;
            case 5:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(20, 8, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(0, 0, 0);
                break;
            case 6:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(36, 12, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(12, 0, 0);
                break;
            case 7:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(56, 16, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(24, 0, 0);
                break;
            case 8:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(80, 20, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(40, 0, 0);
                break;
            case 9:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(108, 24, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(60, 0, 0);
                break;
            case 10:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(140, 24, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(84, 0, 0);
                break;
            case 11:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(176, 32, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(112, 0, 0);
                break;
            case 12:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(252, 104, 42);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(140, 0, 0);
                break;
            case 13:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(241, 112, 122) : *pColor;
                break;
            case 14: case 15:
            case 16: case 17:
            case 18: case 19:
            case 24: case 25:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(255, 255, 255) : *pColor;
                break;
            case 21: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(97, 113, 186) : *pColor; break;
            case 22: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(68, 79, 125) : *pColor; break;
            case 23: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(64, 64, 64) : *pColor; break;
            case 27: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 36, 44) : *pColor; break;
            case 28: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 40, 56) : *pColor; break;
            case 29: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 44, 68) : *pColor; break;
            case 30: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 48, 80) : *pColor; break;
            case 31: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 52, 92) : *pColor; break;
            case 32: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 52, 104) : *pColor; break;
            case 33: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 60, 116) : *pColor; break;
            case 34: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 64, 128) : *pColor; break;
            case 35: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 68, 140) : *pColor; break;
            case 36: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 72, 152) : *pColor; break;
            case 37: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 76, 164) : *pColor; break;
            case 38: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(17, 125, 187) : *pColor; break;
            case 39: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(34, 38, 55) : *pColor; break;
            case 40: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(35, 45, 71) : *pColor; break;
        }
        return S_OK;
    }
    else
    {
        if (iPropId == TMT_TEXTCOLOR)
        {
            *pColor = (g_IsSysThemeDarkMode && (*pColor & 0xff000000) == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        if (iPropId == TMT_FILLCOLOR)
        {
            *pColor = RGB(0,0,0);
            return S_OK;
        }
        else if (iPropId == TMT_FILLCOLORHINT)
        {
            *pColor = RGB(0,0,0);
            return S_OK;
        }
    }
    
    return hr;
}

HRESULT CreateBoundD2DRenderTarget(HDC hdc, LPCRECT pRect, ID2D1Factory* pFactory, ID2D1DCRenderTarget** ppRenderTarget)
{
    if (!pFactory || !ppRenderTarget)
        return FALSE;

    D2D1_RENDER_TARGET_PROPERTIES rtProps = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_SOFTWARE,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
        NULL,
        NULL,
        D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE,
        D2D1_FEATURE_LEVEL_DEFAULT
    );

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> renderTarget;
    HRESULT hr = pFactory->CreateDCRenderTarget(&rtProps, &renderTarget);
    if (FAILED(hr)) {
        Wh_Log(L"Failed to create DC target [ERROR]: 0x%08X\n", hr);
        return hr;
    }

    hr = renderTarget->BindDC(hdc, pRect);
    if (FAILED(hr)) {
        Wh_Log(L"Failed to Bind DC target [ERROR]: 0x%08X\n", hr);
        return hr;
    }
    *ppRenderTarget = renderTarget.Detach();
    return S_OK;
}

class CThemeCache
{
public:
    std::array<HDC, 4> pushbutton;
    std::array<HDC, 8> radiobutton;
    std::array<HDC, 20> checkbutton;
    std::array<HDC, 4> commandlinkbutton;
    std::array<HDC, 3> commandlinkglyph;
    std::array<HDC, 14> listview;
    std::array<HDC, 4> scrollbar;
    std::array<HDC, 4> tab;
    std::array<HDC, 8> combobox;
    std::array<HDC, 4> editbox;
    std::array<HDC, 5> treeview;
    std::array<HDC, 8> treeviewglyph;
    std::array<HDC, 6> itemsview;
    std::array<HDC, 10> progressbar;
    std::array<HDC, 2> indeterminatebar;
    std::array<HDC, 2> trackbar;
    std::array<HDC, 24> trackbarthumb;
    std::array<HDC, 2> header;
    std::array<HDC, 1> previewseparator;
    std::array<HDC, 4> modulebutton;
    std::array<HDC, 4> modulelocationbutton;
    std::array<HDC, 8> modulesplitbutton;
    std::array<HDC, 12> navigationbutton;
    std::array<HDC, 1> navigationdivider;
    std::array<HDC, 5> toolbarbutton;
    std::array<HDC, 4> addressband;
    std::array<HDC, 4> menuitem;
    std::array<HDC, 1> dragdrop;
    std::array<HDC, 8> spin;

    BOOL CachePushButton(INT, INT);
    BOOL CacheRadioButton(LPCRECT, INT, INT);
    BOOL CacheCheckButton(LPCRECT, INT, INT);
    BOOL CacheCommandlinkButton(INT, INT);
    BOOL CacheCommandlinkGlyph(INT, INT);
    BOOL CacheListItem(INT, INT, INT);
    BOOL CacheListGroupHeader(INT, INT, INT);
    BOOL CacheScrollbar(INT, INT, INT);
    BOOL CacheScrollArrow(INT, INT);
    BOOL CacheTab(INT, INT);
    BOOL CacheCombobox(INT, INT, INT);
    BOOL CacheEditBox(INT, INT, INT);
    BOOL CacheTreeViewButton(INT, INT, INT);
    BOOL CacheTreeViewGlyph(INT, INT, INT, BOOL);
    BOOL CacheItemsView(INT, INT, INT);
    BOOL CacheProgressBar(INT, INT, INT);
    BOOL CacheIndeterminateBar(INT, INT);
    BOOL CacheTrackBar(INT, INT);
    BOOL CacheTrackBarThumb(INT, INT, INT);
    BOOL CacheTrackBarPointedThumb(INT, INT, INT);
    BOOL CacheHeader(INT, INT);
    BOOL CachePreviewPaneSeparator();
    BOOL CacheModuleButton(INT, INT);
    BOOL CacheModuleLocationButton(INT, INT);
    BOOL CacheModuleSplitButton(INT, INT, INT);
    BOOL CacheNavigationButton(INT, INT, INT);
    BOOL CacheNavigationDivider();
    BOOL CacheToolbarButton(INT, INT);
    BOOL CacheAddressBand(INT, INT);
    BOOL CacheMenuItem(INT, INT, INT);
    BOOL CacheDragDrop();
    BOOL CacheSpinButton(INT, INT, INT);

    BOOL CreateDIB(HDC& elementHdc, INT Width, INT Height)
    {
        if (elementHdc)
            DeleteHDC(elementHdc);

        if (!(elementHdc = CreateCompatibleDC(NULL)))
            return FALSE;

        BITMAPINFO bmi;
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = Width;
        bmi.bmiHeader.biHeight = -Height;
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biCompression = BI_RGB;
        
        VOID* pvBits;
        HBITMAP hBitmap = CreateDIBSection(elementHdc, &bmi, DIB_RGB_COLORS, &pvBits, nullptr, 0);
        if (!hBitmap)
            return FALSE;
        
        SelectObject(elementHdc, hBitmap);
        return TRUE;
    }

    VOID ClearCache()
    {
        for (HDC& hDC : pushbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : radiobutton)
            DeleteHDC(hDC);
        for (HDC& hDC : checkbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : commandlinkbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : commandlinkglyph)
            DeleteHDC(hDC);
        for (HDC& hDC : listview)
            DeleteHDC(hDC);
        for (HDC& hDC : scrollbar)
            DeleteHDC(hDC);
        for (HDC& hDC : tab)
            DeleteHDC(hDC);
        for (HDC& hDC : combobox)
            DeleteHDC(hDC);
        for (HDC& hDC : editbox)
            DeleteHDC(hDC);
        for (HDC& hDC : treeview)
            DeleteHDC(hDC);
        for (HDC& hDC : treeviewglyph)
            DeleteHDC(hDC);
        for (HDC& hDC : itemsview)
            DeleteHDC(hDC);
        for (HDC& hDC : progressbar)
            DeleteHDC(hDC);
        for (HDC& hDC : indeterminatebar)
            DeleteHDC(hDC);
        for (HDC& hDC : trackbar)
            DeleteHDC(hDC);
        for (HDC& hDC : trackbarthumb)
            DeleteHDC(hDC);
        for (HDC& hDC : header)
            DeleteHDC(hDC);
        for (HDC& hDC : previewseparator)
            DeleteHDC(hDC);
        for (HDC& hDC : modulebutton)
            DeleteHDC(hDC);
        for (HDC& hDC : modulelocationbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : modulesplitbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : navigationbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : navigationdivider)
            DeleteHDC(hDC);
        for (HDC& hDC : toolbarbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : addressband)
            DeleteHDC(hDC);
        for (HDC& hDC : menuitem)
            DeleteHDC(hDC);
        for (HDC& hDC : dragdrop)
            DeleteHDC(hDC);
        for (HDC& hDC : spin)
            DeleteHDC(hDC);
    }

    VOID DeleteHDC(HDC& hDC)
{
    if (hDC) {
        HBITMAP hBmp = (HBITMAP)GetCurrentObject(hDC, OBJ_BITMAP);
        DeleteDC(std::exchange(hDC, nullptr));
        DeleteObject(hBmp);
    }
}

    ~CThemeCache()
    {
        ClearCache();
    }
};
CThemeCache g_themeCache;

VOID DrawNineGridStretch(HDC hdc, HDC& srcDC, LPCRECT dstRect, INT left = 0, INT top = 0, INT right = 0, INT bottom = 0)
{
    if (!hdc || !srcDC)
        return;
    
    HBITMAP hBmp = (HBITMAP)GetCurrentObject(srcDC, OBJ_BITMAP);
    BITMAP bmp = {};
    GetObject(hBmp, sizeof(bmp), &bmp);

    INT srcW = bmp.bmWidth;
    INT srcH = bmp.bmHeight;
    INT dstW = dstRect->right - dstRect->left;
    INT dstH = dstRect->bottom - dstRect->top;

    left   = std::min(left, dstW);
    right  = std::min(right, dstW - left);
    top    = std::min(top, dstH);
    bottom = std::min(bottom, dstH - top);

    INT centerW = dstW - left - right;
    INT centerH = dstH - top - bottom;

    INT srcCenterW = srcW - left - right;
    INT srcCenterH = srcH - top - bottom;

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

    // Full stretch
    if (left + right >= srcW || top + bottom >= srcH)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, dstW, dstH,
                srcDC, 0, 0, srcW, srcH, blend);
        return;
    }
    // Short-circuit if the entire region is fully covered by the top-left corner
    if (dstW <= left && dstH <= top)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, dstW, dstH,
                   srcDC, 0, 0, dstW, dstH, blend);
        return;
    }
    // Center
    if (centerW > 0 && centerH > 0 && srcCenterW > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->top + top, centerW, centerH,
                   srcDC, left, top, srcCenterW, srcCenterH, blend);
    }
    // Top-left
    if (left > 0 && top > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, left, top,
                   srcDC, 0, 0, left, top, blend);
    }
    // Top
    if (centerW > 0 && top > 0 && srcCenterW > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->top, centerW, top,
                   srcDC, left, 0, srcCenterW, top, blend);
    }
    // Top-right
    if (right > 0 && top > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->top, right, top,
                   srcDC, srcW - right, 0, right, top, blend);
    }
    // Left
    if (left > 0 && centerH > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top + top, left, centerH,
                   srcDC, 0, top, left, srcCenterH, blend);
    }
    // Right
    if (right > 0 && centerH > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->top + top, right, centerH,
                   srcDC, srcW - right, top, right, srcCenterH, blend);
    }
    // Bottom-left
    if (left > 0 && bottom > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->bottom - bottom, left, bottom,
                   srcDC, 0, srcH - bottom, left, bottom, blend);
    }
    // Bottom
    if (centerW > 0 && bottom > 0 && srcCenterW > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->bottom - bottom, centerW, bottom,
                   srcDC, left, srcH - bottom, srcCenterW, bottom, blend);
    }
    // Bottom-right
    if (right > 0 && bottom > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->bottom - bottom, right, bottom,
                   srcDC, srcW - right, srcH - bottom, right, bottom, blend);
    }
}

BOOL PaintScroll(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId == SBP_UPPERTRACKVERT || iPartId == SBP_LOWERTRACKVERT
    || iPartId == SBP_UPPERTRACKHORZ || iPartId == SBP_LOWERTRACKHORZ))
        return TRUE;
    if ((!g_d2dFactory ||(iPartId != SBP_THUMBBTNVERT && iPartId != SBP_THUMBBTNHORZ)))
        return FALSE;
    
    INT index = (iStateId == SCRBS_NORMAL) ? 0 : 1;
    if (iPartId == SBP_THUMBBTNHORZ) index += 2;

    if (!g_themeCache.scrollbar[index])
        if (!g_themeCache.CacheScrollbar(iPartId, iStateId, index))
            return FALSE;

    FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
    DrawNineGridStretch(hdc, g_themeCache.scrollbar[index], pRect, 8, 5, 8, 5);
    return TRUE;
}

BOOL CThemeCache::CacheScrollbar(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 17 * scale, height = 11 * scale;
    if (iPartId == SBP_THUMBBTNHORZ)
        width = 20 * scale, height = 17 * scale;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.scrollbar[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.scrollbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_RECT_F Rect;
    if (iPartId == SBP_THUMBBTNVERT && iStateId == SCRBS_NORMAL)
        Rect = D2D1::RectF(width*0.35, 0, width-width*0.35, height);
    else if (iPartId == SBP_THUMBBTNHORZ && iStateId == SCRBS_NORMAL)
        Rect = D2D1::RectF(0, height*0.35, width, height-height*0.35);
    else if (iPartId == SBP_THUMBBTNVERT)
        Rect = D2D1::RectF(width*0.25, 0, width-width*0.25, height);
    else if (iPartId == SBP_THUMBBTNHORZ)
        Rect = D2D1::RectF(0, height*0.25, width, height-height*0.25);
    
    D2D1_COLOR_F Color = (iStateId == SCRBS_NORMAL) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(160, 224, 224, 224);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(Color, &brush);
    D2D1_ROUNDED_RECT rr = {Rect, cornerRadius, cornerRadius};

    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rr, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintScrollBarArrows(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != SBP_ARROWBTN || !g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> dcRenderTarget = nullptr;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &dcRenderTarget)))
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect);
    FLOAT height = static_cast<FLOAT>RECTHEIGHT(pRect);

    FLOAT triangleBaseWidth = 7.0f * scale;
    FLOAT triangleHeight = 4.5f * scale;
    FLOAT centerX = width / 2.0f;
    FLOAT centerY = height / 2.0f;

    D2D1_COLOR_F arrowColor;
    if (iStateId == 2 || iStateId == 6 || iStateId == 10 || iStateId == 14) {
        triangleBaseWidth = 8.0f * scale;
        triangleHeight = 5.5f * scale;
        arrowColor = MyD2D1Color(192, 224, 224, 224);
    }
    else if (iStateId == 4 || iStateId == 8 || iStateId == 12 || iStateId == 16)
        arrowColor = MyD2D1Color(192, 64, 64, 64);
    else 
        arrowColor = MyD2D1Color(128, 160, 160, 160);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    dcRenderTarget->CreateSolidColorBrush(arrowColor, &brush);
    D2D1_POINT_2F points[6] = {};
    if ((iStateId > ABS_UPNORMAL && iStateId <= ABS_UPDISABLED) || iStateId == ABS_UPHOVER)
    {
        points[0] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY + triangleHeight / 2.0f);
        points[1] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY+2 + triangleHeight / 2.0f);
        points[2] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY+2 + triangleHeight / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY + triangleHeight / 2.0f);
        points[4] = D2D1::Point2F(centerX, centerY - triangleHeight / 2.0f);
        points[5] = D2D1::Point2F(centerX-1, centerY - triangleHeight / 2.0f);
    }
    else if ((iStateId > ABS_DOWNNORMAL && iStateId <= ABS_DOWNDISABLED) || iStateId == ABS_DOWNHOVER)
    {
        points[0] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY - triangleHeight / 2.0f);
        points[1] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY-2 - triangleHeight / 2.0f);
        points[2] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY-2 - triangleHeight / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY - triangleHeight / 2.0f);
        points[4] = D2D1::Point2F(centerX, centerY + triangleHeight / 2.0f);
        points[5] = D2D1::Point2F(centerX-1, centerY + triangleHeight / 2.0f);
    }
    else if ((iStateId > ABS_LEFTNORMAL && iStateId <= ABS_LEFTDISABLED) || iStateId == ABS_LEFTHOVER)
    {
        points[0] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY - 1 - triangleBaseWidth / 2.0f);
        points[1] = D2D1::Point2F(centerX+2 + triangleHeight / 2.0f, centerY - 1 - triangleBaseWidth / 2.0f);
        points[2] = D2D1::Point2F(centerX+2 + triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[4] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY);
        points[5] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY-1);
    }
    else if ((iStateId > ABS_RIGHTNORMAL && iStateId <= ABS_RIGHTDISABLED) || iStateId == ABS_RIGHTHOVER)
    {
        points[0] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY-1 - triangleBaseWidth / 2.0f);
        points[1] = D2D1::Point2F(centerX-2 - triangleHeight / 2.0f, centerY-1 - triangleBaseWidth / 2.0f);
        points[2] = D2D1::Point2F(centerX-2 - triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[3] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[4] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY);
        points[5] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY-1);
    }

    FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

    dcRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1PathGeometry> triangleGeo = nullptr;
    if (SUCCEEDED(g_d2dFactory->CreatePathGeometry(&triangleGeo)))
    {
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink = nullptr;
        if (SUCCEEDED(triangleGeo->Open(&sink)))
        {
            sink->BeginFigure(points[0], D2D1_FIGURE_BEGIN_FILLED);
            sink->AddLine(points[1]);
            sink->AddLine(points[2]);
            sink->AddLine(points[3]);
            sink->AddLine(points[4]);
            sink->AddLine(points[5]);
            sink->EndFigure(D2D1_FIGURE_END_CLOSED);
            sink->Close();

            dcRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
        }
    }
    auto hr = dcRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintPushButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, LPCRECT pClipRect)
{
    if (iPartId != BP_PUSHBUTTON || !g_d2dFactory)
        return FALSE;
    
    RECT clipRect{ *pRect };
    if (pClipRect)
        IntersectRect(&clipRect, &clipRect, pClipRect);

    INT index = (iStateId == PBS_HOT) ? 1 : (iStateId == PBS_PRESSED) ? 2
    : (iStateId == PBS_DISABLED) ? 3 : 0;

    if (!g_themeCache.pushbutton[index])
        if (!g_themeCache.CachePushButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.pushbutton[index], &clipRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CachePushButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 18, height = 18;
    FLOAT cornerRadius = 3.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.pushbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.pushbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT rr = {
        D2D1::RectF(0.5f, 0.5f, (FLOAT)width - 0.5f, (FLOAT)height - 0.5f),
        cornerRadius, cornerRadius
    };

    D2D1_COLOR_F fillColor =
        (iStateId == PBS_HOT)      ? MyD2D1Color(128, 96, 96, 96) :
        (iStateId == PBS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60)  :
        (iStateId == PBS_DISABLED) ? MyD2D1Color(64, 64, 64, 64)  :
                                     MyD2D1Color(96, 80, 80, 80);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 112, 112, 112), &borderBrush);
    
    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rr, fillBrush.Get());
    pRenderTarget->DrawRoundedRectangle(&rr, borderBrush.Get(), scale);
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintRadioButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_RADIOBUTTON || !g_d2dFactory)
        return FALSE;
    
    INT index = iStateId - 1;

    if (!g_themeCache.radiobutton[index])
        if (!g_themeCache.CacheRadioButton(pRect, iStateId, index))
            return FALSE;
    // Some theme parts are always fixed size so no stretching is needed
    DrawNineGridStretch(hdc, g_themeCache.radiobutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheRadioButton(LPCRECT pRect,  INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);
    if (!g_themeCache.CreateDIB(g_themeCache.radiobutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, (INT)width, (INT)height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.radiobutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    FLOAT diameter = width - 1.f;
    FLOAT x = 0.5f, y = 0.5f;

    D2D1_ELLIPSE outerEllipse = D2D1::Ellipse(
        D2D1::Point2F(x + diameter / 2.f, y + diameter / 2.f),
        diameter / 2.f, diameter / 2.f
    );

    D2D1_COLOR_F borderColor, radioColor;
    D2D1_COLOR_F innerColor = MyD2D1Color(0, 0, 0);
    FLOAT innerRatio = 0.0f;

    switch (iStateId)
    {
        case CBS_UNCHECKEDNORMAL:
            borderColor = MyD2D1Color(96, 128, 128, 128);
            radioColor = MyD2D1Color(64, 64, 64, 64);
            break;
        case RBS_UNCHECKEDHOT:
            borderColor = MyD2D1Color(144, 144, 144);
            radioColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case RBS_UNCHECKEDPRESSED:
            radioColor = MyD2D1Color(64, 64, 64);
            innerRatio = 0.3f;
            break;
        case RBS_UNCHECKEDDISABLED:
            borderColor = MyD2D1Color(64, 128, 128, 128);
            break;
        case RBS_CHECKEDNORMAL:
            borderColor = radioColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            innerRatio = 0.4f;
            break;
        case RBS_CHECKEDHOT:
            borderColor = radioColor = IsAccentColorPossibleD2D(225, 105, 205, 255, SystemAccentColorLight3);
            innerRatio = 0.6f;
            break;
        case RBS_CHECKEDPRESSED:
            borderColor = radioColor = IsAccentColorPossibleD2D(192, 105, 205, 255, SystemAccentColorLight1);
            innerRatio = 0.33f;
            break;
        case RBS_CHECKEDDISABLED:
            borderColor = radioColor = MyD2D1Color(96, 96, 96);
            innerRatio = 0.3f;
            break;
    }

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(radioColor, &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->FillEllipse(outerEllipse, brush.Get());
    brush->SetColor(borderColor);
    pRenderTarget->DrawEllipse(outerEllipse, brush.Get(), scale);

    if (innerRatio > 0.f)
    {
        FLOAT innerDiameter = diameter * innerRatio;
        D2D1_ELLIPSE innerEllipse = D2D1::Ellipse(
            D2D1::Point2F(x + diameter / 2.f, y + diameter / 2.f),
            innerDiameter / 2.f, innerDiameter / 2.f
        );

        pRenderTarget->CreateSolidColorBrush(innerColor, &brush);
        pRenderTarget->FillEllipse(innerEllipse, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintCheckBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_CHECKBOX || !g_d2dFactory)
        return FALSE;
    
    INT index = iStateId - 1;

    if (!g_themeCache.checkbutton[index])
        if (!g_themeCache.CacheCheckButton(pRect, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.checkbutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheCheckButton(LPCRECT pRect, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);
    FLOAT cornerRadius = 3.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.checkbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, (INT)width, (INT)height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.checkbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(0, 0, width, height),
        cornerRadius, cornerRadius
    };

    D2D1_COLOR_F fillColor, borderColor;
    switch (iStateId) 
    {
        case CBS_UNCHECKEDNORMAL:
            borderColor = MyD2D1Color(96, 128, 128, 128);
            fillColor = MyD2D1Color(64, 96, 96, 96);
            break;
        case CBS_UNCHECKEDHOT:
            borderColor = MyD2D1Color(144, 144, 144);
            fillColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case CBS_UNCHECKEDPRESSED:
            borderColor = MyD2D1Color(96, 144, 144, 144);
            fillColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case CBS_UNCHECKEDDISABLED:
            borderColor = MyD2D1Color(64, 144, 144, 144);
            fillColor = MyD2D1Color(64, 128, 128, 128);
            break;
        case CBS_CHECKEDNORMAL: case CBS_MIXEDNORMAL:
        case CBS_IMPLICITNORMAL: case CBS_EXCLUDEDNORMAL:
            fillColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
            break;
        case CBS_CHECKEDHOT: case CBS_MIXEDHOT:
        case CBS_IMPLICITHOT: case CBS_EXCLUDEDHOT:
            fillColor = IsAccentColorPossibleD2D(224, 102, 206, 255, SystemAccentColorLight3);
            break;
        case CBS_CHECKEDPRESSED: case CBS_MIXEDPRESSED:
        case CBS_IMPLICITPRESSED: case CBS_EXCLUDEDPRESSED:
            fillColor = IsAccentColorPossibleD2D(192, 102, 206, 255, SystemAccentColorLight1);
            break;
        case CBS_CHECKEDDISABLED: case CBS_MIXEDDISABLED:
        case CBS_IMPLICITDISABLED: case CBS_EXCLUDEDDISABLED:
            fillColor = MyD2D1Color(96, 96, 96);
    }
    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(fillColor, &Brush);
    pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> glyphBrush = nullptr;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0), &glyphBrush);

    if (iStateId >= CBS_UNCHECKEDNORMAL && iStateId <= CBS_UNCHECKEDDISABLED)
    {
        Brush->SetColor(borderColor);
        pRenderTarget->DrawRoundedRectangle
        (D2D1_ROUNDED_RECT(D2D1::RectF(.5f, .5f, width - .5f, height - .5f), cornerRadius, cornerRadius), Brush.Get(), scale);
    }
    if (iStateId > CBS_UNCHECKEDDISABLED)
    {       
        if ((iStateId >= CBS_CHECKEDNORMAL && iStateId <= CBS_CHECKEDDISABLED) ||
            (iStateId >= CBS_IMPLICITNORMAL && iStateId <= CBS_IMPLICITDISABLED)) // Checkmark
        {
            FLOAT centerX = width/2.f - 2*scale;
            FLOAT centerY = height/2.f + 2.5*scale;
            FLOAT rightLen = width *.65f ;
            FLOAT leftLen  = width *.3f;

            DOUBLE dxyR = rightLen * 0.7071067;

            DOUBLE dxL = leftLen * 0.5;
            DOUBLE dyL = leftLen * 0.8660254;

            D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY);
            D2D1_POINT_2F ptLeft  = D2D1::Point2F(ptTip.x - dxL, ptTip.y - dyL);
            D2D1_POINT_2F ptRight = D2D1::Point2F(ptTip.x + dxyR, ptTip.y - dxyR);

            pRenderTarget->DrawLine(ptLeft, ptTip, glyphBrush.Get(), scale * 1.2f);
            pRenderTarget->DrawLine(ptTip, ptRight, glyphBrush.Get(), scale * 1.2f);
        }
        if (iStateId >= CBS_EXCLUDEDNORMAL && iStateId <= CBS_EXCLUDEDDISABLED) // X
        {
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/3.f)), (D2D1::Point2F(width *.7f, height/1.5f)), glyphBrush.Get());
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/1.5f)), (D2D1::Point2F(width *.7f, height/3.f)), glyphBrush.Get()); 
        }
        if (iStateId >= CBS_MIXEDNORMAL && iStateId <= CBS_MIXEDDISABLED) // Minus
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/2.f)), (D2D1::Point2F(width *.7f, height/2.f)), glyphBrush.Get());        
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintGroupBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, LPCRECT pClippedRect)
{
    if (!g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    const FLOAT radius = 4.0f;
    const FLOAT x = 0.5f;
    const FLOAT y = 0.5f;
    const FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect) - 0.5f;
    const FLOAT h = static_cast<FLOAT>RECTHEIGHT(pRect) - 0.5f;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);

    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1PathGeometry> geometry;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
    g_d2dFactory->CreatePathGeometry(&geometry);
    geometry->Open(&sink);
    
    if (!pClippedRect) // Top line if label does clip it
    {
        sink->BeginFigure(D2D1::Point2F(radius, y), D2D1_FIGURE_BEGIN_HOLLOW);
        sink->AddLine(D2D1::Point2F(width - radius, y));
    }
    else
        sink->BeginFigure(D2D1::Point2F(width - radius, y), D2D1_FIGURE_BEGIN_HOLLOW);

    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width, radius), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(width, h - radius));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width - radius, h), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(radius, h));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x, h - radius), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(x, radius));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(radius + 1.f, y), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->EndFigure(D2D1_FIGURE_END_OPEN);
    if (pClippedRect && (FLOAT)(pClippedRect->top) == (FLOAT)pRect->top) 
    {
        // Clipped rect sides
        const FLOAT cx = static_cast<FLOAT>(pClippedRect->left) + radius - .5f;
        const FLOAT cx2 = static_cast<FLOAT>(pClippedRect->right) - radius;
        // Top line right side of the label
        pRenderTarget->DrawLine(
            D2D1::Point2F(cx, .5f),
            D2D1::Point2F(cx2, .5f),
            brush.Get()
        );
    }
    sink->Close();
    pRenderTarget->DrawGeometry(geometry.Get(), brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}

    return TRUE;
}

BOOL PaintCommandLink(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_COMMANDLINK || !g_d2dFactory)
        return FALSE;
    
    INT index = (iStateId == CMDLS_NORMAL || iStateId == CMDLS_DISABLED) ? 0 : (iStateId == CMDLS_HOT) ? 1
    : (iStateId == CMDLS_PRESSED) ? 2 : 3;

    if (!g_themeCache.commandlinkbutton[index])
        if (!g_themeCache.CacheCommandlinkButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.commandlinkbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheCommandlinkButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 18, height = 18;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.commandlinkbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.commandlinkbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = { D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius};
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->BeginDraw();
    switch (iStateId)
    {
        case CMDLS_NORMAL:
        case CMDLS_DISABLED:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0, 0), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_HOT:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 144, 144, 144), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_PRESSED:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(64, 144, 144, 144), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_DEFAULTED:
        case CMDLS_DEFAULTED_ANIMATING:
            roundedRect = {D2D1::RectF(1.f * scale, 1.f * scale, width - 1.f * scale, height - 1.f * scale), cornerRadius - 1.f, cornerRadius - 1.f};
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawRoundedRectangle(&roundedRect, brush.Get(), 2.f * scale);
            break;
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintCommandLinkGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_COMMANDLINKGLYPH || !g_d2dFactory)
        return FALSE;
    
    INT index = (iStateId == CMDLGS_HOT) ? 1 : (iStateId == CMDLGS_PRESSED) ? 2
    : (iStateId == CMDLGS_DISABLED) ? 3 : 0;

    if (!g_themeCache.commandlinkglyph[index])
        if (!g_themeCache.CacheCommandlinkGlyph(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.commandlinkglyph[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheCommandlinkGlyph(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT x = 0;
    INT width = 20 * scale, height = 20 * scale;
    if (!g_themeCache.CreateDIB(g_themeCache.commandlinkglyph[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.commandlinkglyph[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    FLOAT tailScale = 1.f;
    D2D1_COLOR_F arrowColor = MyD2D1Color(192, 192, 192);
    if (iStateId == CMDLGS_HOT || iStateId == CMDLGS_PRESSED) {
        arrowColor = MyD2D1Color(255, 255, 255);
        if (iStateId == CMDLGS_PRESSED)
            tailScale = 0.8f;
    }
    else if (iStateId == CMDLGS_DISABLED)
        arrowColor = MyD2D1Color(160, 160, 160);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &brush);

    FLOAT centerY = height / 2.f;
    FLOAT tailLength = width * tailScale;
    FLOAT tailStartX = x;
    FLOAT tailEndX = tailStartX + tailLength;

    FLOAT headSpan = tailLength * 0.4f;
    FLOAT headOffset = headSpan * 0.7071f; // 45 degrees

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(
    D2D1::Point2F(x, centerY),
    D2D1::Point2F(tailLength, centerY),
    brush.Get(), 1.f
    );
    pRenderTarget->DrawLine(
        D2D1::Point2F(tailEndX - headOffset, centerY - headOffset),
        D2D1::Point2F(tailEndX, centerY),
        brush.Get(), 1.f
    );
    pRenderTarget->DrawLine(
        D2D1::Point2F(tailEndX - headOffset, centerY + headOffset),
        D2D1::Point2F(tailEndX, centerY),
        brush.Get()
    );  
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL SanitizeAddressCombobox(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId)
{
    HTHEME hThemeAddressCB = nullptr;
    if (SetThemeHandle(WindowFromDC(hdc), hThemeAddressCB, L"AddressComposited::ComboBox")
    && (iPartId == CP_BORDER || iPartId == CP_TRANSPARENTBACKGROUND))
    {
        CloseThemeData(hThemeAddressCB);
        return TRUE;
    }
    return FALSE;
}

BOOL PaintCombobox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != CP_READONLY && iPartId != CP_BORDER))
        return FALSE;
    
    INT index = (iPartId == CP_READONLY) ? iStateId - 1 : iStateId + 3;
    
    if (!g_themeCache.combobox[index])
        if (!g_themeCache.CacheCombobox(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.combobox[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheCombobox(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.combobox[stateIndex], width, height))
        return FALSE;
    
    // Direct2D render target
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.combobox[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT roundedRect = {D2D1::RectF(0.5, 0.5, width - .5f, height - .5f), cornerRadius, cornerRadius};

    pRenderTarget->BeginDraw();
    if (iPartId == CP_READONLY)
    {
        D2D1_COLOR_F fillColor = (iStateId == PBS_HOT)      ? MyD2D1Color(128, 96, 96, 96) : 
                                 (iStateId == PBS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60) :
                                 (iStateId == PBS_DISABLED) ? MyD2D1Color(64, 64, 64, 64) :
                                                              MyD2D1Color(96, 80, 80, 80);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &Brush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());

        Brush->SetColor(MyD2D1Color(96, 112, 112, 112));
        pRenderTarget->DrawRoundedRectangle(&roundedRect, Brush.Get(), scale);
    }
    else if (iPartId == CP_BORDER)
    {
        D2D1_COLOR_F borderColor = (iStateId == CBXS_HOT) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(96, 128, 128, 128);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), scale);

        if (iStateId == CBXS_PRESSED) 
        {
            borderBrush->SetColor(IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2));
            pRenderTarget->DrawLine(
                D2D1::Point2F(cornerRadius/2 - 1.f * scale, height - 1.5f),
                D2D1::Point2F(width - cornerRadius/2 + 1.f *scale, height - 1.5f),
                borderBrush.Get()
            );
            pRenderTarget->DrawLine(
                D2D1::Point2F(2.f * scale, height - .5f),
                D2D1::Point2F(width - 2.f * scale, height - .5f),
                borderBrush.Get()
            );
        }
        else if (iStateId == CBXS_DISABLED)
        {
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 80, 80, 80), &Brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL IsAddressInnerBackground(HTHEME hTheme, HDC hdc, INT iPartId)
{
    HTHEME hThemeAddress = NULL;
    if (SetThemeHandle(WindowFromDC(hdc), hThemeAddress, L"AddressComposited::Edit") && iPartId == EP_BACKGROUNDWITHBORDER)
    {
        CloseThemeData(hThemeAddress);
        return TRUE;
    }
    return FALSE;
}

BOOL PaintEditBox(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != EP_EDITBORDER_NOSCROLL && iPartId != EP_EDITBORDER_HSCROLL
    && iPartId != EP_EDITBORDER_VSCROLL && iPartId != EP_EDITBORDER_HVSCROLL && iPartId != EP_BACKGROUND
    && (!IsAddressInnerBackground(hTheme, hdc, iPartId))
    ))
        return FALSE;

    // Remove editbox white background flashing
    if (iPartId ==  EP_BACKGROUND) {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return TRUE;
    }
    INT index = (iPartId == EP_BACKGROUNDWITHBORDER) ? 3 : (iStateId == 1) ? 0 : iStateId - 2;

    if (!g_themeCache.editbox[index])
        if (!g_themeCache.CacheEditBox(iPartId, iStateId, index))
            return FALSE;
    // hide the borders of the inner black background of EP_BACKGROUNDWITHBORDER theme class by expanding the black drawing.
    RECT rc = (iPartId == EP_BACKGROUNDWITHBORDER) ? RECT{pRect->left-1, pRect->top-1, pRect->right+3,pRect->bottom+1} : *pRect;
    DrawNineGridStretch(hdc, g_themeCache.editbox[index], &rc, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheEditBox(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;
    if(!g_themeCache.CreateDIB(g_themeCache.editbox[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.editbox[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x + .5f, y + .5f, width - .5f, height - .5f), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();  
    if (iPartId == EP_BACKGROUNDWITHBORDER)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(0, 0, 0) : MyD2D1Color(255, 255, 255), &brush);
        D2D1_RECT_F rc (0, 0, (FLOAT)width, (FLOAT)height);
        pRenderTarget->FillRectangle(&rc, brush.Get());
    }
    if (iStateId == ETS_NORMAL || iStateId == ETS_HOT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        D2D1_COLOR_F borderColor = (iStateId == ETS_HOT) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(96, 112, 112, 112);
        pRenderTarget->CreateSolidColorBrush(borderColor, &brush);
        pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), scale);
    }
    else if (iStateId == ETS_SELECTED)
    {
        FLOAT X = .5f;
        FLOAT Width = static_cast<FLOAT>(width) - .5f, Height = static_cast<FLOAT>(height) - .5f;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 112, 112, 112), &brush);
        pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), scale);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> linebrush;
        pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2), &linebrush);
        pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2 - 1.f * scale, Height - 1.f), D2D1::Point2F(width - cornerRadius/2 + 1.f * scale, Height - 1.f), linebrush.Get());
        pRenderTarget->DrawLine(D2D1::Point2F(X + 2.f * scale, Height), D2D1::Point2F(Width - 2.f * scale , Height), linebrush.Get());
    }
    else if (iStateId == ETS_DISABLED)
    {
        D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush); 
        pRenderTarget->FillRoundedRectangle(rect, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintListBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_RECT_F rect((FLOAT)pRect->left, (FLOAT)pRect->top, (FLOAT)RECTWIDTH(pRect), (FLOAT)RECTHEIGHT(pRect));

    pRenderTarget->BeginDraw();

    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {   
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &Brush);
        pRenderTarget->FillRectangle(&rect, Brush.Get());
    }
    else
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush = nullptr;
        D2D1_COLOR_F borderColor;
        switch (iStateId)
        {
        case LBPSH_NORMAL:
            borderColor = MyD2D1Color(160, 160, 160);
            break;
        case LBPSH_HOT:
        case LBPSH_FOCUSED:
            borderColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            break;
        case LBPSH_DISABLED:
            borderColor = MyD2D1Color(96, 96, 96);
            break;
        default:
            borderColor = MyD2D1Color(160, 160, 160);
            break;
        }
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->FillRectangle(&rect, borderBrush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintDropDownArrow(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, BOOL addressPart)
{
    if (!g_d2dFactory || (iPartId != CP_DROPDOWNBUTTON && iPartId != CP_DROPDOWNBUTTONRIGHT
        && iPartId != CP_DROPDOWNBUTTONLEFT))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    D2D1_COLOR_F arrowColor;
    switch (iStateId)
    {
    case CBXSL_NORMAL:
        arrowColor = MyD2D1Color(192, 192, 192);
        break;
    case CBXS_HOT:
        arrowColor = MyD2D1Color(255, 255, 255);
        break;
    case CBXS_PRESSED:
        arrowColor = MyD2D1Color(160, 160, 160);
        break;
    case CBXS_DISABLED:
        arrowColor = MyD2D1Color(96, 96, 96);
        break;
    }

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect);
    FLOAT height = static_cast<FLOAT>RECTHEIGHT(pRect);
    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;

    FLOAT arrowLength = (addressPart) ? fminf(width, height) *  0.14f : fminf(width, height) *  0.25f;
    // 60 degree angle
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * 0.5f;

    D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY + dy);
    D2D1_POINT_2F ptLeft  = D2D1::Point2F(centerX - dx, centerY - dy);
    D2D1_POINT_2F ptRight = D2D1::Point2F(centerX + dx, centerY - dy);

    pRenderTarget->CreateSolidColorBrush(arrowColor, &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(ptLeft, ptTip, brush.Get(), scale*1.2f);
    pRenderTarget->DrawLine(ptRight, ptTip, brush.Get(), scale*1.2f);
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTab(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId == TABP_PANE || !g_d2dFactory)
        return FALSE;

    INT index = (iStateId == TIS_NORMAL) ? 0 
              : (iStateId == TIS_HOT) ? 1 : (iStateId == TIS_DISABLED) ? 2 : 3;

    if (!g_themeCache.tab[index])
        if (!g_themeCache.CacheTab(iStateId, index))
            return FALSE;

    DrawNineGridStretch(hdc, g_themeCache.tab[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheTab(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.tab[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.tab[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    pRenderTarget->BeginDraw();
    if (iStateId == TIS_NORMAL)
    {
        D2D1_RECT_F rect{0, 0, (FLOAT)width, (FLOAT)height};
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0, 0), &brush);
        pRenderTarget->FillRectangle(rect, brush.Get());
    }
    else if (iStateId == TIS_HOT || iStateId == TIS_DISABLED)
    {
        D2D1_COLOR_F fillColor = (iStateId == TIS_HOT) ? MyD2D1Color(128, 96, 96, 96) : MyD2D1Color(96, 96, 96);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        D2D1_ROUNDED_RECT tabRect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        pRenderTarget->FillRoundedRectangle(tabRect, brush.Get());
    }
    else if (iStateId == TIS_SELECTED || iStateId == TIS_FOCUSED)
    {
        const FLOAT desiredHeight = 2.0f + round(scale);       
        const FLOAT widthPadding  = 5.0f;
        const FLOAT verticalOffset = 1.0f;      
    
        FLOAT pillLeft   = widthPadding;
        FLOAT pillRight  = width - widthPadding;
        FLOAT pillBottom = height - verticalOffset;
        FLOAT pillTop    = pillBottom - desiredHeight;
        FLOAT pillRadius = 1.f + round(scale);

        D2D1_ROUNDED_RECT pillRect = D2D1::RoundedRect(D2D1::RectF(pillLeft, pillTop, pillRight, pillBottom),pillRadius, pillRadius);

        D2D1_COLOR_F pillColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(pillColor, &brush);
        pRenderTarget->FillRoundedRectangle(pillRect, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackbar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_TRACK && iPartId != TKP_TRACKVERT))
        return FALSE;
    
    INT index = (iPartId == TKP_TRACK) ? 0 : 1;

    if (!g_themeCache.trackbar[index])
        if (!g_themeCache.CacheTrackBar(iPartId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbar[index], pRect, 2, 2, 2, 2);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBar(INT iPartId, INT stateIndex)
{
    INT width = 6, height = 6;
    if(!g_themeCache.CreateDIB(g_themeCache.trackbar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    pRenderTarget->BeginDraw();
    D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), 2.f, 2.f);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
    pRenderTarget->FillRoundedRectangle(&body, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackbarThumb(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_THUMB && iPartId != TKP_THUMBVERT))
        return FALSE;
    
    if (iStateId == TUBS_FOCUSED) iStateId = 1;
    else if (iStateId == TUBS_DISABLED) iStateId = 4;
    INT index = (iPartId == TKP_THUMB) ? iStateId - 1 : iStateId + 3;

    if (!g_themeCache.trackbarthumb[index])
        if (!g_themeCache.CacheTrackBarThumb(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbarthumb[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBarThumb(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 10 * scale, height = 21 * scale;

    if (iPartId == TKP_THUMBVERT)
        width = std::exchange(height, width);
    
    if(!g_themeCache.CreateDIB(g_themeCache.trackbarthumb[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbarthumb[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor = (iStateId == TUBS_HOT) ? IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight3) : 
                             (iStateId == TUBS_PRESSED) ? IsAccentColorPossibleD2D(60, 110, 180, SystemAccentColorLight1) :
                             (iStateId == TUBS_DISABLED) ? MyD2D1Color(96, 96, 96) : MyD2D1Color(64, 64, 64);
    D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&body, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackBarPointedThumb(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_THUMBBOTTOM && iPartId != TKP_THUMBTOP 
        && iPartId != TKP_THUMBLEFT && iPartId != TKP_THUMBRIGHT))
        return FALSE;

    if (iStateId == TUBS_FOCUSED) iStateId = 1;
    else if (iStateId == TUBS_DISABLED) iStateId = 4;
    INT index = (iPartId == TKP_THUMBBOTTOM) ? iStateId + 7 : (iPartId == TKP_THUMBTOP) ? iStateId + 11 :
                (iPartId == TKP_THUMBLEFT) ? iStateId + 15 : iStateId + 19;

    if (!g_themeCache.trackbarthumb[index])
        if (!g_themeCache.CacheTrackBarPointedThumb(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbarthumb[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBarPointedThumb(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 11 * scale, height = 19 * scale;

    if (iPartId == TKP_THUMBLEFT || iPartId == TKP_THUMBRIGHT)
        width = std::exchange(height, width);
    
    if(!g_themeCache.CreateDIB(g_themeCache.trackbarthumb[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbarthumb[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor = (iStateId == TUBS_HOT) ? IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight3) : 
                             (iStateId == TUBS_PRESSED) ? IsAccentColorPossibleD2D(60, 110, 180, SystemAccentColorLight1) :
                             (iStateId == TUBS_DISABLED) ? MyD2D1Color(96, 96, 96) : MyD2D1Color(64, 64, 64);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);

    FLOAT cx = width * 0.5f;
    FLOAT cy = height * 0.5f;
    Microsoft::WRL::ComPtr<ID2D1PathGeometry> triangleGeo;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;

    pRenderTarget->BeginDraw();
    if (iPartId == TKP_THUMBBOTTOM)
    {
        FLOAT tipHeight = height * 0.3f;
        FLOAT bodyHeight = height - tipHeight;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, bodyHeight), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(cx - width * 0.5f, bodyHeight - 1.f);
        D2D1_POINT_2F p2 = D2D1::Point2F(cx + width * 0.5f, bodyHeight - 1.f);
        D2D1_POINT_2F p3 = D2D1::Point2F(cx, height);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();
        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBTOP)
    {
        FLOAT tipHeight = height * 0.3f;
        FLOAT bodyY = tipHeight;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, bodyY, width, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(cx - width * 0.5f, tipHeight + 1.f);
        D2D1_POINT_2F p2 = D2D1::Point2F(cx + width * 0.5f, tipHeight + 1.f);
        D2D1_POINT_2F p3 = D2D1::Point2F(cx, 0);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBLEFT)
    {
        FLOAT tipWidth = width * 0.3f;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(tipWidth, 0, width, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(tipWidth + 1.f, cy - height * 0.5f);
        D2D1_POINT_2F p2 = D2D1::Point2F(tipWidth + 1.f, cy + height * 0.5f);
        D2D1_POINT_2F p3 = D2D1::Point2F(0, cy);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBRIGHT)
    {
        FLOAT tipWidth = width * 0.3f;
        FLOAT bodyWidth = width - tipWidth;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, bodyWidth, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(bodyWidth - 1.f, cy - height * 0.5f);
        D2D1_POINT_2F p2 = D2D1::Point2F(bodyWidth - 1.f, cy + height * 0.5f);
        D2D1_POINT_2F p3 = D2D1::Point2F(width, cy);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintProgressBar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    if (iPartId == PP_PULSEOVERLAY || iPartId == PP_MOVEOVERLAY || iPartId == PP_PULSEOVERLAYVERT || iPartId == PP_MOVEOVERLAYVERT)
        return TRUE;

    INT index = (iPartId == PP_FILL) ? iStateId - 1 : (iPartId == PP_FILLVERT) ? iStateId + 3 
              : (iPartId == PP_CHUNK || iPartId == PP_CHUNKVERT) ? 8 : 9;
    
    if (!g_themeCache.progressbar[index])
        if (!g_themeCache.CacheProgressBar(iPartId, iStateId, index))
            return FALSE;
    if (iPartId == PP_FILL)
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 8, 10, 8, 10);
    else if (iPartId == PP_FILLVERT)
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 10, 8, 10, 8);
    else
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 8, 8, 9, 9);
    return TRUE;
}

BOOL CThemeCache::CacheProgressBar(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if (iPartId == PP_FILL) 
        width = 50, height = 23;
    else if (iPartId == PP_FILLVERT)
        width = 23, height = 50;

    if(!g_themeCache.CreateDIB(g_themeCache.progressbar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.progressbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_RECT_F rect = D2D1::RectF(0, 0, width, height);
    D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(rect, cornerRadius, cornerRadius);

    pRenderTarget->BeginDraw();
    if (iPartId == PP_BAR || iPartId == PP_BARVERT ||
        iPartId == PP_TRANSPARENTBAR || iPartId == PP_TRANSPARENTBARVERT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
        pRenderTarget->FillRoundedRectangle(rounded, brush.Get());
    }
    else if (iPartId == PP_CHUNK || iPartId == PP_CHUNKVERT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &brush);
        pRenderTarget->FillRoundedRectangle(rounded, brush.Get());
    }
    else if (iPartId == PP_FILL || iPartId == PP_FILLVERT)
    {
        BOOL isVertical = (iPartId == PP_FILLVERT);
        D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES props = {};
        props.startPoint = isVertical ? D2D1::Point2F(rect.right/2, rect.bottom)
                                      : D2D1::Point2F(rect.left, rect.bottom/2);
        props.endPoint   = isVertical ? D2D1::Point2F(rect.right/2, rect.top)
                                      : D2D1::Point2F(rect.right, rect.bottom/2);
        D2D1_GRADIENT_STOP stops[2];

        switch (iStateId)
        {
            case PBFS_NORMAL:
            {
                Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> solidBrush;
                pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &solidBrush);
                pRenderTarget->FillRoundedRectangle(rounded, solidBrush.Get());
                break;
            }
            case PBFS_ERROR:
            {
                stops[0].color = MyD2D1Color(228, 48, 96);
                stops[0].position = 0.0f;
                stops[1].color = MyD2D1Color(255, 96, 81);
                stops[1].position = 1.0f;
                break;
            }
            case PBFS_PAUSED:
            {
                stops[0].color = MyD2D1Color(228, 128, 48);
                stops[0].position = 0.0f;
                stops[1].color = MyD2D1Color(237, 206, 80);
                stops[1].position = 1.0f;
                break;
            }
            case PBFS_PARTIAL:
            {
                stops[0].color = IsAccentColorPossibleD2D(0, 120, 215, SystemAccentColorBase);
                stops[0].position = 0.0f;
                stops[1].color = IsAccentColorPossibleD2D(64, 160, 255, SystemAccentColorLight2);
                stops[1].position = 1.0f;
                break;
            }
        }
        if (iStateId != PBFS_NORMAL)
        {
            Microsoft::WRL::ComPtr<ID2D1GradientStopCollection> gradientStops;
            pRenderTarget->CreateGradientStopCollection(stops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &gradientStops);

            Microsoft::WRL::ComPtr<ID2D1LinearGradientBrush> gradientBrush;
            pRenderTarget->CreateLinearGradientBrush(props, gradientStops.Get(), &gradientBrush);

            pRenderTarget->FillRoundedRectangle(rounded, gradientBrush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintIndeterminateProgressBar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    if (iPartId != PP_MOVEOVERLAY && iPartId != PP_MOVEOVERLAYVERT)
        return TRUE;

    INT index = (iPartId == PP_MOVEOVERLAY) ? 0 : 1;
    
    // Make progress bar thin
    RECT overlayRect;
    if (iPartId == PP_MOVEOVERLAY)
    {
        INT overlayHeight = RECTHEIGHT(pRect) / 3;
        INT overlayY = (RECTHEIGHT(pRect) - overlayHeight) / 1.5f;
        overlayRect = RECT(pRect->left, overlayY, pRect->right, overlayY + overlayHeight);
    }
    else if (iPartId == PP_MOVEOVERLAYVERT)
    {
        FLOAT overlayWidth = RECTWIDTH(pRect) / 3.0f;
        FLOAT overlayX = (RECTWIDTH(pRect) - overlayWidth) / 1.5f;
        overlayRect = RECT(overlayX, pRect->top, overlayX + overlayWidth, pRect->bottom);
    }
    
    if (!g_themeCache.indeterminatebar[index])
        if (!g_themeCache.CacheIndeterminateBar(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.indeterminatebar[index], &overlayRect, 6, 6, 5, 5);
    return TRUE;
}

BOOL CThemeCache::CacheIndeterminateBar(INT iPartId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 12, height = 12;

    if (iPartId == PP_MOVEOVERLAYVERT)
        width = std::exchange(height, width);

    if(!g_themeCache.CreateDIB(g_themeCache.indeterminatebar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = {0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.indeterminatebar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintListView(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != LVP_LISTITEM 
        && iPartId != LVP_GROUPHEADER && iPartId != LVP_GROUPHEADERLINE && iPartId != LVP_COLUMNDETAIL))
        return FALSE;

    INT index;
    if (iPartId == THEMECLS_COMMONPROPS_PART || iPartId == LVP_LISTITEM) 
        index = (!iPartId) ? 0 : iStateId;
    else if (iPartId == LVP_GROUPHEADER)
    {
        if (iStateId == 2 || iStateId == 4 || iStateId == 6
        || iStateId == 8 || iStateId == 10) index = 7;
        else if (iStateId == 11 || iStateId == 15) index = 8;
        else if (iStateId == 12 || iStateId == 16) index = 9;
        else if (iStateId == 13) index = 10;
        else if (iStateId == 14) index = 11;
        else return FALSE; 
    }
    else if (iPartId == LVP_GROUPHEADERLINE) index = 12;
    else if (iPartId == LVP_COLUMNDETAIL) index = 13;
    else return FALSE;

    if (!g_themeCache.listview[index])
    {
        if (index <= 6)
        {
            if (!g_themeCache.CacheListItem(iPartId, iStateId, index))
                return FALSE;
        }
        else
            if (!g_themeCache.CacheListGroupHeader(iPartId, iStateId, index))
                return FALSE;
    }
    DrawNineGridStretch(hdc, g_themeCache.listview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheListItem(INT iPartId, INT iStateId, INT stateIndex)
{
    if (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != LVP_LISTITEM)
        return FALSE;
    
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.listview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.listview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {
        D2D1_RECT_F rect = D2D1::RectF(x, y, width, height);
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRectangle(&rect, brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else
    {
        D2D1_COLOR_F fillColor, borderColor;
        switch (iStateId)
        {
            case LISS_NORMAL:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
            case LISS_HOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                break;
            case LISS_SELECTED:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LISS_DISABLED:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
            case LISS_SELECTEDNOTFOCUS:
                fillColor = MyD2D1Color(32, 144, 144, 144);
                break;
            case LISS_HOTSELECTED:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
        }
        
        D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius, cornerRadius);
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());

        if (iStateId == LISS_HOTSELECTED || iStateId == LISS_NORMAL || iStateId == LISS_DISABLED)
        {
            x = y = 1.f;
            width = height -= 1.f;
            rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius - 1.f, cornerRadius - 1.f);
            brush->SetColor(borderColor);
            pRenderTarget->DrawRoundedRectangle(&rounded, brush.Get(), 2.f * scale);
        }
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    return TRUE;
}

BOOL CThemeCache::CacheListGroupHeader(INT iPartId, INT iStateId, INT stateIndex)
{
    if (iPartId != LVP_GROUPHEADER && iPartId != LVP_GROUPHEADERLINE && iPartId != LVP_COLUMNDETAIL)
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = (iPartId == LVP_COLUMNDETAIL) ? 2 : 18, height = (iPartId == LVP_COLUMNDETAIL) ? 1 : 18;

    if (!g_themeCache.CreateDIB(g_themeCache.listview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.listview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    if (iPartId == LVP_COLUMNDETAIL)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 160, 160, 160), &brush);

        pRenderTarget->BeginDraw();
        pRenderTarget->DrawLine(D2D1_POINT_2F(width, y), D2D1_POINT_2F(width, height), brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else if (iPartId == LVP_GROUPHEADER)
    {
        D2D1_COLOR_F fillColor = {};
        D2D1_COLOR_F borderColor = {};

        switch (iStateId)
        {
            case LVGH_OPENHOT: case LVGH_OPENSELECTEDHOT:
            case LVGH_OPENSELECTEDNOTFOCUSEDHOT: case LVGH_OPENMIXEDSELECTIONHOT:
            case LVGH_CLOSEHOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                break;
            case LVGH_CLOSESELECTED:
            case LVGH_CLOSEMIXEDSELECTION:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LVGHL_CLOSEMIXEDSELECTIONHOT:
            case LVGHL_CLOSESELECTEDHOT:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LVGHL_CLOSESELECTEDNOTFOCUSED:
                borderColor = MyD2D1Color(255, 255, 255);
                break;
            case LVGHL_CLOSESELECTEDNOTFOCUSEDHOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = MyD2D1Color(255, 255, 255);
                break;
            default:
                return FALSE;
        }
        D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius, cornerRadius);
        pRenderTarget->BeginDraw();
        if (iStateId != LVGHL_CLOSESELECTEDNOTFOCUSED)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());
        }

        if (iStateId == LVGHL_CLOSESELECTEDNOTFOCUSED || iStateId == LVGHL_CLOSESELECTEDNOTFOCUSEDHOT)
        {
            x = y = 1.f;
            width = height -= 1.f;
            rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius - 1.f, cornerRadius - 1.f);
            pRenderTarget->CreateSolidColorBrush(borderColor, &brush);
            pRenderTarget->DrawRoundedRectangle(&rounded, brush.Get(), 2.f * scale);
        }
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else
    {
        D2D1_RECT_F rect = D2D1::RectF(x, y, width, height);
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 160, 160, 160), &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRectangle(&rect, brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    return TRUE;
}

BOOL PaintTreeViewButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != TVP_TREEITEM))
        return FALSE;
    
    INT index = (iPartId == THEMECLS_COMMONPROPS_PART) ? 0 : (iStateId == TREIS_HOT) ? 1 : (iStateId == TREIS_SELECTED) ? 2 :
                (iStateId == TREIS_SELECTEDNOTFOCUS) ? 3 : 4;

    if (!g_themeCache.treeview[index])
        if (!g_themeCache.CacheTreeViewButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.treeview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheTreeViewButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 5.f * scale;
    FLOAT x = 0, y = 0;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.treeview[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.treeview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();
    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &borderBrush);
        pRenderTarget->FillRectangle(D2D1::RectF(x, y, width, height), borderBrush.Get());
    }
    else if (iPartId == TVP_TREEITEM)
    {
        D2D1_COLOR_F fillColor = (iStateId == TREIS_HOT)              ? MyD2D1Color(96, 144, 144, 144) : 
                                 (iStateId == TREIS_SELECTED)         ? MyD2D1Color(64, 144, 144, 144) :
                                 (iStateId == TREIS_SELECTEDNOTFOCUS) ? MyD2D1Color(32, 144, 144, 144) :
                                                                        //TREIS_HOTSELECTED
                                                                        MyD2D1Color(64, 144, 144, 144); 

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());

        if (iStateId == TREIS_SELECTED || iStateId == TREIS_SELECTEDNOTFOCUS || iStateId == TREIS_HOTSELECTED)
        {
            FLOAT pillOffsetY = 7, pillWidth = round(3.4f + scale), pillRadius = round(1.4f + scale);
            brush->SetColor(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2));
            pRenderTarget->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(x, y + pillOffsetY, x + pillWidth, height - pillOffsetY), pillRadius, pillRadius),brush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTreeViewGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TVP_GLYPH && iPartId != TVP_HOTGLYPH))
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect);

    // TreeView glyph symbols have a fixed bitmap size (marked as SIZINGTYPE=TRUESIZE)
    // The TreeView theme class has a bitmap size of 9x9px, while the Explorer::TreeView theme class has a bitmap size of 16x16px
    // Unfortunately, OpenThemeData only detects the parent TreeView theme class
    BOOL ExplorerTreeView = FALSE;
    if (width / (16 * scale) == 1)
        ExplorerTreeView = TRUE;

    INT index = (iPartId == TVP_GLYPH) ? index = iStateId - 1 : index = iStateId + 1;
    index = (ExplorerTreeView) ? index + 4 : index;

    if (!g_themeCache.treeviewglyph[index])
        if (!g_themeCache.CacheTreeViewGlyph(iPartId, iStateId, index, ExplorerTreeView))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.treeviewglyph[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTreeViewGlyph(INT iPartId, INT iStateId, INT stateIndex, BOOL ExplorerTreeView)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 9 * scale;
    INT height = 9 * scale;

    if (ExplorerTreeView)
        width = height = 16 * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.treeviewglyph[stateIndex], width, height))
        return FALSE;

    RECT rc {0, 0, width, height};
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.treeviewglyph[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F arrowColor;
    if (iPartId == TVP_HOTGLYPH) {
        if (iStateId == HGLPS_CLOSED) arrowColor =  MyD2D1Color(255, 255, 255);
        else if (iStateId == HGLPS_OPENED) arrowColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(192, 192, 192) : MyD2D1Color(128, 128, 128);
    }
    else if (iPartId == TVP_GLYPH) {
        if (iStateId == GLPS_CLOSED) arrowColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(148, 148, 148) : MyD2D1Color(64, 64, 64);
        else if (iStateId == GLPS_OPENED) arrowColor = MyD2D1Color(255, 255, 255);
    }

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;
    FLOAT arrowLength = (ExplorerTreeView) ? width * 0.3f : width * 0.55f;
    // 60 degrees
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * 0.5f;

    D2D1_POINT_2F ptTip, ptLeft, ptRight;

    if (iStateId == GLPS_OPENED)
    {
        ptTip   = {centerX, centerY + dy};
        ptLeft  = {centerX - dx, centerY - dy};
        ptRight = {centerX + dx, centerY - dy};
    }
    else if (iStateId == GLPS_CLOSED)
    {
        ptTip   = { centerX + dy, centerY };
        ptLeft  = { centerX - dy, centerY - dx };
        ptRight = { centerX - dy, centerY + dx };
    }

    pRenderTarget->BeginDraw();

    pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 1.5f * scale);
    pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 1.5f * scale);

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintItemsView(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 1 && iPartId != 3 && iPartId != 6
        && (iPartId != 4 && (iStateId == 11 || iStateId == 12))))
        return FALSE;

    INT index = (iPartId == 1 && (iStateId % 2 == 1)) ? 0 :
                (iPartId == 1 && (iStateId % 2 == 0)) ? 1 : (iPartId == 6) ? iStateId + 1 : iStateId + 3;
    
    // New DarkTheme file conflict dialog buttons
    if (iPartId == 4 && iStateId == 11)
        return PaintListView(hdc, 1, 6, pRect);
    else if (iPartId == 4 && iStateId == 12)
        return PaintListView(hdc, 1, 2, pRect);
    
    if (!g_themeCache.itemsview[index])
        if (!g_themeCache.CacheItemsView(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.itemsview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheItemsView(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.itemsview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.itemsview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    x = y += 1;
    width = height -= 1;

    pRenderTarget->BeginDraw();
    if (iPartId == 1)
    {
        if (iStateId == 1 || iStateId == 3)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
            pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(0, 96, 188, SystemAccentColorLight2), &brush);
            pRenderTarget->FillRoundedRectangle(rect, brush.Get());

            brush->SetColor(IsAccentColorPossibleD2D(0, 120, 215, SystemAccentColorLight2));
            pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), 2.0f * scale);
        }
        else if (iStateId == 2 || iStateId == 4)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
            pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(0, 96, 188, SystemAccentColorLight2), &fillBrush);
            pRenderTarget->FillRoundedRectangle(rect, fillBrush.Get());
        }
    }
    else if (iPartId == 3 || iPartId == 6)
    {
        if (iStateId == 1)
        {
            FLOAT radius = (iPartId == 6) ? 2.f * scale : 3.f * scale;
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), radius, radius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &borderBrush);
            pRenderTarget->DrawRoundedRectangle(rect, borderBrush.Get(), 2.0f * scale);
        }
        else if (iStateId == 2)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x-1, y-1, width+1, height+1), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 144, 144, 144), &fillBrush);
            pRenderTarget->FillRoundedRectangle(rect, fillBrush.Get());
        }
    }

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintHeader(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != HP_HEADERITEM)
        return FALSE;

    if (iStateId % 3 == 1) return TRUE;
    INT index = (iStateId % 3 == 2) ? 0 : 1;
    
    if (!g_themeCache.header[index])
        if (!g_themeCache.CacheHeader(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.header[index], pRect, 12, 0, 11, 12);
    return TRUE;
}

BOOL CThemeCache::CacheHeader(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 6.f * scale;
    INT x = 0, y = 0;
    INT width = 24, height = 24;

    if(!g_themeCache.CreateDIB(g_themeCache.header[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.header[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    switch (iStateId)
    {
        case HIS_HOT: case HIS_SORTEDHOT:
        case HIS_ICONHOT: case HIS_ICONSORTEDHOT:
            fillColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case HIS_PRESSED: case HIS_SORTEDPRESSED:
        case HIS_ICONPRESSED: case HIS_ICONSORTEDPRESSED:
            fillColor = MyD2D1Color(64, 144, 144, 144);
            break;
        case HIS_NORMAL: case HIS_SORTEDNORMAL:
        case HIS_ICONNORMAL: case HIS_ICONSORTEDNORMAL:
            return TRUE;
    }
    Microsoft::WRL::ComPtr<ID2D1PathGeometry> geometry;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
    pRenderTarget->BeginDraw();

    g_d2dFactory->CreatePathGeometry(&geometry);
    geometry->Open(&sink);
    sink->BeginFigure(D2D1::Point2F(x, y), D2D1_FIGURE_BEGIN_FILLED);
    sink->AddLine(D2D1::Point2F(width, y));
    sink->AddLine(D2D1::Point2F(width, height - cornerRadius));
    sink->AddArc(D2D1::ArcSegment(
        D2D1::Point2F(width - cornerRadius, height),
        D2D1::SizeF(cornerRadius, cornerRadius), 0.0f, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(cornerRadius, height));
    sink->AddArc(D2D1::ArcSegment(
        D2D1::Point2F(x, height - cornerRadius),
        D2D1::SizeF(cornerRadius, cornerRadius), 0.0f, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(x, y));
    sink->EndFigure(D2D1_FIGURE_END_CLOSED);
    sink->Close();
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    pRenderTarget->FillGeometry(geometry.Get(), brush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintPreviewPaneSeparator(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 3 && iPartId != 4))
        return FALSE;

    if (!g_themeCache.previewseparator[0])
        if (!g_themeCache.CachePreviewPaneSeparator())
            return FALSE;
    
    RECT rc{pRect->left+1, pRect->top, pRect->right, pRect->bottom};
    DrawNineGridStretch(hdc, g_themeCache.previewseparator[0], &rc, 1, 0, 0, 0);
    return TRUE;
}

BOOL CThemeCache::CachePreviewPaneSeparator()
{
    INT x = 0, y = 0;
    INT width = 3, height = 3;
    if(!g_themeCache.CreateDIB(g_themeCache.previewseparator[0], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.previewseparator[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(128, 0, 0, 0), &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(D2D1_POINT_2F(x, y), D2D1_POINT_2F(x, height), brush.Get());
    auto hr = pRenderTarget->EndDraw();

    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId != 3) || !g_d2dFactory)
        return FALSE;
    // Let windows theme paint its (transparent) buttons
    if (iStateId == 1 || iStateId == 6) return FALSE;
    INT index = iStateId - 2; 

    if (!g_themeCache.modulebutton[index])
        if (!g_themeCache.CacheModuleButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.modulebutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.modulebutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulebutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    D2D1_COLOR_F borderColor = MyD2D1Color(255, 255, 255);
    FLOAT Border2pxOffset = 0.f;
    switch (iStateId) 
    {
        case 2: fillColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case 3: fillColor = MyD2D1Color(64, 144, 144, 144);
            break;
        case 4: Border2pxOffset = 1.f * scale;
            break;
        case 5: 
            fillColor = MyD2D1Color(96, 144, 144, 144);
            Border2pxOffset = 1.f * scale;
            break;
    }

    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(Border2pxOffset, Border2pxOffset,
                    width -Border2pxOffset, height -Border2pxOffset) ,
        cornerRadius, cornerRadius
    };

    pRenderTarget->BeginDraw();
    if (iStateId != 4)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());
    }
    if (iStateId == 4 || iStateId == 5)
    {
        Border2pxOffset += 1.f;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), Border2pxOffset);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleLocation(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId != 9) || !g_d2dFactory)
        return FALSE;
    if (iStateId == 6) return FALSE;
    INT index = iStateId - 1; 

    if (!g_themeCache.modulelocationbutton[index])
        if (!g_themeCache.CacheModuleLocationButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.modulelocationbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleLocationButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;
    if(!g_themeCache.CreateDIB(g_themeCache.modulelocationbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulelocationbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor;
    D2D1_COLOR_F borderColor = MyD2D1Color(255, 255, 255);
    FLOAT Border2pxOffset = 0.f;
    switch (iStateId) 
    {
        case 1:
            fillColor = MyD2D1Color(96, 78, 78, 78);
            borderColor = MyD2D1Color(96, 112, 112, 112);
            break;
        case 2:
            fillColor = MyD2D1Color(96, 96, 96, 96);
            borderColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case 3:
            fillColor = MyD2D1Color(96, 88, 88, 88);
            borderColor = MyD2D1Color(96, 80, 80, 80);
            break;
        case 4:
            Border2pxOffset = 1.f * scale;
            borderColor = MyD2D1Color(255, 255, 255);
            break;
    }

    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(Border2pxOffset, Border2pxOffset,
                    width -Border2pxOffset, height -Border2pxOffset) ,
        cornerRadius, cornerRadius
    };

    pRenderTarget->BeginDraw();
    if (iStateId != 4)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());
    }

    Border2pxOffset += 1.f;
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
    pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
    pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), Border2pxOffset);

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleSplitButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 4 && iPartId != 5))
        return FALSE;
    if (iStateId == 1 || iStateId == 6) return FALSE;
    INT index = (iPartId == 4) ? iStateId - 2 : iStateId + 2; 

    if (!g_themeCache.modulesplitbutton[index])
        if (!g_themeCache.CacheModuleSplitButton(iPartId, iStateId, index))
            return FALSE;
    RECT newRc = (iPartId == 4 && iStateId == 4) ? RECT{pRect->left, pRect->top, pRect->right+2, pRect->bottom} : *pRect;
    DrawNineGridStretch(hdc, g_themeCache.modulesplitbutton[index], &newRc, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleSplitButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.modulesplitbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulesplitbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    if (iStateId == 2) fillColor = MyD2D1Color(96, 144, 144, 144);
    else if (iStateId == 3 || iStateId == 5) fillColor = MyD2D1Color(64, 144, 144, 144);
    if (iStateId == 4) {
        y = x += 1.f;
        width = height -= 1;
    }

    pRenderTarget->BeginDraw();
    if (iPartId == 4)
    {
        Microsoft::WRL::ComPtr<ID2D1PathGeometry> path;
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
        g_d2dFactory->CreatePathGeometry(&path);
        path->Open(&sink);

        sink->BeginFigure(D2D1::Point2F(width, y), D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(D2D1::Point2F(x + cornerRadius, y));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x, cornerRadius + y), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(x, height - cornerRadius));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x + cornerRadius, height), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(width, height));
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        if (iStateId == 2 || iStateId == 3 || iStateId == 5)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillGeometry(path.Get(), brush.Get());
        }
        else if (iStateId == 4)
        {
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawGeometry(path.Get(), brush.Get(), 2.f * scale);
        }
    }
    else if (iPartId == 5)
    {
        Microsoft::WRL::ComPtr<ID2D1PathGeometry> path;
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
        g_d2dFactory->CreatePathGeometry(&path);
        path->Open(&sink);

        sink->BeginFigure(D2D1::Point2F(x, y), D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(D2D1::Point2F(width - cornerRadius, y));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width, y + cornerRadius), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(width, height - cornerRadius));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width - cornerRadius, height), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(x, height));
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        if (iStateId == 2 || iStateId == 3 || iStateId == 5)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillGeometry(path.Get(), brush.Get());
        }
        else if (iStateId == 4)
        {
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawGeometry(path.Get(), brush.Get(), 2.f * scale);
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintNavigationButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    INT index = (iPartId == NAV_BACKBUTTON) ? iStateId - 1 : (iPartId == NAV_FORWARDBUTTON) ? iStateId + 3 : iStateId + 7;

    if (!g_themeCache.navigationbutton[index])
        if (!g_themeCache.CacheNavigationButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.navigationbutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheNavigationButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 30 * scale, height = 30 * scale;
    
    if (iPartId == NAV_MENUBUTTON)
        width = 13 * scale, height = 27 * scale;
    
    if(!g_themeCache.CreateDIB(g_themeCache.navigationbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.navigationbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor, arrowColor;
    switch (iStateId) 
    {
        case NAV_BB_NORMAL:
            arrowColor = g_IsSysThemeDarkMode ? MyD2D1Color(255, 255, 255) : MyD2D1Color(32, 32, 32);
            fillColor = MyD2D1Color(0, 0, 0, 0);
            break;
        case NAV_BB_HOT:
            fillColor = MyD2D1Color(32, 255, 255, 255);
            arrowColor = g_IsSysThemeDarkMode ? MyD2D1Color(200, 255, 255, 255) : MyD2D1Color(200, 32, 32, 32);
            break;
        case NAV_BB_PRESSED:
            fillColor = MyD2D1Color(16, 255, 255, 255);
            arrowColor = g_IsSysThemeDarkMode ?MyD2D1Color(200, 160, 160, 160) : MyD2D1Color(200, 96, 96, 96);
            break;
        case NAV_BB_DISABLED:
            arrowColor = MyD2D1Color(160, 64, 64, 64);
            fillColor = MyD2D1Color(0, 0, 0, 0);
            break;
    }

    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    if (iPartId == NAV_BACKBUTTON)
    {
        FLOAT centerY = height / 2.f;
        FLOAT tailLength = width / 2.5f;
        FLOAT tailStartX = width - (tailLength / 1.5f);
        FLOAT tailEndX = tailStartX - tailLength;

        FLOAT headSpand = tailLength * .5f;
        FLOAT headOffset = headSpand * 0.866f;

        pRenderTarget->DrawLine(
        D2D1::Point2F(tailStartX, centerY),
        D2D1::Point2F(tailEndX+1.5f, centerY),
        arrowBrush.Get(), 1.5f
        );
        
        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX + headOffset, centerY + headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );

        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX + headOffset, centerY - headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );  
    }
    else if (iPartId == NAV_FORWARDBUTTON)
    {
        FLOAT centerY = height / 2.f;
        FLOAT tailLength = width / 2.5f;
        FLOAT tailStartX = tailLength / 1.5f;
        FLOAT tailEndX = tailStartX + tailLength;

        FLOAT headSpand = tailLength * .5f;
        FLOAT headOffset = headSpand * 0.866f;

        pRenderTarget->DrawLine(
        D2D1::Point2F(tailStartX, centerY),
        D2D1::Point2F(tailEndX-1.5f, centerY),
        arrowBrush.Get(), 1.5f
        );
        
        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX - headOffset, centerY - headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );

        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX - headOffset, centerY + headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 2.f
        );  
    }
    else if (iPartId == NAV_MENUBUTTON)
    {
        FLOAT centerX = width / 2.f;
        FLOAT centerY = height / 2.f;

        FLOAT arrowLength = std::min(width, height) * 0.33f;
        // 60 degree angle
        FLOAT dx = arrowLength * 0.866f;
        FLOAT dy = arrowLength * 0.5f;

        D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY + dy);
        D2D1_POINT_2F ptLeft  = D2D1::Point2F(centerX - dx, centerY - dy);
        D2D1_POINT_2F ptRight = D2D1::Point2F(centerX + dx, centerY - dy);

        pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 2.f);
        pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 2.f);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintToolbarButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TP_BUTTON && iPartId != TP_DROPDOWNBUTTON && iPartId != TP_SPLITBUTTON))
        return FALSE;
    if (iStateId == TS_NORMAL || iStateId == TS_DISABLED || iStateId == TS_NEARHOT) return FALSE;

    INT index = (iStateId == TS_HOTCHECKED) ? 0 : (iStateId == TS_PRESSED) ? 1 : (iStateId == TS_CHECKED) ? 2 : 3;

    if (!g_themeCache.toolbarbutton[index])
        if (!g_themeCache.CacheToolbarButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.toolbarbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheToolbarButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.toolbarbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.toolbarbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor = (iStateId == TS_HOT || iStateId == TS_OTHERSIDEHOT) ? MyD2D1Color(96, 144, 144, 144) :
                             (iStateId == TS_PRESSED || iStateId == TS_CHECKED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(80, 144, 144, 144);

    pRenderTarget->BeginDraw();

    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());

    if (iStateId == TS_HOTCHECKED || iStateId == TS_CHECKED)
    {
        FLOAT pillOffset = width * 0.2f;
        D2D1_COLOR_F pillColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
        fillBrush->SetColor(pillColor);
        pRenderTarget->DrawLine(D2D1::Point2F(pillOffset, height-1), D2D1::Point2F(width - pillOffset, height-1), fillBrush.Get(), 2.0f);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintToolbarSplitDropDown(HDC hdc, INT iPartId,  INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != TP_SPLITBUTTONDROPDOWN)
        return FALSE;
    
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor = (iStateId == TS_HOT || iStateId == TS_HOTCHECKED || iStateId == TS_OTHERSIDEHOT) ? MyD2D1Color(96, 144, 144, 144) : 
                             (iStateId == TS_PRESSED || iStateId == TS_CHECKED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(0, 0, 0, 0);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    
    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(1.f, 0.f, (FLOAT)width, (FLOAT)height),cornerRadius, cornerRadius);
    FLOAT centerX = width/2.f + 1;
    FLOAT centerY = height/2.f;

    FLOAT arrowLen = width * .25f;
    FLOAT dx = arrowLen * 0.707f;

    pRenderTarget->BeginDraw();

    pRenderTarget->FillRoundedRectangle(&Rect, brush.Get());
    if (iStateId == TS_DISABLED) 
        brush->SetColor(MyD2D1Color(64, 64, 64));
    else
        brush->SetColor( g_IsSysThemeDarkMode ?  MyD2D1Color(255, 255, 255) : MyD2D1Color(0, 0, 0));

    if (iStateId == TS_PRESSED) {
        pRenderTarget->DrawLine(D2D1::Point2F(centerX , centerY + arrowLen/2.f), D2D1::Point2F(centerX - dx , centerY - arrowLen/2.f), brush.Get(), scale * 1.5f);
        pRenderTarget->DrawLine(D2D1::Point2F(centerX , centerY + arrowLen/2.f), D2D1::Point2F(centerX + dx, centerY - arrowLen/2.f), brush.Get(), scale * 1.5f);
    }
    else {
        pRenderTarget->DrawLine(D2D1::Point2F(centerX + arrowLen/2.f, centerY), D2D1::Point2F(centerX - arrowLen/2.f, centerY - dx), brush.Get(), scale * 1.5f);
        pRenderTarget->DrawLine(D2D1::Point2F(centerX + arrowLen/2.f, centerY), D2D1::Point2F(centerX - arrowLen/2.f, centerY + dx), brush.Get(), scale * 1.5f);
    }

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintAddressBand(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != 1)
        return FALSE;
    INT index = iStateId - 1;

    if (!g_themeCache.addressband[index])
        if (!g_themeCache.CacheAddressBand(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.addressband[index], pRect, 12, 12, 11, 11);
    return TRUE;
}

BOOL CThemeCache::CacheAddressBand(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 5.f * scale;
    INT width = 24, height = 24;

    if (!g_themeCache.CreateDIB(g_themeCache.addressband[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.addressband[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor, borderColor;
    switch (iStateId) 
    {
        case 1:
            fillColor = MyD2D1Color(48, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 2:
            fillColor = MyD2D1Color(96, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 3:
            fillColor = MyD2D1Color(24, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 4:
            fillColor = g_IsSysThemeDarkMode ? MyD2D1Color(0, 0, 0) : MyD2D1Color(255, 255, 255);
            borderColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            break;
    }
    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);

    pRenderTarget->BeginDraw();

    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    fillBrush->SetColor(borderColor);
    pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2, height-.5f), D2D1::Point2F(width-cornerRadius/2, height-.5f), fillBrush.Get());
    pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2 - 1.5f, height-1.5f), D2D1::Point2F(width - cornerRadius/2 + 1.5f, height-1.5f), fillBrush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintMenu(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    // Part:14 (Win10) - Part:27 (Win11)
    if (!g_d2dFactory || (iPartId != 27 && iPartId != MENU_POPUPITEM && iPartId != MENU_BARITEM && iPartId != MENU_POPUPSEPARATOR))
        return FALSE;
    if ((iPartId == 27 || iPartId == MENU_POPUPITEM) && iStateId != 2) return FALSE;
    if ((iPartId == MENU_BARITEM) && 
        (iStateId == MBI_NORMAL || iStateId == MBI_DISABLED || iStateId == MBI_DISABLEDPUSHED)) return FALSE;

    INT index = (iPartId == MENU_POPUPSEPARATOR) ? 0 : (iPartId == 27 || iPartId == MENU_POPUPITEM) ? 1 : (iPartId == MENU_BARITEM && iStateId == MBI_PUSHED) ?  3 : 2;

    if (!g_themeCache.menuitem[index])
        if (!g_themeCache.CacheMenuItem(iPartId, iStateId, index))
            return FALSE;
    if (iPartId != MENU_POPUPSEPARATOR)
        DrawNineGridStretch(hdc, g_themeCache.menuitem[index], pRect, 9, 9, 8, 8);
    else
        DrawNineGridStretch(hdc, g_themeCache.menuitem[index], pRect, 1, 5, 0, 0);
    return TRUE;
}

BOOL CThemeCache::CacheMenuItem(INT iPartId, INT iStateId, INT indexState)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if (iPartId == MENU_POPUPSEPARATOR) {
        width = 1;
        height = 5;
    }

    if (!g_themeCache.CreateDIB(g_themeCache.menuitem[indexState], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.menuitem[indexState], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    pRenderTarget->BeginDraw();
    
    if (iPartId == MENU_POPUPITEM || iPartId == 27)
    {
        D2D1_COLOR_F fillColor = IsAccentColorPossibleD2D(0, 160, 255, SystemAccentColorLight1);
        D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    }
    else if (iPartId == MENU_POPUPSEPARATOR) {
        D2D1_COLOR_F lineColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(96, 255, 255, 255) : MyD2D1Color(64, 0, 0, 0);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> lineBrush;
        pRenderTarget->CreateSolidColorBrush(lineColor, &lineBrush);

        pRenderTarget->DrawLine({0, (FLOAT)height/2}, {(FLOAT)width, (FLOAT)height/2}, lineBrush.Get());
    }
    else {
        D2D1_COLOR_F fillColor = (iStateId == MBI_PUSHED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(128, 96, 96, 96);
        D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintDragDrop(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != DD_IMAGEBG)
        return FALSE;

    if (!g_themeCache.dragdrop[0])
        if (!g_themeCache.CacheDragDrop())
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.dragdrop[0], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheDragDrop()
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 108, height = 108;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.dragdrop[0], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.dragdrop[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = { D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius};
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->BeginDraw();

    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 96, 96, 96), &brush);
    pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintSpinArrowGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    INT width = RECTWIDTH(pRect);
    INT height = RECTHEIGHT(pRect);

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F arrowColor =
        (iStateId == UPS_HOT)      ? MyD2D1Color(255, 255, 255) :
        (iStateId == UPS_PRESSED)  ? MyD2D1Color(128, 128, 128)  :
        (iStateId == UPS_DISABLED) ? MyD2D1Color(64, 64, 64)  :
                                     MyD2D1Color(192, 192, 192);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;
    FLOAT arrowLength = (iPartId == SPNP_UP || iPartId == SPNP_DOWN) ? std::min(width, height) * 0.5f
                        : std::min(width, height) * 0.3f;
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * .5f;

    D2D1_POINT_2F ptTip, ptLeft, ptRight;

    if (iPartId == SPNP_UP) {
        ptTip   = { centerX,      centerY - dy };
        ptLeft  = { centerX - dx, centerY + dy };
        ptRight = { centerX + dx, centerY + dy };
    }
    else if (iPartId == SPNP_DOWN) {
        ptTip   = {centerX, centerY + dy};
        ptLeft  = {centerX - dx, centerY - dy};
        ptRight = {centerX + dx, centerY - dy};
    }
    else if (iPartId == SPNP_DOWNHORZ)
    {
        ptTip   = { centerX - dy, centerY };
        ptLeft  = { centerX + dy, centerY - dx };
        ptRight = { centerX + dy, centerY + dx };
    }
    else if (iPartId == SPNP_UPHORZ)
    {
        ptTip   = { centerX + dy, centerY };
        ptLeft  = { centerX - dy, centerY - dx };
        ptRight = { centerX - dy, centerY + dx };
    }

    pRenderTarget->BeginDraw();

    pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 1.5f);
    pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 1.5f);
    
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintSpin(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    INT index = (iStateId == UPS_HOT) ? 1 : (iStateId == UPS_PRESSED) ? 2
            : (iStateId == UPS_DISABLED) ? 3 : 0;

    index = (iPartId == SPNP_DOWNHORZ || iPartId == SPNP_UPHORZ) ? index + 4 : index;
    
    // Clean previous paintings
    PatBlt(hdc, pRect->left, pRect->top, RECTWIDTH(pRect), RECTHEIGHT(pRect), BLACKNESS);

    if (!g_themeCache.spin[index])
        if (!g_themeCache.CacheSpinButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.spin[index], pRect, 6, 5, 6, 5);

    // Custom glyphs aren't cached due to no image stretching, draw them at runtime
    if (PaintSpinArrowGlyph(hdc, iPartId, iStateId, pRect))
        return TRUE;
    else {
        // Erase any previous custom drawing
        PatBlt(hdc, pRect->left, pRect->top, RECTWIDTH(pRect), RECTHEIGHT(pRect), BLACKNESS);
        return FALSE;
    }
}

BOOL CThemeCache::CacheSpinButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 12, height = 12;
    FLOAT cornerRadius = 2.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.spin[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.spin[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = {{0.f, 0.f, (FLOAT)width, (FLOAT)height}, cornerRadius, cornerRadius};
    D2D1_RECT_F Rect = {0.f, 0.f, (FLOAT)width, (FLOAT)height};

    D2D1_COLOR_F fillColor =
        (iStateId == UPS_HOT)      ? MyD2D1Color(128, 96, 96, 96) :
        (iStateId == UPS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60)  :
        (iStateId == UPS_DISABLED) ? MyD2D1Color(160, 0, 0, 0)  :
                                     MyD2D1Color(96, 80, 80, 80);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);

    pRenderTarget->BeginDraw();

    if (iPartId == SPNP_UP || iPartId == SPNP_DOWN)
        pRenderTarget->FillRectangle(&Rect, fillBrush.Get());
    else
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

HRESULT WINAPI HookedDrawThemeBackground(
    HTHEME hTheme,
    HDC hdc,
    INT iPartId,
    INT iStateId,
    LPCRECT pRect,
    LPCRECT pClipRect)
{       
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ScrollBar")
    {
        if (PaintScroll(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintScrollBarArrows(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Button")
    {
        if (PaintPushButton(hdc, iPartId, iStateId, pRect, pClipRect))
            return S_OK;
        else if (PaintRadioButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCheckBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLink(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLinkGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (iPartId == BP_GROUPBOX)
        {
            HTHEME hThemeGroupBox = nullptr;
            if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeGroupBox, L"Button"))
            {
                if (PaintGroupBox(hdc, iPartId, iStateId, pRect, pClipRect)) {
                    CloseThemeData(hThemeGroupBox);
                    return S_OK;
                }
            }
            
            if (hThemeGroupBox)
                CloseThemeData(hThemeGroupBox);
        }
    }
    else if (ThemeClassName == L"Tab")
    {
        if (PaintTab(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ComboBox")
    {
        // The Win32 address bar uses both the "Combobox" and "ComboBox" theme classes along with other classes
        // ComboBox is used when the address bar is selected, while combobox is used when the drop-down window is open
        if (SanitizeAddressCombobox(hTheme, hdc, iPartId, iStateId))
            return S_OK;
        else if (PaintDropDownArrow(hdc, iPartId, iStateId, pRect, TRUE))
            return S_OK;
    }
    else if (ThemeClassName == L"Combobox")
    {
        if (PaintCombobox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintDropDownArrow(hdc, iPartId, iStateId, pRect, FALSE))
            return S_OK;
    }
    else if (ThemeClassName == L"Listbox")
    {
        if (PaintListBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Edit")
    {
        if (PaintEditBox(hTheme, hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"TrackBar")
    {
        if (PaintTrackbar(hdc, iPartId, iStateId, pRect))
            return S_OK;
        if (PaintTrackbarThumb(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintTrackBarPointedThumb(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Progress")
    {
        // The exported GetThemeClass function does not provide
        // full string of theme class names of derived theme classes
        // Use the OpenThemeData API instead.
        HTHEME hThemeProgress = NULL;
        if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeProgress, L"Indeterminate::Progress"))
        {
            if (PaintIndeterminateProgressBar(hdc, iPartId, iStateId, pRect))
            {
                CloseThemeData(hThemeProgress);
                return S_OK;
            }
            CloseThemeData(hThemeProgress);
        }
        else if (PaintProgressBar(hdc, iPartId, iStateId, pRect)) 
        {
            CloseThemeData(hThemeProgress);
            return S_OK;
        }
        if (hThemeProgress)
            CloseThemeData(hThemeProgress);
    } 
    else if (ThemeClassName == L"ListView")
    {
        if (PaintListView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"TreeView")
    {
        if (PaintTreeViewButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        if (PaintTreeViewGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Header")
    {
        if (PaintHeader(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Navigation")
    {
        if (PaintNavigationButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Toolbar")
    {
        HTHEME hThemeToolbar = NULL;
        if (SetThemeHandle(WindowFromDC(hdc), hThemeToolbar, L"BB::Toolbar"))
        {
            if (PaintToolbarSplitDropDown(hdc, iPartId, iStateId, pRect)) {
                CloseThemeData(hThemeToolbar);
                return S_OK;
            }
        }
        if (PaintToolbarButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"AddressBand" || ThemeClassName == L"SearchBox")
    {
        if (PaintAddressBand(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Menu")
    {
        if (PaintMenu(hdc, iPartId, iStateId, pRect))
            return S_OK;
        // Force menu white glyphs
        else if (iPartId <= MENU_SYSTEMRESTORE && iPartId >= MENU_SYSTEMCLOSE && g_IsSysThemeDarkMode) {
            HTHEME hThemeMenu = NULL;
            if (SetThemeHandle(WindowFromDC(hdc), hThemeMenu, L"DarkMode::Menu")) {
                auto hr = DrawThemeBackground_orig(hThemeMenu, hdc, iPartId, iStateId, pRect, pClipRect);
                CloseThemeData(hThemeMenu);
                return hr;
            }
        }
    }
    else if (ThemeClassName == L"DragDrop")
    {
        if (PaintDragDrop(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Spin")
    {
        if (PaintSpin(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }

    HRESULT hr = DrawThemeBackground_orig(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
    
    if((ThemeClassName == L"Rebar" && (iPartId == RP_BAND || iPartId == RP_BACKGROUND) && iStateId == 0)
        || (ThemeClassName == L"Header" && (iPartId == THEMECLS_COMMONPROPS_PART || (iPartId == HP_HEADERITEM && (iStateId == HIS_NORMAL || iStateId == HIS_SORTEDNORMAL || iStateId == HIS_ICONNORMAL))))
        || (ThemeClassName == L"TaskDialog" && iPartId == TDLG_FOOTNOTEPANE && iStateId == 0)
        || (ThemeClassName == L"Tab" && iPartId == TABP_PANE)
        || (ThemeClassName == L"Status" && iPartId == THEMECLS_COMMONPROPS_PART)
        || (ThemeClassName == L"Tooltip" && (iPartId == TTP_STANDARD || iPartId == TTP_BALLOON || iPartId == TTP_BALLOONSTEM)))
    {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    else if (ThemeClassName == L"Menu" && (iPartId == MENU_BARBACKGROUND || iPartId == MENU_BARITEM))
    {
        RECT clipRect{*pRect};
        if (pClipRect)
            IntersectRect(&clipRect, pRect, pClipRect);
        FillRect(hdc, &clipRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    else if (ThemeClassName == L"Menu" && (iPartId == MENU_POPUPBACKGROUND || iPartId == MENU_POPUPBORDERS || iPartId == MENU_POPUPGUTTER || 
        iPartId == MENU_POPUPCHECKBACKGROUND || ((iPartId == MENU_POPUPITEM || iPartId == 27) && iStateId != MPI_HOT)))
    {
        RECT clipRect{*pRect};
        if (pClipRect)
            IntersectRect(&clipRect, pRect, pClipRect);
        if (g_settings.FlyoutsEffects)
            FillRect(hdc, &clipRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        else if (g_settings.FillBg) {
            HBRUSH brush = CreateSolidBrush(RGB(32, 32, 32));
            FillRect(hdc, &clipRect, brush);
            DeleteObject(brush);
        }
        return S_OK;
    }
    else if (ThemeClassName == L"Toolbar" && iPartId == THEMECLS_COMMONPROPS_PART) {
        HTHEME hThemeToolbar = nullptr;
        if ((SetThemeHandle(WindowFromDC(hdc), hThemeToolbar, L"Placesbar::Toolbar"))) {
            FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
            CloseThemeData(hThemeToolbar);
            return S_OK;
        }
    }
    return hr;
}

HRESULT WINAPI HookedDrawThemeBackgroundEx(
    HTHEME hTheme,
    HDC hdc,
    INT iPartId,
    INT iStateId,
    LPCRECT pRect,
    const DTBGOPTS* pOptions)
{    
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ScrollBar")
    {
        if (PaintScroll(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintScrollBarArrows(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ListView")
    {
        if (PaintListView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Edit")
    {
        if (PaintEditBox(hTheme ,hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Button")
    {
        RECT rcClip = *pRect;
        if(pOptions && pOptions->dwFlags & DTBG_CLIPRECT)
            rcClip = pOptions->rcClip;
        if (PaintPushButton(hdc, iPartId, iStateId, pRect, &rcClip))
            return S_OK;
        else if (PaintRadioButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCheckBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLink(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLinkGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ItemsView")
    {
        if (PaintItemsView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Header")
    {
        if (PaintHeader(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane")
    {
        if (PaintPreviewPaneSeparator(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Progress")
    {
        HTHEME hThemeProgress = NULL;
        if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeProgress, L"Indeterminate::Progress"))
        {
            if (PaintIndeterminateProgressBar(hdc, iPartId, iStateId, pRect))
            {
                CloseThemeData(hThemeProgress);
                return S_OK;
            }
        }
        else if (PaintProgressBar(hdc, iPartId, iStateId, pRect)) 
        {
            CloseThemeData(hThemeProgress);
            return S_OK;
        }

        if (hThemeProgress)
            CloseThemeData(hThemeProgress);
    } 
    else if (ThemeClassName == L"CommandModule")
    {
        if (PaintModuleButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintModuleSplitButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintModuleLocation(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }

    HRESULT hr = DrawThemeBackgroundEx_orig(hTheme, hdc, iPartId, iStateId, pRect, pOptions);

    if ((ThemeClassName == L"Rebar" && (iPartId == RP_BAND || iPartId == RP_BACKGROUND) && iStateId == 0) 
        || (ThemeClassName == L"TreeView" && iPartId == THEMECLS_COMMONPROPS_PART))
    {
        return S_OK;    
    }
    else if ((ThemeClassName == L"PreviewPane" && iPartId == 1)
        || (ThemeClassName == L"Header" && iPartId == THEMECLS_COMMONPROPS_PART)
        || (ThemeClassName == L"CommandModule" && iPartId == 1 && iStateId == 0)
        || (ThemeClassName == L"TaskDialog" && (iPartId == TDLG_CONTENTPANE || iPartId == TDLG_FOOTNOTESEPARATOR ||  iPartId == TDLG_FOOTNOTEPANE || iPartId == TDLG_SECONDARYPANEL) && iStateId == 0)
        || (ThemeClassName == L"TaskDialog" && iPartId == TDLG_PRIMARYPANEL)
        || (ThemeClassName == L"AeroWizard" && (iPartId == AW_TITLEBAR || iPartId == AW_HEADERAREA || iPartId == AW_CONTENTAREA || iPartId == AW_COMMANDAREA))
        || (ThemeClassName == L"CommonItemsDialog" && iPartId == 1)
        || (ThemeClassName == L"ControlPanel" && (iPartId == CPANEL_CONTENTPANE || iPartId == CPANEL_CONTENTPANELINE || iPartId == CPANEL_BANNERAREA || iPartId == CPANEL_LARGECOMMANDAREA || iPartId == CPANEL_SMALLCOMMANDAREA)))
    {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    return hr;
}

// Remove white rect below menubar (e.g. seen in mmc.exe)
HRESULT WINAPI HookedDrawThemeEdge(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, const RECT *pDestRect, UINT uEdge, UINT uFlags, RECT *pContentRect)
{
    std::wstring ThemeClass = GetThemeClass(hTheme);

    if (ThemeClass == L"Rebar" && iPartId == RP_BAND) {
        FillRect(hdc, pContentRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }

    return DrawThemeEdge_orig(hTheme, hdc, iPartId, iStateId, pDestRect, uEdge, uFlags, pContentRect);
}

HRESULT WINAPI HookedGetThemeMargins(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, INT iPropId, RECT* prc, MARGINS *pMargins)
{
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    auto ret = GetThemeMargins_orig(hTheme, hdc, iPartId, iStateId, iPropId, prc, pMargins);

    if (ThemeClassName == L"Tooltip" && iPartId == TTP_STANDARD) {
        if (iPropId == TMT_CONTENTMARGINS)
            *pMargins = {8, 8, 8, 8};
        else if (iPropId == TMT_CAPTIONMARGINS)
            *pMargins = {10, 10, 10, 10};
    }
    else if (ThemeClassName == L"Menu")
    {
        if (iPartId == MENU_POPUPITEM || iPartId == 27 || iPartId == 26) 
        {
            if (iPropId == TMT_CONTENTMARGINS)
                *pMargins = {2, 2, 4, 4};
            else if (iPropId == TMT_SIZINGMARGINS)
                *pMargins = {10, 10, 10, 10};
            else if (iPropId == 10000)
                *pMargins = {0, 0, 4, 4};
        }
        else if (iPartId == MENU_BARITEM) {
            if (iPropId == 10000)
                *pMargins = {9, 9, 3, 3};
        }
    }
    else if (ThemeClassName == L"Edit")
    {
        if (iPropId == TMT_SIZINGMARGINS)
            *pMargins = {8, 8, 8, 8};
    }   
    
    return ret;
}

HRESULT WINAPI HookedGetThemeFont (HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, INT iPropId, LOGFONTW* pFont)
{
    auto hr = GetThemeFont_orig(hTheme, hdc, iPartId, iStateId, iPropId, pFont);
    std::wstring ThemeClassName = GetThemeClass(hTheme);
    
    if (ThemeClassName == L"Menu" && iPropId == TMT_FONT) 
    {
        // Return if it's not the original font
        if (wcscmp(pFont->lfFaceName, L"Segoe UI"))
            return hr;
        wcscpy_s(pFont->lfFaceName, LF_FACESIZE, L"Segoe UI Variable Small");
        pFont->lfHeight = -13;
        pFont->lfWeight = 400;
        pFont->lfQuality = CLEARTYPE_QUALITY;
        pFont->lfPitchAndFamily = DEFAULT_PITCH;
    }
    else if (ThemeClassName == L"ControlPanelStyle" && iPartId == CPANEL_TITLE && iPropId == TMT_FONT) {
        wcscpy_s(pFont->lfFaceName, LF_FACESIZE, L"Segoe UI Variable Display Semib");
        pFont->lfHeight = -24;
    }
    return hr;
}

//https://github.com/ALTaleX531/TranslucentFlyouts/blob/master/TFMain/EffectHelper.hpp
// Required for flyouts with DWM SYSTEMBACKDROP effects
VOID TriggerWindowNCRendering(HWND hwnd)
{
    // NOTICE WINDOWS THAT WE HAVE ACTIVATED THE WINDOW
    DefWindowProcW(hwnd, WM_NCACTIVATE, TRUE, 0);
    //SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_DRAWFRAME | SWP_NOACTIVATE);
}

VOID DwmMakeWindowTransparent(HWND hwnd)
{
    DWM_BLURBEHIND bb{ DWM_BB_ENABLE | DWM_BB_BLURREGION | DWM_BB_TRANSITIONONMAXIMIZED, TRUE, CreateRectRgn(0, 0, -1, -1), TRUE };
    DwmEnableBlurBehindWindow(hwnd, &bb);
    DeleteObject(bb.hRgnBlur);
}

VOID EnableBlurBehind(HWND hWnd)
{
    // Does not interfere with the Windows Terminal, GameBar overlay
    if(!(IsWindowClass(hWnd, L"CASCADIA_HOSTING_WINDOW_CLASS") || IsWindowClass(hWnd, L"ApplicationFrameWindow")))
    {
        ACCENT_POLICY accentPolicy = {};
        WINCOMPATTRDATA winCompositionAttrib = {};
        DWM_BLURBEHIND dwmBlurBehindData = { };

        dwmBlurBehindData.fEnable = TRUE;
        dwmBlurBehindData.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION | DWM_BB_TRANSITIONONMAXIMIZED;
        // Blurs window client area
        HRGN hRgn = CreateRectRgn(0, 0, -1, -1);
        dwmBlurBehindData.hRgnBlur = hRgn;
        dwmBlurBehindData.fTransitionOnMaximized = TRUE;

        DwmEnableBlurBehindWindow(hWnd, &dwmBlurBehindData);
        DeleteObject(hRgn);

        accentPolicy.AccentState = ACCENT_STATE_ENABLE_ACRYLICBLURBEHIND;
        accentPolicy.GradientColor = g_settings.AccentBlurBehindClr;

        winCompositionAttrib.Attrib = WCA_ACCENT_POLICY;
        winCompositionAttrib.pvData = &accentPolicy;
        winCompositionAttrib.cbData = sizeof(accentPolicy);

        if (SetWindowCompositionAttribute)
            SetWindowCompositionAttribute(hWnd, &winCompositionAttrib);    
    }
}

static LRESULT WINAPI HookedDefWindowProcW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{    
    if (msg == WM_SETTINGCHANGE) 
    {
        // System theme change
        if (lParam && wcscmp((LPCWSTR)lParam, L"ImmersiveColorSet") == 0) 
        {
            // Fetch the actual current theme file path from registry
            std::wstring currentTheme = GetCurrentWindowsThemePath();

            AcquireSRWLockExclusive(&g_ThemeChangeLock);

            COLORREF crAccent = (g_settings.AccentColorize) ? GetAccentColor() : g_settings.AccentColor;

            if (currentTheme != g_LastThemePath || g_settings.AccentColor != crAccent) 
            {
                g_LastThemePath = currentTheme; 

                // Process the theme change
                g_themeCache.ClearCache();
                g_IsSysThemeDarkMode = ShouldSystemUseDarkMode();
                g_AccentPalette.LoadAccentPalette();
                
                if (g_settings.AccentColorize)
                    g_settings.AccentColor = crAccent;

                if (g_settings.SetSystemColors)
                    ColorizeSysColors();

                AcquireSRWLockExclusive(&g_SysColorsLock);
                for (HBRUSH& brush : g_themeCachedCustomSysColorBrushes) {
                    if (brush) { 
                        DeleteObject(brush); brush = nullptr; 
                    }
                }
                ReleaseSRWLockExclusive(&g_SysColorsLock);
            }
            
            ReleaseSRWLockExclusive(&g_ThemeChangeLock);
        }
    }   

    if (IsWindowClass(hWnd, L"ViewControlClass") && msg == WM_NCPAINT) {
        UINT borderType = DWMWCP_ROUND;
        DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &borderType, sizeof(UINT));
    }
    return DefWindowProc_orig(hWnd, msg, wParam, lParam);
}

VOID HandleEffects(HWND hWnd)
{
    BOOL isFlyoutWindow = isWindowFlyout(hWnd);

    if (g_IsSysThemeDarkMode) 
        DwmSetWindowAttribute(hWnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &ENABLE, sizeof(UINT));

    if(g_settings.BgType == g_settings.AccentBlurBehind)
        EnableBlurBehind(hWnd);
    else if (g_settings.BgType > g_settings.AccentBlurBehind)
    {
        if (isFlyoutWindow) {
            DwmMakeWindowTransparent(hWnd);
            TriggerWindowNCRendering(hWnd);
        }
        DwmSetWindowAttribute(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &g_settings.BgType, sizeof(UINT));
    }

    if (!isFlyoutWindow && g_settings.BgType != g_settings.Default) {
        MARGINS margins = {-1, -1, -1, -1};
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    }
    
    if (isFlyoutWindow) {
        UINT borderType = DWMWCP_ROUND;
        DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &borderType, sizeof(UINT));
    }
    
    return;
}

VOID NewWindowShown(HWND hWnd)
{
    if(!IsWindowEligible(hWnd))
        return;

    HandleEffects(hWnd);

    if (IsExcelProcess())
        ApplyExcelWorksheetTransparencyToChildren(hWnd);
}

VOID DwmExpandFrameIntoClientAreaHook() {
    WindhawkUtils::SetFunctionHook(DwmExtendFrameIntoClientArea, HookedDwmExtendFrameIntoClientArea, &DwmExtendFrameIntoClientArea_orig);
}

VOID DwmSetWindowAttributeHook() {
    WindhawkUtils::SetFunctionHook(DwmSetWindowAttribute, HookedDwmSetWindowAttribute, &DwmSetWindowAttribute_orig); 
}

HRESULT WINAPI HookedGetThemeTransitionDuration(HTHEME hTheme, INT iPartId, INT iStateIdFrom, INT iStateIdTo, INT iPropId, DWORD *pdwDuration)
{
    auto hr = GetThemeTransitionDuration_orig(hTheme, iPartId, iStateIdFrom, iStateIdTo, iPropId, pdwDuration);
    std::wstring ThemeClassStr = GetThemeClass(hTheme);
    
    if (ThemeClassStr == L"ScrollBar" && (iPartId == SBP_ARROWBTN || iPartId == SBP_THUMBBTNHORZ || iPartId == SBP_THUMBBTNVERT) && iStateIdTo == SCRBS_NORMAL)
        *pdwDuration = 40;
    else if (ThemeClassStr == L"ScrollBar" && (iPartId == SBP_ARROWBTN && iStateIdFrom == SCRBS_HOT && iStateIdTo == SCRBS_HOVER))
        *pdwDuration = 40;
    
    return hr;
}

LRESULT (STDCALL *CThemeMenu_MenuKeyboardMsgProc_orig)(INT, WPARAM, LPARAM);
LRESULT STDCALL HookedCThemeMenu_MenuKeyboardMsgProc_orig(INT code, WPARAM wParam, LPARAM lParam)
{
    auto res = CThemeMenu_MenuKeyboardMsgProc_orig(code, wParam, lParam);

    #ifdef _WIN64
        INT archOffset = 1;
    #else
        INT archOffset = 2;
    #endif

    UINT msg = *reinterpret_cast<DWORD*>(lParam + 16 / archOffset);
    HWND hWnd = *reinterpret_cast<HWND*>(lParam + 24 / archOffset);

    if (IsWindowClass(hWnd, MENUPOPUP_CLASS) && (msg == WM_NCPAINT || msg == WM_PRINT))
        HandleEffects(hWnd);

    return res;
}

HRESULT (__fastcall *_GetBrushesForPart_orig)(HTHEME, INT, COLORREF, HBITMAP*, HBRUSH*);
HRESULT __fastcall Hooked_GetBrushesForPart(HTHEME hTheme, INT iPartId, COLORREF Color, HBITMAP *phBitmap, HBRUSH *phBrush)
{
   std::wstring ThemeClass = GetThemeClass(hTheme);
    
    if (ThemeClass == L"Tab" && (iPartId == TABP_BODY || iPartId == TABP_AEROWIZARDBODY)) {
        if (!*phBrush || *phBrush != GetSysColorBrush(COLOR_WINDOW)) {
            *phBrush = GetSysColorBrush(COLOR_WINDOW);
            return S_OK;
        }
    }
    
    return _GetBrushesForPart_orig(hTheme, iPartId, Color, phBitmap, phBrush);
}

void (__fastcall *_BorderRect_orig)(HDC, COLORREF, LPRECT, INT, INT);
void __fastcall Hooked_BorderRect(HDC hdc, COLORREF color, LPRECT pRect, INT cxThickness, INT cyThickness)
{
    if (!pRect) return;

    auto BorderComposition = [&](RECT rcBorder)
    {
        BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
        params.dwFlags = BPPF_ERASE | BPPF_NOCLIP;
        HDC memDC = NULL;

        HPAINTBUFFER hpb = BeginBufferedPaint(hdc, &rcBorder, BPBF_TOPDOWNDIB, &params, &memDC);
        if (!hpb) {
            Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
            return _BorderRect_orig(hdc, color, pRect, cxThickness, cyThickness);
        }

        SetBkColor(memDC, color);
        ExtTextOutW(memDC, pRect->left, pRect->top, ETO_OPAQUE, pRect, NULL, NULL, NULL);
        BufferedPaintMakeOpaque(hpb, pRect);
        EndBufferedPaint(hpb, TRUE);
    };

    RECT rcBorder;
    // 1. Bottom Border
    rcBorder = *pRect;
    rcBorder.top = rcBorder.bottom - cyThickness;
    BorderComposition(rcBorder);

    // 2. Right Border
    rcBorder = *pRect;
    rcBorder.left = rcBorder.right - cxThickness;
    BorderComposition(rcBorder);

    // 3. Left Border
    rcBorder = *pRect;
    rcBorder.right = rcBorder.left + cxThickness;
    BorderComposition(rcBorder);

    // 4. Top Border
    rcBorder = *pRect;
    rcBorder.bottom = rcBorder.top + cyThickness;
    BorderComposition(rcBorder);

    return;
}

VOID UxThemeHooks(BOOL isFlyoutEffectEnabled)
{
    WindhawkUtils::SYMBOL_HOOK uxtheme_dll_hooks[] =
    {   
        // Inlined symbol in ARM64 system, avoid hooking.
        #ifdef _M_ARM64
        #else
            {
                {
                    #ifdef _WIN64
                        L"void __cdecl _BorderRect(struct HDC__ *,unsigned long,struct tagRECT const *,int,int)"
                    #else
                        L"void __stdcall _BorderRect(struct HDC__ *,unsigned long,struct tagRECT const *,int,int)"
                    #endif
                },
                &_BorderRect_orig,
                Hooked_BorderRect,
                FALSE
            },
        #endif
        {
            {
                #ifdef _WIN64
                    L"long __cdecl _GetBrushesForPart(void *,int,int,struct HBITMAP__ * *,struct HBRUSH__ * *)"
                #else
                    L"long __stdcall _GetBrushesForPart(void *,int,int,struct HBITMAP__ * *,struct HBRUSH__ * *)"
                #endif
            },
            &_GetBrushesForPart_orig,
            Hooked_GetBrushesForPart,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"protected: static __int64 __cdecl CThemeMenu::MenuKeyboardMsgProc(int,unsigned __int64,__int64)"
                #else
                    L"protected: static long __stdcall CThemeMenu::MenuKeyboardMsgProc(int,unsigned int,long)"
                #endif
            },
            &CThemeMenu_MenuKeyboardMsgProc_orig,
            HookedCThemeMenu_MenuKeyboardMsgProc_orig,
            FALSE
        },
    };

    HMODULE hUxTheme = LoadLibraryEx(L"uxtheme.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hUxTheme) {
        Wh_Log(L"Failed to load uxtheme.dll");
        return;
    }

    // If flyout effects setting isn't enabled hook to all symbols except the last one -> CThemeMenu::MenuKeyboardMsgProc
    if (!WindhawkUtils::HookSymbols(hUxTheme, uxtheme_dll_hooks, !isFlyoutEffectEnabled ? ARRAYSIZE(uxtheme_dll_hooks) - 1 : ARRAYSIZE(uxtheme_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in uxtheme.dll");
        return;
    }
}

VOID RestoreWindowCustomizations(HWND hWnd)
{
    if(!IsWindowEligible(hWnd))
        return;

    ACCENT_POLICY accentPolicy = {};
    WINCOMPATTRDATA winCompositionAttrib = {};
    DWM_BLURBEHIND dwmBlurBehindData = {};

    // Disabling AccentBlurBehind temp workaround
    dwmBlurBehindData.fEnable = FALSE;
    dwmBlurBehindData.dwFlags = DWM_BB_ENABLE;
    DwmEnableBlurBehindWindow(hWnd, &dwmBlurBehindData);

    accentPolicy.AccentState = ACCENT_STATE_DISABLED;

    winCompositionAttrib.Attrib = WCA_ACCENT_POLICY;
    winCompositionAttrib.pvData = &accentPolicy;
    winCompositionAttrib.cbData = sizeof(accentPolicy);

    if (SetWindowCompositionAttribute)
        SetWindowCompositionAttribute(hWnd, &winCompositionAttrib);
    
    DWM_SYSTEMBACKDROP_TYPE backdrop = DWMSBT_NONE;
    DwmSetWindowAttribute(hWnd, DWMWA_SYSTEMBACKDROP_TYPE , &backdrop, sizeof(UINT));

    // Manually restore frame extension
    if(!(IsWindowClass(hWnd,  L"TaskManagerWindow") && g_settings.BgType != g_settings.Default))
    {
        MARGINS margins = { 0, 0, 0, 0 };
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    }
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) 
{
    DWORD dwProcessId = 0;
    // Pass console window, it might be called from other processes like Clink:https://github.com/chrisant996/clink
    if ((!GetWindowThreadProcessId(hWnd, &dwProcessId) || dwProcessId != GetCurrentProcessId()) && !IsWindowClass(hWnd, L"ConsoleWindowClass")) 
        return TRUE;
    else
    {
        HWND hParentWnd = GetAncestor(hWnd, GA_PARENT);
        if (hParentWnd && hParentWnd != GetDesktopWindow())
            return TRUE;
        else if(g_settings.Unload)
            RestoreWindowCustomizations(hWnd);
        else
            NewWindowShown(hWnd);
    }
    return TRUE;
}

VOID ApplyForExistingWindows()
{
    EnumWindows(EnumWindowsProc, 0);
}

COLORREF GetColorSetting(LPCWSTR hexColor) 
{
    if (!hexColor)
        return DWMWA_COLOR_NONE;
    else 
    {
        size_t len = wcslen(hexColor);
        if (len != 6 && len != 8)
        {
            Wh_Log(L"[ERROR] Invalid color length");
            return FALSE;
        }
        
        auto hexToByte = [](WCHAR c) -> INT {
            if (c >= L'0' && c <= L'9') return c - L'0';
            if (c >= L'A' && c <= L'F') return 10 + (c - L'A');
            if (c >= L'a' && c <= L'f') return 10 + (c - L'a');
            return -1;
        };

        BYTE alpha = 0x00;
        BYTE rgb[3] = { 0 };

        if (len == 8) 
        {
            alpha = 0XFF;
            INT alphaHigh = hexToByte(hexColor[0]);
            INT alphaLow  = hexToByte(hexColor[1]);
            if (alphaHigh < 0 || alphaLow < 0)
                return FALSE;
            alpha = (alphaHigh << 4) | alphaLow;
            hexColor += 2;
        }

        for (INT i = 0; i < 3; ++i) 
        {
            INT high = hexToByte(hexColor[i * 2]);
            INT low  = hexToByte(hexColor[i * 2 + 1]);
            if (high < 0 || low < 0)
                return FALSE;
            rgb[i] = (high << 4) | low;
        }

        return (alpha << 24) | (rgb[2] << 16) | (rgb[1] << 8) | rgb[0];
    }
}

// ---------------------------------------------------------------------------------------------
// User32.dll internal operations in most cases use the gpsi pointer (global pointer shared info) in order to fetch useful attributes about the system session
// one of them being the system color buffer, gpsi pointing to offest 4568 to system COLORREFs and offset 4696 to system BRUSHES
//
// Kernel operations (e.g. win32kfull.sys) use: W32GetUserSessionState() + offset (<20016> as of Win11 26200.8655) + <System color offset>
//
// System color offsets:
//
//     -System colors-                      -System brushes-
//
// 4568: COLOR_SCROLLBAR                4696: COLOR_SCROLLBAR
// 4572: COLOR_BACKGROUND               4704: COLOR_BACKGROUND
// 4576: COLOR_ACTIVECAPTION            4712: COLOR_ACTIVECAPTION
// 4580: COLOR_INACTIVECAPTION          4720: COLOR_INACTIVECAPTION
// 4584: COLOR_MENU                     4728: COLOR_MENU
// 4588: COLOR_WINDOW                   4736: COLOR_WINDOW
// 4592: COLOR_WINDOWFRAME              4744: COLOR_WINDOWFRAME
// 4596: COLOR_MENUTEXT                 4752: COLOR_MENUTEXT
// 4600: COLOR_WINDOWTEXT               4760: COLOR_WINDOWTEXT
// 4604: COLOR_CAPTIONTEXT              4768: COLOR_CAPTIONTEXT
// 4608: COLOR_ACTIVEBORDER             4776: COLOR_ACTIVEBORDER
// 4612: COLOR_INACTIVEBORDER           4784: COLOR_INACTIVEBORDER
// 4616: COLOR_APPWORKSPACE             4792: COLOR_APPWORKSPACE
// 4620: COLOR_HIGHLIGHT                4800: COLOR_HIGHLIGHT
// 4624: COLOR_HIGHLIGHTTEXT            4808: COLOR_HIGHLIGHTTEXT
// 4628: COLOR_BTNFACE                  4816: COLOR_BTNFACE
// 4632: COLOR_BTNSHADOW                4824: COLOR_BTNSHADOW
// 4636: COLOR_GRAYTEXT                 4832: COLOR_GRAYTEXT
// 4640: COLOR_BTNTEXT                  4840: COLOR_BTNTEXT
// 4644: COLOR_INACTIVECAPTIONTEXT      4848: COLOR_INACTIVECAPTIONTEXT
// 4648: COLOR_BTNHIGHLIGHT             4856: COLOR_BTNHIGHLIGHT
// 4652: COLOR_3DDKSHADOW               4864: COLOR_3DDKSHADOW
// 4656: COLOR_3DLIGHT                  4872: COLOR_3DLIGHT
// 4660: COLOR_INFOTEXT                 4880: COLOR_INFOTEXT
// 4664: COLOR_INFOBK                   4888: COLOR_INFOBK
// 4668: COLOR_HOTLIGHT                 4896: COLOR_HOTLIGHT
// 4672: COLOR_GRADIENTACTIVECAPTION    4904: COLOR_GRADIENTACTIVECAPTION
// 4676: COLOR_GRADIENTACTIVECAPTION    4912: COLOR_GRADIENTACTIVECAPTION
// 4680: COLOR_MENUHIGHLIGHT            4920: COLOR_MENUHIGHLIGHT
// 4688: COLOR_MENUBAR                  4928: COLOR_MENUBAR
// ---------------------------------------------------------------------------------------------

// Replace the gpsi pointer inside user32 internal symbols with SysColor APIs (GetSysColor()/GetSysColorBrush())
LRESULT MyRealDefWindowProcWorker(UINT msg, WPARAM wParam)
{
    COLORREF sysColorBk = 0;
    COLORREF sysColorTxt = 0;
    HBRUSH sysBrush = nullptr;
    if (msg == WM_CTLCOLOR || msg == WM_CTLCOLOREDIT || msg == WM_CTLCOLORLISTBOX)
    {
        sysColorBk = GetSysColor(COLOR_WINDOW);                                 // Default: *gpsi + 4588 (COLOR_WINDOW)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4600 (COLOR_WINDOWTEXT)
        sysBrush = GetSysColorBrush(COLOR_WINDOW);                              // Default: *gpsi + 4736 (COLOR_WINDOW)
    }
    else if (msg == WM_CTLCOLORMSGBOX || msg == WM_CTLCOLORDLG || msg == WM_CTLCOLORSTATIC)
    {
        sysColorBk = GetSysColor(COLOR_BTNFACE);                                // Default: *gpsi + 4628 (COLOR_BTNTEXT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4600 (COLOR_WINDOWTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNFACE);                             // Default: *gpsi + 4816 (COLOR_BTNTEXT)
    }
    else if (msg == WM_CTLCOLORBTN)
    {
        sysColorBk = GetSysColor(COLOR_BTNFACE);                                // Default: *gpsi + 4628 (COLOR_BTNTEXT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4816 (COLOR_BTNTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNFACE);                             // Default: *gpsi + 4816 (COLOR_BTNTEXT)
    }
    else if (msg == WM_CTLCOLORSCROLLBAR)
    {
        sysColorBk = GetSysColor(COLOR_BTNHIGHLIGHT);                           // Default: *gpsi + 4648 (COLOR_BTNHIGHLIGHT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4840 (COLOR_BTNTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNHIGHLIGHT);                        // Default: *gpsi + 4856 (COLOR_BTNHIGHLIGHT)
    }

    HDC hdc = reinterpret_cast<HDC>(wParam);

    SetTextColor(hdc, sysColorTxt);
    SetBkColor(hdc, sysColorBk);
    return reinterpret_cast<LRESULT>(sysBrush);
}

#ifdef _WIN64
    LRESULT (__fastcall *RealDefWindowProcWorker_orig)(struct tagWND*, UINT, WPARAM, LPARAM, UINT);
    LRESULT __fastcall HookedRealDefWindowProcWorker(struct tagWND* pwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT flags)
    {
        switch (msg)
        {
            case WM_CTLCOLOR:
            case WM_CTLCOLORMSGBOX:
            case WM_CTLCOLOREDIT:
            case WM_CTLCOLORLISTBOX:
            case WM_CTLCOLORBTN:
            case WM_CTLCOLORDLG:
            case WM_CTLCOLORSCROLLBAR:
            case WM_CTLCOLORSTATIC:
            {
                LRESULT res = MyRealDefWindowProcWorker(msg, wParam);
                return res;
            }
        }

        return RealDefWindowProcWorker_orig(pwnd, msg, wParam, lParam, flags);
    }
#else
    LRESULT (__fastcall *RealDefWindowProcWorker_orig)(UINT, WPARAM, struct tagWND*, UINT, LPARAM, UINT);
    LRESULT __fastcall HookedRealDefWindowProcWorker(UINT msg, WPARAM wParam, struct tagWND* pwnd, UINT msg_dup, LPARAM lParam, UINT flags)
    {
        switch (msg)
        {
            case WM_CTLCOLOR:
            case WM_CTLCOLORMSGBOX:
            case WM_CTLCOLOREDIT:
            case WM_CTLCOLORLISTBOX:
            case WM_CTLCOLORBTN:
            case WM_CTLCOLORDLG:
            case WM_CTLCOLORSCROLLBAR:
            case WM_CTLCOLORSTATIC:
            {
                LRESULT res = MyRealDefWindowProcWorker(msg, wParam);
                return res;
            }
        }

        return RealDefWindowProcWorker_orig(msg, wParam, pwnd, msg_dup, lParam, flags);
    }
#endif

// Paints the background of message boxes
HBRUSH (STDCALL *MB_DlgProc_orig)(HWND, UINT, WPARAM, LPARAM);
HBRUSH STDCALL Hooked_MB_DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_CTLCOLORDLG || msg == WM_CTLCOLORSTATIC)
        return GetSysColorBrush(COLOR_WINDOW); // Default: gpsi + 4736 (COLOR_WINDOW)
    return MB_DlgProc_orig(hwnd, msg, wParam, lParam);
}

// Paints the lower part of message boxes
void (THISCALL *DrawCommandRectangle_orig)(HWND);
void THISCALL Hooked_DrawCommandRectangle(HWND hWnd)
{
    PAINTSTRUCT ps{};
    HDC hdc = BeginPaint(hWnd, &ps);
    if (!hdc)
        return;

    // Get window or client rectangle
    RECT rc{};
    GetClientRect(hWnd, &rc);

    // Match USER behavior
    HBRUSH hBrush = CreateSolidBrush(GetSysColor(COLOR_WINDOW)); // Default: gpsi + 4736 (COLOR_WINDOW)
    HGDIOBJ oldBrush = SelectObject(hdc, hBrush);

    HPEN hPen = CreatePen(PS_NULL, 0, 0);
    HGDIOBJ oldPen = SelectObject(hdc, hPen);

    Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

    // Restore
    SelectObject(hdc, oldPen);
    DeleteObject(hPen);

    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);

    EndPaint(hWnd, &ps);
}

// Modifying the background and text color of the classic Win32 tooltip (e.g., the one that appears when hovering the pointer over title bar buttons) which uses the gpsi pointer.
// Additionally, enlarging the tooltip window and applying mod's effects.
void (__fastcall *RenderTooltip_orig)(HWND, HDC, HGDIOBJ*);
void __fastcall HookedRenderTooltip(HWND hWnd, HDC hdc, HGDIOBJ *a3)
{
    HGDIOBJ oldObj = SelectObject(hdc, a3[1]);
    
    LPCWCHAR lpString = reinterpret_cast<LPCWCHAR>(*a3);
    UINT cch = wcslen(lpString); 

    SIZE textSize;
    GetTextExtentPoint32W(hdc, lpString, static_cast<INT>(cch), &textSize);

    RECT clientRect {0};
    GetClientRect(hWnd, &clientRect);

    // Inflate tooltip window rect by x1.8
    if (clientRect.bottom < static_cast<LONG>(textSize.cy * 1.8)) 
    {
        RECT winRect {0};
        GetWindowRect(hWnd, &winRect);
        
        INT newWidth = static_cast<INT>((winRect.right - winRect.left) * 1.8);
        INT newHeight = static_cast<INT>((winRect.bottom - winRect.top) * 1.8);

        // Start with the X and Y coordinates the system originally gave it
        INT newX = winRect.left;
        INT newY = winRect.top;

        // Screen Edge Detection
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        
        // Find out exactly which monitor the cursor is currently on
        HMONITOR hMonitor = MonitorFromPoint(cursorPos, MONITOR_DEFAULTTONEAREST);
        MONITORINFO mi = { sizeof(mi) };
        GetMonitorInfoW(hMonitor, &mi);

        // Check if our new width pushes it past the right edge of this monitor
        if ((newX + newWidth) > mi.rcMonitor.right)
            // Shift X leftwards so the right edge of the tooltip matches the screen edge
            // (Subtracting an extra 2 pixels so it doesn't touch the absolute physical bezel)
            newX = mi.rcMonitor.right - newWidth - 2;

        // Optional bonus: Do the same check for the bottom edge, just in case
        if ((newY + newHeight) > mi.rcMonitor.bottom)
            newY = mi.rcMonitor.bottom - newHeight - 2;

        // Apply the new position and dimensions
        SetWindowPos(hWnd, NULL, newX, newY, newWidth, newHeight,
                     SWP_NOZORDER | SWP_NOACTIVATE
                     );
        
        GetClientRect(hWnd, &clientRect);
    }

    COLORREF oldTextClr = SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));  // Default: gpsi + 4660 (COLOR_WINDOWTEXT)
    COLORREF oldBkClr = SetBkColor(hdc, RGB(0, 0, 0));                                                  // Default: gpsi + 4888 (COLOR_INFOTEXT)

    INT textX = (clientRect.right - textSize.cx) / 2;
    INT textY = (clientRect.bottom - textSize.cy) / 2;
    
    if (textX < 0) textX = 2;
    if (textY < 0) textY = 1;

    ExtTextOutW(hdc, textX, textY, ETO_OPAQUE, &clientRect, lpString, cch, 0);
    
    SetTextColor(hdc, oldTextClr);
    SetBkColor(hdc, oldBkClr);
    SelectObject(hdc, oldObj);
    
    return;
}

VOID User32Hooks(BOOL areSysColorsApplied)
{
    WindhawkUtils::SYMBOL_HOOK user32_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"__int64 __cdecl RealDefWindowProcWorker(struct tagWND *,unsigned int,unsigned __int64,__int64,unsigned long)"
                #else
                    L"long __stdcall RealDefWindowProcWorker(struct tagWND *,unsigned int,unsigned int,long,unsigned long)"
                #endif
            },
            &RealDefWindowProcWorker_orig,
            HookedRealDefWindowProcWorker,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"void __cdecl RenderTooltip(struct HWND__ *,struct HDC__ *,struct TooltipInfo *)"
                #else
                    L"void __stdcall RenderTooltip(struct HWND__ *,struct HDC__ *,struct TooltipInfo *)"
                #endif
            },
            &RenderTooltip_orig,
            HookedRenderTooltip,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"__int64 __cdecl MB_DlgProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)"
                #else
                    L"int __stdcall MB_DlgProc(struct HWND__ *,unsigned int,unsigned int,long)"
                #endif

            },
            &MB_DlgProc_orig,
            Hooked_MB_DlgProc,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"void __cdecl DrawCommandRectangle(struct HWND__ *)"
                #else
                    L"void __stdcall DrawCommandRectangle(struct HWND__ *)"
                #endif

            },
            &DrawCommandRectangle_orig,
            Hooked_DrawCommandRectangle,
            FALSE
        }
    };

    HMODULE hUser32 = LoadLibraryEx(L"user32.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hUser32) {
        Wh_Log(L"Failed to load user32.dll");
        return;
    }

    // If SetSysColors API is executed then hook only the first two symbols of the array -> RealDefWindowProcWorker, RenderTooltip routines
    if (!WindhawkUtils::HookSymbols(hUser32, user32_dll_hooks, areSysColorsApplied ? 2 : ARRAYSIZE(user32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in user32.dll");
        return;
    }
}

// Change Desktop items text and shadow colors in light theme
int (__fastcall *DrawShadowTextEx_orig)(HDC, LPCWSTR, INT, LPRECT, UINT, COLORREF, COLORREF, INT, INT, BYTE, BOOL);
int __fastcall HookedDrawShadowTextEx(HDC hdc, LPCWSTR lpchText, INT cchText, LPRECT pRect, UINT uformat, 
                COLORREF crText, COLORREF crShadow, INT ixOffset, INT iyOffset, BYTE bAlpha, BOOL InitBufferPaintFlag)
{
    if (!g_IsSysThemeDarkMode && g_InsideExplorerProc) {
        crText = RGB(0, 0, 0);
        crShadow = RGB(255, 255, 255);
    }
    return DrawShadowTextEx_orig(hdc, lpchText, cchText, pRect, uformat, crText, crShadow, ixOffset, iyOffset, bAlpha, InitBufferPaintFlag);
}

void (__fastcall *SHThemeDrawText_orig)(void*, HDC, INT, INT, DTTOPTS*, LPCWSTR, LPRECT, INT, UINT, INT, __int64, COLORREF, COLORREF);
void __fastcall Hooked_SHThemeDrawText(void *hTheme, HDC hdc, INT iPartId, INT iStateId, DTTOPTS *pOptions, LPCWSTR lpString, LPRECT pRect, INT iLVGroupAlignFlag, UINT uFormat, INT a10, __int64 a11, COLORREF crText, COLORREF crBackground)
{
    if (!g_InsideTaskMgrProc)
        crText = g_IsSysThemeDarkMode && (crText & 0x00ffffff) <= RGB(96, 96, 96) ? RGB(255, 255, 255) : !g_IsSysThemeDarkMode ? RGB(0, 0, 0) : crText;

    SHThemeDrawText_orig(hTheme, hdc, iPartId, iStateId, pOptions, lpString, pRect, iLVGroupAlignFlag, uFormat, a10, a11, crText, crBackground);
    return;

}

// Alpha blend highlighted text rectangle
void (__fastcall *SHThemeFillTextRect_orig)(HDC, LPRECT, COLORREF, INT);
void __fastcall HookedSHThemeFillTextRect(HDC hDC, LPRECT lprc, COLORREF color, INT sysColorCode)
{
    if (color != GetSysColor(COLOR_HIGHLIGHT))
        return SHThemeFillTextRect_orig(hDC, lprc, color, sysColorCode);
    
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hDC, lprc, BPBF_TOPDOWNDIB, &params, &memDC); 
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return SHThemeFillTextRect_orig(hDC, lprc, color, sysColorCode); 
    }

    SHThemeFillTextRect_orig(memDC, lprc, color, sysColorCode);

    BufferedPaintMakeOpaque(hpb, lprc);
    EndBufferedPaint(hpb, TRUE); 
}

// Alpha blend highlighted text rectangle
COLORREF (__fastcall *FillRectClr_orig)(HDC, LPRECT, COLORREF);
COLORREF __fastcall HookedFillRectClr(HDC hdc, LPRECT lprect, COLORREF color)
{
    if (color != GetSysColor(COLOR_HIGHLIGHT))
        return FillRectClr_orig(hdc, lprect, color);
        
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hdc, lprect, BPBF_TOPDOWNDIB, &params, &memDC);
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return FillRectClr_orig(hdc, lprect, color);
    }

    HBRUSH highlightedBrush = GetSysColorBrush(COLOR_HIGHLIGHT);
    FillRect(memDC, lprect, highlightedBrush);

    BufferedPaintMakeOpaque(hpb, lprect);
    EndBufferedPaint(hpb, TRUE); 
    
    return color;
}

// As of Win11 26200.8655 - Listbox background fill color return COLOR_WINDOW system color
// We return white color so the black text inside listboxes are readable on system light theme.
HBRUSH (__fastcall *ListBox_GetBrush_orig)(struct tagLBIV*, HBRUSH*);
HBRUSH __fastcall HookedListBox_GetBrush(struct tagLBIV *a1, HBRUSH *hbr)
{   
    // Default return brush: GetSysColorBrush(COLOR_WINDOW)
    HBRUSH ret = g_IsSysThemeDarkMode ? ListBox_GetBrush_orig(a1, hbr) : (HBRUSH)GetStockObject(WHITE_BRUSH);
    return ret;
}

// As of Win11 26200.8655 - The ComboBox control (e.g., the Windows address bar) draws an internal rectangle using a brush with the COLOR_WINDOW system color.
// Since the custom COLOR_WINDOW is black, whereas the rest of the ComboBox control's background is intended to be drawn in white,
// we intervene to correct this behavior in light theme mode.
void (__fastcall *ComboEx_OnDrawItem_orig)(struct COMBOEX*, struct tagDRAWITEMSTRUCT*);
void __fastcall HookedComboEx_OnDrawItem(struct COMBOEX *a1, struct tagDRAWITEMSTRUCT *a2)
{
    if (!g_IsSysThemeDarkMode) 
    {
        InflateRect(&a2->rcItem, 1, 1);
        FillRect(a2->hDC, &a2->rcItem, (HBRUSH)GetStockObject(WHITE_BRUSH));
        InflateRect(&a2->rcItem, -1, -1);
    }
    ComboEx_OnDrawItem_orig(a1, a2);
    return;
}

VOID Comctl32Hooks()
{
    WindhawkUtils::SYMBOL_HOOK comctl32_dll_hooks[] =
    {   
        // 32-bit version contains complex color specification, avoid it.
        #ifdef _WIN64
        {
            {
                L"SHThemeDrawText"
            },
            &SHThemeDrawText_orig,
            Hooked_SHThemeDrawText,
            FALSE
        },
        #endif
        {
            {
                #ifdef _WIN64
                    L"DrawShadowTextEx"
                #else
                    L"_DrawShadowTextEx@44"
                #endif
            },
            &DrawShadowTextEx_orig,
            HookedDrawShadowTextEx,
            FALSE
        },
        // Symbols are inlined in ARM64, avoid hooking.
        #ifdef _M_ARM64
        #else
            // SHThemeFillTextRect available only to 64-bit version.
            // Color specification for the 32-bit version is implemented within SHThemeDrawText()
            // Color specification for the 64-bit version is implemented within SHThemeDrawText() -> SHThemeComputeTextColors()
            #ifdef _WIN64
            {
                {
                    L"SHThemeFillTextRect"
                },
                &SHThemeFillTextRect_orig,
                HookedSHThemeFillTextRect,
                FALSE
            },
            #endif
            {
                {
                    #ifdef _WIN64
                        L"FillRectClr"
                    #else
                        L"_FillRectClr@12"
                    #endif
                },
                &FillRectClr_orig,
                HookedFillRectClr,
                FALSE
            },
            {
                {
                    #ifdef _WIN64
                        L"struct HBRUSH__ * __cdecl ListBox_GetBrush(struct tagLBIV *,struct HBRUSH__ * *)"
                    #else
                        L"struct HBRUSH__ * __stdcall ListBox_GetBrush(struct tagLBIV *,struct HBRUSH__ * *)"
                    #endif
                },
                &ListBox_GetBrush_orig,
                HookedListBox_GetBrush,
                FALSE
            },
        #endif
        {
            {
                #ifdef _WIN64
                    L"void __cdecl ComboEx_OnDrawItem(struct COMBOEX *,struct tagDRAWITEMSTRUCT *)"
                #else
                    L"void __stdcall ComboEx_OnDrawItem(struct COMBOEX *,struct tagDRAWITEMSTRUCT *)"
                #endif
            },
            &ComboEx_OnDrawItem_orig,
            HookedComboEx_OnDrawItem,
            FALSE
        },           
    };

    HMODULE hComCtl32 = LoadComCtlModule();
    if (!hComCtl32) {
        Wh_Log(L"Failed to load comctl32.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hComCtl32, comctl32_dll_hooks, ARRAYSIZE(comctl32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in comctl32.dll");
        return;
    }
}

BOOL CThemeCache::CacheNavigationDivider()
{
    FLOAT x = 0, y = 0;
    FLOAT width = 2, height = 2;

    if(!g_themeCache.CreateDIB(g_themeCache.navigationdivider[0], width, height))
        return FALSE;

    RECT rc = {(INT)x, (INT)y, (INT)width, (INT)height};
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.navigationdivider[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(96, 160, 160, 160) : MyD2D1Color(96, 0, 0, 0), &brush);

    pRenderTarget->BeginDraw();

    // 0.5f makes stroke height 1px
    pRenderTarget->DrawLine(D2D1_POINT_2F(x, y + .5f), D2D1_POINT_2F(width, y + .5f), brush.Get());

    HRESULT hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

// Internal symbol returning Systreeview window handle
__int64 (THISCALL *CNscTree_GetWindowsDDT_orig)(class CNscTree*, HWND *, HWND *);

// Render custom D2D alpha blended navigation pane divider
void (THISCALL *CNscTree_DrawDivider_orig)(class CNscTree* , HDC, struct _TREEITEM*);
void THISCALL Hooked_CNscTree_DrawDivider(CNscTree *__this, HDC hdc, struct _TREEITEM *hTreeItem)
{
    auto Fallback = [&](LPCWSTR errorMessage = NULL) {
        if (errorMessage)
            Wh_Log(L"%s", errorMessage);
        CNscTree_DrawDivider_orig(__this, hdc, hTreeItem);
        return;
    };

    HWND hwndTreeView = nullptr;
    // CNscTree_GetWindowsDDT returns 0 if succeeded
    if (CNscTree_GetWindowsDDT_orig && CNscTree_GetWindowsDDT_orig(__this, &hwndTreeView, &hwndTreeView))
        return Fallback(L"Failed acquiring treeview window handle");
    
    RECT treeItemRect = {0};
    *reinterpret_cast<HTREEITEM*>(&treeItemRect) = (HTREEITEM)hTreeItem;
    
    if (!SendMessageW(hwndTreeView, TVM_GETITEMRECT, 0, (LPARAM)&treeItemRect))
        return Fallback();
    
    if (!g_d2dFactory)
        return Fallback();

    if (!g_themeCache.navigationdivider[0] && !g_themeCache.CacheNavigationDivider())
        return Fallback();
    
    RECT lineRc = treeItemRect;
    INT middlePoint = RECTHEIGHT(&treeItemRect) / 4.f;
    lineRc.top = treeItemRect.top + middlePoint - 1;
    lineRc.bottom = treeItemRect.top + middlePoint + 1;
    lineRc.left = treeItemRect.left + RECTWIDTH(&treeItemRect) * 0.05f; // default horizontal bounds offset
    lineRc.right = treeItemRect.right - lineRc.left;

    DrawNineGridStretch(hdc, g_themeCache.navigationdivider[0], &lineRc, 1, 1, 0, 0);
    return;
}

VOID ExplorerFrameHooks()
{
    WindhawkUtils::SYMBOL_HOOK explorerframe_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"private: void __cdecl CNscTree::DrawDivider(struct HDC__ *,struct _TREEITEM *)"
                #else
                    L"private: void __thiscall CNscTree::DrawDivider(struct HDC__ *,struct _TREEITEM *)"
                #endif
            },
            &CNscTree_DrawDivider_orig,
            Hooked_CNscTree_DrawDivider,
            FALSE
        },
        // We're getting only the symbol address.
        {
            {
                #ifdef _WIN64
                    L"public: virtual long __cdecl CNscTree::GetWindowsDDT(struct HWND__ * *,struct HWND__ * *)"
                #else
                    L"public: virtual long __thiscall CNscTree::GetWindowsDDT(struct HWND__ * *,struct HWND__ * *)"
                #endif
            },
            &CNscTree_GetWindowsDDT_orig,
            nullptr,
            FALSE
        },          
    };

    HMODULE hExplorerFrame = LoadLibraryEx(L"ExplorerFrame.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hExplorerFrame) {
        Wh_Log(L"Failed to load ExplorerFrame.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hExplorerFrame, explorerframe_dll_hooks, ARRAYSIZE(explorerframe_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in ExplorerFrame.dll");
        return;
    }
}

// Branding images are painted using TransparentBlt() with white transparency mask.
// Paint everything except the image text into white in order to force transparency to the background.
void RecolorBrandingLogoBackground(HBITMAP hbm)
{
    if (!hbm) 
        return;

    BITMAP bm{};
    if (!GetObject(hbm, sizeof(bm), &bm)) 
        return;

    BITMAPINFO bmi{};
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = bm.bmWidth;
    bmi.bmiHeader.biHeight      = bm.bmHeight;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    HDC hdc = CreateCompatibleDC(nullptr);
    if (!hdc) 
        return;

    size_t pixels = static_cast<size_t>(bm.bmWidth) * bm.bmHeight;
    
    auto px = std::make_unique<COLORREF[]>(pixels);

    if (GetDIBits(hdc, hbm, 0, bm.bmHeight, px.get(), &bmi, DIB_RGB_COLORS))
    {
        // Check if the first pixel is RGB(240, 240, 240). If not, it's probably a custom image -> abort.
        if ((px[0] & 0x00FFFFFF) == 0x00F0F0F0)
        {
            // Target color to keep: RGB(0, 120, 212)
            constexpr COLORREF targetColor = 0x000078D4; 

            for (size_t i = 0; i < pixels; ++i)
            {
                if ((px[i] & 0x00FFFFFF) != targetColor)
                    px[i] = 0xFFFFFFFF; // Turn white
                else
                    px[i] = g_settings.AccentColorize ?
                            // bgr -> rgb 
                            (0xFF000000 | ((g_settings.AccentColor & 0x0000FF) << 16) | (g_settings.AccentColor & 0x00FF00) | ((g_settings.AccentColor & 0xFF0000) >> 16))
                            : px[i];
            }
            SetDIBits(hdc, hbm, 0, bm.bmHeight, px.get(), &bmi, DIB_RGB_COLORS);
        }
    }
    DeleteDC(hdc); 
}

// Intercept the windows branding logo image (e.g winver, shutdown dialog, regedit etc.)
// Winver loads the bitmap using LoadAboutBitmaps() routine, shutdown dialog using LoadBrandingBitmap().
HANDLE (STDCALL *BrandingLoadImage_orig)(LPCWSTR, UINT, UINT, INT, INT, UINT);
HANDLE STDCALL HookedBrandingLoadImage(LPCWSTR pszBrand, UINT uID, UINT type, INT cx, INT cy, UINT  fuLoad)
{   
    auto hImage = BrandingLoadImage_orig(pszBrand, uID, type, cx, cy, fuLoad);

    // The image resource is fetched from basebrd.dll resource image 121.
    if (!wcscmp(pszBrand, L"Basebrd") && uID == 121)
        RecolorBrandingLogoBackground(reinterpret_cast<HBITMAP>(hImage));
    return hImage;
}

VOID WinbrandHooks()
{
    WindhawkUtils::SYMBOL_HOOK winbrand_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"BrandingLoadImage"
                #else
                    L"_BrandingLoadImage@24"
                #endif
            },
            &BrandingLoadImage_orig,
            HookedBrandingLoadImage,
            FALSE
        },
    };

    HMODULE hWinbrand = LoadLibraryEx(L"winbrand.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hWinbrand ) {
        Wh_Log(L"Failed to load winbrand.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hWinbrand , winbrand_dll_hooks, ARRAYSIZE(winbrand_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in winbrand.dll");
        return;
    }
}

// Imitate the internal pseudohandle logic and replace gpsi pointer with GetSysColorBrush getter API.
BOOL WINAPI HookedFillRect(HDC hdc, LPCRECT lprc, HBRUSH hbr)
{    
    ULONG_PTR pseudoSystemBrush = (ULONG_PTR)hbr - 1;
    if (pseudoSystemBrush <= 30)
        return FillRect_orig(hdc, lprc, GetSysColorBrush((INT)pseudoSystemBrush));    

    return FillRect_orig(hdc, lprc, hbr);
}

// Paint the explorer dialogs bottom part background
BOOL (__fastcall *SetDarkThemeColors_orig)(void **, HDC);
BOOL __fastcall HookedSetDarkThemeColors(void **Brush, HDC hdc)
{
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));
    //if ( !*Brush )
        *Brush = (void*)GetSysColorBrush(COLOR_WINDOW);
    return *Brush != nullptr;
}

// Paint the explorer dialogs editbox background
LRESULT (STDCALL *CFileNameComboBox_s_ComboBoxRootSubclass_orig)(HWND, UINT, HDC, LPARAM, UINT_PTR, DWORD_PTR);
LRESULT STDCALL HookedCFileNameComboBox_s_ComboBoxRootSubclass(HWND hWnd, UINT uMsg, HDC wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    auto ret = CFileNameComboBox_s_ComboBoxRootSubclass_orig(hWnd, uMsg, wParam, lParam, uIdSubclass, dwRefData);

    // Intercept the paint messages
    if (uMsg != WM_CTLCOLOREDIT && uMsg != WM_CTLCOLORLISTBOX && uMsg != WM_CTLCOLORSTATIC) 
        return ret;
    
    HDC hdc = reinterpret_cast<HDC>(wParam);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));
    return reinterpret_cast<LRESULT>(GetSysColorBrush(COLOR_WINDOW));
}

// Paint the explorer dialogs editbox background
BOOL (STDCALL *CComboBoxExBase_OnWinEvent_orig)(class CComboBoxExBase *, HWND, UINT, HDC, LPARAM, LRESULT*);
BOOL STDCALL HookedCComboBoxExBase_OnWinEvent(class CComboBoxExBase *__this, HWND hWnd, UINT uMsg, HDC hdc, LPARAM lParam, LRESULT* pResult)
{
    auto ret = CComboBoxExBase_OnWinEvent_orig(__this, hWnd, uMsg, hdc, lParam, pResult);

    // Intercept the paint messages
    if (uMsg != WM_CTLCOLOREDIT && uMsg != WM_CTLCOLORLISTBOX && uMsg != WM_CTLCOLORSTATIC) 
        return ret;

    if (ret == false && pResult != nullptr && *pResult != 0) 
    {
        // C. Overwrite the original SetBkColor and SetTextColor
        SetBkColor(hdc, RGB(0, 0, 0));          // Black Background
        SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));  // White Text

        // D. Replace the original Dark Gray brush in the out-parameter with our Black Brush
        *pResult = reinterpret_cast<LRESULT>(GetSysColorBrush(COLOR_WINDOW));
    }
    return ret;
}

VOID Comdlg32Hooks()
{
    WindhawkUtils::SYMBOL_HOOK comdlg32_dll_hooks[] =
    {
        
        {
            {
                #ifdef _WIN64
                    L"bool __cdecl SetDarkThemeColors(class wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct HBRUSH__ *,int (__cdecl*)(void *),&int __cdecl DeleteObject(void *),struct wistd::integral_constant<unsigned __int64,0>,struct HBRUSH__ *,struct HBRUSH__ *,0,std::nullptr_t> > > &,struct HDC__ *)"
                #else
                    L"bool __stdcall SetDarkThemeColors(class wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct HBRUSH__ *,int (__stdcall*)(void *),&int __stdcall DeleteObject(void *),struct wistd::integral_constant<unsigned int,0>,struct HBRUSH__ *,struct HBRUSH__ *,0,std::nullptr_t> > > &,struct HDC__ *)"
                #endif
            },
            &SetDarkThemeColors_orig,
            HookedSetDarkThemeColors,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"private: static __int64 __cdecl CFileNameComboBox::s_ComboBoxRootSubclass(struct HWND__ *,unsigned int,unsigned __int64,__int64,unsigned __int64,unsigned __int64)"
                #else
                    L"private: static long __stdcall CFileNameComboBox::s_ComboBoxRootSubclass(struct HWND__ *,unsigned int,unsigned int,long,unsigned int,unsigned long)"
                #endif
            },
            &CFileNameComboBox_s_ComboBoxRootSubclass_orig,
            HookedCFileNameComboBox_s_ComboBoxRootSubclass,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"public: virtual long __cdecl CComboBoxExBase::OnWinEvent(struct HWND__ *,unsigned int,unsigned __int64,__int64,__int64 *)"
                #else
                    L"public: virtual long __stdcall CComboBoxExBase::OnWinEvent(struct HWND__ *,unsigned int,unsigned int,long,long *)"
                #endif
            },
            &CComboBoxExBase_OnWinEvent_orig,
            HookedCComboBoxExBase_OnWinEvent,
            FALSE
        },
        
    };

    HMODULE hComDlg32 = LoadLibraryEx(L"comdlg32.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hComDlg32 ) {
        Wh_Log(L"Failed to load comdlg32.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hComDlg32 , comdlg32_dll_hooks, ARRAYSIZE(comdlg32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in comdlg32.dll");
        return;
    }
}

VOID CustomRenderingHooks()
{
    InitDirect2D();
    #ifdef _WIN64
        CplDuiHook();
    #endif
    WindhawkUtils::SetFunctionHook(DefWindowProc, HookedDefWindowProcW, &DefWindowProc_orig);
    WindhawkUtils::SetFunctionHook(GetThemeColor, HookedGetColorTheme, &GetThemeColor_orig);   
    WindhawkUtils::SetFunctionHook(DrawThemeBackground, HookedDrawThemeBackground, &DrawThemeBackground_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeBackgroundEx, HookedDrawThemeBackgroundEx, &DrawThemeBackgroundEx_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeEdge, HookedDrawThemeEdge, &DrawThemeEdge_orig);
    ExplorerFrameHooks();
    Comctl32Hooks();
    if (g_IsSysThemeDarkMode)
        Comdlg32Hooks();
    WinbrandHooks();
    User32Hooks(g_settings.SetSystemColors);
    if (!g_settings.SetSystemColors) {
        WindhawkUtils::SetFunctionHook(FillRect, HookedFillRect, &FillRect_orig);
        WindhawkUtils::SetFunctionHook(GetSysColor, HookedGetSysColor, &GetSysColor_orig);
        WindhawkUtils::SetFunctionHook(GetSysColorBrush, HookedGetSysColorBrush, &GetSysColorBrush_orig);
    }
    WindhawkUtils::SetFunctionHook(DrawTextWithGlow, HookedDrawTextWithGlow, &DrawTextWithGlow);
    WindhawkUtils::SetFunctionHook(DrawTextW, HookedDrawTextW, &DrawTextW_orig);
    WindhawkUtils::SetFunctionHook(ExtTextOutW, HookedExtTextOutW, &ExtTextOutW_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeText, HookedDrawThemeText, &DrawThemeText_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeTextEx, HookedDrawThemeTextEx, &DrawThemeTextEx_orig);
    UxThemeHooks(g_settings.FlyoutsEffects);
    if (g_settings.FlyoutsEffects)
        WindhawkUtils::SetFunctionHook(GetThemeMargins, HookedGetThemeMargins, &GetThemeMargins_orig);
    WindhawkUtils::SetFunctionHook(GetThemeTransitionDuration, HookedGetThemeTransitionDuration, &GetThemeTransitionDuration_orig);
    WindhawkUtils::SetFunctionHook(GetThemeFont, HookedGetThemeFont, &GetThemeFont_orig);
}

VOID ApplyHooks()
{
    if(g_settings.FillBg)
        CustomRenderingHooks();
    if (g_settings.BgType != g_settings.Default) {
        DwmSetWindowAttributeHook();
        DwmExpandFrameIntoClientAreaHook();
    }        
}

// Normalizes a path: flips slashes, trims trailing slashes, lowercases.
std::wstring NormalizeRule(std::wstring path) 
{
    if (path.empty()) return path;

    // 1. Normalize slashes
    for (auto& ch : path)
        if (ch == L'/') 
            ch = L'\\';

    // 2. Trim trailing slashes (now guaranteed to be backslashes)
    while (!path.empty() && path.back() == L'\\')
        path.pop_back();
    
    if (path.empty()) 
        return path;

    // 3. Lowercase
    LCMapStringEx(LOCALE_NAME_USER_DEFAULT, LCMAP_LOWERCASE, 
                  path.c_str(), (INT)path.length(), &path[0], (INT)path.length(), 
                  nullptr, nullptr, 0);

    return path;
}

struct CurrentProcessInfo {
    std::wstring fullPath;   // (e.g. c:\windows\system32\notepad.exe)
    std::wstring fileName;   // (e.g. notepad.exe)
    std::wstring directory;  // (e.g. c:\windows\system32)
};

CurrentProcessInfo GetCurrentProcessInfo() 
{
    WCHAR modulePath[MAX_PATH];
    GetModuleFileNameW(nullptr, modulePath, MAX_PATH);

    CurrentProcessInfo info;
    info.fullPath = modulePath;

    // FIX 1: Strip Windows long path prefix if present, otherwise string matches fail
    if (info.fullPath.find(L"\\\\?\\") == 0) {
        info.fullPath.erase(0, 4);
    }

    // FIX 2: Process paths can occasionally contain forward slashes depending on launch method.
    for (auto& ch : info.fullPath) {
        if (ch == L'/') ch = L'\\';
    }

    // Lowercase the main string once
    LCMapStringEx(LOCALE_NAME_USER_DEFAULT, LCMAP_LOWERCASE, 
                  info.fullPath.c_str(), (INT)info.fullPath.length(), 
                  &info.fullPath[0], (INT)info.fullPath.length(), 
                  nullptr, nullptr, 0);

    // Extract substrings cleanly 
    size_t pos = info.fullPath.find_last_of(L'\\');
    if (pos != std::wstring::npos) {
        info.fileName = info.fullPath.substr(pos + 1);
        info.directory = info.fullPath.substr(0, pos);
    } else {
        info.fileName = info.fullPath;
        info.directory = L""; 
    }

    return info;
}

bool MatchesProcessRule(const std::wstring& rawEntry, const CurrentProcessInfo& proc) 
{
    std::wstring entry = NormalizeRule(rawEntry);
    if (entry.empty()) return false;

    // Exact full path or directory match
    if (entry == proc.fullPath || entry == proc.directory)
        return true;

    // Bare name, e.g. "mspaint.exe"
    if (entry.find(L'\\') == std::wstring::npos) {
        return entry == proc.fileName;
    }

    // FIX 3: Subfolder match. Use .find() == 0 for a bulletproof "starts_with" check.
    std::wstring prefix = entry + L"\\";
    if (proc.fullPath.find(prefix) == 0)
        return true;

    return false;
}

VOID LoadWindowProcessRules()
{
    CurrentProcessInfo currProc = GetCurrentProcessInfo();

    for (INT i = 0;; i++) 
    {
        auto program = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].target", i));
        
        if (!*program)
            break; 

        if (MatchesProcessRule(program.get(), currProc))
        {
            g_settings.FillBg = Wh_GetIntSetting(L"RuledPrograms[%d].RenderingMod.ThemeBackground", i);
            
            BOOL globalSetting_CustomTheme = Wh_GetIntSetting(L"RenderingMod.ThemeBackground");
            if (!globalSetting_CustomTheme)
                GenerateTextAlphaGammaLUT();
            
            g_settings.AccentColorize = Wh_GetIntSetting(L"RuledPrograms[%d].RenderingMod.AccentColorControls", i);
            if (g_settings.AccentColorize)
                g_settings.AccentColor = GetAccentColor();
            
            BOOL globalSetting_SetSysColorAPI = Wh_GetIntSetting(L"RenderingMod.Syscolors");

            // Reset system colors to default values if the system color setting is disabled for the specific ruled process
            if (!g_settings.FillBg && globalSetting_SetSysColorAPI)
                g_DefaultSysColors = TRUE;
            
            // Hook all necessary APIs to restore system colors when SetSysColors API has been executed by the mod
            if (g_DefaultSysColors) {
                WindhawkUtils::SetFunctionHook(GetSysColor, HookedGetSysColor, &GetSysColor_orig);
                WindhawkUtils::SetFunctionHook(GetSysColorBrush, HookedGetSysColorBrush, &GetSysColorBrush_orig);               
                WindhawkUtils::SetFunctionHook(FillRect, HookedFillRect, &FillRect_orig);
                User32Hooks(g_settings.SetSystemColors);
            }   

            auto strStyle = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].BackgroundEffects.type", i));
            if (0 == wcscmp(strStyle, L"acrylicblur"))
                g_settings.BgType = g_settings.AccentBlurBehind;
            else if (0 == wcscmp(strStyle, L"acrylicsystem"))
                g_settings.BgType = g_settings.AcrylicSystemBackdrop;
            else if (0 == wcscmp(strStyle, L"mica"))
                g_settings.BgType = g_settings.Mica;
            else if (0 == wcscmp(strStyle, L"mica_tabbed"))
                g_settings.BgType = g_settings.MicaAlt;
            else 
                g_settings.BgType = g_settings.Default;

            g_settings.AccentBlurBehindClr = GetColorSetting(WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].BackgroundEffects.AccentBlurBehind", i)));
            
            break;
        }
    }
}

VOID LoadSettings()
{
    g_settings.AccentColorize = Wh_GetIntSetting(L"RenderingMod.AccentColorControls");
    if (g_settings.AccentColorize)
       g_settings.AccentColor = GetAccentColor();

    g_settings.FillBg = Wh_GetIntSetting(L"RenderingMod.ThemeBackground");
    if (g_settings.FillBg)
        GenerateTextAlphaGammaLUT();
    
    g_settings.SetSystemColors = Wh_GetIntSetting(L"RenderingMod.Syscolors");
    // SetSysColors API available only in theme customization
    if (g_settings.SetSystemColors && g_settings.FillBg)
        ColorizeSysColors();
    
    auto strStyle = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"BackgroundEffects.type"));
    if (0 == wcscmp(strStyle, L"acrylicblur"))
        g_settings.BgType = g_settings.AccentBlurBehind;
    else if (0 == wcscmp(strStyle, L"acrylicsystem"))
        g_settings.BgType = g_settings.AcrylicSystemBackdrop;
    else if (0 == wcscmp(strStyle, L"mica"))
        g_settings.BgType = g_settings.Mica;
    else if (0 == wcscmp(strStyle, L"mica_tabbed"))
        g_settings.BgType = g_settings.MicaAlt;
    else 
        g_settings.BgType = g_settings.Default;
    
    g_settings.AccentBlurBehindClr = GetColorSetting(WindhawkUtils::StringSetting(Wh_GetStringSetting(L"BackgroundEffects.AccentBlurBehind")));

    g_settings.FlyoutsEffects = Wh_GetIntSetting(L"FlyoutsEffects");
        
    LoadWindowProcessRules();
    
    ApplyHooks();
}


#undef GetCurrentTime

// Global WinRT GUID/ABI declarations required by C++/WinRT.
template <> inline constexpr winrt::guid winrt::impl::guid_v<winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>>{
    winrt::impl::guid_v<winrt::Windows::Foundation::IPropertyValue>
};


// windows.graphics.effects.interop.h
#ifndef BUILD_WINDOWS
namespace ABI {
#endif
namespace Windows {
namespace Graphics {
namespace Effects {

typedef interface IGraphicsEffectSource                         IGraphicsEffectSource;
typedef interface IGraphicsEffectD2D1Interop                    IGraphicsEffectD2D1Interop;


typedef enum GRAPHICS_EFFECT_PROPERTY_MAPPING
{
    GRAPHICS_EFFECT_PROPERTY_MAPPING_UNKNOWN,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_DIRECT,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORX,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORY,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORZ,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_VECTORW,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_RECT_TO_VECTOR4,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_RADIANS_TO_DEGREES,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLORMATRIX_ALPHA_MODE,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR3,
    GRAPHICS_EFFECT_PROPERTY_MAPPING_COLOR_TO_VECTOR4
} GRAPHICS_EFFECT_PROPERTY_MAPPING;

//+-----------------------------------------------------------------------------
//
//  Interface:
//      IGraphicsEffectD2D1Interop
//
//  Synopsis:
//      An interface providing a Interop counterpart to IGraphicsEffect
//      and allowing for metadata queries.
//
//------------------------------------------------------------------------------

#undef INTERFACE
#define INTERFACE IGraphicsEffectD2D1Interop
DECLARE_INTERFACE_IID_(IGraphicsEffectD2D1Interop, IUnknown, "2FC57384-A068-44D7-A331-30982FCF7177")
{
    STDMETHOD(GetEffectId)(
        _Out_ GUID * id
        ) PURE;

    STDMETHOD(GetNamedPropertyMapping)(
        LPCWSTR name,
        _Out_ UINT * index,
        _Out_ GRAPHICS_EFFECT_PROPERTY_MAPPING * mapping
        ) PURE;

    STDMETHOD(GetPropertyCount)(
        _Out_ UINT * count
        ) PURE;

    STDMETHOD(GetProperty)(
        UINT index,
        _Outptr_ winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue> ** value
        ) PURE;

    STDMETHOD(GetSource)(
        UINT index,
        _Outptr_ IGraphicsEffectSource ** source
        ) PURE;

    STDMETHOD(GetSourceCount)(
        _Out_ UINT * count
        ) PURE;
};


} // namespace Effects
} // namespace Graphics
} // namespace Windows
#ifndef BUILD_WINDOWS
} // namespace ABI
#endif

template <> inline constexpr winrt::guid winrt::impl::guid_v<ABI::Windows::Graphics::Effects::IGraphicsEffectD2D1Interop>{
    0x2FC57384, 0xA068, 0x44D7, { 0xA3, 0x31, 0x30, 0x98, 0x2F, 0xCF, 0x71, 0x77 }
};




namespace FileExplorerStyler {


struct ThemeTargetStyles {
    PCWSTR target;
    std::vector<PCWSTR> styles;
};

enum class BackgroundTranslucentEffect {
    kDefault,
    kBlur,
    kAcrylic,
    kMica,
    kMicaAlt,
    kNone,
};

struct Theme {
    std::vector<ThemeTargetStyles> targetStyles;
    std::vector<PCWSTR> styleConstants;
    std::vector<PCWSTR> themeResourceVariables;
    int explorerFrameContainerHeight = 0;
    BackgroundTranslucentEffect backgroundTranslucentEffect =
        BackgroundTranslucentEffect::kDefault;
};

// clang-format off

const Theme g_themeTranslucent_Explorer11 = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness=0,0,0,1",
        L"BorderBrush=#40A0A0A0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas > Microsoft.UI.Xaml.Shapes.Path#SelectedBackgroundPath", {
        L"Fill=#40404040"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=<AcrylicBrush TintColor=\"#121212\" Opacity=\"0.3\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
}, {}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeMicaBar = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource LayerOnMicaBaseAltFillColorDefault}\"/>",
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
}};

const Theme g_themeNoCommandBar = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,1"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeMinimal_Explorer11 = {{
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root@CommonStates > Border#AppBarButtonInnerBorder", {
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.07\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Pressed:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Disabled:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root@CommonStates > Border#AppBarButtonInnerBorder", {
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Pressed:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Disabled:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>"}},
    ThemeTargetStyles{L"AppBarButton#refreshButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#upButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.AddressBarControl > Grid#PART_LayoutRoot > Grid#NormalModeGrid", {
        L"BorderThickness=0,0,0,1",
        L"BorderBrush=#A0A0A0"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,3,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=4",
        L"Margin=0,-3,0,3",
        L"Height=28"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>",
        L"Background@PointerOverSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.13\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PressedSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>"}},
    ThemeTargetStyles{L"Grid#FileExplorerAddressBarGrid", {
        L"Grid.ColumnSpan=2",
        L"Margin=0,0,10,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root", {
        L"Padding=2"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root", {
        L"Padding=2"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root > Grid#ContentRoot > Viewbox#ContentViewbox", {
        L"Margin=9"}},
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root > Grid#ContentRoot > Viewbox#ContentViewbox", {
        L"Margin=9"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"MinHeight=28",
        L"Height=28"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Margin=0,0,20,4"}},
    ThemeTargetStyles{L"Border#ScrollIncreaseButtonContainer", {
        L"Margin=0,0,0,4"}},
    ThemeTargetStyles{L"Border#ScrollDecreaseButtonContainer", {
        L"Margin=0,0,0,4"}},
    ThemeTargetStyles{L"Grid#FileExplorerAddressBarGrid", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl#NavigationBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Margin=100,0,0,-15",
        L"Grid.RowSpan=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl > Grid#NavigationBarControlGrid", {
        L"Margin=0,0,0,-18",
        L"Background=Transparent",
        L"Width=100",
        L"HorizontalAlignment=0"}},
}, {}, {}, /*explorerFrameContainerHeight=*/42};

const Theme g_themeTabless = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=$NavigationBarGrid"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=$CommandBarGrid"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid > Border", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer > Microsoft.UI.Xaml.Controls.Button#CloseButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Canvas", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource SystemChromeLowColor}\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.ContentPresenter > Microsoft.UI.Xaml.Controls.StackPanel > Microsoft.UI.Xaml.Controls.TextBlock", {
        L"FontFamily=Segoe UI, Segoe Fluent Icons",
        L"FontWeight=Normal"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Height=36"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Padding=1,0,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem", {
        L"Margin=0,-8,0,0"}},
}, {
    L"NavigationBarGrid=2",
    L"CommandBarGrid=1",
}};

const Theme g_themeMatter = {{
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment  = 1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Background=Transparent",
        L"Visibility = 1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=5",
        L"Margin=2,4,0,4",
        L"Height=29"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background = Transparent",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:= $accentColor2",
        L"Background@PointerOverSelected:= $accentColor",
        L"Background@PointerOver:= $accentColor2",
        L"Background@Normal=$accentColor",
        L"Background@PressedSelected:=$accentColor2",
        L"Background@Pressed := $accentColor2"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility  = 0",
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background :=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.4\" />",
        L"CornerRadius = 6",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Margin = 0,-5,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background :=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.4\" />",
        L"CornerRadius = 6",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Cut]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Copy]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Paste]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Rename]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Share]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#ScrollDecreaseButtonContainer", {
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#ScrollIncreaseButtonContainer", {
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Create a new item in the current location.]", {
        L"Visibility  = 1"}},
}, {
    L"accentColor=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" />",
    L"accentColor2=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.5\" />",
}};

const Theme g_themeWindowGlass = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#PART_LayoutRoot", {
        L"Background=Transparent",
        L"RenderTransform:=<TranslateTransform X=\"0\"/>"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FirstCrumbStackPanelControl#FirstCrumbStackPanel", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Grid#RootCommandSearchGrid > Windows.UI.Xaml.Controls.Border#BorderElement", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.NavigationViewItemPresenter#NavigationViewItemPresenter > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot", {
        L"BorderThickness=$BorderThickness",
        L"Background:=$ButtonBackground",
        L"BorderBrush:=$ButtonBorder"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar", {
        L"RenderTransform:=<TranslateTransform X=\"0\" Y=\"0\" />",
        L"HorizontalAlignment=Center",
        L"Margin=-4",
        L"Padding=10"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerSecondaryCommandBar", {
        L"RenderTransform:=<TranslateTransform X=\"Auto\" />",
        L"HorizontalAlignment=Center",
        L"Margin=-4",
        L"Padding=10",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"CornerRadius=$CornerRadius",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush=Transparent",
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerSecondaryCommandBar > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"CornerRadius=$CornerRadius",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"Background=#10808080",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"ColumnDefinitions:=<ColumnDefinitionCollection><ColumnDefinition Width=\"Auto\"/><ColumnDefinition Width=\"*\"/><ColumnDefinition Width=\"430\"/></ColumnDefinitionCollection>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"BorderBrush:=$MainContentBG",
        L"CornerRadius=8",
        L"BorderThickness=0",
        L"Margin=0,0,8,8",
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"BorderBrush:=$MainContentBG",
        L"CornerRadius=8",
        L"BorderThickness=0",
        L"Margin=0,0,8,8",
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid > Grid#GalleryRootGrid", {
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=$Background"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=8",
        L"Margin=5",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>",
        L"Background@PointerOverSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.13\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PressedSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.CommandBarFlyoutCommandBar > Grid#LayoutRoot > Grid#OuterContentRoot > Grid#ContentRoot > Grid#PrimaryItemsRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"Margin=0,0,0,-5",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Grid#OuterOverflowContentRootV2 > Grid#OverflowContentRoot > CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"MenuFlyoutPresenter > Border", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$CornerRadius",
        L"Margin=0,0,180,0",
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"MaxWidth=750",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#PART_AutoSuggestBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#NavigationCommands", {
        L"Margin=180,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#RootContainer", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border > Microsoft.UI.Xaml.Controls.Button#AddButton", {
        L"RenderTransform:=<TranslateTransform Y=\"-6\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TextBlock#TextLabel", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#SubItemChevronPanel > Microsoft.UI.Xaml.Controls.FontIcon#SubItemChevron", {
        L"RenderTransform:=<TranslateTransform X=\"-5\" Y=\"12\" />"}},
}, {
    L"Background=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15323232\"/>",
    L"BorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"{ThemeResource SystemChromeHighColor}\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SystemChromeLowColor}\" Offset=\"0.15\" /><GradientStop Color=\"{ThemeResource SystemChromeHighColor}\" Offset=\"0.95\" /></LinearGradientBrush>",
    L"BorderThickness=0.3,1,0.3,0.3",
    L"ButtonBackground=<SolidColorBrush Color=\"{ThemeResource SystemAccentColor}\" Opacity=\"1\" />",
    L"ButtonBorder=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight3}\" Opacity=\"1\" />",
    L"CornerRadius=8",
    L"Background2=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"0\" />",
    L"MainContentBG=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"1\" />",
}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeAddressSearchOnly = {{
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=0",
        L"Background=Transparent",
        L"MinHeight=48",
        L"Margin=0,26,0,1"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#refreshButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#upButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#backButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton", {
        L"Visibility=Collapsed"}},
}, {}, {}, /*explorerFrameContainerHeight=*/80};

const Theme g_themeTintedGlass = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=$CommonBgBrush",
        L"BorderThickness=0,0,0,0",
        L"BorderBrush=$CommonBgBrush"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas > Microsoft.UI.Xaml.Shapes.Path#SelectedBackgroundPath", {
        L"Fill:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background:=$CommonBgBrush"}},
}, {
    L"CommonBgBrush=<WindhawkBlur BlurAmount=\"18\" TintColor=\"#80000000\"/>",
}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeLiquidGlass = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#PART_LayoutRoot", {
        L"Background=Transparent",
        L"HorizontalAlignment=Stretch"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FirstCrumbStackPanelControl#FirstCrumbStackPanel", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Grid#RootCommandSearchGrid > Windows.UI.Xaml.Controls.Border#BorderElement", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.NavigationViewItemPresenter#NavigationViewItemPresenter > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot", {
        L"BorderThickness=$ElementBorderThickness",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorder",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background:=Transparent",
        L"BorderBrush:=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderThickness=$ElementBorderThickness",
        L"Margin=4,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderThickness=$ElementBorderThickness",
        L"Margin=4,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid > Grid#GalleryRootGrid", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"ToolTip", {
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Margin=5",
        L"Height=35",
        L"BorderThickness=$ElementBorderThickness",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderBrush:=$ElementBorderBrush"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=$ElementBackground",
        L"Background@PointerOverSelected:=$AccentBackground",
        L"Background@PointerOver:=$AccentBackground",
        L"Background@Normal:=$ElementBackground",
        L"Background@PressedSelected:=$ButtonBackground2"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Visibility=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$ElementBackground",
        L"BorderThickness=$ElementBorderThickness",
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$ElementCornerRadius",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"CornerRadius=$ElementCornerRadius",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#PART_AutoSuggestBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#RootContainer", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border > Microsoft.UI.Xaml.Controls.Button#AddButton", {
        L"RenderTransform:=<TranslateTransform Y=\"-8\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TextBlock#TextLabel", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#SubItemChevronPanel > Microsoft.UI.Xaml.Controls.FontIcon#SubItemChevron", {
        L"RenderTransform:=<TranslateTransform X=\"-5\" Y=\"12\" />"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Height = 28"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,1"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail", {
        L"Background:=Transparent"}},
}, {
    L"ContentBG=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"1\" />",
    L"Background=<WindhawkBlur BlurAmount=\"15\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.2\" />",
    L"ElementBackground=<WindhawkBlur BlurAmount=\"20\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.4\" />",
    L"ElementBackground2=<WindhawkBlur BlurAmount=\"20\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.2\" />",
    L"AccentBackground=<WindhawkBlur BlurAmount=\"15\" TintColor=\"{ThemeResource SystemAccentColorLight1}\" TintOpacity=\"0.2\" />",
    L"BorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"#50808080\" Offset=\"0.0\" /><GradientStop Color=\"#50404040\" Offset=\"0.25\" /><GradientStop Color=\"#50808080\" Offset=\"1\" /></LinearGradientBrush>",
    L"ElementBorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"#50808080\" Offset=\"1\" /><GradientStop Color=\"#50606060\" Offset=\"0.15\" /></LinearGradientBrush>",
    L"BorderThickness=0.3,1,0.3,0.3",
    L"ElementBorderThickness=0.3,0.3,0.3,1",
    L"CornerRadius=12",
    L"ElementCornerRadius=8",
}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeMicaTabless = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=$NavigationBarGrid"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=$CommandBarGrid"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid > Border", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer > Microsoft.UI.Xaml.Controls.Button#CloseButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Canvas", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource SystemChromeLowColor}\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.ContentPresenter > Microsoft.UI.Xaml.Controls.StackPanel > Microsoft.UI.Xaml.Controls.TextBlock", {
        L"FontFamily=Segoe UI, Segoe Fluent Icons",
        L"FontWeight=Normal"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Height=36"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Padding=1,0,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem", {
        L"Margin=0,-8,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background:="}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Microsoft.UI.Xaml.Controls.Grid", {
        L"Background:="}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"Background:="}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.StackPanel#DetailsViewThumbnail > Microsoft.UI.Xaml.Controls.Grid", {
        L"Background:="}},
}, {
    L"NavigationBarGrid=1",
    L"CommandBarGrid=2",
}};

const Theme g_themeOS26_Liquid_Glass = {{
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=12",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment=1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Background=Transparent",
        L"MinHeight=0"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=12",
        L"Margin=2,4,0,4",
        L"Height=27",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#35ffffff\" />",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15ffffff\" />"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,2",
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-6,0,0,0"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=14",
        L"BorderThickness=1",
        L"Margin=2",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=14",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#OuterOverflowContentRootV2", {
        L"CornerRadius=20"}},
    ThemeTargetStyles{L"Button#MoreButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Margin=0,9,9,0"}},
}};

const Theme g_themeOS26_Liquid_Glass_variant_Compact = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.SuggestionsPopup", {
        L"Margin=0,0,0,900"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=12",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Button#MoreButton", {
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,2,3,2",
        L"Width=45",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid > OuterOverflowContentRootV2", {
        L"CornerRadius=250"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter > Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter", {
        L"Background=transparent"}},
    ThemeTargetStyles{L"AppBarButton[7]", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0",
        L"Margin=0,0,0,0",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox > ContentViewB", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Grid.Row=0",
        L"Grid.RowSpan=1",
        L"CornerRadius:=15",
        L"Width=400",
        L"HorizontalAlignment=Left",
        L"Background:=transparent",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Grid#OverflowSeparator", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > ItemsControl#PrimaryItemsControl", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Visibility=Visible",
        L"Margin=0,40,0,-20"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Margin=370,1,0,1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=150",
        L"Height=40",
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2,2,0,2",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#20ffffff\"/>",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,4",
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=",
        L"BorderBrush:="}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates", {
        L"BorderThickness=1",
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=10",
        L"Margin=-90,0,90,0",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-8,0,90,0"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background=Transparent",
        L"CornerRadius=8",
        L"Margin=2,1,2,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,2,3,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#OuterOverflowContentRootV2", {
        L"CornerRadius=20"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility=Visible",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#stopButton", {
        L"Visibility=Collapsed",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeZEUSosX_044 = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness=0",
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"HorizontalAlignment=Left",
        L"VerticalAlignment=Top",
        L"Width=155",
        L"Margin=197,-30,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment=Left",
        L"VerticalAlignment=Top"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"ColumnDefinitions:=<ColumnDefinitionCollection><ColumnDefinition Width=\"Auto\"/><ColumnDefinition Width=\"*\"/><ColumnDefinition Width=\"380\"/></ColumnDefinitionCollection>",
        L"Margin=0,-16,0,-21"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Grid.Row=0",
        L"HorizontalAlignment=Left",
        L"Margin=100,0,0,0",
        L"Width=1",
        L"MaxWidth=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"HorizontalAlignment=Left",
        L"Margin=100,0,0,0",
        L"Width=1",
        L"MaxWidth=1"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"Margin=0,0,140,0",
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"TextAlignment=Center",
        L"HorizontalContentAlignment=Center"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"HorizontalAlignment=Stretch",
        L"Height=28",
        L"Margin=155,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox", {
        L"HorizontalAlignment=Stretch",
        L"Height=28",
        L"Margin=-7,-1,7,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar Button", {
        L"FontSize=14"}},
}, {}, {}, /*explorerFrameContainerHeight=*/44, BackgroundTranslucentEffect::kMica};

const Theme g_themeCompact_Explorer11 = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.SuggestionsPopup", {
        L"Margin=0,0,0,900"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=10",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Button#MoreButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=3,2,3,2",
        L"Width=45",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid > OuterOverflowContentRootV2", {
        L"CornerRadius=250"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter > Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter", {
        L"Background=transparent"}},
    ThemeTargetStyles{L"AppBarButton[7]", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0",
        L"Margin=0,0,0,0",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox > ContentViewB", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Grid.Row=0",
        L"Grid.RowSpan=1",
        L"CornerRadius:=15",
        L"Width=400",
        L"HorizontalAlignment=Left",
        L"Background:=transparent",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Grid#OverflowSeparator", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > ItemsControl#PrimaryItemsControl", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Visibility=Visible",
        L"Margin=0,40,0,-20"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Margin=370,1,0,1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=150",
        L"Height=40",
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2,2,0,2",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#30ffffff\"/>",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#40ffffff\"/>",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#20ffffff\"/>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,4",
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=0",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=",
        L"BorderBrush:="}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"Margin=-90,0,90,0",
        L"Height=30"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-8,0,90,0"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background=Transparent",
        L"CornerRadius=4",
        L"BorderThickness=0",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=3,2,3,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility=Visible",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#stopButton", {
        L"Visibility=Collapsed",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeFloat = {{
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.6\"/>",
        L"Background@PointerOverSelected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.7\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.3\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0\"/>",
        L"Background@PressedSelected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.9\"/>",
        L"CornerRadius=6"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"BorderThickness=1",
        L"Margin=2,0,0,0",
        L"Height=35"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"CornerRadius=4"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,3",
        L"CornerRadius=10",
        L"BorderThickness=0",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid", {
        L"Height=44"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"CornerRadius=6",
        L"Margin=8,4,8,0",
        L"Height=54"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Margin=0,8,0,0",
        L"BorderThickness=0,1,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.TabViewListView#TabListView", {
        L"Margin=-3,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=Collapsed"}},
}, {}, {
    L"Tab@Light=#ffffffff",
    L"Tab@Dark=#000000",
}, /*explorerFrameContainerHeight=*/160};

// clang-format on

enum class BackgroundTranslucentEffectRegion {
    kEntireWindow,
    kExplorerFrame,
};

enum class XamlDiagnosticsHandling {
    kAlert,
    kBlock,
    kAllow,
};

struct {
    std::optional<BackgroundTranslucentEffect> backgroundTranslucentEffect;
    BackgroundTranslucentEffectRegion backgroundTranslucentEffectRegion;
    int explorerFrameContainerHeight;
    XamlDiagnosticsHandling xamlDiagnosticsHandling;
} g_settings;

BackgroundTranslucentEffect g_themeBackgroundTranslucentEffect;
int g_themeExplorerFrameContainerHeight;

std::atomic<bool> g_initialized;
thread_local bool g_initializedForThread;

// An InstanceHandle is the address of an interface on the element, so it names
// an element only for as long as that element lives: an element allocated over
// a destroyed one is reported under the same handle. Everything the mod records
// is therefore keyed by an id minted per reported element, which is never
// reused, rather than by the handle itself.
enum class ElementId : uint64_t { None = 0 };

ElementId GetOrCreateElementId(
    InstanceHandle handle,
    winrt::Windows::Foundation::IInspectable const& element);
ElementId FindElementId(InstanceHandle handle);
void ForgetElementId(InstanceHandle handle);

void ApplyCustomizations(ElementId elementId,
                         winrt::Microsoft::UI::Xaml::FrameworkElement element,
                         PCWSTR fallbackClassName);
void CleanupCustomizations(ElementId elementId);
void QueueDiagnosticsRelease(InstanceHandle handle);
void FlushDiagnosticsReleasesIfQuiet();

HMODULE GetCurrentModuleHandle() {
    HMODULE module;
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                               GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                           L"", &module)) {
        return nullptr;
    }

    return module;
}

////////////////////////////////////////////////////////////////////////////////
// clang-format off

#pragma region winrt_hpp


// Alias some long namespaces for convenience. The WinRT headers are
// included at global scope, so explicitly refer to the global winrt namespace.
namespace wf = ::winrt::Windows::Foundation;
namespace mux = ::winrt::Microsoft::UI::Xaml;

// A weak reference for the object, or an empty one when the object is null or
// doesn't support weak references: cppwinrt's make_weak dereferences a null
// pointer for an object without that support instead of reporting it. Throws,
// as make_weak does, when the object supports weak references but one can't be
// made.
winrt::weak_ref<wf::IInspectable> TryMakeWeak(wf::IInspectable const& object)
{
    if (!object.try_as<::IWeakReferenceSource>())
    {
        return nullptr;
    }

    return winrt::make_weak(object);
}

#pragma endregion  // winrt_hpp

#pragma region visualtreewatcher_hpp


// XamlDiagnostics implements this interface too, and xamlom.h does not declare
// it. UnregisterInstance closes the runtime object cached for a handle, the
// only reference the diagnostics keep to an element once it was reported.
static constexpr GUID IID_IXamlDiagnosticsTestHooks =
    {0x735941a2, 0x3ee3, 0x495a, {0x8d, 0xa9, 0x97, 0x26, 0x27, 0x00, 0x30, 0x75}};

struct IXamlDiagnosticsTestHooks : IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE UnregisterInstance(InstanceHandle handle) = 0;
    virtual HRESULT STDMETHODCALLTYPE TryGetDispatcherQueueForObject(InstanceHandle handle, void** dispatcherQueue) = 0;
};

// The handle a mutation callback would report for an element, for elements
// which were reached some other way, e.g. by walking the visual tree. Derived
// the way the diagnostics derive it, by querying IInspectable and taking the
// pointer, and not through GetHandleFromIInspectable: that one creates the
// runtime object when none is cached, so asking it about an element whose
// reference was released would take a new reference and pin it again.
InstanceHandle HandleFromInspectable(wf::IInspectable const& instance)
{
    winrt::com_ptr<::IInspectable> inspectable;
    winrt::check_hresult(reinterpret_cast<::IUnknown*>(winrt::get_abi(instance))->QueryInterface(winrt::guid_of<wf::IInspectable>(), inspectable.put_void()));
    return reinterpret_cast<InstanceHandle>(inspectable.get());
}

class VisualTreeWatcher : public winrt::implements<VisualTreeWatcher, IVisualTreeServiceCallback2, winrt::non_agile>
{
public:
    VisualTreeWatcher(winrt::com_ptr<IUnknown> site);

    VisualTreeWatcher(const VisualTreeWatcher&) = delete;
    VisualTreeWatcher& operator=(const VisualTreeWatcher&) = delete;

    VisualTreeWatcher(VisualTreeWatcher&&) = delete;
    VisualTreeWatcher& operator=(VisualTreeWatcher&&) = delete;

    ~VisualTreeWatcher();

    void UnadviseVisualTreeChange();

    bool ReleaseDiagnosticsReference(InstanceHandle handle);

private:
    HRESULT STDMETHODCALLTYPE OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) override;
    HRESULT STDMETHODCALLTYPE OnElementStateChanged(InstanceHandle element, VisualElementState elementState, LPCWSTR context) noexcept override;

    wf::IInspectable FromHandle(InstanceHandle handle)
    {
        wf::IInspectable obj;
        winrt::check_hresult(m_XamlDiagnostics->GetIInspectableFromHandle(handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(obj))));
        return obj;
    }

    winrt::com_ptr<IXamlDiagnostics> m_XamlDiagnostics = nullptr;
    winrt::com_ptr<IXamlDiagnosticsTestHooks> m_XamlDiagnosticsTestHooks = nullptr;
};

#pragma endregion  // visualtreewatcher_hpp

#pragma region visualtreewatcher_cpp

VisualTreeWatcher::VisualTreeWatcher(winrt::com_ptr<IUnknown> site) :
    m_XamlDiagnostics(site.as<IXamlDiagnostics>())
{
    Wh_Log(L"Constructing VisualTreeWatcher");

    HRESULT hr = m_XamlDiagnostics->QueryInterface(IID_IXamlDiagnosticsTestHooks, m_XamlDiagnosticsTestHooks.put_void());
    if (FAILED(hr)) {
        Wh_Log(L"IXamlDiagnosticsTestHooks is unavailable, elements will be leaked: %08X", hr);
    }

    // winrt::check_hresult(m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(this));

    // Calling AdviseVisualTreeChange from the current thread causes the app to
    // hang in Advising::RunOnUIThread sometimes. Creating a new thread and
    // calling it from there fixes it.
    HANDLE thread = CreateThread(
        nullptr, 0,
        [](LPVOID lpParam) -> DWORD {
            auto watcher = reinterpret_cast<VisualTreeWatcher*>(lpParam);
            HRESULT hr = watcher->m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(watcher);
            watcher->Release();
            if (FAILED(hr)) {
                Wh_Log(L"Error %08X", hr);
            }
            return 0;
        },
        this, 0, nullptr);
    if (thread) {
        AddRef();
        CloseHandle(thread);
    }
}

VisualTreeWatcher::~VisualTreeWatcher()
{
    Wh_Log(L"Destructing VisualTreeWatcher");
}

void VisualTreeWatcher::UnadviseVisualTreeChange()
{
    Wh_Log(L"UnadviseVisualTreeChange VisualTreeWatcher");
    HRESULT hr = m_XamlDiagnostics.as<IVisualTreeService3>()->UnadviseVisualTreeChange(this);
    if (FAILED(hr)) {
        Wh_Log(L"UnadviseVisualTreeChange failed with error %08X", hr);
    }
}

// Reports whether dropping the reference destroyed the element, which is what
// tells the caller that the handle is free to name a different element from now
// on and that the id recorded for this one has to go.
bool VisualTreeWatcher::ReleaseDiagnosticsReference(InstanceHandle handle)
{
    if (!m_XamlDiagnosticsTestHooks) {
        return false;
    }

    winrt::weak_ref<wf::IInspectable> weakElement;
    {
        // Not through FromHandle: a handle whose runtime object is already gone
        // fails to resolve routinely, and throwing for it would pay for an
        // originate with a stack capture every time. The strong reference has
        // to be gone again before the release below, hence the scope.
        wf::IInspectable element;
        HRESULT hr = m_XamlDiagnostics->GetIInspectableFromHandle(handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(element)));
        if (SUCCEEDED(hr) && element) {
            try {
                weakElement = TryMakeWeak(element);
            } catch (...) {
                Wh_Log(L"Error %08X", winrt::to_hresult());
            }
        }
    }

    HRESULT hr = m_XamlDiagnosticsTestHooks->UnregisterInstance(handle);
    if (FAILED(hr)) {
        Wh_Log(L"UnregisterInstance failed with error %08X", hr);
        return false;
    }

    // Not every reported object supports weak references, and then the release
    // just proceeds unobserved.
    return weakElement && !weakElement.get();
}

HRESULT VisualTreeWatcher::OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) try
{
    Wh_Log(L"========================================");

    switch (mutationType)
    {
    case Add:
        Wh_Log(L"Mutation type: Add %llu", element.Handle);
        break;

    case Remove:
        Wh_Log(L"Mutation type: Remove %llu", element.Handle);
        break;

    default:
        Wh_Log(L"Mutation type: %d %llu", static_cast<int>(mutationType), element.Handle);
        break;
    }

    Wh_Log(L"Element type: %s", element.Type);

    if (!g_initializedForThread)
    {
        Wh_Log(L"Not initialized for thread %u", GetCurrentThreadId());
        return S_OK;
    }

    // Caught here rather than by the handler below, so that the bookkeeping
    // which hands the element's reference back still runs when the styling work
    // throws. Otherwise a single failed element would be held for good.
    try
    {
        if (mutationType == Add)
        {
            const auto inspectable = FromHandle(element.Handle);
            auto elementId = GetOrCreateElementId(element.Handle, inspectable);
            auto frameworkElement = inspectable.try_as<mux::FrameworkElement>();
            if (frameworkElement)
            {
                Wh_Log(L"FrameworkElement name: %s", frameworkElement.Name().c_str());
                if (elementId == ElementId::None)
                {
                    Wh_Log(L"Skipping element which can't be given an id");
                }
                else
                {
                    ApplyCustomizations(elementId, frameworkElement, element.Type);
                }
            }
            else
            {
                Wh_Log(L"Skipping non-FrameworkElement");
            }
        }
        else if (mutationType == Remove)
        {
            CleanupCustomizations(FindElementId(element.Handle));
        }
    }
    catch (...)
    {
        Wh_Log(L"Error %08X", winrt::to_hresult());
    }

    // A tree discarded whole is never dismantled, so it reports no removals to
    // be released by.
    FlushDiagnosticsReleasesIfQuiet();

    if (mutationType == Add)
    {
        QueueDiagnosticsRelease(element.Handle);
        QueueDiagnosticsRelease(relation.Parent);
    }
    else if (mutationType == Remove)
    {
        // Queued rather than released outright: this report arrives from inside
        // the Leave walk which is still visiting the subtree being removed.
        QueueDiagnosticsRelease(element.Handle);
        ForgetElementId(element.Handle);
    }

    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);

    // Returning an error prevents (some?) further messages, always return
    // success.
    // return hr;
    return S_OK;
}

HRESULT VisualTreeWatcher::OnElementStateChanged(InstanceHandle, VisualElementState, LPCWSTR) noexcept
{
    return S_OK;
}

#pragma endregion  // visualtreewatcher_cpp

#pragma region tap_hpp


// Read by the UI threads while the thread which injects or uninitializes the TAP
// replaces it.
[[clang::no_destroy]] winrt::com_ptr<VisualTreeWatcher> g_visualTreeWatcher;
SRWLOCK g_visualTreeWatcherLock = SRWLOCK_INIT;

// {C85D8CC7-5463-40E8-A432-F5916B6427E5}
static constexpr CLSID CLSID_WindhawkTAP = { 0xc85d8cc7, 0x5463, 0x40e8, { 0xa4, 0x32, 0xf5, 0x91, 0x6b, 0x64, 0x27, 0xe5 } };

class WindhawkTAP : public winrt::implements<WindhawkTAP, IObjectWithSite, winrt::non_agile>
{
public:
    HRESULT STDMETHODCALLTYPE SetSite(IUnknown *pUnkSite) override;
    HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, void **ppvSite) noexcept override;

private:
    winrt::com_ptr<IUnknown> site;
};

#pragma endregion  // tap_hpp

#pragma region tap_cpp

winrt::com_ptr<VisualTreeWatcher> GetVisualTreeWatcher()
{
    AcquireSRWLockShared(&g_visualTreeWatcherLock);
    auto watcher = g_visualTreeWatcher;
    ReleaseSRWLockShared(&g_visualTreeWatcherLock);
    return watcher;
}

// Hands the previous watcher back to be unadvised and released outside the
// lock: both can wait on the UI threads, which take it.
winrt::com_ptr<VisualTreeWatcher> ExchangeVisualTreeWatcher(winrt::com_ptr<VisualTreeWatcher> watcher)
{
    AcquireSRWLockExclusive(&g_visualTreeWatcherLock);
    std::swap(g_visualTreeWatcher, watcher);
    ReleaseSRWLockExclusive(&g_visualTreeWatcherLock);
    return watcher;
}

HRESULT WindhawkTAP::SetSite(IUnknown *pUnkSite) try
{
    // Only ever 1 VTW at once.
    if (auto previous = ExchangeVisualTreeWatcher(nullptr))
    {
        previous->UnadviseVisualTreeChange();
    }

    site.copy_from(pUnkSite);

    if (site)
    {
        // Decrease refcount increased by InitializeXamlDiagnosticsEx.
        FreeLibrary(GetCurrentModuleHandle());

        ExchangeVisualTreeWatcher(winrt::make_self<VisualTreeWatcher>(site));
    }

    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

HRESULT WindhawkTAP::GetSite(REFIID riid, void **ppvSite) noexcept
{
    return site.as(riid, ppvSite);
}

#pragma endregion  // tap_cpp

#pragma region simplefactory_hpp


template<class T>
struct SimpleFactory : winrt::implements<SimpleFactory<T>, IClassFactory, winrt::non_agile>
{
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override try
    {
        if (!pUnkOuter)
        {
            *ppvObject = nullptr;
            return winrt::make<T>().as(riid, ppvObject);
        }
        else
        {
            return CLASS_E_NOAGGREGATION;
        }
    }
    catch (...)
    {
        HRESULT hr = winrt::to_hresult();
        Wh_Log(L"Error %08X", hr);
        return hr;
    }

    HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override
    {
        return S_OK;
    }
};

#pragma endregion  // simplefactory_hpp

#pragma region module_cpp


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdll-attribute-on-redeclaration"

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) try
{
    if (rclsid == CLSID_WindhawkTAP)
    {
        *ppv = nullptr;
        return winrt::make<SimpleFactory<WindhawkTAP>>().as(riid, ppv);
    }
    else
    {
        return CLASS_E_CLASSNOTAVAILABLE;
    }
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllCanUnloadNow()
{
    if (winrt::get_module_lock())
    {
        return S_FALSE;
    }
    else
    {
        return S_OK;
    }
}

#pragma clang diagnostic pop

#pragma endregion  // module_cpp

#pragma region api_cpp

bool g_inInjectWindhawkTAP = false;

using PFN_INITIALIZE_XAML_DIAGNOSTICS_EX = decltype(&InitializeXamlDiagnosticsEx);

HRESULT InjectWindhawkTAP() noexcept
{
    HMODULE module = GetCurrentModuleHandle();
    if (!module)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR location[MAX_PATH];
    switch (GetModuleFileName(module, location, ARRAYSIZE(location)))
    {
    case 0:
    case ARRAYSIZE(location):
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const HMODULE wux(GetModuleHandle(L"Microsoft.Internal.FrameworkUdk.dll"));
    if (!wux) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const auto ixde = reinterpret_cast<PFN_INITIALIZE_XAML_DIAGNOSTICS_EX>(GetProcAddress(wux, "InitializeXamlDiagnosticsEx"));
    if (!ixde) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    // I didn't find a better way than trying many connections until one works.
    // Reference:
    // https://github.com/microsoft/microsoft-ui-xaml/blob/d74a0332cf0d5e58f12eddce1070fa7a79b4c2db/src/dxaml/xcp/dxaml/lib/DXamlCore.cpp#L2782
    g_inInjectWindhawkTAP = true;

    HRESULT hr;
    for (int i = 0; i < 10000; i++)
    {
        WCHAR connectionName[256];
        wsprintf(connectionName, L"WinUIVisualDiagConnection%d", i + 1);

        hr = ixde(connectionName, GetCurrentProcessId(), L"", location, CLSID_WindhawkTAP, nullptr);
        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
        {
            break;
        }
    }

    g_inInjectWindhawkTAP = false;

    return hr;
}

#pragma endregion  // api_cpp

// clang-format on
////////////////////////////////////////////////////////////////////////////////



using namespace std::string_view_literals;




using namespace winrt::Microsoft::UI::Xaml;

namespace muxc = winrt::Microsoft::UI::Xaml::Controls;
namespace wge = ::winrt::Windows::Graphics::Effects;
namespace muc = ::winrt::Microsoft::UI::Composition;
namespace muxh = mux::Hosting;
namespace awge = ::ABI::Windows::Graphics::Effects;

// https://stackoverflow.com/a/51274008
template <auto fn>
struct deleter_from_fn {
    template <typename T>
    constexpr void operator()(T* arg) const {
        fn(arg);
    }
};
using string_setting_unique_ptr =
    std::unique_ptr<const WCHAR[], deleter_from_fn<Wh_FreeStringSetting>>;

using PropertyKeyValue =
    std::pair<DependencyProperty, winrt::Windows::Foundation::IInspectable>;

using PropertyValuesUnresolved =
    std::vector<std::pair<std::wstring, std::wstring>>;
using PropertyValues = std::vector<PropertyKeyValue>;
using PropertyValuesMaybeUnresolved =
    std::variant<PropertyValuesUnresolved, PropertyValues>;

struct ElementMatcher {
    enum class Kind {
        Element,   // Normal element matcher.
        Wildcard,  // '*': matches zero or more intermediate ancestors.
        Root,      // ':root': asserts the next element has no parent.
    };
    Kind kind = Kind::Element;
    std::wstring type;
    std::wstring name;
    std::optional<std::wstring> visualStateGroupName;
    int oneBasedIndex = 0;
    PropertyValuesMaybeUnresolved propertyValues;
};

// A `Property[@VisualState][:]=value` rule that sets a control property.
// `value` may contain `{{...}}` placeholders, in which case `isDynamic()`
// returns true and the rule is re-resolved on every apply.
struct ValueRule {
    std::wstring propertyName;
    std::wstring visualState;
    std::wstring value;
    bool isXamlValue = false;

    bool isDynamic() const { return value.find(L"{{") != std::wstring::npos; }
};

// A `Property=>VarName` rule that observes a control property and writes its
// current value into the named mod-global style variable.
struct CaptureRule {
    std::wstring propertyName;
    std::wstring varName;
};

// Parsed-but-not-yet-resolved rules for one target. Captures and value-rules
// are intentionally split: they live in different fields of `ResolvedRules`
// post-resolution, and the parser already validates that captures cannot carry
// `:=` or `@VisualState`.
struct UnresolvedRules {
    std::vector<ValueRule> valueRules;
    std::vector<CaptureRule> captureRules;
};

struct XamlBlurBrushParams {
    float blurAmount;
    winrt::Windows::UI::Color tint;
    std::optional<uint8_t> tintOpacity;
    std::wstring tintThemeResourceKey;  // Empty if not from ThemeResource
    std::optional<float> tintLuminosityOpacity;
    std::optional<float> tintSaturation;
    std::optional<float> noiseOpacity;
    std::optional<float> noiseDensity;
    std::optional<winrt::Windows::UI::Color> fallbackColor;
    std::wstring fallbackThemeResourceKey;  // Empty if not from ThemeResource
};

// Holds the raw rule body for a style whose value depends on `{{...}}`
// substitutions. Re-resolved on every apply and on every variable change.
// `propertyName` is kept alongside the value because Windows.UI.Xaml's
// DependencyProperty does not expose its name, and the re-resolution path needs
// to feed the name back to the XAML parser.
struct DynamicStyleTemplate {
    std::wstring propertyName;
    std::wstring rawValue;
    bool isXamlValue = false;
};

// Tagged value for one (property, visualState) cell of PropertyOverrides.
// Possible states:
// - IInspectable        : fully resolved WinRT value (literal or static XAML).
//                         Apply directly via SetValue.
// - XamlBlurBrushParams : parsed `<WindhawkBlur .../>` parameters. The brush
//                         instance is constructed at apply time (needs the live
//                         UIElement).
// - DynamicStyleTemplate: rule body contains `{{...}}` substitutions.
//                         Re-resolved on every apply and on every variable
//                         change. This arm appears only inside
//                         PropertyOverrides cells; it is never stored in
//                         ElementPropertyCustomizationState::customValue (see
//                         notes there).
using PropertyOverrideValue =
    std::variant<winrt::Windows::Foundation::IInspectable,
                 XamlBlurBrushParams,
                 DynamicStyleTemplate>;

// Property -> visual state -> value.
using PropertyOverrides =
    std::unordered_map<DependencyProperty,
                       std::unordered_map<std::wstring, PropertyOverrideValue>>;

// Resolved counterpart to CaptureRule: the property name string has been turned
// into an actual DependencyProperty by the XAML parser, so the apply path can
// call RegisterPropertyChangedCallback / GetValue directly without re-resolving
// on every use.
struct CaptureSpec {
    DependencyProperty property{nullptr};
    std::wstring varName;
};

struct ResolvedRules {
    PropertyOverrides propertyOverrides;
    std::vector<CaptureSpec> captures;
    // Whether this target consumes style variables. Lets ApplyCustomizations
    // skip the visual-tree bookkeeping that only variable users need.
    bool hasDynamicValues = false;
};

using PropertyOverridesMaybeUnresolved =
    std::variant<UnresolvedRules, ResolvedRules>;

// A `{{Var}}` reference resolved for one consuming property. The owner lets a
// value change on some other capture of the same name be skipped.
struct StyleVariableDependency {
    std::wstring name;
    ElementId owner = ElementId::None;  // None when the variable was undefined
};

// Interned node of an element's visual-tree spine. Nodes are shared by every
// tracked element under the same ancestor, so the pool holds one node per
// distinct ancestor rather than a full path per element. Once a node exists its
// `parent` and `depth` are final; an element that is later reparented keeps the
// spine it was first seen with, and only the nodes of a spine interned before
// its root object was attached (see GetOrCreateElementTreeNode) are ever
// replaced.
struct ElementTreeNode {
    // A node can outlive the object it describes -- descendant nodes and
    // not-yet-cleaned-up ElementCustomizationState entries keep it alive -- so
    // this is what proves a pool hit isn't a recycled address.
    winrt::weak_ref<DependencyObject> ref;
    std::shared_ptr<ElementTreeNode> parent;
    uint32_t depth = 0;
    // The depth-0 node this spine hangs from, `this` for a root itself. The
    // parent chain keeps it alive, so a raw pointer is enough.
    ElementTreeNode* root = nullptr;
};

// Keyed by the object's IUnknown pointer: COM only guarantees a stable pointer
// for that interface, and the same element is reached both as a
// FrameworkElement and as a VisualTreeHelper::GetParent result.
thread_local std::unordered_map<void*, std::weak_ptr<ElementTreeNode>>
    g_elementTreeNodes;

// Expired pool entries are reaped once the map grows past this, which is then
// set to twice the surviving size, making the sweep amortized O(1).
thread_local size_t g_elementTreeNodesReapThreshold = 64;

void* ElementIdentityKey(DependencyObject const& object) {
    return winrt::get_abi(object.as<winrt::Windows::Foundation::IUnknown>());
}

// A depth-0 node is a placeholder root until proven otherwise: if its object
// has since gained a parent, the spine was interned before that object was
// attached and stops short of the real root. Asked of any node on the spine,
// not just of the root itself, so that a descendant interned through a
// placeholder root is repaired too.
bool IsStaleSpine(ElementTreeNode const& node) {
    auto object = node.root->ref.get();
    return object && Media::VisualTreeHelper::GetParent(object);
}

// Fetch (or build) the spine node for `object`. Uses
// VisualTreeHelper::GetParent rather than Parent(), same reason as in
// FindElementPropertyOverrides. Returns nullptr if a node can't be built,
// leaving callers with no proximity information rather than a wrong answer.
std::shared_ptr<ElementTreeNode> GetOrCreateElementTreeNode(
    DependencyObject object) {
    if (!object) {
        return nullptr;
    }

    std::shared_ptr<ElementTreeNode> node;

    // Ancestors still lacking a node, innermost first. The walk stops at the
    // first ancestor that is already interned, so a new sibling of an
    // already-seen element costs one GetParent call.
    std::vector<DependencyObject> missing;

    try {
        for (auto iter = object; iter;
             iter = Media::VisualTreeHelper::GetParent(iter)) {
            auto key = ElementIdentityKey(iter);

            if (auto it = g_elementTreeNodes.find(key);
                it != g_elementTreeNodes.end()) {
                auto existing = it->second.lock();
                // A weak_ref never resolves to an object other than its own, so
                // a live ref proves this address hasn't been recycled since.
                if (!existing || !existing->ref.get()) {
                    Wh_Log(L"Replacing stale tree node for a reused address");
                    g_elementTreeNodes.erase(it);
                } else if (!IsStaleSpine(*existing)) {
                    node = std::move(existing);
                    break;
                } else {
                    // Drop the node and keep walking: the ancestors above it
                    // are stale for the same reason, up to the placeholder
                    // root, above which the real spine gets built. A stale
                    // shared_ptr already cached elsewhere (see
                    // EnsureElementTreeNode) is refreshed the same way on its
                    // own next use, so no element is stuck unrankable.
                    Wh_Log(L"Rebuilding tree node interned before attachment");
                    g_elementTreeNodes.erase(it);
                }
            }

            missing.push_back(iter);
        }

        for (auto it = missing.rbegin(); it != missing.rend(); ++it) {
            auto fresh = std::make_shared<ElementTreeNode>();
            fresh->ref = *it;
            fresh->depth = node ? node->depth + 1 : 0;
            fresh->root = node ? node->root : fresh.get();
            fresh->parent = std::move(node);
            g_elementTreeNodes[ElementIdentityKey(*it)] = fresh;
            node = std::move(fresh);
        }
    } catch (winrt::hresult_error const& ex) {
        Wh_Log(L"Error %08X: %s", ex.code(), ex.message().c_str());
        return nullptr;
    }

    return node;
}

void ReapElementTreeNodesIfNeeded() {
    if (g_elementTreeNodes.size() < g_elementTreeNodesReapThreshold) {
        return;
    }

    std::erase_if(g_elementTreeNodes,
                  [](const auto& item) { return item.second.expired(); });
    g_elementTreeNodesReapThreshold =
        std::max<size_t>(64, g_elementTreeNodes.size() * 2);
}

// Depth of the lowest common ancestor of two spine nodes, or -1 when they have
// none (separate visual trees, or a node that couldn't be built). A node counts
// as its own ancestor, so an element on the other's parent chain scores its own
// depth -- the deepest score that element can reach.
int ElementTreeLcaDepth(ElementTreeNode const* a, ElementTreeNode const* b) {
    if (!a || !b) {
        return -1;
    }

    while (a->depth > b->depth) {
        a = a->parent.get();
    }
    while (b->depth > a->depth) {
        b = b->parent.get();
    }

    while (a != b) {
        a = a->parent.get();
        b = b->parent.get();
        if (!a || !b) {
            return -1;
        }
    }

    return static_cast<int>(a->depth);
}

struct ElementCustomizationRules {
    ElementMatcher elementMatcher;
    std::vector<ElementMatcher> parentElementMatchers;
    PropertyOverridesMaybeUnresolved propertyOverrides;
};

thread_local std::vector<ElementCustomizationRules>
    g_elementsCustomizationRules;

struct ElementPropertyCustomizationState {
    std::optional<winrt::Windows::Foundation::IInspectable> originalValue;
    // The most recently applied value, re-pushed by the per-DP property-
    // changed callback when something external (animation, system Setter)
    // overrides it. Although PropertyOverrideValue's variant declares a
    // DynamicStyleTemplate arm, customValue here is always either IInspectable
    // or XamlBlurBrushParams in practice -- dynamic styles get resolved into
    // one of those before being stored, and the source template lives
    // separately in `dynamicTemplate` below.
    std::optional<PropertyOverrideValue> customValue;
    // The value SetOrClearValue wrote for customValue, which is what a write
    // by something else is told apart from.
    winrt::Windows::Foundation::IInspectable lastAppliedValue{nullptr};
    int64_t propertyChangedToken = 0;
    // Source template for dynamic styles whose value contains `{{...}}`
    // substitutions; re-evaluated whenever a referenced variable changes, with
    // the resolved result written back into `customValue`. Empty for static
    // styles.
    std::optional<DynamicStyleTemplate> dynamicTemplate;
    // Style variables this property's value depends on, each with the capture
    // that supplied it. Populated alongside `dynamicTemplate`; empty for static
    // styles.
    std::vector<StyleVariableDependency> variableDependencies;
    // Makes this property re-resolve on any change to any of its variables:
    // expansion aborts at the first failure, so the names past that point have
    // no recorded owner and a targeted propagation would never reach them.
    bool lastResolveFailed = false;
};

struct CapturePropertyCustomizationState {
    std::wstring varName;
    int64_t propertyChangedToken = 0;
};

struct ElementCustomizationStateForVisualStateGroup {
    std::unordered_map<DependencyProperty, ElementPropertyCustomizationState>
        propertyCustomizationStates;
    winrt::event_token visualStateGroupCurrentStateChangedToken;
};

struct ElementCustomizationState {
    winrt::weak_ref<FrameworkElement> element;

    // Scores how close each capture of a style variable is to this element.
    // Only built for elements that capture or consume a variable.
    std::shared_ptr<ElementTreeNode> treeNode;

    // Capture state lives at the element level: capture rules (`Prop=>Var`) are
    // intentionally not visual-state-aware (the parser rejects `@VisualState`
    // on them), and a single element observed by multiple targets with
    // different VSGs should still only register one
    // RegisterPropertyChangedCallback per DP and one SizeChanged subscription.
    std::unordered_map<DependencyProperty, CapturePropertyCustomizationState>
        captureCustomizationStates;

    // ActualWidth/ActualHeight (and other layout-driven DPs) do not fire
    // RegisterPropertyChangedCallback on UWP, so any element with capture rules
    // also subscribes to `FrameworkElement.SizeChanged` to pick up size
    // changes.
    winrt::event_token captureSizeChangedToken;

    // Use list to avoid reallocations on insertion, as pointers to items are
    // captured in callbacks and stored.
    std::list<std::pair<std::optional<winrt::weak_ref<VisualStateGroup>>,
                        ElementCustomizationStateForVisualStateGroup>>
        perVisualStateGroup;
};

thread_local std::unordered_map<ElementId, ElementCustomizationState>
    g_elementsCustomizationState;

// The weak reference is what keeps an id honest. A handle is an address, so a
// destroyed element can be replaced by one reporting the same handle, and an
// entry whose element is gone, or is no longer the element being asked about,
// belongs to that destroyed predecessor and must not name the new one.
struct ElementIdEntry {
    ElementId id = ElementId::None;
    winrt::weak_ref<wf::IInspectable> element;
};

thread_local std::unordered_map<InstanceHandle, ElementIdEntry> g_elementIds;
thread_local uint64_t g_lastElementId;

ElementId GetOrCreateElementId(InstanceHandle handle,
                               wf::IInspectable const& element) {
    if (!handle || !element) {
        return ElementId::None;
    }

    auto& entry = g_elementIds[handle];
    if (entry.id != ElementId::None && entry.element.get() == element) {
        return entry.id;
    }

    entry.id = static_cast<ElementId>(++g_lastElementId);

    winrt::weak_ref<wf::IInspectable> weakElement;
    try {
        weakElement = TryMakeWeak(element);
    } catch (winrt::hresult_error const& ex) {
        Wh_Log(L"Error %08X: %s", ex.code(), ex.message().c_str());
    }

    if (!weakElement) {
        // Without a weak reference the entry cannot be told apart from one for
        // a successor at the same address, so neither it nor the id it names is
        // kept: an id no lookup can reach again would key state that nothing
        // could ever tear down, on an element nothing would then hold back from
        // being released.
        g_elementIds.erase(handle);
        return ElementId::None;
    }

    entry.element = std::move(weakElement);
    return entry.id;
}

// By handle alone, for the element which is being reported as removed: it is
// the element the entry was made for, and a stale entry names something already
// destroyed, whose state is due for teardown either way.
ElementId FindElementId(InstanceHandle handle) {
    auto it = g_elementIds.find(handle);
    return it != g_elementIds.end() ? it->second.id : ElementId::None;
}

void ForgetElementId(InstanceHandle handle) {
    g_elementIds.erase(handle);
}

// Dead entries are reaped once the map grows past this, which is then set to
// twice the surviving size, making the sweep amortized O(1).
thread_local size_t g_elementIdsReapThreshold = 64;

// An element whose diagnostics reference was handed back is destroyed without a
// removal being reported for it, so what the mod keys by that element has to be
// found rather than told. An entry whose weak reference no longer resolves
// names such an element, and is torn down the way its removal would have.
void ReapDeadElementIdsIfNeeded() {
    if (g_elementIds.size() < g_elementIdsReapThreshold) {
        return;
    }

    // Collected before anything is torn down: CleanupCustomizations runs XAML
    // work which can re-enter ApplyCustomizations and rehash the map.
    std::vector<std::pair<InstanceHandle, ElementId>> dead;
    for (const auto& [handle, entry] : g_elementIds) {
        if (!entry.element.get()) {
            dead.push_back({handle, entry.id});
        }
    }

    if (!dead.empty()) {
        Wh_Log(L"Reaping %zu of %zu element ids", dead.size(),
               g_elementIds.size());
    }

    for (const auto& [handle, elementId] : dead) {
        CleanupCustomizations(elementId);
        g_elementIds.erase(handle);
    }

    g_elementIdsReapThreshold = std::max<size_t>(64, g_elementIds.size() * 2);
}

// The element's spine node. An element can be matched before its subtree is
// attached, in which case the eager build in ApplyCustomizations interns a
// spine that stops at a placeholder root; re-checked on every use so it's
// rebuilt once the subtree is actually in the tree.
ElementTreeNode* EnsureElementTreeNode(
    ElementCustomizationState& elementCustomizationState) {
    if (!elementCustomizationState.treeNode ||
        IsStaleSpine(*elementCustomizationState.treeNode)) {
        if (auto element = elementCustomizationState.element.get()) {
            elementCustomizationState.treeNode =
                GetOrCreateElementTreeNode(element);
        }
    }

    return elementCustomizationState.treeNode.get();
}

// Mod-global style variable registry. Populated by `Property=>VarName` capture
// rules and consumed by `{{VarName}}` substitutions in other styles. Every
// capturing element gets its own entry, so a name stays defined until its last
// capture goes away, and a consumer reading the name resolves to whichever
// capture is closest to it in the visual tree.
struct StyleVariableValue {
    std::wstring stringForm;        // invariant-formatted text representation
    std::optional<double> numeric;  // only present when source was numeric
    // True for primitive captures whose `stringForm` is meaningful to insert
    // verbatim into a XAML attribute (numeric, boolean, string). False for
    // opaque types -- their stringForm is the captured class name, kept only
    // for diagnostics; bare-identifier substitution skips such variables.
    bool substitutable = false;
};

// One element's capture of a variable. FindElementPropertyOverrides dedupes
// captures by name, so (name, elementId) identifies an entry.
struct StyleVariableCapture {
    ElementId elementId;
    StyleVariableValue value;
};

struct StyleVariableConsumer {
    ElementId elementId;
    DependencyProperty property{nullptr};
    // Each consumer remembers its own fallbackClassName so that propagation can
    // re-resolve dynamic styles using the consumer's match-site context, not
    // the (potentially different) capturer's.
    std::wstring fallbackClassName;
};

// Mod-global style variable registry. The struct mirrors the per-XamlRoot state
// used by the taskbar styler so the variable-resolution call paths stay aligned
// across the styler mods, but here all elements share one registry.
struct StyleVariableState {
    std::unordered_map<std::wstring, std::vector<StyleVariableCapture>>
        variables;
    std::unordered_map<std::wstring, std::vector<StyleVariableConsumer>>
        consumers;
    // How many entries the two maps above hold for each element. They're keyed
    // by variable name, so without this, asking whether an element appears in
    // either of them means walking every name.
    std::unordered_map<ElementId, size_t> elementRefs;
};

thread_local StyleVariableState g_styleVariableState;

// Non-zero while PropagateStyleVariableChange is running, so nested calls queue
// instead of recursing.
thread_local int g_styleVariablePropagationDepth;

struct PendingStyleVariablePropagation {
    StyleVariableState* state;
    std::wstring varName;
    std::optional<ElementId> changedOwner;

    bool operator==(const PendingStyleVariablePropagation&) const = default;
};

void AddStyleVariableElementRef(StyleVariableState* state,
                                ElementId elementId) {
    state->elementRefs[elementId]++;
}

void ReleaseStyleVariableElementRefs(StyleVariableState* state,
                                     ElementId elementId,
                                     size_t count) {
    if (!count) {
        return;
    }

    auto it = state->elementRefs.find(elementId);
    if (it == state->elementRefs.end()) {
        return;
    }

    if (it->second > count) {
        it->second -= count;
    } else {
        state->elementRefs.erase(it);
    }
}

// Propagations queued while another one is running, drained by the outermost
// PropagateStyleVariableChange frame.
thread_local std::vector<PendingStyleVariablePropagation>
    g_pendingStyleVariablePropagations;

StyleVariableState* GetStyleVariableState() {
    return &g_styleVariableState;
}

thread_local bool g_elementPropertyModifying;

// An image with a remote source fails to load when the process starts before
// the network is up. Such images are tracked so that the load can be retried
// once there's internet access, and are cached in a file in the mod storage
// folder, which is what's loaded when it's there, so that the image shows up at
// once and offline. Only a target which has no image is retried, and only a
// source which isn't showing anything is replaced, so an image that's currently
// displayed can't be blanked out.
struct TrackedImage {
    // An ImageBrush or an Image element. Both hold an image source which can
    // fail to load and both report the outcome, but through unrelated types, so
    // the source is addressed by DependencyProperty and each type gets its own
    // revoker pair.
    winrt::weak_ref<DependencyObject> target;
    DependencyProperty sourceProperty{nullptr};
    // The remote address: the entry's identity and what's downloaded, even
    // while the cached file is what's loaded.
    winrt::Windows::Foundation::Uri uri{nullptr};
    std::wstring url;
    // The cached copy of the image, empty when there's no cache folder.
    std::filesystem::path cachePath;

    // Decode properties of the BitmapImage the style declared, reapplied to the
    // BitmapImage a retry creates.
    int32_t decodePixelWidth = 0;
    int32_t decodePixelHeight = 0;
    Media::Imaging::DecodePixelType decodePixelType =
        Media::Imaging::DecodePixelType::Physical;
    Media::Imaging::BitmapCreateOptions createOptions =
        Media::Imaging::BitmapCreateOptions::None;
    bool autoPlay = true;

    Media::ImageBrush::ImageFailed_revoker brushImageFailedRevoker;
    Media::ImageBrush::ImageOpened_revoker brushImageOpenedRevoker;
    Controls::Image::ImageFailed_revoker elementImageFailedRevoker;
    Controls::Image::ImageOpened_revoker elementImageOpenedRevoker;

    // Whether the target has an image. Retries target the ones which don't.
    bool loaded = false;

    // Whether the target is loading from the cached file rather than from the
    // remote address, which is what a load failure is judged by.
    bool usingCache = false;

    ULONGLONG lastRetryTick = 0;
    int retryCount = 0;
};

struct TrackedImagesForThread {
    // Entries are held by shared_ptr so that event handlers can reference them
    // via a weak_ptr and do nothing once an entry is gone.
    std::list<std::shared_ptr<TrackedImage>> images;
    winrt::Microsoft::UI::Dispatching::DispatcherQueue dispatcher{nullptr};
    winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer retryTimer{nullptr};
    winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer::Tick_revoker
        retryTimerTickRevoker;
    // Tick the scheduled retry round is due at, zero if none is scheduled.
    ULONGLONG retryDueTick = 0;
};

thread_local TrackedImagesForThread g_trackedImagesForThread;

// The remote address of each cached file which has been substituted for one, so
// that a target given an already substituted source is tracked as well.
// Outlives the entries, since the style value it describes is shared by targets
// which come and go. Thread local like that value.
thread_local std::unordered_map<std::wstring, winrt::Windows::Foundation::Uri>
    g_imageCacheUriRemotes;

// A single connectivity transition raises several network status events, and
// the state right after the first one isn't final yet.
constexpr DWORD kNetworkChangeDebounceMs = 2000;

// Minimum delay between the retries of an image, doubling with each attempt up
// to about five minutes. Also keeps a retry from being started while the
// previous one is still loading.
constexpr ULONGLONG kImageRetryBaseDelayMs = 5000;
constexpr int kImageRetryMaxBackoffShift = 6;
constexpr ULONGLONG kImageRetryMaxDelayMs = kImageRetryBaseDelayMs
                                            << kImageRetryMaxBackoffShift;

// Caps the attempts of an image, bounding the series of retries which a failure
// starts. The count starts over once the image has been idle for the maximum
// delay, so connectivity which returns much later can still recover it.
constexpr int kImageRetryMaxCount = 20;

// Guards the globals below it. The network status handler acquires it, so it
// must never be held while adding or removing that handler: the event source
// can wait for an invocation which is already in flight, and registering from a
// UI thread pumps messages, which can re-enter this code on the same thread.
std::mutex g_imageRetryMutex;
bool g_imageRetryActive;
// The dispatcher of each UI thread which has tracked images, used to run a
// retry on the thread that owns the image.
std::vector<winrt::weak_ref<winrt::Microsoft::UI::Dispatching::DispatcherQueue>>
    g_imageRetryDispatchers;
winrt::event_token g_networkStatusChangedToken;
// Set while a thread is registering the handler outside the mutex, so that a
// concurrent or re-entrant call doesn't register a second one.
bool g_networkStatusChangedRegistering;
// Callbacks which are on their way into mod code, counted so that the module
// isn't freed out from under them.
size_t g_imageRetryPendingCallbacks;
std::condition_variable g_imageRetryPendingCallbacksCv;

// A cached file is fetched again once it's this old, and its write time is
// stamped whether or not the fetch gets through, so that the write time doubles
// as when the file was last known to be in use.
constexpr ULONGLONG kImageCacheRefreshIntervalMs = 7ULL * 24 * 60 * 60 * 1000;
// A file which nothing stamps ages until it's swept. Long enough for a theme
// which is switched away from and back to keep its images.
constexpr ULONGLONG kImageCacheMaxUnusedMs = 30ULL * 24 * 60 * 60 * 1000;

// Guards the globals below it.
std::mutex g_imageDownloadMutex;
// The URL of each image to fetch, or an empty string for a cache sweep. The
// path a URL is cached at follows from the URL, so it isn't carried along.
std::list<std::wstring> g_imageDownloadQueue;
// The URL of every queued and in flight job, so that one image isn't fetched
// twice at once. A job which failed is dropped: the retries of the image it's
// for are what ask again, and they're already paced and capped.
std::unordered_set<std::wstring> g_imageDownloadUrls;
// The URL of every cached file which failed to load, taking the images it's
// for back to the remote address for the rest of the process. Not per entry,
// since the file is what was rejected and the entries which share the URL
// would otherwise hand it out again. Global for the same reason: the file is
// process wide, not thread wide.
std::unordered_set<std::wstring> g_imageCacheRejectedUrls;
PTP_WORK g_imageDownloadWork;
// Whether a callback is draining the queue; a job added meanwhile joins it.
bool g_imageDownloadRunning;
bool g_imageDownloadStopping;

enum class ResourceVariableTheme {
    None,
    Dark,
    Light,
};

enum class ResourceVariableType {
    String,
    Xaml,
    ThemeResourceReference,
};

struct ResourceVariableEntry {
    std::wstring key;
    std::wstring value;
    ResourceVariableTheme theme;
    ResourceVariableType type;
};

thread_local std::vector<ResourceVariableEntry> g_resourceVariables;

// Track original resource values for restoration (per-thread since
// Application::Current().Resources() is per-thread).
thread_local std::unordered_map<std::wstring,
                                winrt::Windows::Foundation::IInspectable>
    g_originalResourceValues;

// Track our merged theme dictionary for cleanup (per-thread).
thread_local ResourceDictionary g_resourceVariablesThemeDict{nullptr};

// For listening to theme color changes (per-thread).
thread_local winrt::Windows::UI::ViewManagement::UISettings g_uiSettings{
    nullptr};
thread_local winrt::event_token g_colorValuesChangedToken;

winrt::Windows::Foundation::IInspectable ReadLocalValueWithWorkaround(
    DependencyObject elementDo,
    DependencyProperty property) {
    auto value = elementDo.ReadLocalValue(property);
    if (value) {
        // A workaround for ColumnDefinitionCollection of
        // NavigationBarControlGrid which can't be read by ReadLocalValue for
        // some reason, even though it seems to be a local property.
        if (value == DependencyProperty::UnsetValue()) {
            auto grid = elementDo.try_as<Controls::Grid>();
            if (grid && grid.Name() == L"NavigationBarControlGrid") {
                auto value2 = elementDo.GetValue(property);
                if (value2 && winrt::get_class_name(value2) ==
                                  L"Microsoft.UI.Xaml.Controls."
                                  L"ColumnDefinitionCollection") {
                    Wh_Log(
                        L"Using GetValue workaround for "
                        L"ColumnDefinitionCollection");
                    value = std::move(value2);
                }
            }
        }

        // TODO: Is this still needed?
#if 0
        auto className = winrt::get_class_name(value);
        if (className == L"Windows.UI.Xaml.Data.BindingExpressionBase" ||
            className == L"Windows.UI.Xaml.Data.BindingExpression") {
            // BindingExpressionBase was observed to be returned for XAML
            // properties that were declared as following:
            //
            // <Border ... CornerRadius="{TemplateBinding CornerRadius}" />
            //
            // Calling SetValue with it fails with an error, so we won't be able
            // to use it to restore the value. As a workaround, we use
            // GetAnimationBaseValue to get the value.
            Wh_Log(L"ReadLocalValue returned %s, using GetAnimationBaseValue",
                   className.c_str());
            value = elementDo.GetAnimationBaseValue(property);
        }
#endif
    }

    Wh_Log(L"Read property value %s",
           value ? (value == DependencyProperty::UnsetValue()
                        ? L"(unset)"
                        : winrt::get_class_name(value).c_str())
                 : L"(null)");

    return value;
}

////////////////////////////////////////////////////////////////////////////////
// Noise generation
//
// Generates a tileable noise BMP in memory. Density controls the brightness
// distribution curve via a power function (lower density = sparser bright
// pixels). Opacity is handled downstream by the composition effect graph.
winrt::Windows::Storage::Streams::IRandomAccessStream CreateNoiseStream(
    float density) {
    // Cache the last stream to avoid regenerating when density hasn't changed.
    // The cached stream is never read directly; callers get independent clones
    // via CloneStream() so they don't share a seek cursor.
    thread_local float cachedDensity = std::numeric_limits<float>::quiet_NaN();
    thread_local winrt::Windows::Storage::Streams::InMemoryRandomAccessStream
        cachedStream{nullptr};

    if (density == cachedDensity && cachedStream) {
        return cachedStream.CloneStream();
    }

    // Use 256x256 to minimize visible tiling seams.
    constexpr int kSize = 256;
    constexpr DWORD kBpp = 32;
    constexpr DWORD rowSize = kSize * (kBpp / 8);
    constexpr DWORD dataSize = rowSize * kSize;

    BITMAPFILEHEADER fileHeader{
        .bfType = 0x4D42,  // "BM"
        .bfSize =
            sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dataSize,
        .bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER),
    };

    BITMAPINFOHEADER infoHeader{
        .biSize = sizeof(BITMAPINFOHEADER),
        .biWidth = kSize,
        .biHeight = kSize,
        .biPlanes = 1,
        .biBitCount = kBpp,
        .biSizeImage = dataSize,
    };

    std::vector<uint8_t> pixels(dataSize);

    // Precompute the density power curve as a lookup table so that
    // std::pow is called 256 times instead of once per pixel (65536).
    float safeDensity = std::clamp(density, 0.001f, 1.0f);
    float exponent = 1.0f / safeDensity;

    uint8_t lut[256];
    for (int i = 0; i < 256; i++) {
        lut[i] = static_cast<uint8_t>(std::pow(i / 255.0f, exponent) * 255.0f);
    }

    std::mt19937 rng(0);
    std::uniform_int_distribution<int> dist(0, 255);

    for (size_t i = 0; i < pixels.size(); i += 4) {
        uint8_t gray = lut[dist(rng)];

        // Fully opaque; opacity is applied downstream by ColorMatrixEffect.
        pixels[i] = gray;
        pixels[i + 1] = gray;
        pixels[i + 2] = gray;
        pixels[i + 3] = 255;
    }

    winrt::Windows::Storage::Streams::InMemoryRandomAccessStream stream;
    winrt::Windows::Storage::Streams::DataWriter writer(stream);
    writer.WriteBytes(winrt::array_view<const uint8_t>(
        reinterpret_cast<const uint8_t*>(&fileHeader), sizeof(fileHeader)));
    writer.WriteBytes(winrt::array_view<const uint8_t>(
        reinterpret_cast<const uint8_t*>(&infoHeader), sizeof(infoHeader)));
    writer.WriteBytes(pixels);
    writer.StoreAsync().get();
    writer.DetachStream();

    cachedStream = std::move(stream);
    cachedDensity = density;

    return cachedStream.CloneStream();
}

// Blur background implementation, copied from TranslucentTB.
////////////////////////////////////////////////////////////////////////////////
// clang-format off

typedef enum MY_D2D1_GAUSSIANBLUR_OPTIMIZATION
{
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED = 0,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED = 1,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY = 2,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_FORCE_DWORD = 0xffffffff

} MY_D2D1_GAUSSIANBLUR_OPTIMIZATION;

////////////////////////////////////////////////////////////////////////////////
// XamlBlurBrush.h
class XamlBlurBrush : public Media::XamlCompositionBrushBaseT<XamlBlurBrush>
{
public:
    XamlBlurBrush(UIElement element,
                  float blurAmount,
                  winrt::Windows::UI::Color tint,
                  std::optional<uint8_t> tintOpacity,
                  winrt::hstring tintThemeResourceKey,
                  std::optional<float> tintLuminosityOpacity,
                  std::optional<float> tintSaturation,
                  std::optional<float> noiseOpacity,
                  std::optional<float> noiseDensity,
                  std::optional<winrt::Windows::UI::Color> fallbackColor,
                  winrt::hstring fallbackThemeResourceKey);
    ~XamlBlurBrush();

    void OnConnected();
    void OnDisconnected();

private:
    void RefreshThemeTint();
    void RefreshFallbackColor();
    bool ShouldUseFallback() const;
    void RefreshBrush();
    muc::CompositionBrush CreateEffectBrush();
    muc::CompositionBrush CreateFallbackBrush();

    muc::Compositor m_compositor;
    float m_blurAmount;
    winrt::Windows::UI::Color m_tint;
    std::optional<uint8_t> m_tintOpacity;
    winrt::hstring m_tintThemeResourceKey;
    std::optional<float> m_tintLuminosityOpacity;
    std::optional<float> m_tintSaturation;
    std::optional<float> m_noiseOpacity;
    std::optional<float> m_noiseDensity;
    std::optional<winrt::Windows::UI::Color> m_fallbackColor;
    winrt::hstring m_fallbackThemeResourceKey;
    Media::SolidColorBrush m_proxyBrush{nullptr};
    Media::SolidColorBrush m_fallbackProxyBrush{nullptr};
    winrt::weak_ref<FrameworkElement> m_weakProxyElement;
    winrt::hstring m_proxyKey;
    winrt::hstring m_fallbackProxyKey;
    winrt::Windows::UI::ViewManagement::UISettings m_uiSettings{nullptr};
    winrt::event_token m_advancedEffectsEnabledChangedToken{};
    winrt::event_token m_energySaverStatusChangedToken{};
    winrt::Microsoft::UI::Dispatching::DispatcherQueue m_dispatcher{nullptr};
    HKEY m_powerKey{nullptr};
    HANDLE m_regNotifyEvent{nullptr};
    HANDLE m_regWaitHandle{nullptr};

    static void CALLBACK OnEnergySaverRegistryChanged(PVOID context,
                                                      BOOLEAN timerOrWaitFired);
};

////////////////////////////////////////////////////////////////////////////////
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- RenderingMod:
    - ThemeBackground: TRUE
      $name: 🔷 Windows theme custom rendering
      $description: >-
       Modifies parts of the Windows theme using the Direct2D graphics API and modifies 
       Windows GDI text rendering by patching the alpha channel and adjusting text colors.
        ✨It is recommended to enable this with background translucent effects.
    - SysColors: FALSE
      $name: 🔷 New system colors
      $description: >-
       Modifies additional system UI colors by calling SetSysColors API. (Requires Windows theme custom rendering)
        ⚠️For issues with excluded processes, use process rules in mod's settings. For more refer to the FAQ.
    - AccentColorControls: TRUE
      $name: 🔷 Windows theme accent colorizer
      $description: >-
       Paint with accent color parts of windows theme. (Requires Windows theme custom rendering)
  $name: 🔶 Theme Customization
- BackgroundEffects:
    - type: acrylicblur
      $name: 🔷 Background effects
      $description: >-
        Windows 11 version >= 22621.xxx (22H2) is required for SystemBackdrop effects.
      $options:
      - none: Default
      - acrylicblur: Blur (AccentBlurBehind)
      - acrylicsystem: Acrylic (SystemBackdrop)
      - mica: Mica (SystemBackdrop)
      - mica_tabbed: MicaAlt (SystemBackdrop)
    - AccentBlurBehind: "3A232323"
      $name: 🔷 AccentBlurBehind color blend
      $description: >-
        Blending color with blur background.
        Color in hexadecimal ARGB format e.g. 3A232323
  $name: 🔶 Translucent Effects
- FlyoutsEffects: TRUE
  $name: 🔶 Flyout effects
  $description: >-
    Expand the effects to Win32 flyouts (context menus, dropdown menus, tooltips)
     ✨It is recommended to enable this with both background translucent effects and Windows theme custom rendering.
- RuledPrograms:
    - - target: "Notepad.exe"
        $name: 🔶 Process
        $description: >-
         Entries can be process names, paths or subdirectories for example:
          • Notepad.exe
          • C:\Program Files\Microsoft Office\root\Office16\EXCEL.EXE
          • C:\Users
      - RenderingMod:
          - ThemeBackground: FALSE
            $name: 🔷 Windows theme custom rendering
            $description: >-
              Modifies parts of the Windows theme using the Direct2D graphics API and modifies Windows GDI text rendering by patching the alpha channel and adjusting text colors.
               ✨It is recommended to enable this with background translucent effects.
          - AccentColorControls: FALSE
            $name: 🔷 Windows theme accent colorizer
            $description: >-
              Paint with accent color parts of windows theme. (Requires Windows theme custom rendering)
        $name: 🔶 Theme Customization
      - BackgroundEffects:
        - type: none
          $name: 🔷 Background translucent effects
          $description: >-
           Windows 11 version >= 22621.xxx (22H2) is required for SystemBackdrop effects.
          $options:
          - none: Default
          - acrylicblur: Blur (AccentBlurBehind)
          - acrylicsystem: Acrylic (SystemBackdrop)
          - mica: Mica (SystemBackdrop)
          - mica_tabbed: MicaAlt (SystemBackdrop)
        - AccentBlurBehind: "3A232323"
          $name: 🔷 AccentBlurBehind color blend
          $description: >-
           Blending color with blur background.
            Color in hexadecimal ARGB format e.g. 3A232323
        $name: 🔶 Translucent Effects
  $name: ⏩ Process Rules
  $description: >-
      Add rules to each specified process or processes from specific subdirectories
       ❗ Add process rules for the excluded process instead of using Windhawk's process exclusion when the "New system colors" global setting is enabled.


// ===== Stylisation intégrée de l'Explorateur de fichiers Windows 11 =====
- theme: ""
  $name: Thème
  $description: >-
    Themes are collections of styles. For details about the themes below, or for
    information about submitting your own theme, refer to the relevant section
    in the mod details.
  $options:
  - "": Aucun
  - Translucent Explorer11: Translucent Explorer11
  - MicaBar: MicaBar
  - NoCommandBar: NoCommandBar
  - Minimal Explorer11: Minimal Explorer11
  - Tabless: Tabless
  - Matter: Matter
  - WindowGlass: WindowGlass
  - AddressSearchOnly: AddressSearchOnly
  - TintedGlass: TintedGlass
  - LiquidGlass: LiquidGlass
  - MicaTabless: MicaTabless
  - OS26 Liquid Glass: OS26 Liquid Glass
  - OS26 Liquid Glass_variant_Compact: OS26 Liquid Glass (Compact)
  - ZEUSosX_044: ZEUSosX_044
  - Compact Explorer11: Compact Explorer11
  - Float: Float
- backgroundTranslucentEffect: ""
  $name: Effet d'arrière-plan translucide
  $description: >-
    The translucent effect to use for the File Explorer background. For
    additional translucent effects, check out the Translucent Windows mod.
  $options:
  - "": Par défaut pour le thème sélectionné
  - default: Par défaut de Windows
  - acrylicblur: Blur (AccentBlurBehind)
  - acrylic: Acrylique
  - mica: Mica
  - micaAlt: Mica Alt
  - none: Aucun
- backgroundTranslucentEffectRegion: ""
  $name: Effet d'arrière-plan translucide region
  $description: >-
    The region where the translucent background effect is applied.
  $options:
  - "": Entire window
  - explorerFrame: File Explorer frame only
- styleConstants: [""]
  $name: Constantes de style
  $description: >-
    Some themes support style constants for customization, such as colors. Refer
    to the theme page for available constants. For technical details, refer to
    the mod description.
- controlStyles:
  - - target: ""
      $name: Cible
    - styles: [""]
      $name: Styles
  $name: Styles des contrôles
- themeResourceVariables: [""]
  $name: Variables de ressources
  $description: >-
    Use "Key=Value" to override an existing resource with a new value.

    Use "Key@Dark=Value" or "Key@Light=Value" to define theme-aware resources
    that can be referenced with {ThemeResource Key} in styles.

    The ":=" syntax can be used to set a XAML value. For details, refer to the
    mod description.
- explorerFrameContainerHeight: 0
  $name: Hauteur du conteneur du cadre de l'Explorateur
  $description: >-
    The height of the explorer frame container which includes the tabs, the
    address bar, and the command bar, set to zero to use the default height.
- xamlDiagnosticsHandling: alert
  $name: Gestion du consommateur de diagnostics XAML
  $description: >-
    How to handle other programs (e.g. ExplorerBlurMica) that try to use XAML
    diagnostics. There can only be one consumer at a time. Block will prevent
    other programs from using it, which might break them. Allow will let them
    use it, which might break this mod.
  $options:
  - alert: Alerte (demander avant de bloquer)
  - block: Bloquer les autres consommateurs
  - allow: Autoriser les autres consommateurs
*/

// ==/WindhawkModSettings==

#include <windhawk_utils.h>

// Avoid a WinBase.h macro collision with the C++/WinRT headers.
#undef GetCurrentTime

#include <windowsx.h>
#include <dwmapi.h>
#include <vssym32.h>
#include <uxtheme.h>
#include <cmath>
#include <string>
#include <array>
#include <d2d1.h>
#include <wrl.h>
#include <ShellScalingApi.h>
#include <atomic>
#include <optional>
#include <vector>
#include <winrt/Microsoft.UI.Xaml.h>
#include <Unknwn.h>
#include <weakreference.h>
#include <winrt/base.h>
#include <ocidl.h>
#include <combaseapi.h>
#include <windhawk_utils.h>
#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <filesystem>
#include <limits>
#include <list>
#include <memory>
#include <mutex>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <initguid.h>
#include <commctrl.h>
#include <d2d1_1.h>
#include <dwmapi.h>
#include <roapi.h>
#include <shlwapi.h>
#include <uxtheme.h>
#include <vssym32.h>
#include <windows.graphics.effects.h>
#include <winstring.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Dispatching.h>
#include <winrt/Microsoft.UI.Text.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.Imaging.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Effects.h>
#include <winrt/Windows.Networking.Connectivity.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.System.Power.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <xamlom.h>

#define RECTWIDTH(lprc)     ((lprc)->right - (lprc)->left)
#define RECTHEIGHT(lprc)    ((lprc)->bottom - (lprc)->top)

#ifdef _WIN64
#define THISCALL  __cdecl
#define _THISCALL L"__cdecl"
#else
#define THISCALL  __thiscall
#define _THISCALL L"__thiscall"
#endif

#ifdef _WIN64
#define STDCALL  __cdecl
#define _STDCALL L"__cdecl"
#else
#define STDCALL  __stdcall
#define _STDCALL L"__stdcall"
#endif

static constexpr UINT ENABLE = 1;
static constexpr UINT AUTO = 0; // DWMSBT_AUTO
//static constexpr UINT NONE = 1; // DWMSBT_NONE
static constexpr UINT MAINWINDOW = 2; // DWMSBT_MAINWINDOW
static constexpr UINT TRANSIENTWINDOW = 3; // DWMSBT_TRANSIENTWINDOW
static constexpr UINT TABBEDWINDOW = 4; // DWMSBT_TABBEDWINDOW

// Get DPI value from the primary monitor without dependance to DPI-aware API
// TODO: Get DPI per window monitor
UINT GetDpiFromMonitor()
{
    // Get monitor handle without the need of a window handle
    HMONITOR hPrimary = MonitorFromPoint({0, 0}, MONITOR_DEFAULTTOPRIMARY);
    UINT dpiX = USER_DEFAULT_SCREEN_DPI, dpiY = USER_DEFAULT_SCREEN_DPI;
    if (SUCCEEDED(GetDpiForMonitor(hPrimary, MDT_EFFECTIVE_DPI, &dpiX, &dpiY)))
        return dpiY;
    return USER_DEFAULT_SCREEN_DPI;
}
UINT g_Dpi = GetDpiFromMonitor();

typedef HRESULT(WINAPI* pDrawTextWithGlow)(HDC hdcMem, LPWSTR pszText, UINT cch, RECT* pRect, DWORD dwFlags, COLORREF crText,
                                          COLORREF crGlow, UINT nGlowRadius, UINT nGlowIntensity, BOOL fPreMultiply,
                                          DTT_CALLBACK_PROC pfnDrawTextCallback, LPARAM lParam);
static auto DrawTextWithGlow = (pDrawTextWithGlow)GetProcAddress(GetModuleHandle(L"uxtheme.dll"), MAKEINTRESOURCEA(126));

// Detects system dark/light theme mode
typedef BOOL(WINAPI* pShouldSystemUseDarkMode)();
static auto ShouldSystemUseDarkMode = (pShouldSystemUseDarkMode)GetProcAddress(GetModuleHandle(L"uxtheme.dll"), MAKEINTRESOURCEA(138));
BOOL g_IsSysThemeDarkMode = ShouldSystemUseDarkMode();

// Redirect per ruled program the system colors to hardcoded default ones 
// when custom system colors are applied in global settings.
BOOL g_DefaultSysColors = FALSE;
// Global system colors buffers like Windows does.
std::array<HBRUSH, COLOR_MENUBAR + 1> g_themeCachedCustomSysColorBrushes {nullptr};
std::array<HBRUSH, COLOR_MENUBAR + 1> g_themeCachedDefaultSysColorBrushes {nullptr};
SRWLOCK g_SysColorsLock = SRWLOCK_INIT;

// Helpers for resetting theming containers and attributes
std::wstring GetCurrentWindowsThemePath();
// Lock in order to safely reset theme cache and attributes on theme change
SRWLOCK g_ThemeChangeLock = SRWLOCK_INIT;
std::wstring g_LastThemePath = GetCurrentWindowsThemePath();

// Flag to prevent customizing text colors of Task Manager
BOOL g_InsideTaskMgrProc = FALSE;

BOOL g_InsideExplorerProc = FALSE;

using PUNICODE_STRING = PVOID;
constexpr auto MENUPOPUP_CLASS = L"#32768";
constexpr UINT THEMECLS_COMMONPROPS_PART = 0;

ATOM g_explorerStylerNoBackgroundEffectAtom = 0;

struct Settings{
    BOOL FillBg = FALSE;
    BOOL AccentColorize = FALSE;
    COLORREF AccentColor = 0xFFFFFFFF;
    BOOL TextAlphaBlend = FALSE;
    BOOL SetSystemColors = FALSE;
    COLORREF AccentBlurBehindClr = 0x00000000;
    BOOL FlyoutsEffects = FALSE;
    BOOL Unload = FALSE;

    enum BACKGROUNDTYPE
    {
        Default,
        AccentBlurBehind,
        AcrylicSystemBackdrop,
        Mica,
        MicaAlt,
    } BgType = Default;

} g_settings;

struct ACCENT_POLICY 
{
    INT AccentState;
    INT AccentFlags;
    INT GradientColor;
    INT AnimationId;
};

enum ACCENT_STATE
{
    ACCENT_STATE_DISABLED,
    ACCENT_STATE_ENABLE_GRADIENT,
    ACCENT_STATE_ENABLE_TRANSPARENTGRADIENT,
    ACCENT_STATE_ENABLE_BLURBEHIND,	// Removed in Windows 11 22H2+
    ACCENT_STATE_ENABLE_ACRYLICBLURBEHIND,
    ACCENT_STATE_ENABLE_HOSTBACKDROP,
    ACCENT_STATE_INVALID_STATE
};

enum ACCENT_FLAG
{
    ACCENT_FLAG_NONE,
    ACCENT_FLAG_ENABLE_MODERN_ACRYLIC_RECIPE = 1 << 1,	// Windows 11 22H2+
    ACCENT_FLAG_ENABLE_GRADIENT_COLOR = 1 << 1, // ACCENT_ENABLE_BLURBEHIND
    ACCENT_FLAG_ENABLE_FULLSCREEN = 1 << 2,
    ACCENT_FLAG_ENABLE_BORDER_LEFT = 1 << 5,
    ACCENT_FLAG_ENABLE_BORDER_TOP = 1 << 6,
    ACCENT_FLAG_ENABLE_BORDER_RIGHT = 1 << 7,
    ACCENT_FLAG_ENABLE_BORDER_BOTTOM = 1 << 8,
    ACCENT_FLAG_ENABLE_BLUR_RECT = 1 << 9,	// DwmpUpdateAccentBlurRect, it is conflicted with ACCENT_ENABLE_GRADIENT_COLOR when using ACCENT_ENABLE_BLURBEHIND
    ACCENT_FLAG_ENABLE_BORDER = ACCENT_FLAG_ENABLE_BORDER_LEFT | ACCENT_FLAG_ENABLE_BORDER_TOP 
    | ACCENT_FLAG_ENABLE_BORDER_RIGHT | ACCENT_FLAG_ENABLE_BORDER_BOTTOM
};

struct WINCOMPATTRDATA 
{
    DWORD Attrib;
    PVOID pvData;
    SIZE_T cbData;
};

enum WINDOWCOMPOSITIONATTRIB 
{
    WCA_UNDEFINED,
    WCA_NCRENDERING_ENABLED,
    WCA_NCRENDERING_POLICY,
    WCA_TRANSITIONS_FORCEDISABLED,
    WCA_ALLOW_NCPAINT,
    WCA_CAPTION_BUTTON_BOUNDS,
    WCA_NONCLIENT_RTL_LAYOUT,
    WCA_FORCE_ICONIC_REPRESENTATION,
    WCA_EXTENDED_FRAME_BOUNDS,
    WCA_HAS_ICONIC_BITMAP,
    WCA_THEME_ATTRIBUTES,
    WCA_NCRENDERING_EXILED,
    WCA_NCADORNMENTINFO,
    WCA_EXCLUDED_FROM_LIVEPREVIEW,
    WCA_VIDEO_OVERLAY_ACTIVE,
    WCA_FORCE_ACTIVEWINDOW_APPEARANCE,
    WCA_DISALLOW_PEEK,
    WCA_CLOAK,
    WCA_CLOAKED,
    WCA_ACCENT_POLICY,
    WCA_FREEZE_REPRESENTATION,
    WCA_EVER_UNCLOAKED,
    WCA_VISUAL_OWNER,
    WCA_HOLOGRAPHIC,
    WCA_EXCLUDED_FROM_DDA,
    WCA_PASSIVEUPDATEMODE,
    WCA_USEDARKMODECOLORS,
    WCA_CORNER_STYLE,
    WCA_PART_COLOR,
    WCA_DISABLE_MOVESIZE_FEEDBACK,
    WCA_LAST
};

typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);
auto SetWindowCompositionAttribute = (pSetWindowCompositionAttribute) GetProcAddress(GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute");

ID2D1Factory* g_d2dFactory = nullptr;

VOID InitDirect2D()
{
    if (!g_d2dFactory)
    {
        D2D1_FACTORY_OPTIONS options = {};
        D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, options, &g_d2dFactory);
    }
}

VS_FIXEDFILEINFO* GetModuleVersionInfo(HMODULE hModule, UINT *puPtrLen)
{
    void *pFixedFileInfo = nullptr;
    UINT uPtrLen = 0;

    HRSRC hResource =
        FindResourceW(hModule, MAKEINTRESOURCEW(VS_VERSION_INFO), RT_VERSION);
    if (hResource)
    {
        HGLOBAL hGlobal = LoadResource(hModule, hResource);
        if (hGlobal)
        {
            void *pData = LockResource(hGlobal);
            if (pData)
            {
                if (!VerQueryValueW(pData, L"\\", &pFixedFileInfo, &uPtrLen)
                || uPtrLen == 0)
                {
                    pFixedFileInfo = nullptr;
                    uPtrLen = 0;
                }
            }
        }
    }

    if (puPtrLen)
    {
        *puPtrLen = uPtrLen;
    }

    return (VS_FIXEDFILEINFO *)pFixedFileInfo;
}

/*
  * Loads comctl32.dll, version 6.0.
  * This uses an activation context that uses shell32.dll's manifest
  * to load 6.0, even in apps which don't have the proper manifest for
  * it.
  * From: https://github.com/ramensoftware/windhawk-mods/blob/main/mods/classic-list-group-fix.wh.cpp
*/
HMODULE LoadComCtlModule(void)
{
    HMODULE hShell32 = LoadLibraryW(L"shell32.dll");
    ACTCTXW actCtx = { sizeof(actCtx) };
    actCtx.dwFlags = ACTCTX_FLAG_RESOURCE_NAME_VALID | ACTCTX_FLAG_HMODULE_VALID;
    actCtx.lpResourceName = MAKEINTRESOURCEW(124);
    actCtx.hModule = hShell32;
    HANDLE hActCtx = CreateActCtxW(&actCtx);
    ULONG_PTR ulCookie;
    ActivateActCtx(hActCtx, &ulCookie);
    HMODULE hComCtl = LoadLibraryExW(L"comctl32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    /**
      * Certain processes will ignore the activation context and load
      * comctl32.dll 5.82 anyway. If that occurs, just reject it.
      */
    VS_FIXEDFILEINFO *pVerInfo = GetModuleVersionInfo(hComCtl, nullptr);
    if (!pVerInfo || HIWORD(pVerInfo->dwFileVersionMS) < 6)
    {
        FreeLibrary(hComCtl);
        hComCtl = NULL;
    }
    DeactivateActCtx(0, ulCookie);
    ReleaseActCtx(hActCtx);
    FreeLibrary(hShell32);
    return hComCtl;
}

using NtUserCreateWindowEx_t = HWND(WINAPI*)(DWORD, PUNICODE_STRING, LPCWSTR, PUNICODE_STRING, DWORD, LONG, LONG, LONG, LONG, HWND, HMENU, HINSTANCE, LPVOID, DWORD, DWORD, DWORD, VOID*);
NtUserCreateWindowEx_t NtUserCreateWindowEx_Original;

static decltype(&DwmExtendFrameIntoClientArea) DwmExtendFrameIntoClientArea_orig = nullptr;
static decltype(&DwmSetWindowAttribute) DwmSetWindowAttribute_orig = nullptr;

static decltype(&DrawTextW) DrawTextW_orig = nullptr;
static decltype(&ExtTextOutW) ExtTextOutW_orig = nullptr;
static decltype(&DrawThemeText) DrawThemeText_orig = nullptr;
static decltype(&DrawThemeTextEx) DrawThemeTextEx_orig = nullptr;

static decltype(&GetThemeColor) GetThemeColor_orig = nullptr;
static decltype(&DrawThemeBackground) DrawThemeBackground_orig = nullptr;
static decltype(&DrawThemeBackgroundEx) DrawThemeBackgroundEx_orig = nullptr;
static decltype(&GetThemeMargins) GetThemeMargins_orig = nullptr;
static decltype(&GetThemeTransitionDuration) GetThemeTransitionDuration_orig = nullptr;
static decltype (&GetThemeFont) GetThemeFont_orig = nullptr;
static decltype(&GetSysColor) GetSysColor_orig = GetSysColor; // Assign the pointer to the original function as we call HookedSysColor() even if the function isn't hooked.
static decltype(&GetSysColorBrush) GetSysColorBrush_orig = GetSysColorBrush;
static decltype(&FillRect) FillRect_orig = nullptr;
static decltype(&DrawThemeEdge) DrawThemeEdge_orig = nullptr;
static decltype(&DefWindowProcW) DefWindowProc_orig = nullptr;

VOID NewWindowShown(HWND);
VOID HandleEffects(HWND hWnd);

std::wstring GetWindowClass(HWND hWnd)
{
    if (!hWnd)
        return L"";
    WCHAR buffer[MAX_PATH];
    GetClassNameW(hWnd, buffer, MAX_PATH);
    return buffer;
}

BOOL IsWindowClass(HWND hWnd, LPCWSTR className)
{
    if (!hWnd)
        return FALSE;
    return GetWindowClass(hWnd) == className;
}


// Excel worksheet transparency support.
BOOL IsExcelProcess()
{
    WCHAR processPath[MAX_PATH] = {};

    if (!GetModuleFileNameW(nullptr, processPath, MAX_PATH))
        return FALSE;

    const WCHAR* fileName = wcsrchr(processPath, L'\\');
    fileName = fileName ? fileName + 1 : processPath;

    return _wcsicmp(fileName, L"EXCEL.EXE") == 0;
}

BOOL IsExcelWorksheetWindow(HWND hWnd)
{
    return IsExcelProcess() && IsWindowClass(hWnd, L"EXCEL7");
}

VOID ApplyExcelWorksheetTransparency(HWND hWnd)
{
    if (!IsExcelWorksheetWindow(hWnd))
        return;

    LONG_PTR exStyle = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);

    if (!(exStyle & WS_EX_LAYERED))
        SetWindowLongPtrW(hWnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED);

    SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    SetWindowPos(
        hWnd, nullptr, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
        SWP_NOACTIVATE | SWP_FRAMECHANGED
    );

    InvalidateRect(hWnd, nullptr, TRUE);
}

VOID RestoreExcelWorksheetTransparency(HWND hWnd)
{
    if (!IsExcelWorksheetWindow(hWnd))
        return;

    LONG_PTR exStyle = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);

    if (exStyle & WS_EX_LAYERED)
    {
        SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);
        SetWindowLongPtrW(hWnd, GWL_EXSTYLE, exStyle & ~WS_EX_LAYERED);
        SetWindowPos(
            hWnd, nullptr, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
            SWP_NOACTIVATE | SWP_FRAMECHANGED
        );
    }
}

BOOL CALLBACK EnumExcelWorksheetProc(HWND hWnd, LPARAM)
{
    ApplyExcelWorksheetTransparency(hWnd);
    return TRUE;
}

VOID ApplyExcelWorksheetTransparencyToChildren(HWND hExcelWindow)
{
    if (!IsExcelProcess() || !hExcelWindow)
        return;

    EnumChildWindows(hExcelWindow, EnumExcelWorksheetProc, 0);
}

BOOL CALLBACK RestoreExcelWindowsProc(HWND hWnd, LPARAM)
{
    RestoreExcelWorksheetTransparency(hWnd);
    EnumChildWindows(hWnd, EnumExcelWorksheetProc, 0);
    return TRUE;
}

BOOL IsWindowCloaked(HWND hwnd) {
    BOOL isCloaked = FALSE;
    return SUCCEEDED(DwmGetWindowAttribute(hwnd, DWMWA_CLOAKED, &isCloaked,
                                           sizeof(isCloaked))) &&
           isCloaked;
}

BOOL isWindowFlyout(HWND hWnd)
{
    return IsWindowClass(hWnd, TOOLTIPS_CLASS) || IsWindowClass(hWnd, L"DropDown") || IsWindowClass(hWnd, L"ViewControlClass") 
           || IsWindowClass(hWnd, MENUPOPUP_CLASS) || IsWindowClass(hWnd, L"MicrosoftWindowsTooltip") ||IsWindowClass(hWnd, L"BaseBar"); // Support m417z Folder Hover Menu mod
}

BOOL IsWindowEligible(HWND hWnd) 
{       
    if (isWindowFlyout(hWnd) && g_settings.FlyoutsEffects)
        return TRUE;
    
    LONG_PTR styleEx = GetWindowLongPtrW(hWnd, GWL_EXSTYLE);
    LONG_PTR style = GetWindowLongPtrW(hWnd, GWL_STYLE);
    
    HWND hParentWnd = GetAncestor(hWnd, GA_PARENT);
    if (hParentWnd && hParentWnd != GetDesktopWindow())
        return FALSE;
    
    BOOL hasTitleBar = (style & WS_CAPTION) == WS_CAPTION;
    BOOL hasCaptionButtons = (style & (WS_MINIMIZEBOX | WS_MAXIMIZEBOX)) != 0;
    BOOL hasSystemMenu = (style & WS_SYSMENU) != 0;
    BOOL hasThickFrame = (style & WS_THICKFRAME) == WS_THICKFRAME;
    BOOL isWindowCEF = (IsWindowClass(hWnd, L"Chrome_WidgetWin_1") || IsWindowClass(hWnd, L"Chrome_WidgetWin_0"));

    // https://devblogs.microsoft.com/oldnewthing/20200302-00/?p=103507
    // Allow containers of Windows Store apps (WinStore.exe, Settings.exe, etc.)
    // Allow also Chromium Embedded Framework (Brave.exe) created as cloaked.
    if (IsWindowCloaked(hWnd) && !IsWindowClass(hWnd, L"ApplicationFrameWindow") && !isWindowCEF)
        return FALSE;

    // Windows become disabled even when they are displayed (e.g. Recycle Bin) when a pop-up window opens in front.
    if (!IsWindowEnabled(hWnd) && !IsWindowVisible(hWnd))
        return FALSE;
    
    // Pass ineligible CEF windows like Discord/Vencord
    if (isWindowCEF && (hasCaptionButtons || hasTitleBar))
        return TRUE;
    // Fixes Snipping Tool recording
    if ((styleEx & WS_EX_NOACTIVATE) || (styleEx & WS_EX_TRANSPARENT))
        return FALSE;
    // Most top-level windows
    if ((style & WS_POPUPWINDOW) == WS_POPUPWINDOW || (style & WS_OVERLAPPEDWINDOW) == WS_OVERLAPPEDWINDOW 
       || (styleEx & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME) // || (styleEx & WS_EX_CONTROLPARENT) == WS_EX_CONTROLPARENT)
            return TRUE;
    // Overlapped windows like the Win32 progress window
    if (hasTitleBar && hasSystemMenu && (hasCaptionButtons || hasThickFrame))
        return TRUE;

    return FALSE;
}

std::wstring GetCurrentWindowsThemePath() 
{
    std::wstring themePath;
    HKEY hKey = nullptr;

    LSTATUS status = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
        0,
        KEY_READ,
        &hKey
    );

    if (status != ERROR_SUCCESS)
        return L"";

    // 2. Query the size of the string buffer first
    DWORD bufferSize = 0;
    status = RegQueryValueExW(
        hKey,
        L"CurrentTheme",
        nullptr,
        nullptr,
        nullptr, // Pass nullptr to just get the required size
        &bufferSize
    );

    // 3. Allocate the string buffer and fetch the actual data
    if (status == ERROR_SUCCESS && bufferSize > 0) 
    {
        // Resize our wstring to fit the data (bufferSize includes the null terminator)
        themePath.resize(bufferSize / sizeof(wchar_t) - 1);

        status = RegQueryValueExW(
            hKey,
            L"CurrentTheme",
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(&themePath[0]),
            &bufferSize
        );

        if (status != ERROR_SUCCESS)
            themePath.clear();
    }
    RegCloseKey(hKey);

    return themePath;
}

std::wstring GetProcStrFromPath(std::wstring path) {
    size_t pos = path.find_last_of(L"\\/");
    if (pos != std::wstring::npos && pos + 1 < path.length()) {
        path = path.substr(pos + 1);
    }

    if (!path.empty()) 
    {
        LCMapStringEx(
            LOCALE_NAME_USER_DEFAULT, 
            LCMAP_LOWERCASE,
            path.c_str(),
            path.length(),
            &path[0],
            path.length(),
            nullptr, nullptr, 0);
    }
    return path;
}

std::wstring GetCurrProcStr() {
    WCHAR modulePath[MAX_PATH];
    GetModuleFileNameW(NULL, modulePath, MAX_PATH);

    return GetProcStrFromPath(modulePath);
}

BOOL CheckExplorerProcess() {
    return GetCurrProcStr() == L"explorer.exe";
}

BOOL InTaskManagerProcess() {
    return GetCurrProcStr() == L"taskmgr.exe";
}

enum AccentColorShade
{
    SystemAccentColorLight3,
    SystemAccentColorLight2,
    SystemAccentColorLight1,
    SystemAccentColorBase,
    SystemAccentColorDark1,
    SystemAccentColorDark2,
    SystemAccentColorDark3,
    Unused,
    AccentColorCount
};

class AccentPalette
{
public:
    std::array<COLORREF, AccentColorCount> Colors{};
    BOOL LoadAccentPalette();
    AccentPalette()
    {
        if (!LoadAccentPalette())
            Colors.fill(GetSysColor(COLOR_HIGHLIGHT));
    }
};
AccentPalette g_AccentPalette;

BOOL AccentPalette::LoadAccentPalette()
{
    const LPCWSTR kAccentRegPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent";
    const LPCWSTR kAccentPaletteValue = L"AccentPalette";

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, kAccentRegPath, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return FALSE;

    BYTE data[32] = {};
    DWORD dataSize = sizeof(data);
    DWORD type = 0;

    if (RegQueryValueExW(hKey, kAccentPaletteValue, nullptr, &type, data, &dataSize) != ERROR_SUCCESS || type != REG_BINARY || dataSize < AccentColorCount * 4)
    {
        RegCloseKey(hKey);
        return FALSE;
    }

    RegCloseKey(hKey);

    for (INT i = 0; i < AccentColorCount; ++i)
    {
        DWORD color = *reinterpret_cast<DWORD*>(&data[i * 4]);
        Colors[i] = color;
    }
    return TRUE;
}

COLORREF GetAccentColor()
{
    // In some programs, e.g. snippingtool.exe, the default blue accent color is used instead of the Windows theme with DwmGetColorizationColor.
    // Use the immersive color API if available, fall back to DwmGetColorizationColor
    // https://github.com/ALTaleX531/TranslucentFlyouts/blob/017970cbac7b77758ab6217628912a8d551fcf7c/Common/ThemeHelper.hpp#L278
    static const auto s_GetImmersiveColorFromColorSetEx{reinterpret_cast<DWORD(WINAPI*)(DWORD dwImmersiveColorSet, DWORD dwImmersiveColorType, BOOL bIgnoreHighContrast, DWORD dwHighContrastCacheMode)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(95)))};
    static const auto s_GetImmersiveColorTypeFromName{reinterpret_cast<DWORD(WINAPI*)(LPCWSTR name)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(96)))};
    static const auto s_GetImmersiveUserColorSetPreference{reinterpret_cast<DWORD(WINAPI*)(BOOL bForceCheckRegistry, BOOL bSkipCheckOnFail)>(GetProcAddress(GetModuleHandleW(L"UxTheme.dll"), MAKEINTRESOURCEA(98)))};

    COLORREF AccentClr{ 0 };
    BOOL opaque = FALSE;
    
    if (s_GetImmersiveColorFromColorSetEx && s_GetImmersiveColorTypeFromName && s_GetImmersiveUserColorSetPreference) 
    {
        AccentClr = s_GetImmersiveColorFromColorSetEx(
            s_GetImmersiveUserColorSetPreference(FALSE, FALSE),
            s_GetImmersiveColorTypeFromName(L"ImmersiveStartHoverBackground"),
            TRUE,
            0
        );
        return RGB((AccentClr & 0xFF), (AccentClr >> 8) & 0xFF, (AccentClr >> 16) & 0xFF);
    }
    else if (SUCCEEDED(DwmGetColorizationColor(&AccentClr, &opaque)))
    {
        return RGB((AccentClr >> 16) & 0xFF, (AccentClr >> 8) & 0xFF,  AccentClr & 0xFF);
    }
    else
        return g_AccentPalette.Colors[SystemAccentColorBase];
}

D2D1_COLOR_F MyD2D1Color(BYTE A, BYTE R, BYTE G, BYTE B)
{
    return D2D1_COLOR_F{
        static_cast<FLOAT>(R) / 255.0f,
        static_cast<FLOAT>(G) / 255.0f,
        static_cast<FLOAT>(B) / 255.0f,
        static_cast<FLOAT>(A) / 255.0f
    };
}

D2D1_COLOR_F MyD2D1Color(BYTE R, BYTE G, BYTE B)
{
    return MyD2D1Color(255, R, G, B);
}

D2D1_COLOR_F IsAccentColorPossibleD2D(BYTE A, BYTE R, BYTE G, BYTE B, AccentColorShade AccentShade = SystemAccentColorBase)
{
    if (g_settings.AccentColorize)
    {       
        // Change light/dark accent shades to dark/light depending theme dark mode
        /* if (ShouldSystemUseDarkMode() && AccentShade > 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade);
        else if (!ShouldSystemUseDarkMode() && AccentShade < 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade); */
        R = GetRValue(g_AccentPalette.Colors[(INT)AccentShade]);
        G = GetGValue(g_AccentPalette.Colors[(INT)AccentShade]);
        B = GetBValue(g_AccentPalette.Colors[(INT)AccentShade]);
        return MyD2D1Color(A, R, G, B);
    }
    else
        return MyD2D1Color(A, R, G, B);
}

D2D1_COLOR_F IsAccentColorPossibleD2D(BYTE R, BYTE G, BYTE B, AccentColorShade AccentShade = SystemAccentColorBase)
{
    if (g_settings.AccentColorize)
    {   
        // Change light/dark accent shades to dark/light depending theme dark mode
        /* if (ShouldSystemUseDarkMode() && AccentShade > 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade);
        else if (!ShouldSystemUseDarkMode() && AccentShade < 3)
            AccentShade = static_cast<AccentColorShade>(6 - AccentShade); */
        R = GetRValue(g_AccentPalette.Colors[(INT)AccentShade]);
        G = GetGValue(g_AccentPalette.Colors[(INT)AccentShade]);
        B = GetBValue(g_AccentPalette.Colors[(INT)AccentShade]);
        return MyD2D1Color(255, R, G, B);
    }
    else
        return MyD2D1Color(R, G, B);
}

HRESULT WINAPI HookedDwmSetWindowAttribute(HWND hWnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute)
{    
    if(!IsWindowEligible(hWnd))
        return DwmSetWindowAttribute_orig(hWnd, dwAttribute, pvAttribute, cbAttribute);
    
    // Popup menus (#32768) pass here by default to paint 
    // handle by the internal uxtheme function CThemeMenuPopup::EnableRoundedCorners()
    if (IsWindowClass(hWnd, MENUPOPUP_CLASS) && g_settings.FlyoutsEffects && dwAttribute == DWMWA_WINDOW_CORNER_PREFERENCE) {
        UINT menuCornerRadius = DWMWCP_ROUND;
        return DwmSetWindowAttribute_orig(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &menuCornerRadius, sizeof(menuCornerRadius));
    }
    
    if ((dwAttribute == DWMWA_SYSTEMBACKDROP_TYPE || dwAttribute == DWMWA_USE_HOSTBACKDROPBRUSH) && g_settings.BgType != g_settings.Default)
    {
        if (g_settings.BgType == g_settings.AccentBlurBehind)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &AUTO, sizeof(UINT));
        if(g_settings.BgType == g_settings.AcrylicSystemBackdrop)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &TRANSIENTWINDOW, sizeof(UINT));
        else if(g_settings.BgType == g_settings.MicaAlt)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &TABBEDWINDOW, sizeof(UINT));
        else if(g_settings.BgType == g_settings.Mica)
            return DwmSetWindowAttribute_orig(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &MAINWINDOW, sizeof(UINT));
    }
    
    return DwmSetWindowAttribute_orig(hWnd, dwAttribute, pvAttribute, cbAttribute);
}

HRESULT WINAPI HookedDwmExtendFrameIntoClientArea(HWND hWnd, const MARGINS* pMarInset)
{
    if(!IsWindowEligible(hWnd))
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, pMarInset);
    
    if(!IsWindowClass(hWnd, L"CASCADIA_HOSTING_WINDOW_CLASS")) {
        static const MARGINS margins = {-1, -1, -1, -1};
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, &margins);
    }
    else
        [[clang::musttail]]return DwmExtendFrameIntoClientArea_orig(hWnd, pMarInset);
}

HWND WINAPI HookedNtUserCreateWindowEx(DWORD dwExStyle,
                                       PUNICODE_STRING UnsafeClassName,
                                       LPCWSTR         VersionedClass,
                                       PUNICODE_STRING UnsafeWindowName,
                                       DWORD           dwStyle,
                                       LONG            x,
                                       LONG            y,
                                       LONG            nWidth,
                                       LONG            nHeight,
                                       HWND            hWndParent,
                                       HMENU           hMenu,
                                       HINSTANCE       hInstance,
                                       LPVOID          lpParam,
                                       DWORD           dwShowMode,
                                       DWORD           dwUnknown1,
                                       DWORD           dwUnknown2,
                                       VOID*           qwUnknown3) 
{
    HWND hWnd = NtUserCreateWindowEx_Original(
        dwExStyle, UnsafeClassName, VersionedClass, UnsafeWindowName, dwStyle,
        x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam,
        dwShowMode, dwUnknown1, dwUnknown2, qwUnknown3);
    
    if(hWnd)
        NewWindowShown(hWnd);

    return hWnd;
}

std::wstring GetThemeClass(HTHEME hTheme) 
{
    typedef HRESULT(WINAPI* pGetThemeClass)(HTHEME, LPCTSTR, INT);
    static auto GetClassName = (pGetThemeClass)GetProcAddress(GetModuleHandleW(L"uxtheme"), MAKEINTRESOURCEA(74));

    std::wstring ret;
    if (GetClassName)
    {
        WCHAR buffer[255] = { 0 };
        HRESULT hr = GetClassName(hTheme, buffer, 255);
        return SUCCEEDED(hr) ? buffer : L"";
    }
    return ret;
}

// Alpha gamma correction LUT — built once at process startup.
// Applies sRGB inverse gamma ^(1/1.4) to coverage values, which:
// Brightens antialiased edge pixels
// Closely matches DrawTextWithGlow's CGamma table behavior
// Requires no RGB linearization — operates on alpha only
static std::array<BYTE, 256> g_textAlphaGammaLUT = {0};
VOID GenerateTextAlphaGammaLUT()
{
    for (INT i = 0; i < 256; ++i) 
    {
        FLOAT a = i * (1.0f / 255.0f);
        // a = 1.0 (white luma) -> gamma = 1.5
        // a = 0.0 (black luma) -> gamma = 1.2
        FLOAT gamma = 1.2f + (0.3f * a);
        // Apply the dynamic inverse gamma
        FLOAT g = powf(a, 1.0f / gamma);
        g_textAlphaGammaLUT[i] = (BYTE)(g * 255.0f + 0.5f);
    }
}

BOOL ExtTextOutBkPaint(HDC hdc, LPCRECT lprect, UINT options)
{
    if (!(options & ETO_OPAQUE)) 
        return TRUE;
        
    // Make opaque highlighted text background rectangle
    if (GetBkColor(hdc) == GetSysColor(COLOR_HIGHLIGHT)) 
    {
        BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
        HDC memDC = nullptr;
        HPAINTBUFFER hpb = BeginBufferedPaint(hdc, lprect, BPBF_TOPDOWNDIB, &params, &memDC); 
        if (!hpb) {
            Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
            return FALSE;
        }

        FillRect(memDC, lprect, GetSysColorBrush(COLOR_HIGHLIGHT));
        BufferedPaintMakeOpaque(hpb, lprect);

        if (FAILED(EndBufferedPaint(hpb, TRUE))) {
            Wh_Log(L"EndBufferedPaint failed error:0x%08x", GetLastError());
            return FALSE;
        }
    }
    else {
        HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
        FillRect(hdc, lprect, brush);
        DeleteObject(brush);
    }
    return TRUE;
}

BOOL ExtTextOutComposition(HDC hdc, HPAINTBUFFER hpb, LPCRECT pTextRect)
{
    RGBQUAD* pPixels = nullptr;
    INT rowWidth = 0; // stride
    if (FAILED(GetBufferedPaintBits(hpb, &pPixels, &rowWidth))) {
        EndBufferedPaint(hpb, FALSE);
        Wh_Log(L"Failed GetBufferedPaintBits error:0x%08x", GetLastError());
        return FALSE;
    }

    INT txtRcHeight = RECTHEIGHT(pTextRect);
    INT txtRcWidth = RECTWIDTH(pTextRect);
    
    BYTE pxBlue = GetBValue(GetTextColor(hdc));
    BYTE pxGreen = GetGValue(GetTextColor(hdc));
    BYTE pxRed = GetRValue(GetTextColor(hdc));
    
    // Alpha composition
    for (INT cy = 0; cy < txtRcHeight; ++cy) {
        RGBQUAD* row = pPixels + (cy * rowWidth);
        for (INT cx = 0; cx < txtRcWidth; ++cx) {
            RGBQUAD& px = row[cx];
            // Avoid background pixels
            if ((px.rgbBlue | px.rgbGreen | px.rgbRed) == 0)
                continue;
            
            // Greyscale alpha
            BYTE luma = (px.rgbBlue + (px.rgbGreen << 1) + px.rgbRed) >> 2;          
            // Gamma alpha correction
            BYTE txtA = g_textAlphaGammaLUT[luma];
            
            px.rgbBlue     = (pxBlue * txtA) >> 8;
            px.rgbGreen    = (pxGreen * txtA) >> 8;
            px.rgbRed      = (pxRed * txtA) >> 8;
            px.rgbReserved = txtA;
        }
    }
    
    return TRUE;
}

VOID ExtTextOutAlignRect(HDC hdc, POINT &point, SIZE textSize, UINT textAlignment)
{
    // TA_BASELINE's bits are a superset of TA_BOTTOM's, and TA_CENTER's are
    // a superset of TA_RIGHT's - mask the field and compare for equality
    // rather than testing individual bits, or TA_CENTER/TA_BASELINE get
    // misread as TA_RIGHT/TA_BOTTOM.
    UINT vAlign = textAlignment & (TA_BOTTOM | TA_BASELINE);
    UINT hAlign = textAlignment & (TA_RIGHT | TA_CENTER);
    if (vAlign == TA_BASELINE)
    {
        TEXTMETRIC tm;
        if (GetTextMetrics(hdc, &tm))
            point.y = point.y - tm.tmAscent;        
    }
    else if (vAlign == TA_BOTTOM)
        point.y = point.y - textSize.cy;

    if (hAlign == TA_CENTER)
        point.x = point.x - textSize.cx / 2;
    else if (hAlign == TA_RIGHT)
        point.x = point.x - textSize.cx;

    return;
}

VOID ExtTextOutDxWidth(UINT options, const INT* lpDx, UINT c, SIZE& textSize)
{    
    INT dx = 0;
    INT dy = 0;
    UINT stride = (options & ETO_PDY) ? 2 : 1;
    
    for (UINT i = 0; i < c; i++)
    {
        dx += lpDx[i * stride];
        if (options & ETO_PDY)
            dy += lpDx[i * stride + 1];
    }
    
    textSize.cx = std::max<LONG>(textSize.cx, dx);
    if (options & ETO_PDY)
        textSize.cy += abs(dy); // Expand height to encompass the vertical shifting
}

// Calculate text boundaries
BOOL ExtTextOutCalcRect(HDC hdc, POINT point, UINT options, RECT& textRect,
                        LPCRECT lprect, LPCWSTR lpString, UINT c, const INT* lpDx)
{
    SIZE textSize = {0};
    UINT ta = GetTextAlign(hdc);

    BOOL res = (options & ETO_GLYPH_INDEX)
        ? GetTextExtentPointI(hdc, (WORD*)lpString, c, &textSize)
        : GetTextExtentPoint32W(hdc, lpString, c, &textSize);
    if (!res)
        return FALSE;

    if (lpDx)
        ExtTextOutDxWidth(options, lpDx, c, textSize);
    if (ta)
        ExtTextOutAlignRect(hdc, point, textSize, ta);

    SetRect(&textRect, point.x, point.y, point.x + textSize.cx, point.y + textSize.cy);

    if (lprect) {
        if (options & ETO_CLIPPED)                        // GDI clips the glyphs to it
            IntersectRect(&textRect, &textRect, lprect);
        if (options & ETO_OPAQUE)                         // ...and fills it
            UnionRect(&textRect, &textRect, lprect);
    }

    return !IsRectEmpty(&textRect);
}

BOOL ExtTextOutShouldSkip(HDC hdc, UINT options, LPCRECT lprect, LPCWSTR lpString, INT c)
{
    if (!hdc || !lpString || !c || !options || GetTextAlign(hdc) & TA_UPDATECP)
        return TRUE;
    
    if (options & (ETO_OPAQUE | ETO_CLIPPED) && (!lprect || IsRectEmpty(lprect)))
        return TRUE;
    
    return FALSE;
}

BOOL WINAPI HookedExtTextOutW(
    HDC hdc,
    INT x,
    INT y,
    UINT options,
    LPCRECT lprect,
    LPCWSTR lpString,
    UINT c,
    const INT* lpDx)
{   
    if (ExtTextOutShouldSkip(hdc, options, lprect, lpString, c))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    RECT textRect {0};
    if (!ExtTextOutCalcRect(hdc, {x, y}, options, textRect, lprect, lpString, c, lpDx))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    if (!ExtTextOutBkPaint(hdc, lprect, options))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
            
    // https://devblogs.microsoft.com/oldnewthing/20110520-00/?p=10613
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
    params.dwFlags = BPPF_ERASE | BPPF_NOCLIP;
    BLENDFUNCTION blend = {AC_SRC_OVER, 0, 255, AC_SRC_ALPHA};
    params.pBlendFunction = &blend;

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hdc, &textRect, BPBF_TOPDOWNDIB, &params, &memDC);
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
    }

    SelectObject(memDC, GetCurrentObject(hdc, OBJ_FONT));
    SetTextAlign(memDC, GetTextAlign(hdc));
    SetLayout(memDC, GetLayout(hdc));
    SetBkMode(memDC, TRANSPARENT);
    SetTextColor(memDC, RGB(255, 255, 255)); // White text mask

    // Remove default background painting operation, as it done by our ExtTextOutBkPaint helper
    WINBOOL res = ExtTextOutW_orig(memDC, x, y, options & ~ETO_OPAQUE, lprect, lpString, c, lpDx);

    // Text greyscale alpha composition
    if (!ExtTextOutComposition(hdc, hpb, &textRect))
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);

    // EndBufferedPaint executes AlphaBlend only on DIBs otherwise applies BitBlt.
    if (FAILED(EndBufferedPaint(hpb, TRUE))) {
        Wh_Log(L"EndBufferedPaint failed error:0x%08x", GetLastError());
        return ExtTextOutW_orig(hdc, x, y, options, lprect, lpString, c, lpDx);
    }
    return res;
}

// Bypass alpha blending operation done by DrawTextWithGlow (e.g context menus, win32 adressbar) as it is done by our ExtTextOutW hook.
HRESULT WINAPI HookedDrawTextWithGlow(HDC hdcMem, LPWSTR pszText, UINT cch, RECT* pRect, DWORD dwFlags, COLORREF crText,
                                      COLORREF crGlow, UINT nGlowRadius, UINT nGlowIntensity, BOOL fPreMultiply,
                                      DTT_CALLBACK_PROC pfnDrawTextCallback, LPARAM lParam)
{
    if (pRect->right == pRect->left || pRect->bottom == pRect->top) { 
        if ((dwFlags & DT_CALCRECT) == 0)
            return DrawTextWithGlow(hdcMem, pszText, cch, pRect, dwFlags, crText, crGlow, nGlowRadius, nGlowIntensity, fPreMultiply, pfnDrawTextCallback, lParam);
    }

    // Do not mess with text using glow effects (if such exist in Win11)
    if (nGlowRadius > 0)
        return DrawTextWithGlow(hdcMem, pszText, cch, pRect, dwFlags, crText, crGlow, nGlowRadius, nGlowIntensity, fPreMultiply, pfnDrawTextCallback, lParam);

    SetTextColor(hdcMem, crText);
    SetBkColor(hdcMem, RGB(0, 0, 0));
    
    HRESULT hr = S_OK;
    
    if (pfnDrawTextCallback)
        hr = pfnDrawTextCallback(hdcMem, pszText, cch, pRect, dwFlags, lParam);
    else
        hr = DrawTextW(hdcMem, pszText, cch, pRect, dwFlags & ~DT_MODIFYSTRING);

    return hr;
}

INT WINAPI HookedDrawTextW(HDC hdc, LPCWSTR lpchText, INT cchText, LPRECT lprc, UINT format)
{   
    // Windows 11 context menus use Fluent icons as glyphs
    // Handled internally in the shell32 routine s_DrawGlyph()
    auto ContextMenuGlyphs = [&hdc, &lpchText]() {
        const WCHAR fluentIconGlyph_ChevronRightMed = 0xE974;
        const WCHAR fluentIconGlyph_ChevronLeftMed = 0xE973;
        const WCHAR fluentIconGlyph_AcceptMedium = 0xF78C;
        const WCHAR fluentIconGlyph_RadioBullet = 0xE915;
        
        if (*lpchText == fluentIconGlyph_ChevronRightMed || *lpchText == fluentIconGlyph_ChevronLeftMed 
            || *lpchText == fluentIconGlyph_AcceptMedium || *lpchText == fluentIconGlyph_RadioBullet)
                g_IsSysThemeDarkMode ? SetTextColor(hdc, RGB(255, 255, 255)) : SetTextColor(hdc, RGB(0, 0, 0));
    };

    // Catch and modify context menu fluent icons coloring
    if (cchText == 1)
        ContextMenuGlyphs();

    // Modify and convert hardcoded Syslink black text color into white (e.g. inside "Sharing" win32 Properties tab)
    if (!g_IsSysThemeDarkMode || (GetTextColor(hdc) & 0x00FFFFFF) != RGB(0, 0, 0))
        return DrawTextW_orig(hdc, lpchText, cchText, lprc, format);
    
    HWND hWnd = WindowFromDC(hdc);
    if (GetWindowClass(hWnd) == L"SysLink")
        SetTextColor(hdc, RGB(255, 255, 255));

    return DrawTextW_orig(hdc, lpchText, cchText, lprc, format);
}

HRESULT WINAPI HookedDrawThemeTextEx(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCWSTR pszText,
    INT cchText, DWORD dwTextFlags, LPRECT pRect, const DTTOPTS* pOptions)
{
    std::wstring ThemeClassName = GetThemeClass(hTheme);
    if (pOptions == nullptr) {
        DTTOPTS Options = { sizeof(DTTOPTS) };
        GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
        Options.dwFlags |= DTT_TEXTCOLOR;
        return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, &Options);
    }

    if ((pOptions->dwFlags & DTT_CALCRECT))
        return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, pOptions);
    
    DTTOPTS Options = { sizeof(DTTOPTS) };
    Options = *pOptions;
    GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
    Options.dwFlags |= DTT_TEXTCOLOR;
    return DrawThemeTextEx_orig(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, (LPRECT)pRect, &Options);

}

HRESULT WINAPI HookedDrawThemeText(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCTSTR pszText,
    INT cchText, DWORD dwTextFlags, DWORD dwTextFlags2, LPCRECT pRect) 
{
    DTTOPTS Options = { sizeof(DTTOPTS) };
    RECT Rect = *pRect;

    GetThemeColor(hTheme, iPartId, iStateId, TMT_TEXTCOLOR, &Options.crText);
    HRESULT ret = HookedDrawThemeTextEx(hTheme, hdc, iPartId, iStateId, pszText, cchText, dwTextFlags, &Rect, &Options);

    return ret;
}

// https://github.com/ramensoftware/windhawk-mods/blob/15e5d9838349e4b927ed8ac5433e9894ff6cda28/mods/uxtheme-hook.wh.cpp#L90
typedef VOID(CALLBACK *Element_PaintBgT)(class Element*, HDC , class Value*, LPRECT, LPRECT, LPRECT, LPRECT);
Element_PaintBgT Element_PaintBg;
VOID CALLBACK Element_PaintBgHook(class Element* This, HDC hdc, class Value* value, LPRECT pRect, LPRECT pClipRect, LPRECT pExcludeRect, LPRECT pTargetRect)
{   
    Element_PaintBg(This, hdc, value, pRect, pClipRect, pExcludeRect, pTargetRect);

    //unsigned char byteValue = *(reinterpret_cast<unsigned char*>(value) + 8);
    if ((INT)(*(DWORD *)value << 26) >> 26 != 9 )
    {
        auto v44 = *((__int64 *)value + 1);
        auto v45 = (v44+20)& 7;
        // 6-> selection
        // 3-> hovered stuff
        // 4-> cpanel top bar and side bar (white image)
        // 1-> some new cp page style (cp_hub_frame)
        if (v45 == 4)
            FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        else
            return;
    }
    else
        return;
}

VOID CplDuiHook()
{
    WindhawkUtils::SYMBOL_HOOK dui70dll_hooks[] =
    {
        {
            {
                L"public: void __cdecl DirectUI::Element::PaintBackground(struct HDC__ *,class DirectUI::Value *,struct tagRECT const &,struct tagRECT const &,struct tagRECT const &,struct tagRECT const &)"
            },
            &Element_PaintBg,
            Element_PaintBgHook,
            FALSE
        },
    };

    HMODULE hDui = LoadLibraryEx(L"dui70.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    WindhawkUtils::HookSymbols(hDui, dui70dll_hooks, ARRAYSIZE(dui70dll_hooks));
}

constexpr INT SysColorElements[] = {
	COLOR_SCROLLBAR ,
    COLOR_BACKGROUND ,
    COLOR_ACTIVECAPTION ,
    COLOR_INACTIVECAPTION ,
    COLOR_MENU ,
    COLOR_WINDOW ,
    COLOR_WINDOWFRAME ,
    COLOR_MENUTEXT ,
    COLOR_WINDOWTEXT ,
    COLOR_CAPTIONTEXT ,
    COLOR_ACTIVEBORDER ,
    COLOR_INACTIVEBORDER ,
    COLOR_APPWORKSPACE ,
    COLOR_HIGHLIGHT ,
    COLOR_HIGHLIGHTTEXT ,
    COLOR_BTNFACE ,
    COLOR_BTNSHADOW ,
    COLOR_GRAYTEXT ,
    COLOR_BTNTEXT ,
    COLOR_INACTIVECAPTIONTEXT ,
    COLOR_BTNHIGHLIGHT ,
    COLOR_3DDKSHADOW ,
    COLOR_3DLIGHT ,
    COLOR_INFOTEXT ,
    COLOR_INFOBK ,
    COLOR_GRADIENTACTIVECAPTION ,
    COLOR_GRADIENTINACTIVECAPTION ,
    COLOR_MENUHILIGHT ,
    COLOR_MENUBAR,
    COLOR_HOTLIGHT
};

HTHEME SetThemeHandle(HWND hWnd, HTHEME& hTheme, LPCWSTR themeclass)
{
    return hTheme = OpenThemeData(hWnd, themeclass);
}

VOID RevertSysColors()
{
    HTHEME hThemeSysMetrics = nullptr;
    if (!SetThemeHandle(nullptr, hThemeSysMetrics, L"sysmetrics"))
        return;
    
    COLORREF aNewColors[ARRAYSIZE(SysColorElements)];

    for (UINT i = 0; i < ARRAYSIZE(SysColorElements); i++) 
        aNewColors[i] = GetThemeSysColor(hThemeSysMetrics, i); 
    SetSysColors(ARRAYSIZE(SysColorElements), SysColorElements, aNewColors); 

    CloseThemeData(hThemeSysMetrics);
    hThemeSysMetrics = nullptr;
}

static COLORREF GetDefaultSysColor(INT nIndex)
{
    if (nIndex == COLOR_SCROLLBAR)
        return RGB(200, 200, 200);
    else if (nIndex == COLOR_BACKGROUND || nIndex == COLOR_MENUTEXT || nIndex == COLOR_WINDOWTEXT || nIndex == COLOR_CAPTIONTEXT
            || nIndex == COLOR_BTNTEXT || nIndex == COLOR_INACTIVECAPTIONTEXT || nIndex == COLOR_INFOTEXT)
                return RGB(0, 0, 0);
    else if (nIndex == COLOR_ACTIVECAPTION)
        return RGB(153, 180, 209);
    else if (nIndex == COLOR_INACTIVECAPTION)
        return RGB (191, 205, 219);
    else if (nIndex == COLOR_MENU || nIndex == COLOR_BTNFACE || nIndex == COLOR_MENUBAR)  
        return RGB(240, 240, 240);
    else if (nIndex == COLOR_WINDOW || nIndex == COLOR_BTNHIGHLIGHT || nIndex == COLOR_INFOBK || nIndex == COLOR_HIGHLIGHTTEXT)
        return RGB(255, 255, 255);
    else if (nIndex == COLOR_WINDOWFRAME)
        return RGB(100, 100, 100);
    else if (nIndex == COLOR_ACTIVEBORDER)
        return RGB(180, 180, 180);
    else if (nIndex == COLOR_INACTIVEBORDER)
        return RGB(244, 247, 252);
    else if (nIndex == COLOR_APPWORKSPACE)
        return RGB(171, 171, 171);
    else if (nIndex == COLOR_HIGHLIGHT || nIndex == COLOR_MENUHILIGHT)
        return RGB(0, 120, 212);
    else if (nIndex == COLOR_BTNSHADOW)
        return RGB(160, 160, 160);
    else if (nIndex == COLOR_GRAYTEXT)
        return RGB(109, 109, 109);
    else if (nIndex == COLOR_3DDKSHADOW)
        return RGB(105, 105, 105);
    else if (nIndex == COLOR_3DLIGHT)
        return RGB(227, 227, 227);
    else if (nIndex == COLOR_HOTLIGHT)
        return RGB(0, 102, 204);
    else if (nIndex == COLOR_GRADIENTACTIVECAPTION)
        return RGB(185, 209, 234);
    else if (nIndex == COLOR_GRADIENTINACTIVECAPTION)
        return RGB(215, 228, 242);
    
    return GetSysColor_orig(nIndex);
}

static COLORREF GetCustomSysColor(INT nIndex)
{
    if (nIndex == COLOR_SCROLLBAR || nIndex == COLOR_BACKGROUND || nIndex == COLOR_MENU || nIndex == COLOR_WINDOW || nIndex == COLOR_INACTIVEBORDER || nIndex == COLOR_INFOBK ||
        nIndex == COLOR_MENUBAR)
        return RGB(0, 0, 0);
    else if (nIndex == COLOR_GRADIENTACTIVECAPTION || nIndex == COLOR_INACTIVECAPTION)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 0, 0);
    else if (nIndex == COLOR_ACTIVECAPTION || nIndex == COLOR_GRADIENTINACTIVECAPTION)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(32, 32, 32);
    else if (nIndex == COLOR_ACTIVEBORDER)
        return RGB(32, 32, 32);
    else if (nIndex == COLOR_BTNSHADOW)
        return RGB(32, 32, 32);
    else if (nIndex == COLOR_WINDOWFRAME)
        return RGB(96, 96, 96);
    else if (nIndex == COLOR_BTNHIGHLIGHT)
        return RGB(64, 64, 64);
    else if (nIndex == COLOR_WINDOWTEXT)
        return RGB(240, 240, 240);
    else if (nIndex == COLOR_MENUTEXT || nIndex == COLOR_CAPTIONTEXT ||
             nIndex == COLOR_BTNTEXT || nIndex == COLOR_INFOTEXT || nIndex == COLOR_HIGHLIGHTTEXT)
        return RGB(255, 255, 255);
    else if (nIndex == COLOR_APPWORKSPACE)
        return RGB(8, 8, 8);
    else if (nIndex == COLOR_HIGHLIGHT || nIndex == COLOR_MENUHILIGHT)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 120, 215);
    else if (nIndex == COLOR_BTNFACE)
        return RGB(0, 0, 0);
    else if (nIndex == COLOR_GRAYTEXT)
        return RGB(128, 128, 128);
    else if (nIndex == COLOR_INACTIVECAPTIONTEXT)
        return RGB(160, 160, 160);
    else if (nIndex == COLOR_3DDKSHADOW)
        return RGB(16, 16, 16);
    else if (nIndex == COLOR_3DLIGHT)
        return RGB(4, 4, 4);
    else if (nIndex == COLOR_HOTLIGHT)
        return (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(0, 148, 251);

    return GetSysColor_orig(nIndex);
}

COLORREF WINAPI HookedGetSysColor(INT nIndex) 
{
    if (g_DefaultSysColors)
        return GetDefaultSysColor(nIndex);
    else
        return GetCustomSysColor(nIndex);
}

HBRUSH WINAPI HookedGetSysColorBrush(INT nIndex) 
{
    if (nIndex < 0 || nIndex > COLOR_MENUBAR)
        return GetSysColorBrush_orig(nIndex);
    
    auto& cacheArray = g_DefaultSysColors ? g_themeCachedDefaultSysColorBrushes : g_themeCachedCustomSysColorBrushes;
    
    HBRUSH cachedBrush = cacheArray[nIndex];
    
    if (cachedBrush && GetObjectType(cachedBrush) == OBJ_BRUSH)
        return cachedBrush; 

    AcquireSRWLockExclusive(&g_SysColorsLock);
    
    HBRUSH& refSysBrush = cacheArray[nIndex];
    
    if (refSysBrush && GetObjectType(refSysBrush) != OBJ_BRUSH)
        refSysBrush = NULL; 

    if (!refSysBrush) {
        COLORREF color = HookedGetSysColor(nIndex);
        refSysBrush = CreateSolidBrush(color);
    }

    HBRUSH hbr = refSysBrush;
    ReleaseSRWLockExclusive(&g_SysColorsLock);
    
    return hbr;
}

VOID ColorizeSysColors()
{   
    // Stop recalling SetSysColors if syscolor changes have been applied.
    // SetSysColors redraws all top level windows causing flickering.
    if (GetSysColor_orig(COLOR_WINDOW) == RGB(0, 0, 0))
    {
        if (g_settings.AccentColorize && GetSysColor_orig(COLOR_HIGHLIGHT) == g_settings.AccentColor)
            return;
        else if (!g_settings.AccentColorize)
            return ;
    }
    
    COLORREF aNewColors[ARRAYSIZE(SysColorElements)];
    for (UINT i = 0; i < ARRAYSIZE(SysColorElements); i++)
        aNewColors[i] = GetCustomSysColor(SysColorElements[i]);
        
    SetSysColors(ARRAYSIZE(SysColorElements), SysColorElements, aNewColors);
}

HRESULT WINAPI HookedGetColorTheme(HTHEME hTheme, INT iPartId, INT iStateId, INT iPropId, COLORREF *pColor) 
{
    HRESULT hr = GetThemeColor_orig(hTheme, iPartId, iStateId, iPropId, pColor);
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ItemsView" && iPropId == TMT_TEXTCOLOR && ((iPartId == 4 && iStateId == 1) || iPartId == 5))
    {
        *pColor = (!g_IsSysThemeDarkMode && *pColor == 0x006D6D6D) ? RGB(0, 0, 0) : *pColor;
        return S_OK;
    }
    if (ThemeClassName == L"ListView" && iPropId == TMT_TEXTCOLOR && iPartId == LVP_LISTITEM)
    {
        *pColor = (g_IsSysThemeDarkMode && (iStateId == THEMECLS_COMMONPROPS_PART || iStateId == LISS_SELECTED)) ? RGB(255, 255, 255) : *pColor;
        *pColor = (!g_IsSysThemeDarkMode && *pColor == 0x006D6D6D) ? RGB(0, 0, 0) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"ListView" && iPartId == LVP_GROUPHEADER)
    {
        *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane" && (iPartId == 5 || iPartId == 7 || iPartId == 6) && iPropId == TMT_FILLCOLOR) {
        *pColor = (iPartId == 6) ? RGB(192, 192, 192) : RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane" && iPropId == TMT_TEXTCOLOR) {
        *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (iPropId == TMT_TEXTCOLOR && ThemeClassName == L"ControlPanel" && iPartId == CPANEL_HELPLINK) {
        *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
        return S_OK;
    }  
    else if (ThemeClassName == L"ControlPanelStyle" && iPropId == TMT_TEXTCOLOR)
    {
        if ((iPartId == CPANEL_BODYTITLE || iPartId == CPANEL_GROUPTEXT || iPartId == CPANEL_MESSAGETEXT 
            || iPartId == CPANEL_BODYTEXT || iPartId == CPANEL_TITLE || iPartId == CPANEL_CONTENTPANELABEL) && iStateId == 0)
        {
            *pColor =  (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId == CPANEL_SECTIONTITLELINK && (iStateId == CPCL_NORMAL || iStateId == CPCL_HOT))
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPCL_NORMAL) ? RGB(240, 255, 240) : RGB(224, 255, 224)) : *pColor;
            return S_OK;                   
        }
        else if (iPartId == CPANEL_CONTENTLINK || iPartId == CPANEL_HELPLINK)
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPHL_NORMAL) ? RGB(96, 205, 255) : (iStateId == CPHL_HOT) ? RGB(153, 236, 255) : 
                      (iStateId == CPHL_PRESSED) ? RGB(0, 148, 251) : RGB(96, 96, 96)) : *pColor;
            return S_OK;
        }
        else if (iPartId == CPANEL_TASKLINK) 
        {
            *pColor = (g_IsSysThemeDarkMode) ? ((iStateId == CPTL_NORMAL) ? RGB(190, 190, 190): (iStateId == CPTL_HOT) ? RGB(255, 255, 255) : 
                      (iStateId == CPTL_PRESSED) ? RGB(160, 160, 160) : (iStateId == CPTL_DISABLED) ? RGB(96, 96, 96) : RGB(255, 255, 255)) : *pColor;
            return S_OK;
        }
    }     
    else if (ThemeClassName == L"ControlPanelStyle" && iPropId == TMT_FILLCOLORHINT && (iPartId == CPANEL_CONTENTPANELINE && iStateId == 0))
    {
        *pColor = RGB(64, 64, 64);
        return S_OK;
    }
    else if (ThemeClassName == L"CommandModule" && iPropId == TMT_TEXTCOLOR)
    {
        // TASKBUTTON
        if(iPartId == 3 && iStateId == 1)
        {
            *pColor = *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        // LYBRARYPANETOPVIEW
        else if (iPartId == 9)
        {
            *pColor = (iStateId == 1) ? RGB(96, 205, 255) : (iStateId == 2) ? RGB(153, 236, 255) : (iStateId == 3) ? RGB(0, 148, 251) : RGB(96, 96, 96);
            return S_OK;
        }  
    }
    else if (ThemeClassName == L"TaskDialogStyle" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == TDLG_MAININSTRUCTIONPANE) {
            *pColor = RGB(96, 205, 255);
            return S_OK;
        }
        else if (iPartId == TDLG_CONTENTPANE || iPartId == TDLG_VERIFICATIONTEXT) {
            *pColor =  (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Button" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == BP_PUSHBUTTON && iStateId != PBS_DISABLED)
        {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId != BP_PUSHBUTTON)
        {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(192, 192, 192) : *pColor;
            return S_OK;
        }   
    }
    else if (ThemeClassName == L"Static")
    {
        *pColor = (g_IsSysThemeDarkMode && *pColor < RGB(16, 16, 16)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"TreeView" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Tab" && iPropId == TMT_TEXTCOLOR)
    {
        if (iStateId == CSTB_HOT)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(224, 224, 224) : *pColor;
        else if (iStateId == CSTB_SELECTED)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        else
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(192, 192, 192) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Edit" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == 1) {
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        else if (iPartId == THEMECLS_COMMONPROPS_PART) {
            *pColor = (g_IsSysThemeDarkMode && (*pColor & 0xff000000) == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Header" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"SearchEditBox" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (*pColor == 0x006d6d6d) ? ((g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0)) : *pColor;
        return S_OK;
    }
    else if (ThemeClassName == L"Combobox" && iPropId == TMT_TEXTCOLOR)
    {
        if (iStateId != CBXS_DISABLED)
            *pColor = (g_IsSysThemeDarkMode && *pColor == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
        return S_OK;
    }
    
    else if (ThemeClassName == L"Menu" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == MENU_BARITEM && (iStateId != MBI_DISABLED && iStateId != MBI_DISABLEDPUSHED)) {
            *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        else if ((iPartId == MENU_POPUPITEM || iPartId == 27) && (iStateId != 3 && iStateId != 4)) {
            *pColor = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Menu" && (iPropId == TMT_FILLCOLOR || iPropId == TMT_FILLCOLORHINT))
    {
        *pColor = (g_settings.FlyoutsEffects) ? RGB(0, 0, 0) : (g_settings.FillBg) ? RGB(32, 32, 32) : *pColor;
        return S_OK;
    }
    else if ((ThemeClassName == L"Toolbar") && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId == THEMECLS_COMMONPROPS_PART && iStateId != TS_DISABLED) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        if (iStateId == TS_DISABLED) {
            *pColor = RGB(128,128,128);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"Tooltip" && iPropId == TMT_TEXTCOLOR)
    {
        if (iPartId== TTP_STANDARD || iPartId == TTP_BALLOON) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(255, 255, 255) : RGB(0, 0, 0);
            return S_OK;
        }
        else if (iPartId == TTP_BALLOONTITLE) {
            *pColor = (g_IsSysThemeDarkMode) ? RGB(96, 205, 255) : *pColor;
            return hr;        
        }        
    }
    else if (ThemeClassName == L"DragDrop" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = (iStateId == 1) ? ((g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96, 205, 255)) : RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"ChartView")
    {
        if ((iPartId == 29 || iPartId == 31 || iPartId == 32 || iPartId == 33) && iStateId == 1) {
            if (iPropId == TMT_FILLCOLOR)
                *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
            // Instead of the 1st byte of the DWORD/COLORREF variable, the last byte is used as the alpha of the fill color
            else if (iPropId == TMT_ALPHALEVEL)
                *pColor = RGB(255, 0, 0);
            return S_OK;
        }
        if ((iPartId == 34) && iStateId == 1) {
            if (iPropId == TMT_FILLCOLOR)
                *pColor = (g_settings.AccentColorize) ? g_settings.AccentColor : RGB(96,205,255);
            else if (iPropId == TMT_ALPHALEVEL)
                *pColor = RGB(96, 0, 0);
            return S_OK;
        }
    }
    else if (ThemeClassName == L"MonthCal") {
        return hr;
    }
    else if (ThemeClassName == L"AeroWizardStyle" && iPropId == TMT_TEXTCOLOR)
    {
        *pColor = RGB(255, 255, 255);
        return S_OK;
    }
    else if (ThemeClassName == L"ScrollbarStyle" && iPropId == TMT_FILLCOLORHINT)
    {
        *pColor = RGB(96, 96, 96);
        return S_OK;
    }
    else if (ThemeClassName == L"TaskManager")
    {
        switch (iPartId)
        {
            case 2: case 41:
            case 42:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(21, 21, 21) : *pColor;
                break;
            case 3: case 20:
            case 26:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(0, 0, 0) : *pColor;
                break;
            case 4:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(8, 4, 0) : *pColor;
                break;
            case 5:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(20, 8, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(0, 0, 0);
                break;
            case 6:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(36, 12, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(12, 0, 0);
                break;
            case 7:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(56, 16, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(24, 0, 0);
                break;
            case 8:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(80, 20, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(40, 0, 0);
                break;
            case 9:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(108, 24, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(60, 0, 0);
                break;
            case 10:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(140, 24, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(84, 0, 0);
                break;
            case 11:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(176, 32, 0);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(112, 0, 0);
                break;
            case 12:
                if (iPropId == TMT_FILLCOLOR) *pColor = RGB(252, 104, 42);
                else if (iPropId == TMT_TEXTCOLOR) *pColor = RGB(140, 0, 0);
                break;
            case 13:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(241, 112, 122) : *pColor;
                break;
            case 14: case 15:
            case 16: case 17:
            case 18: case 19:
            case 24: case 25:
                *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(255, 255, 255) : *pColor;
                break;
            case 21: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(97, 113, 186) : *pColor; break;
            case 22: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(68, 79, 125) : *pColor; break;
            case 23: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(64, 64, 64) : *pColor; break;
            case 27: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 36, 44) : *pColor; break;
            case 28: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 40, 56) : *pColor; break;
            case 29: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 44, 68) : *pColor; break;
            case 30: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 48, 80) : *pColor; break;
            case 31: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 52, 92) : *pColor; break;
            case 32: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 52, 104) : *pColor; break;
            case 33: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 60, 116) : *pColor; break;
            case 34: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 64, 128) : *pColor; break;
            case 35: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 68, 140) : *pColor; break;
            case 36: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 72, 152) : *pColor; break;
            case 37: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(32, 76, 164) : *pColor; break;
            case 38: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(17, 125, 187) : *pColor; break;
            case 39: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(34, 38, 55) : *pColor; break;
            case 40: *pColor = (iPropId == TMT_FILLCOLOR) ? RGB(35, 45, 71) : *pColor; break;
        }
        return S_OK;
    }
    else
    {
        if (iPropId == TMT_TEXTCOLOR)
        {
            *pColor = (g_IsSysThemeDarkMode && (*pColor & 0xff000000) == RGB(0, 0, 0)) ? RGB(255, 255, 255) : *pColor;
            return S_OK;
        }
        if (iPropId == TMT_FILLCOLOR)
        {
            *pColor = RGB(0,0,0);
            return S_OK;
        }
        else if (iPropId == TMT_FILLCOLORHINT)
        {
            *pColor = RGB(0,0,0);
            return S_OK;
        }
    }
    
    return hr;
}

HRESULT CreateBoundD2DRenderTarget(HDC hdc, LPCRECT pRect, ID2D1Factory* pFactory, ID2D1DCRenderTarget** ppRenderTarget)
{
    if (!pFactory || !ppRenderTarget)
        return FALSE;

    D2D1_RENDER_TARGET_PROPERTIES rtProps = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_SOFTWARE,
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
        NULL,
        NULL,
        D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE,
        D2D1_FEATURE_LEVEL_DEFAULT
    );

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> renderTarget;
    HRESULT hr = pFactory->CreateDCRenderTarget(&rtProps, &renderTarget);
    if (FAILED(hr)) {
        Wh_Log(L"Failed to create DC target [ERROR]: 0x%08X\n", hr);
        return hr;
    }

    hr = renderTarget->BindDC(hdc, pRect);
    if (FAILED(hr)) {
        Wh_Log(L"Failed to Bind DC target [ERROR]: 0x%08X\n", hr);
        return hr;
    }
    *ppRenderTarget = renderTarget.Detach();
    return S_OK;
}

class CThemeCache
{
public:
    std::array<HDC, 4> pushbutton;
    std::array<HDC, 8> radiobutton;
    std::array<HDC, 20> checkbutton;
    std::array<HDC, 4> commandlinkbutton;
    std::array<HDC, 3> commandlinkglyph;
    std::array<HDC, 14> listview;
    std::array<HDC, 4> scrollbar;
    std::array<HDC, 4> tab;
    std::array<HDC, 8> combobox;
    std::array<HDC, 4> editbox;
    std::array<HDC, 5> treeview;
    std::array<HDC, 8> treeviewglyph;
    std::array<HDC, 6> itemsview;
    std::array<HDC, 10> progressbar;
    std::array<HDC, 2> indeterminatebar;
    std::array<HDC, 2> trackbar;
    std::array<HDC, 24> trackbarthumb;
    std::array<HDC, 2> header;
    std::array<HDC, 1> previewseparator;
    std::array<HDC, 4> modulebutton;
    std::array<HDC, 4> modulelocationbutton;
    std::array<HDC, 8> modulesplitbutton;
    std::array<HDC, 12> navigationbutton;
    std::array<HDC, 1> navigationdivider;
    std::array<HDC, 5> toolbarbutton;
    std::array<HDC, 4> addressband;
    std::array<HDC, 4> menuitem;
    std::array<HDC, 1> dragdrop;
    std::array<HDC, 8> spin;

    BOOL CachePushButton(INT, INT);
    BOOL CacheRadioButton(LPCRECT, INT, INT);
    BOOL CacheCheckButton(LPCRECT, INT, INT);
    BOOL CacheCommandlinkButton(INT, INT);
    BOOL CacheCommandlinkGlyph(INT, INT);
    BOOL CacheListItem(INT, INT, INT);
    BOOL CacheListGroupHeader(INT, INT, INT);
    BOOL CacheScrollbar(INT, INT, INT);
    BOOL CacheScrollArrow(INT, INT);
    BOOL CacheTab(INT, INT);
    BOOL CacheCombobox(INT, INT, INT);
    BOOL CacheEditBox(INT, INT, INT);
    BOOL CacheTreeViewButton(INT, INT, INT);
    BOOL CacheTreeViewGlyph(INT, INT, INT, BOOL);
    BOOL CacheItemsView(INT, INT, INT);
    BOOL CacheProgressBar(INT, INT, INT);
    BOOL CacheIndeterminateBar(INT, INT);
    BOOL CacheTrackBar(INT, INT);
    BOOL CacheTrackBarThumb(INT, INT, INT);
    BOOL CacheTrackBarPointedThumb(INT, INT, INT);
    BOOL CacheHeader(INT, INT);
    BOOL CachePreviewPaneSeparator();
    BOOL CacheModuleButton(INT, INT);
    BOOL CacheModuleLocationButton(INT, INT);
    BOOL CacheModuleSplitButton(INT, INT, INT);
    BOOL CacheNavigationButton(INT, INT, INT);
    BOOL CacheNavigationDivider();
    BOOL CacheToolbarButton(INT, INT);
    BOOL CacheAddressBand(INT, INT);
    BOOL CacheMenuItem(INT, INT, INT);
    BOOL CacheDragDrop();
    BOOL CacheSpinButton(INT, INT, INT);

    BOOL CreateDIB(HDC& elementHdc, INT Width, INT Height)
    {
        if (elementHdc)
            DeleteHDC(elementHdc);

        if (!(elementHdc = CreateCompatibleDC(NULL)))
            return FALSE;

        BITMAPINFO bmi;
        bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmi.bmiHeader.biWidth = Width;
        bmi.bmiHeader.biHeight = -Height;
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biCompression = BI_RGB;
        
        VOID* pvBits;
        HBITMAP hBitmap = CreateDIBSection(elementHdc, &bmi, DIB_RGB_COLORS, &pvBits, nullptr, 0);
        if (!hBitmap)
            return FALSE;
        
        SelectObject(elementHdc, hBitmap);
        return TRUE;
    }

    VOID ClearCache()
    {
        for (HDC& hDC : pushbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : radiobutton)
            DeleteHDC(hDC);
        for (HDC& hDC : checkbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : commandlinkbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : commandlinkglyph)
            DeleteHDC(hDC);
        for (HDC& hDC : listview)
            DeleteHDC(hDC);
        for (HDC& hDC : scrollbar)
            DeleteHDC(hDC);
        for (HDC& hDC : tab)
            DeleteHDC(hDC);
        for (HDC& hDC : combobox)
            DeleteHDC(hDC);
        for (HDC& hDC : editbox)
            DeleteHDC(hDC);
        for (HDC& hDC : treeview)
            DeleteHDC(hDC);
        for (HDC& hDC : treeviewglyph)
            DeleteHDC(hDC);
        for (HDC& hDC : itemsview)
            DeleteHDC(hDC);
        for (HDC& hDC : progressbar)
            DeleteHDC(hDC);
        for (HDC& hDC : indeterminatebar)
            DeleteHDC(hDC);
        for (HDC& hDC : trackbar)
            DeleteHDC(hDC);
        for (HDC& hDC : trackbarthumb)
            DeleteHDC(hDC);
        for (HDC& hDC : header)
            DeleteHDC(hDC);
        for (HDC& hDC : previewseparator)
            DeleteHDC(hDC);
        for (HDC& hDC : modulebutton)
            DeleteHDC(hDC);
        for (HDC& hDC : modulelocationbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : modulesplitbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : navigationbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : navigationdivider)
            DeleteHDC(hDC);
        for (HDC& hDC : toolbarbutton)
            DeleteHDC(hDC);
        for (HDC& hDC : addressband)
            DeleteHDC(hDC);
        for (HDC& hDC : menuitem)
            DeleteHDC(hDC);
        for (HDC& hDC : dragdrop)
            DeleteHDC(hDC);
        for (HDC& hDC : spin)
            DeleteHDC(hDC);
    }

    VOID DeleteHDC(HDC& hDC)
{
    if (hDC) {
        HBITMAP hBmp = (HBITMAP)GetCurrentObject(hDC, OBJ_BITMAP);
        DeleteDC(std::exchange(hDC, nullptr));
        DeleteObject(hBmp);
    }
}

    ~CThemeCache()
    {
        ClearCache();
    }
};
CThemeCache g_themeCache;

VOID DrawNineGridStretch(HDC hdc, HDC& srcDC, LPCRECT dstRect, INT left = 0, INT top = 0, INT right = 0, INT bottom = 0)
{
    if (!hdc || !srcDC)
        return;
    
    HBITMAP hBmp = (HBITMAP)GetCurrentObject(srcDC, OBJ_BITMAP);
    BITMAP bmp = {};
    GetObject(hBmp, sizeof(bmp), &bmp);

    INT srcW = bmp.bmWidth;
    INT srcH = bmp.bmHeight;
    INT dstW = dstRect->right - dstRect->left;
    INT dstH = dstRect->bottom - dstRect->top;

    left   = std::min(left, dstW);
    right  = std::min(right, dstW - left);
    top    = std::min(top, dstH);
    bottom = std::min(bottom, dstH - top);

    INT centerW = dstW - left - right;
    INT centerH = dstH - top - bottom;

    INT srcCenterW = srcW - left - right;
    INT srcCenterH = srcH - top - bottom;

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

    // Full stretch
    if (left + right >= srcW || top + bottom >= srcH)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, dstW, dstH,
                srcDC, 0, 0, srcW, srcH, blend);
        return;
    }
    // Short-circuit if the entire region is fully covered by the top-left corner
    if (dstW <= left && dstH <= top)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, dstW, dstH,
                   srcDC, 0, 0, dstW, dstH, blend);
        return;
    }
    // Center
    if (centerW > 0 && centerH > 0 && srcCenterW > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->top + top, centerW, centerH,
                   srcDC, left, top, srcCenterW, srcCenterH, blend);
    }
    // Top-left
    if (left > 0 && top > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top, left, top,
                   srcDC, 0, 0, left, top, blend);
    }
    // Top
    if (centerW > 0 && top > 0 && srcCenterW > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->top, centerW, top,
                   srcDC, left, 0, srcCenterW, top, blend);
    }
    // Top-right
    if (right > 0 && top > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->top, right, top,
                   srcDC, srcW - right, 0, right, top, blend);
    }
    // Left
    if (left > 0 && centerH > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->top + top, left, centerH,
                   srcDC, 0, top, left, srcCenterH, blend);
    }
    // Right
    if (right > 0 && centerH > 0 && srcCenterH > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->top + top, right, centerH,
                   srcDC, srcW - right, top, right, srcCenterH, blend);
    }
    // Bottom-left
    if (left > 0 && bottom > 0)
    {
        AlphaBlend(hdc, dstRect->left, dstRect->bottom - bottom, left, bottom,
                   srcDC, 0, srcH - bottom, left, bottom, blend);
    }
    // Bottom
    if (centerW > 0 && bottom > 0 && srcCenterW > 0)
    {
        AlphaBlend(hdc, dstRect->left + left, dstRect->bottom - bottom, centerW, bottom,
                   srcDC, left, srcH - bottom, srcCenterW, bottom, blend);
    }
    // Bottom-right
    if (right > 0 && bottom > 0)
    {
        AlphaBlend(hdc, dstRect->right - right, dstRect->bottom - bottom, right, bottom,
                   srcDC, srcW - right, srcH - bottom, right, bottom, blend);
    }
}

BOOL PaintScroll(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId == SBP_UPPERTRACKVERT || iPartId == SBP_LOWERTRACKVERT
    || iPartId == SBP_UPPERTRACKHORZ || iPartId == SBP_LOWERTRACKHORZ))
        return TRUE;
    if ((!g_d2dFactory ||(iPartId != SBP_THUMBBTNVERT && iPartId != SBP_THUMBBTNHORZ)))
        return FALSE;
    
    INT index = (iStateId == SCRBS_NORMAL) ? 0 : 1;
    if (iPartId == SBP_THUMBBTNHORZ) index += 2;

    if (!g_themeCache.scrollbar[index])
        if (!g_themeCache.CacheScrollbar(iPartId, iStateId, index))
            return FALSE;

    FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
    DrawNineGridStretch(hdc, g_themeCache.scrollbar[index], pRect, 8, 5, 8, 5);
    return TRUE;
}

BOOL CThemeCache::CacheScrollbar(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 17 * scale, height = 11 * scale;
    if (iPartId == SBP_THUMBBTNHORZ)
        width = 20 * scale, height = 17 * scale;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.scrollbar[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.scrollbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_RECT_F Rect;
    if (iPartId == SBP_THUMBBTNVERT && iStateId == SCRBS_NORMAL)
        Rect = D2D1::RectF(width*0.35, 0, width-width*0.35, height);
    else if (iPartId == SBP_THUMBBTNHORZ && iStateId == SCRBS_NORMAL)
        Rect = D2D1::RectF(0, height*0.35, width, height-height*0.35);
    else if (iPartId == SBP_THUMBBTNVERT)
        Rect = D2D1::RectF(width*0.25, 0, width-width*0.25, height);
    else if (iPartId == SBP_THUMBBTNHORZ)
        Rect = D2D1::RectF(0, height*0.25, width, height-height*0.25);
    
    D2D1_COLOR_F Color = (iStateId == SCRBS_NORMAL) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(160, 224, 224, 224);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(Color, &brush);
    D2D1_ROUNDED_RECT rr = {Rect, cornerRadius, cornerRadius};

    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rr, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintScrollBarArrows(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != SBP_ARROWBTN || !g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> dcRenderTarget = nullptr;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &dcRenderTarget)))
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect);
    FLOAT height = static_cast<FLOAT>RECTHEIGHT(pRect);

    FLOAT triangleBaseWidth = 7.0f * scale;
    FLOAT triangleHeight = 4.5f * scale;
    FLOAT centerX = width / 2.0f;
    FLOAT centerY = height / 2.0f;

    D2D1_COLOR_F arrowColor;
    if (iStateId == 2 || iStateId == 6 || iStateId == 10 || iStateId == 14) {
        triangleBaseWidth = 8.0f * scale;
        triangleHeight = 5.5f * scale;
        arrowColor = MyD2D1Color(192, 224, 224, 224);
    }
    else if (iStateId == 4 || iStateId == 8 || iStateId == 12 || iStateId == 16)
        arrowColor = MyD2D1Color(192, 64, 64, 64);
    else 
        arrowColor = MyD2D1Color(128, 160, 160, 160);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    dcRenderTarget->CreateSolidColorBrush(arrowColor, &brush);
    D2D1_POINT_2F points[6] = {};
    if ((iStateId > ABS_UPNORMAL && iStateId <= ABS_UPDISABLED) || iStateId == ABS_UPHOVER)
    {
        points[0] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY + triangleHeight / 2.0f);
        points[1] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY+2 + triangleHeight / 2.0f);
        points[2] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY+2 + triangleHeight / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY + triangleHeight / 2.0f);
        points[4] = D2D1::Point2F(centerX, centerY - triangleHeight / 2.0f);
        points[5] = D2D1::Point2F(centerX-1, centerY - triangleHeight / 2.0f);
    }
    else if ((iStateId > ABS_DOWNNORMAL && iStateId <= ABS_DOWNDISABLED) || iStateId == ABS_DOWNHOVER)
    {
        points[0] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY - triangleHeight / 2.0f);
        points[1] = D2D1::Point2F(centerX-1 - triangleBaseWidth / 2.0f, centerY-2 - triangleHeight / 2.0f);
        points[2] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY-2 - triangleHeight / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleBaseWidth / 2.0f, centerY - triangleHeight / 2.0f);
        points[4] = D2D1::Point2F(centerX, centerY + triangleHeight / 2.0f);
        points[5] = D2D1::Point2F(centerX-1, centerY + triangleHeight / 2.0f);
    }
    else if ((iStateId > ABS_LEFTNORMAL && iStateId <= ABS_LEFTDISABLED) || iStateId == ABS_LEFTHOVER)
    {
        points[0] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY - 1 - triangleBaseWidth / 2.0f);
        points[1] = D2D1::Point2F(centerX+2 + triangleHeight / 2.0f, centerY - 1 - triangleBaseWidth / 2.0f);
        points[2] = D2D1::Point2F(centerX+2 + triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[3] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[4] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY);
        points[5] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY-1);
    }
    else if ((iStateId > ABS_RIGHTNORMAL && iStateId <= ABS_RIGHTDISABLED) || iStateId == ABS_RIGHTHOVER)
    {
        points[0] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY-1 - triangleBaseWidth / 2.0f);
        points[1] = D2D1::Point2F(centerX-2 - triangleHeight / 2.0f, centerY-1 - triangleBaseWidth / 2.0f);
        points[2] = D2D1::Point2F(centerX-2 - triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[3] = D2D1::Point2F(centerX - triangleHeight / 2.0f, centerY + triangleBaseWidth / 2.0f);
        points[4] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY);
        points[5] = D2D1::Point2F(centerX + triangleHeight / 2.0f, centerY-1);
    }

    FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

    dcRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1PathGeometry> triangleGeo = nullptr;
    if (SUCCEEDED(g_d2dFactory->CreatePathGeometry(&triangleGeo)))
    {
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink = nullptr;
        if (SUCCEEDED(triangleGeo->Open(&sink)))
        {
            sink->BeginFigure(points[0], D2D1_FIGURE_BEGIN_FILLED);
            sink->AddLine(points[1]);
            sink->AddLine(points[2]);
            sink->AddLine(points[3]);
            sink->AddLine(points[4]);
            sink->AddLine(points[5]);
            sink->EndFigure(D2D1_FIGURE_END_CLOSED);
            sink->Close();

            dcRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
        }
    }
    auto hr = dcRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintPushButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, LPCRECT pClipRect)
{
    if (iPartId != BP_PUSHBUTTON || !g_d2dFactory)
        return FALSE;
    
    RECT clipRect{ *pRect };
    if (pClipRect)
        IntersectRect(&clipRect, &clipRect, pClipRect);

    INT index = (iStateId == PBS_HOT) ? 1 : (iStateId == PBS_PRESSED) ? 2
    : (iStateId == PBS_DISABLED) ? 3 : 0;

    if (!g_themeCache.pushbutton[index])
        if (!g_themeCache.CachePushButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.pushbutton[index], &clipRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CachePushButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 18, height = 18;
    FLOAT cornerRadius = 3.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.pushbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.pushbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT rr = {
        D2D1::RectF(0.5f, 0.5f, (FLOAT)width - 0.5f, (FLOAT)height - 0.5f),
        cornerRadius, cornerRadius
    };

    D2D1_COLOR_F fillColor =
        (iStateId == PBS_HOT)      ? MyD2D1Color(128, 96, 96, 96) :
        (iStateId == PBS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60)  :
        (iStateId == PBS_DISABLED) ? MyD2D1Color(64, 64, 64, 64)  :
                                     MyD2D1Color(96, 80, 80, 80);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 112, 112, 112), &borderBrush);
    
    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rr, fillBrush.Get());
    pRenderTarget->DrawRoundedRectangle(&rr, borderBrush.Get(), scale);
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintRadioButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_RADIOBUTTON || !g_d2dFactory)
        return FALSE;
    
    INT index = iStateId - 1;

    if (!g_themeCache.radiobutton[index])
        if (!g_themeCache.CacheRadioButton(pRect, iStateId, index))
            return FALSE;
    // Some theme parts are always fixed size so no stretching is needed
    DrawNineGridStretch(hdc, g_themeCache.radiobutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheRadioButton(LPCRECT pRect,  INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);
    if (!g_themeCache.CreateDIB(g_themeCache.radiobutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, (INT)width, (INT)height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.radiobutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    FLOAT diameter = width - 1.f;
    FLOAT x = 0.5f, y = 0.5f;

    D2D1_ELLIPSE outerEllipse = D2D1::Ellipse(
        D2D1::Point2F(x + diameter / 2.f, y + diameter / 2.f),
        diameter / 2.f, diameter / 2.f
    );

    D2D1_COLOR_F borderColor, radioColor;
    D2D1_COLOR_F innerColor = MyD2D1Color(0, 0, 0);
    FLOAT innerRatio = 0.0f;

    switch (iStateId)
    {
        case CBS_UNCHECKEDNORMAL:
            borderColor = MyD2D1Color(96, 128, 128, 128);
            radioColor = MyD2D1Color(64, 64, 64, 64);
            break;
        case RBS_UNCHECKEDHOT:
            borderColor = MyD2D1Color(144, 144, 144);
            radioColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case RBS_UNCHECKEDPRESSED:
            radioColor = MyD2D1Color(64, 64, 64);
            innerRatio = 0.3f;
            break;
        case RBS_UNCHECKEDDISABLED:
            borderColor = MyD2D1Color(64, 128, 128, 128);
            break;
        case RBS_CHECKEDNORMAL:
            borderColor = radioColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            innerRatio = 0.4f;
            break;
        case RBS_CHECKEDHOT:
            borderColor = radioColor = IsAccentColorPossibleD2D(225, 105, 205, 255, SystemAccentColorLight3);
            innerRatio = 0.6f;
            break;
        case RBS_CHECKEDPRESSED:
            borderColor = radioColor = IsAccentColorPossibleD2D(192, 105, 205, 255, SystemAccentColorLight1);
            innerRatio = 0.33f;
            break;
        case RBS_CHECKEDDISABLED:
            borderColor = radioColor = MyD2D1Color(96, 96, 96);
            innerRatio = 0.3f;
            break;
    }

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(radioColor, &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->FillEllipse(outerEllipse, brush.Get());
    brush->SetColor(borderColor);
    pRenderTarget->DrawEllipse(outerEllipse, brush.Get(), scale);

    if (innerRatio > 0.f)
    {
        FLOAT innerDiameter = diameter * innerRatio;
        D2D1_ELLIPSE innerEllipse = D2D1::Ellipse(
            D2D1::Point2F(x + diameter / 2.f, y + diameter / 2.f),
            innerDiameter / 2.f, innerDiameter / 2.f
        );

        pRenderTarget->CreateSolidColorBrush(innerColor, &brush);
        pRenderTarget->FillEllipse(innerEllipse, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintCheckBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_CHECKBOX || !g_d2dFactory)
        return FALSE;
    
    INT index = iStateId - 1;

    if (!g_themeCache.checkbutton[index])
        if (!g_themeCache.CacheCheckButton(pRect, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.checkbutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheCheckButton(LPCRECT pRect, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);
    FLOAT cornerRadius = 3.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.checkbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, (INT)width, (INT)height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.checkbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(0, 0, width, height),
        cornerRadius, cornerRadius
    };

    D2D1_COLOR_F fillColor, borderColor;
    switch (iStateId) 
    {
        case CBS_UNCHECKEDNORMAL:
            borderColor = MyD2D1Color(96, 128, 128, 128);
            fillColor = MyD2D1Color(64, 96, 96, 96);
            break;
        case CBS_UNCHECKEDHOT:
            borderColor = MyD2D1Color(144, 144, 144);
            fillColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case CBS_UNCHECKEDPRESSED:
            borderColor = MyD2D1Color(96, 144, 144, 144);
            fillColor = MyD2D1Color(48, 144, 144, 144);
            break;
        case CBS_UNCHECKEDDISABLED:
            borderColor = MyD2D1Color(64, 144, 144, 144);
            fillColor = MyD2D1Color(64, 128, 128, 128);
            break;
        case CBS_CHECKEDNORMAL: case CBS_MIXEDNORMAL:
        case CBS_IMPLICITNORMAL: case CBS_EXCLUDEDNORMAL:
            fillColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
            break;
        case CBS_CHECKEDHOT: case CBS_MIXEDHOT:
        case CBS_IMPLICITHOT: case CBS_EXCLUDEDHOT:
            fillColor = IsAccentColorPossibleD2D(224, 102, 206, 255, SystemAccentColorLight3);
            break;
        case CBS_CHECKEDPRESSED: case CBS_MIXEDPRESSED:
        case CBS_IMPLICITPRESSED: case CBS_EXCLUDEDPRESSED:
            fillColor = IsAccentColorPossibleD2D(192, 102, 206, 255, SystemAccentColorLight1);
            break;
        case CBS_CHECKEDDISABLED: case CBS_MIXEDDISABLED:
        case CBS_IMPLICITDISABLED: case CBS_EXCLUDEDDISABLED:
            fillColor = MyD2D1Color(96, 96, 96);
    }
    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush = nullptr;
    pRenderTarget->CreateSolidColorBrush(fillColor, &Brush);
    pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> glyphBrush = nullptr;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0), &glyphBrush);

    if (iStateId >= CBS_UNCHECKEDNORMAL && iStateId <= CBS_UNCHECKEDDISABLED)
    {
        Brush->SetColor(borderColor);
        pRenderTarget->DrawRoundedRectangle
        (D2D1_ROUNDED_RECT(D2D1::RectF(.5f, .5f, width - .5f, height - .5f), cornerRadius, cornerRadius), Brush.Get(), scale);
    }
    if (iStateId > CBS_UNCHECKEDDISABLED)
    {       
        if ((iStateId >= CBS_CHECKEDNORMAL && iStateId <= CBS_CHECKEDDISABLED) ||
            (iStateId >= CBS_IMPLICITNORMAL && iStateId <= CBS_IMPLICITDISABLED)) // Checkmark
        {
            FLOAT centerX = width/2.f - 2*scale;
            FLOAT centerY = height/2.f + 2.5*scale;
            FLOAT rightLen = width *.65f ;
            FLOAT leftLen  = width *.3f;

            DOUBLE dxyR = rightLen * 0.7071067;

            DOUBLE dxL = leftLen * 0.5;
            DOUBLE dyL = leftLen * 0.8660254;

            D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY);
            D2D1_POINT_2F ptLeft  = D2D1::Point2F(ptTip.x - dxL, ptTip.y - dyL);
            D2D1_POINT_2F ptRight = D2D1::Point2F(ptTip.x + dxyR, ptTip.y - dxyR);

            pRenderTarget->DrawLine(ptLeft, ptTip, glyphBrush.Get(), scale * 1.2f);
            pRenderTarget->DrawLine(ptTip, ptRight, glyphBrush.Get(), scale * 1.2f);
        }
        if (iStateId >= CBS_EXCLUDEDNORMAL && iStateId <= CBS_EXCLUDEDDISABLED) // X
        {
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/3.f)), (D2D1::Point2F(width *.7f, height/1.5f)), glyphBrush.Get());
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/1.5f)), (D2D1::Point2F(width *.7f, height/3.f)), glyphBrush.Get()); 
        }
        if (iStateId >= CBS_MIXEDNORMAL && iStateId <= CBS_MIXEDDISABLED) // Minus
            pRenderTarget->DrawLine((D2D1::Point2F(width *.3f, height/2.f)), (D2D1::Point2F(width *.7f, height/2.f)), glyphBrush.Get());        
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintGroupBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, LPCRECT pClippedRect)
{
    if (!g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    const FLOAT radius = 4.0f;
    const FLOAT x = 0.5f;
    const FLOAT y = 0.5f;
    const FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect) - 0.5f;
    const FLOAT h = static_cast<FLOAT>RECTHEIGHT(pRect) - 0.5f;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);

    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1PathGeometry> geometry;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
    g_d2dFactory->CreatePathGeometry(&geometry);
    geometry->Open(&sink);
    
    if (!pClippedRect) // Top line if label does clip it
    {
        sink->BeginFigure(D2D1::Point2F(radius, y), D2D1_FIGURE_BEGIN_HOLLOW);
        sink->AddLine(D2D1::Point2F(width - radius, y));
    }
    else
        sink->BeginFigure(D2D1::Point2F(width - radius, y), D2D1_FIGURE_BEGIN_HOLLOW);

    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width, radius), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(width, h - radius));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width - radius, h), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(radius, h));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x, h - radius), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(x, radius));
    sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(radius + 1.f, y), D2D1::SizeF(radius, radius), 0, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->EndFigure(D2D1_FIGURE_END_OPEN);
    if (pClippedRect && (FLOAT)(pClippedRect->top) == (FLOAT)pRect->top) 
    {
        // Clipped rect sides
        const FLOAT cx = static_cast<FLOAT>(pClippedRect->left) + radius - .5f;
        const FLOAT cx2 = static_cast<FLOAT>(pClippedRect->right) - radius;
        // Top line right side of the label
        pRenderTarget->DrawLine(
            D2D1::Point2F(cx, .5f),
            D2D1::Point2F(cx2, .5f),
            brush.Get()
        );
    }
    sink->Close();
    pRenderTarget->DrawGeometry(geometry.Get(), brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}

    return TRUE;
}

BOOL PaintCommandLink(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_COMMANDLINK || !g_d2dFactory)
        return FALSE;
    
    INT index = (iStateId == CMDLS_NORMAL || iStateId == CMDLS_DISABLED) ? 0 : (iStateId == CMDLS_HOT) ? 1
    : (iStateId == CMDLS_PRESSED) ? 2 : 3;

    if (!g_themeCache.commandlinkbutton[index])
        if (!g_themeCache.CacheCommandlinkButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.commandlinkbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheCommandlinkButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 18, height = 18;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.commandlinkbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.commandlinkbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = { D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius};
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->BeginDraw();
    switch (iStateId)
    {
        case CMDLS_NORMAL:
        case CMDLS_DISABLED:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0, 0), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_HOT:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 144, 144, 144), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_PRESSED:
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(64, 144, 144, 144), &brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());
            break;
        case CMDLS_DEFAULTED:
        case CMDLS_DEFAULTED_ANIMATING:
            roundedRect = {D2D1::RectF(1.f * scale, 1.f * scale, width - 1.f * scale, height - 1.f * scale), cornerRadius - 1.f, cornerRadius - 1.f};
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawRoundedRectangle(&roundedRect, brush.Get(), 2.f * scale);
            break;
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintCommandLinkGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId != BP_COMMANDLINKGLYPH || !g_d2dFactory)
        return FALSE;
    
    INT index = (iStateId == CMDLGS_HOT) ? 1 : (iStateId == CMDLGS_PRESSED) ? 2
    : (iStateId == CMDLGS_DISABLED) ? 3 : 0;

    if (!g_themeCache.commandlinkglyph[index])
        if (!g_themeCache.CacheCommandlinkGlyph(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.commandlinkglyph[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheCommandlinkGlyph(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT x = 0;
    INT width = 20 * scale, height = 20 * scale;
    if (!g_themeCache.CreateDIB(g_themeCache.commandlinkglyph[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.commandlinkglyph[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    FLOAT tailScale = 1.f;
    D2D1_COLOR_F arrowColor = MyD2D1Color(192, 192, 192);
    if (iStateId == CMDLGS_HOT || iStateId == CMDLGS_PRESSED) {
        arrowColor = MyD2D1Color(255, 255, 255);
        if (iStateId == CMDLGS_PRESSED)
            tailScale = 0.8f;
    }
    else if (iStateId == CMDLGS_DISABLED)
        arrowColor = MyD2D1Color(160, 160, 160);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &brush);

    FLOAT centerY = height / 2.f;
    FLOAT tailLength = width * tailScale;
    FLOAT tailStartX = x;
    FLOAT tailEndX = tailStartX + tailLength;

    FLOAT headSpan = tailLength * 0.4f;
    FLOAT headOffset = headSpan * 0.7071f; // 45 degrees

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(
    D2D1::Point2F(x, centerY),
    D2D1::Point2F(tailLength, centerY),
    brush.Get(), 1.f
    );
    pRenderTarget->DrawLine(
        D2D1::Point2F(tailEndX - headOffset, centerY - headOffset),
        D2D1::Point2F(tailEndX, centerY),
        brush.Get(), 1.f
    );
    pRenderTarget->DrawLine(
        D2D1::Point2F(tailEndX - headOffset, centerY + headOffset),
        D2D1::Point2F(tailEndX, centerY),
        brush.Get()
    );  
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL SanitizeAddressCombobox(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId)
{
    HTHEME hThemeAddressCB = nullptr;
    if (SetThemeHandle(WindowFromDC(hdc), hThemeAddressCB, L"AddressComposited::ComboBox")
    && (iPartId == CP_BORDER || iPartId == CP_TRANSPARENTBACKGROUND))
    {
        CloseThemeData(hThemeAddressCB);
        return TRUE;
    }
    return FALSE;
}

BOOL PaintCombobox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != CP_READONLY && iPartId != CP_BORDER))
        return FALSE;
    
    INT index = (iPartId == CP_READONLY) ? iStateId - 1 : iStateId + 3;
    
    if (!g_themeCache.combobox[index])
        if (!g_themeCache.CacheCombobox(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.combobox[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheCombobox(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.combobox[stateIndex], width, height))
        return FALSE;
    
    // Direct2D render target
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.combobox[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT roundedRect = {D2D1::RectF(0.5, 0.5, width - .5f, height - .5f), cornerRadius, cornerRadius};

    pRenderTarget->BeginDraw();
    if (iPartId == CP_READONLY)
    {
        D2D1_COLOR_F fillColor = (iStateId == PBS_HOT)      ? MyD2D1Color(128, 96, 96, 96) : 
                                 (iStateId == PBS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60) :
                                 (iStateId == PBS_DISABLED) ? MyD2D1Color(64, 64, 64, 64) :
                                                              MyD2D1Color(96, 80, 80, 80);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &Brush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());

        Brush->SetColor(MyD2D1Color(96, 112, 112, 112));
        pRenderTarget->DrawRoundedRectangle(&roundedRect, Brush.Get(), scale);
    }
    else if (iPartId == CP_BORDER)
    {
        D2D1_COLOR_F borderColor = (iStateId == CBXS_HOT) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(96, 128, 128, 128);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), scale);

        if (iStateId == CBXS_PRESSED) 
        {
            borderBrush->SetColor(IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2));
            pRenderTarget->DrawLine(
                D2D1::Point2F(cornerRadius/2 - 1.f * scale, height - 1.5f),
                D2D1::Point2F(width - cornerRadius/2 + 1.f *scale, height - 1.5f),
                borderBrush.Get()
            );
            pRenderTarget->DrawLine(
                D2D1::Point2F(2.f * scale, height - .5f),
                D2D1::Point2F(width - 2.f * scale, height - .5f),
                borderBrush.Get()
            );
        }
        else if (iStateId == CBXS_DISABLED)
        {
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 80, 80, 80), &Brush);
            pRenderTarget->FillRoundedRectangle(&roundedRect, Brush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL IsAddressInnerBackground(HTHEME hTheme, HDC hdc, INT iPartId)
{
    HTHEME hThemeAddress = NULL;
    if (SetThemeHandle(WindowFromDC(hdc), hThemeAddress, L"AddressComposited::Edit") && iPartId == EP_BACKGROUNDWITHBORDER)
    {
        CloseThemeData(hThemeAddress);
        return TRUE;
    }
    return FALSE;
}

BOOL PaintEditBox(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != EP_EDITBORDER_NOSCROLL && iPartId != EP_EDITBORDER_HSCROLL
    && iPartId != EP_EDITBORDER_VSCROLL && iPartId != EP_EDITBORDER_HVSCROLL && iPartId != EP_BACKGROUND
    && (!IsAddressInnerBackground(hTheme, hdc, iPartId))
    ))
        return FALSE;

    // Remove editbox white background flashing
    if (iPartId ==  EP_BACKGROUND) {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return TRUE;
    }
    INT index = (iPartId == EP_BACKGROUNDWITHBORDER) ? 3 : (iStateId == 1) ? 0 : iStateId - 2;

    if (!g_themeCache.editbox[index])
        if (!g_themeCache.CacheEditBox(iPartId, iStateId, index))
            return FALSE;
    // hide the borders of the inner black background of EP_BACKGROUNDWITHBORDER theme class by expanding the black drawing.
    RECT rc = (iPartId == EP_BACKGROUNDWITHBORDER) ? RECT{pRect->left-1, pRect->top-1, pRect->right+3,pRect->bottom+1} : *pRect;
    DrawNineGridStretch(hdc, g_themeCache.editbox[index], &rc, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheEditBox(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;
    if(!g_themeCache.CreateDIB(g_themeCache.editbox[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.editbox[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x + .5f, y + .5f, width - .5f, height - .5f), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();  
    if (iPartId == EP_BACKGROUNDWITHBORDER)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(0, 0, 0) : MyD2D1Color(255, 255, 255), &brush);
        D2D1_RECT_F rc (0, 0, (FLOAT)width, (FLOAT)height);
        pRenderTarget->FillRectangle(&rc, brush.Get());
    }
    if (iStateId == ETS_NORMAL || iStateId == ETS_HOT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        D2D1_COLOR_F borderColor = (iStateId == ETS_HOT) ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(96, 112, 112, 112);
        pRenderTarget->CreateSolidColorBrush(borderColor, &brush);
        pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), scale);
    }
    else if (iStateId == ETS_SELECTED)
    {
        FLOAT X = .5f;
        FLOAT Width = static_cast<FLOAT>(width) - .5f, Height = static_cast<FLOAT>(height) - .5f;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 112, 112, 112), &brush);
        pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), scale);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> linebrush;
        pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2), &linebrush);
        pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2 - 1.f * scale, Height - 1.f), D2D1::Point2F(width - cornerRadius/2 + 1.f * scale, Height - 1.f), linebrush.Get());
        pRenderTarget->DrawLine(D2D1::Point2F(X + 2.f * scale, Height), D2D1::Point2F(Width - 2.f * scale , Height), linebrush.Get());
    }
    else if (iStateId == ETS_DISABLED)
    {
        D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush); 
        pRenderTarget->FillRoundedRectangle(rect, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintListBox(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_RECT_F rect((FLOAT)pRect->left, (FLOAT)pRect->top, (FLOAT)RECTWIDTH(pRect), (FLOAT)RECTHEIGHT(pRect));

    pRenderTarget->BeginDraw();

    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {   
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> Brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &Brush);
        pRenderTarget->FillRectangle(&rect, Brush.Get());
    }
    else
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush = nullptr;
        D2D1_COLOR_F borderColor;
        switch (iStateId)
        {
        case LBPSH_NORMAL:
            borderColor = MyD2D1Color(160, 160, 160);
            break;
        case LBPSH_HOT:
        case LBPSH_FOCUSED:
            borderColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            break;
        case LBPSH_DISABLED:
            borderColor = MyD2D1Color(96, 96, 96);
            break;
        default:
            borderColor = MyD2D1Color(160, 160, 160);
            break;
        }
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->FillRectangle(&rect, borderBrush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintDropDownArrow(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect, BOOL addressPart)
{
    if (!g_d2dFactory || (iPartId != CP_DROPDOWNBUTTON && iPartId != CP_DROPDOWNBUTTONRIGHT
        && iPartId != CP_DROPDOWNBUTTONLEFT))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    D2D1_COLOR_F arrowColor;
    switch (iStateId)
    {
    case CBXSL_NORMAL:
        arrowColor = MyD2D1Color(192, 192, 192);
        break;
    case CBXS_HOT:
        arrowColor = MyD2D1Color(255, 255, 255);
        break;
    case CBXS_PRESSED:
        arrowColor = MyD2D1Color(160, 160, 160);
        break;
    case CBXS_DISABLED:
        arrowColor = MyD2D1Color(96, 96, 96);
        break;
    }

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = static_cast<FLOAT>RECTWIDTH(pRect);
    FLOAT height = static_cast<FLOAT>RECTHEIGHT(pRect);
    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;

    FLOAT arrowLength = (addressPart) ? fminf(width, height) *  0.14f : fminf(width, height) *  0.25f;
    // 60 degree angle
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * 0.5f;

    D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY + dy);
    D2D1_POINT_2F ptLeft  = D2D1::Point2F(centerX - dx, centerY - dy);
    D2D1_POINT_2F ptRight = D2D1::Point2F(centerX + dx, centerY - dy);

    pRenderTarget->CreateSolidColorBrush(arrowColor, &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(ptLeft, ptTip, brush.Get(), scale*1.2f);
    pRenderTarget->DrawLine(ptRight, ptTip, brush.Get(), scale*1.2f);
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTab(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (iPartId == TABP_PANE || !g_d2dFactory)
        return FALSE;

    INT index = (iStateId == TIS_NORMAL) ? 0 
              : (iStateId == TIS_HOT) ? 1 : (iStateId == TIS_DISABLED) ? 2 : 3;

    if (!g_themeCache.tab[index])
        if (!g_themeCache.CacheTab(iStateId, index))
            return FALSE;

    DrawNineGridStretch(hdc, g_themeCache.tab[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheTab(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.tab[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.tab[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    pRenderTarget->BeginDraw();
    if (iStateId == TIS_NORMAL)
    {
        D2D1_RECT_F rect{0, 0, (FLOAT)width, (FLOAT)height};
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(0, 0, 0, 0), &brush);
        pRenderTarget->FillRectangle(rect, brush.Get());
    }
    else if (iStateId == TIS_HOT || iStateId == TIS_DISABLED)
    {
        D2D1_COLOR_F fillColor = (iStateId == TIS_HOT) ? MyD2D1Color(128, 96, 96, 96) : MyD2D1Color(96, 96, 96);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        D2D1_ROUNDED_RECT tabRect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        pRenderTarget->FillRoundedRectangle(tabRect, brush.Get());
    }
    else if (iStateId == TIS_SELECTED || iStateId == TIS_FOCUSED)
    {
        const FLOAT desiredHeight = 2.0f + round(scale);       
        const FLOAT widthPadding  = 5.0f;
        const FLOAT verticalOffset = 1.0f;      
    
        FLOAT pillLeft   = widthPadding;
        FLOAT pillRight  = width - widthPadding;
        FLOAT pillBottom = height - verticalOffset;
        FLOAT pillTop    = pillBottom - desiredHeight;
        FLOAT pillRadius = 1.f + round(scale);

        D2D1_ROUNDED_RECT pillRect = D2D1::RoundedRect(D2D1::RectF(pillLeft, pillTop, pillRight, pillBottom),pillRadius, pillRadius);

        D2D1_COLOR_F pillColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(pillColor, &brush);
        pRenderTarget->FillRoundedRectangle(pillRect, brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackbar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_TRACK && iPartId != TKP_TRACKVERT))
        return FALSE;
    
    INT index = (iPartId == TKP_TRACK) ? 0 : 1;

    if (!g_themeCache.trackbar[index])
        if (!g_themeCache.CacheTrackBar(iPartId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbar[index], pRect, 2, 2, 2, 2);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBar(INT iPartId, INT stateIndex)
{
    INT width = 6, height = 6;
    if(!g_themeCache.CreateDIB(g_themeCache.trackbar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    pRenderTarget->BeginDraw();
    D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), 2.f, 2.f);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
    pRenderTarget->FillRoundedRectangle(&body, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackbarThumb(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_THUMB && iPartId != TKP_THUMBVERT))
        return FALSE;
    
    if (iStateId == TUBS_FOCUSED) iStateId = 1;
    else if (iStateId == TUBS_DISABLED) iStateId = 4;
    INT index = (iPartId == TKP_THUMB) ? iStateId - 1 : iStateId + 3;

    if (!g_themeCache.trackbarthumb[index])
        if (!g_themeCache.CacheTrackBarThumb(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbarthumb[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBarThumb(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 10 * scale, height = 21 * scale;

    if (iPartId == TKP_THUMBVERT)
        width = std::exchange(height, width);
    
    if(!g_themeCache.CreateDIB(g_themeCache.trackbarthumb[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbarthumb[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor = (iStateId == TUBS_HOT) ? IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight3) : 
                             (iStateId == TUBS_PRESSED) ? IsAccentColorPossibleD2D(60, 110, 180, SystemAccentColorLight1) :
                             (iStateId == TUBS_DISABLED) ? MyD2D1Color(96, 96, 96) : MyD2D1Color(64, 64, 64);
    D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&body, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTrackBarPointedThumb(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TKP_THUMBBOTTOM && iPartId != TKP_THUMBTOP 
        && iPartId != TKP_THUMBLEFT && iPartId != TKP_THUMBRIGHT))
        return FALSE;

    if (iStateId == TUBS_FOCUSED) iStateId = 1;
    else if (iStateId == TUBS_DISABLED) iStateId = 4;
    INT index = (iPartId == TKP_THUMBBOTTOM) ? iStateId + 7 : (iPartId == TKP_THUMBTOP) ? iStateId + 11 :
                (iPartId == TKP_THUMBLEFT) ? iStateId + 15 : iStateId + 19;

    if (!g_themeCache.trackbarthumb[index])
        if (!g_themeCache.CacheTrackBarPointedThumb(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.trackbarthumb[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTrackBarPointedThumb(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 11 * scale, height = 19 * scale;

    if (iPartId == TKP_THUMBLEFT || iPartId == TKP_THUMBRIGHT)
        width = std::exchange(height, width);
    
    if(!g_themeCache.CreateDIB(g_themeCache.trackbarthumb[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.trackbarthumb[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor = (iStateId == TUBS_HOT) ? IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight3) : 
                             (iStateId == TUBS_PRESSED) ? IsAccentColorPossibleD2D(60, 110, 180, SystemAccentColorLight1) :
                             (iStateId == TUBS_DISABLED) ? MyD2D1Color(96, 96, 96) : MyD2D1Color(64, 64, 64);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);

    FLOAT cx = width * 0.5f;
    FLOAT cy = height * 0.5f;
    Microsoft::WRL::ComPtr<ID2D1PathGeometry> triangleGeo;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;

    pRenderTarget->BeginDraw();
    if (iPartId == TKP_THUMBBOTTOM)
    {
        FLOAT tipHeight = height * 0.3f;
        FLOAT bodyHeight = height - tipHeight;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, width, bodyHeight), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(cx - width * 0.5f, bodyHeight - 1.f);
        D2D1_POINT_2F p2 = D2D1::Point2F(cx + width * 0.5f, bodyHeight - 1.f);
        D2D1_POINT_2F p3 = D2D1::Point2F(cx, height);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();
        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBTOP)
    {
        FLOAT tipHeight = height * 0.3f;
        FLOAT bodyY = tipHeight;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, bodyY, width, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(cx - width * 0.5f, tipHeight + 1.f);
        D2D1_POINT_2F p2 = D2D1::Point2F(cx + width * 0.5f, tipHeight + 1.f);
        D2D1_POINT_2F p3 = D2D1::Point2F(cx, 0);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBLEFT)
    {
        FLOAT tipWidth = width * 0.3f;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(tipWidth, 0, width, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(tipWidth + 1.f, cy - height * 0.5f);
        D2D1_POINT_2F p2 = D2D1::Point2F(tipWidth + 1.f, cy + height * 0.5f);
        D2D1_POINT_2F p3 = D2D1::Point2F(0, cy);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    else if (iPartId == TKP_THUMBRIGHT)
    {
        FLOAT tipWidth = width * 0.3f;
        FLOAT bodyWidth = width - tipWidth;
        FLOAT bodyRadius = 2.f * scale;

        D2D1_ROUNDED_RECT body = D2D1::RoundedRect(D2D1::RectF(0, 0, bodyWidth, height), bodyRadius, bodyRadius);
        pRenderTarget->FillRoundedRectangle(body, brush.Get());

        D2D1_POINT_2F p1 = D2D1::Point2F(bodyWidth - 1.f, cy - height * 0.5f);
        D2D1_POINT_2F p2 = D2D1::Point2F(bodyWidth - 1.f, cy + height * 0.5f);
        D2D1_POINT_2F p3 = D2D1::Point2F(width, cy);

        g_d2dFactory->CreatePathGeometry(&triangleGeo);
        triangleGeo->Open(&sink);
        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(p2);
        sink->AddLine(p3);
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();

        pRenderTarget->FillGeometry(triangleGeo.Get(), brush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintProgressBar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    if (iPartId == PP_PULSEOVERLAY || iPartId == PP_MOVEOVERLAY || iPartId == PP_PULSEOVERLAYVERT || iPartId == PP_MOVEOVERLAYVERT)
        return TRUE;

    INT index = (iPartId == PP_FILL) ? iStateId - 1 : (iPartId == PP_FILLVERT) ? iStateId + 3 
              : (iPartId == PP_CHUNK || iPartId == PP_CHUNKVERT) ? 8 : 9;
    
    if (!g_themeCache.progressbar[index])
        if (!g_themeCache.CacheProgressBar(iPartId, iStateId, index))
            return FALSE;
    if (iPartId == PP_FILL)
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 8, 10, 8, 10);
    else if (iPartId == PP_FILLVERT)
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 10, 8, 10, 8);
    else
        DrawNineGridStretch(hdc, g_themeCache.progressbar[index], pRect, 8, 8, 9, 9);
    return TRUE;
}

BOOL CThemeCache::CacheProgressBar(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if (iPartId == PP_FILL) 
        width = 50, height = 23;
    else if (iPartId == PP_FILLVERT)
        width = 23, height = 50;

    if(!g_themeCache.CreateDIB(g_themeCache.progressbar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.progressbar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_RECT_F rect = D2D1::RectF(0, 0, width, height);
    D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(rect, cornerRadius, cornerRadius);

    pRenderTarget->BeginDraw();
    if (iPartId == PP_BAR || iPartId == PP_BARVERT ||
        iPartId == PP_TRANSPARENTBAR || iPartId == PP_TRANSPARENTBARVERT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
        pRenderTarget->FillRoundedRectangle(rounded, brush.Get());
    }
    else if (iPartId == PP_CHUNK || iPartId == PP_CHUNKVERT)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &brush);
        pRenderTarget->FillRoundedRectangle(rounded, brush.Get());
    }
    else if (iPartId == PP_FILL || iPartId == PP_FILLVERT)
    {
        BOOL isVertical = (iPartId == PP_FILLVERT);
        D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES props = {};
        props.startPoint = isVertical ? D2D1::Point2F(rect.right/2, rect.bottom)
                                      : D2D1::Point2F(rect.left, rect.bottom/2);
        props.endPoint   = isVertical ? D2D1::Point2F(rect.right/2, rect.top)
                                      : D2D1::Point2F(rect.right, rect.bottom/2);
        D2D1_GRADIENT_STOP stops[2];

        switch (iStateId)
        {
            case PBFS_NORMAL:
            {
                Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> solidBrush;
                pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &solidBrush);
                pRenderTarget->FillRoundedRectangle(rounded, solidBrush.Get());
                break;
            }
            case PBFS_ERROR:
            {
                stops[0].color = MyD2D1Color(228, 48, 96);
                stops[0].position = 0.0f;
                stops[1].color = MyD2D1Color(255, 96, 81);
                stops[1].position = 1.0f;
                break;
            }
            case PBFS_PAUSED:
            {
                stops[0].color = MyD2D1Color(228, 128, 48);
                stops[0].position = 0.0f;
                stops[1].color = MyD2D1Color(237, 206, 80);
                stops[1].position = 1.0f;
                break;
            }
            case PBFS_PARTIAL:
            {
                stops[0].color = IsAccentColorPossibleD2D(0, 120, 215, SystemAccentColorBase);
                stops[0].position = 0.0f;
                stops[1].color = IsAccentColorPossibleD2D(64, 160, 255, SystemAccentColorLight2);
                stops[1].position = 1.0f;
                break;
            }
        }
        if (iStateId != PBFS_NORMAL)
        {
            Microsoft::WRL::ComPtr<ID2D1GradientStopCollection> gradientStops;
            pRenderTarget->CreateGradientStopCollection(stops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &gradientStops);

            Microsoft::WRL::ComPtr<ID2D1LinearGradientBrush> gradientBrush;
            pRenderTarget->CreateLinearGradientBrush(props, gradientStops.Get(), &gradientBrush);

            pRenderTarget->FillRoundedRectangle(rounded, gradientBrush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintIndeterminateProgressBar(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    if (iPartId != PP_MOVEOVERLAY && iPartId != PP_MOVEOVERLAYVERT)
        return TRUE;

    INT index = (iPartId == PP_MOVEOVERLAY) ? 0 : 1;
    
    // Make progress bar thin
    RECT overlayRect;
    if (iPartId == PP_MOVEOVERLAY)
    {
        INT overlayHeight = RECTHEIGHT(pRect) / 3;
        INT overlayY = (RECTHEIGHT(pRect) - overlayHeight) / 1.5f;
        overlayRect = RECT(pRect->left, overlayY, pRect->right, overlayY + overlayHeight);
    }
    else if (iPartId == PP_MOVEOVERLAYVERT)
    {
        FLOAT overlayWidth = RECTWIDTH(pRect) / 3.0f;
        FLOAT overlayX = (RECTWIDTH(pRect) - overlayWidth) / 1.5f;
        overlayRect = RECT(overlayX, pRect->top, overlayX + overlayWidth, pRect->bottom);
    }
    
    if (!g_themeCache.indeterminatebar[index])
        if (!g_themeCache.CacheIndeterminateBar(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.indeterminatebar[index], &overlayRect, 6, 6, 5, 5);
    return TRUE;
}

BOOL CThemeCache::CacheIndeterminateBar(INT iPartId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 3.f * scale;
    INT width = 12, height = 12;

    if (iPartId == PP_MOVEOVERLAYVERT)
        width = std::exchange(height, width);

    if(!g_themeCache.CreateDIB(g_themeCache.indeterminatebar[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = {0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.indeterminatebar[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2), &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintListView(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != LVP_LISTITEM 
        && iPartId != LVP_GROUPHEADER && iPartId != LVP_GROUPHEADERLINE && iPartId != LVP_COLUMNDETAIL))
        return FALSE;

    INT index;
    if (iPartId == THEMECLS_COMMONPROPS_PART || iPartId == LVP_LISTITEM) 
        index = (!iPartId) ? 0 : iStateId;
    else if (iPartId == LVP_GROUPHEADER)
    {
        if (iStateId == 2 || iStateId == 4 || iStateId == 6
        || iStateId == 8 || iStateId == 10) index = 7;
        else if (iStateId == 11 || iStateId == 15) index = 8;
        else if (iStateId == 12 || iStateId == 16) index = 9;
        else if (iStateId == 13) index = 10;
        else if (iStateId == 14) index = 11;
        else return FALSE; 
    }
    else if (iPartId == LVP_GROUPHEADERLINE) index = 12;
    else if (iPartId == LVP_COLUMNDETAIL) index = 13;
    else return FALSE;

    if (!g_themeCache.listview[index])
    {
        if (index <= 6)
        {
            if (!g_themeCache.CacheListItem(iPartId, iStateId, index))
                return FALSE;
        }
        else
            if (!g_themeCache.CacheListGroupHeader(iPartId, iStateId, index))
                return FALSE;
    }
    DrawNineGridStretch(hdc, g_themeCache.listview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheListItem(INT iPartId, INT iStateId, INT stateIndex)
{
    if (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != LVP_LISTITEM)
        return FALSE;
    
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.listview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.listview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {
        D2D1_RECT_F rect = D2D1::RectF(x, y, width, height);
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRectangle(&rect, brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else
    {
        D2D1_COLOR_F fillColor, borderColor;
        switch (iStateId)
        {
            case LISS_NORMAL:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
            case LISS_HOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                break;
            case LISS_SELECTED:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LISS_DISABLED:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
            case LISS_SELECTEDNOTFOCUS:
                fillColor = MyD2D1Color(32, 144, 144, 144);
                break;
            case LISS_HOTSELECTED:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                borderColor = IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2);
                break;
        }
        
        D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius, cornerRadius);
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());

        if (iStateId == LISS_HOTSELECTED || iStateId == LISS_NORMAL || iStateId == LISS_DISABLED)
        {
            x = y = 1.f;
            width = height -= 1.f;
            rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius - 1.f, cornerRadius - 1.f);
            brush->SetColor(borderColor);
            pRenderTarget->DrawRoundedRectangle(&rounded, brush.Get(), 2.f * scale);
        }
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    return TRUE;
}

BOOL CThemeCache::CacheListGroupHeader(INT iPartId, INT iStateId, INT stateIndex)
{
    if (iPartId != LVP_GROUPHEADER && iPartId != LVP_GROUPHEADERLINE && iPartId != LVP_COLUMNDETAIL)
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = (iPartId == LVP_COLUMNDETAIL) ? 2 : 18, height = (iPartId == LVP_COLUMNDETAIL) ? 1 : 18;

    if (!g_themeCache.CreateDIB(g_themeCache.listview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.listview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    if (iPartId == LVP_COLUMNDETAIL)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 160, 160, 160), &brush);

        pRenderTarget->BeginDraw();
        pRenderTarget->DrawLine(D2D1_POINT_2F(width, y), D2D1_POINT_2F(width, height), brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else if (iPartId == LVP_GROUPHEADER)
    {
        D2D1_COLOR_F fillColor = {};
        D2D1_COLOR_F borderColor = {};

        switch (iStateId)
        {
            case LVGH_OPENHOT: case LVGH_OPENSELECTEDHOT:
            case LVGH_OPENSELECTEDNOTFOCUSEDHOT: case LVGH_OPENMIXEDSELECTIONHOT:
            case LVGH_CLOSEHOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                break;
            case LVGH_CLOSESELECTED:
            case LVGH_CLOSEMIXEDSELECTION:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LVGHL_CLOSEMIXEDSELECTIONHOT:
            case LVGHL_CLOSESELECTEDHOT:
                fillColor = MyD2D1Color(64, 144, 144, 144);
                break;
            case LVGHL_CLOSESELECTEDNOTFOCUSED:
                borderColor = MyD2D1Color(255, 255, 255);
                break;
            case LVGHL_CLOSESELECTEDNOTFOCUSEDHOT:
                fillColor = MyD2D1Color(96, 144, 144, 144);
                borderColor = MyD2D1Color(255, 255, 255);
                break;
            default:
                return FALSE;
        }
        D2D1_ROUNDED_RECT rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius, cornerRadius);
        pRenderTarget->BeginDraw();
        if (iStateId != LVGHL_CLOSESELECTEDNOTFOCUSED)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillRoundedRectangle(&rounded, brush.Get());
        }

        if (iStateId == LVGHL_CLOSESELECTEDNOTFOCUSED || iStateId == LVGHL_CLOSESELECTEDNOTFOCUSEDHOT)
        {
            x = y = 1.f;
            width = height -= 1.f;
            rounded = D2D1::RoundedRect(D2D1::RectF(x, y, width , height), cornerRadius - 1.f, cornerRadius - 1.f);
            pRenderTarget->CreateSolidColorBrush(borderColor, &brush);
            pRenderTarget->DrawRoundedRectangle(&rounded, brush.Get(), 2.f * scale);
        }
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    else
    {
        D2D1_RECT_F rect = D2D1::RectF(x, y, width, height);
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 160, 160, 160), &brush);
        pRenderTarget->BeginDraw();
        pRenderTarget->FillRectangle(&rect, brush.Get());
        auto hr = pRenderTarget->EndDraw();
        if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    }
    return TRUE;
}

BOOL PaintTreeViewButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != THEMECLS_COMMONPROPS_PART && iPartId != TVP_TREEITEM))
        return FALSE;
    
    INT index = (iPartId == THEMECLS_COMMONPROPS_PART) ? 0 : (iStateId == TREIS_HOT) ? 1 : (iStateId == TREIS_SELECTED) ? 2 :
                (iStateId == TREIS_SELECTEDNOTFOCUS) ? 3 : 4;

    if (!g_themeCache.treeview[index])
        if (!g_themeCache.CacheTreeViewButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.treeview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheTreeViewButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 5.f * scale;
    FLOAT x = 0, y = 0;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.treeview[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.treeview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();
    if (iPartId == THEMECLS_COMMONPROPS_PART)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(MyD2D1Color(96, 96, 96), &borderBrush);
        pRenderTarget->FillRectangle(D2D1::RectF(x, y, width, height), borderBrush.Get());
    }
    else if (iPartId == TVP_TREEITEM)
    {
        D2D1_COLOR_F fillColor = (iStateId == TREIS_HOT)              ? MyD2D1Color(96, 144, 144, 144) : 
                                 (iStateId == TREIS_SELECTED)         ? MyD2D1Color(64, 144, 144, 144) :
                                 (iStateId == TREIS_SELECTEDNOTFOCUS) ? MyD2D1Color(32, 144, 144, 144) :
                                                                        //TREIS_HOTSELECTED
                                                                        MyD2D1Color(64, 144, 144, 144); 

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());

        if (iStateId == TREIS_SELECTED || iStateId == TREIS_SELECTEDNOTFOCUS || iStateId == TREIS_HOTSELECTED)
        {
            FLOAT pillOffsetY = 7, pillWidth = round(3.4f + scale), pillRadius = round(1.4f + scale);
            brush->SetColor(IsAccentColorPossibleD2D(102, 206, 255, SystemAccentColorLight2));
            pRenderTarget->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(x, y + pillOffsetY, x + pillWidth, height - pillOffsetY), pillRadius, pillRadius),brush.Get());
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintTreeViewGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TVP_GLYPH && iPartId != TVP_HOTGLYPH))
        return FALSE;

    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT width = RECTWIDTH(pRect);

    // TreeView glyph symbols have a fixed bitmap size (marked as SIZINGTYPE=TRUESIZE)
    // The TreeView theme class has a bitmap size of 9x9px, while the Explorer::TreeView theme class has a bitmap size of 16x16px
    // Unfortunately, OpenThemeData only detects the parent TreeView theme class
    BOOL ExplorerTreeView = FALSE;
    if (width / (16 * scale) == 1)
        ExplorerTreeView = TRUE;

    INT index = (iPartId == TVP_GLYPH) ? index = iStateId - 1 : index = iStateId + 1;
    index = (ExplorerTreeView) ? index + 4 : index;

    if (!g_themeCache.treeviewglyph[index])
        if (!g_themeCache.CacheTreeViewGlyph(iPartId, iStateId, index, ExplorerTreeView))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.treeviewglyph[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheTreeViewGlyph(INT iPartId, INT iStateId, INT stateIndex, BOOL ExplorerTreeView)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 9 * scale;
    INT height = 9 * scale;

    if (ExplorerTreeView)
        width = height = 16 * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.treeviewglyph[stateIndex], width, height))
        return FALSE;

    RECT rc {0, 0, width, height};
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.treeviewglyph[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F arrowColor;
    if (iPartId == TVP_HOTGLYPH) {
        if (iStateId == HGLPS_CLOSED) arrowColor =  MyD2D1Color(255, 255, 255);
        else if (iStateId == HGLPS_OPENED) arrowColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(192, 192, 192) : MyD2D1Color(128, 128, 128);
    }
    else if (iPartId == TVP_GLYPH) {
        if (iStateId == GLPS_CLOSED) arrowColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(148, 148, 148) : MyD2D1Color(64, 64, 64);
        else if (iStateId == GLPS_OPENED) arrowColor = MyD2D1Color(255, 255, 255);
    }

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;
    FLOAT arrowLength = (ExplorerTreeView) ? width * 0.3f : width * 0.55f;
    // 60 degrees
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * 0.5f;

    D2D1_POINT_2F ptTip, ptLeft, ptRight;

    if (iStateId == GLPS_OPENED)
    {
        ptTip   = {centerX, centerY + dy};
        ptLeft  = {centerX - dx, centerY - dy};
        ptRight = {centerX + dx, centerY - dy};
    }
    else if (iStateId == GLPS_CLOSED)
    {
        ptTip   = { centerX + dy, centerY };
        ptLeft  = { centerX - dy, centerY - dx };
        ptRight = { centerX - dy, centerY + dx };
    }

    pRenderTarget->BeginDraw();

    pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 1.5f * scale);
    pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 1.5f * scale);

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintItemsView(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 1 && iPartId != 3 && iPartId != 6
        && (iPartId != 4 && (iStateId == 11 || iStateId == 12))))
        return FALSE;

    INT index = (iPartId == 1 && (iStateId % 2 == 1)) ? 0 :
                (iPartId == 1 && (iStateId % 2 == 0)) ? 1 : (iPartId == 6) ? iStateId + 1 : iStateId + 3;
    
    // New DarkTheme file conflict dialog buttons
    if (iPartId == 4 && iStateId == 11)
        return PaintListView(hdc, 1, 6, pRect);
    else if (iPartId == 4 && iStateId == 12)
        return PaintListView(hdc, 1, 2, pRect);
    
    if (!g_themeCache.itemsview[index])
        if (!g_themeCache.CacheItemsView(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.itemsview[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheItemsView(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.itemsview[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.itemsview[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    x = y += 1;
    width = height -= 1;

    pRenderTarget->BeginDraw();
    if (iPartId == 1)
    {
        if (iStateId == 1 || iStateId == 3)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
            pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(0, 96, 188, SystemAccentColorLight2), &brush);
            pRenderTarget->FillRoundedRectangle(rect, brush.Get());

            brush->SetColor(IsAccentColorPossibleD2D(0, 120, 215, SystemAccentColorLight2));
            pRenderTarget->DrawRoundedRectangle(rect, brush.Get(), 2.0f * scale);
        }
        else if (iStateId == 2 || iStateId == 4)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
            pRenderTarget->CreateSolidColorBrush(IsAccentColorPossibleD2D(0, 96, 188, SystemAccentColorLight2), &fillBrush);
            pRenderTarget->FillRoundedRectangle(rect, fillBrush.Get());
        }
    }
    else if (iPartId == 3 || iPartId == 6)
    {
        if (iStateId == 1)
        {
            FLOAT radius = (iPartId == 6) ? 2.f * scale : 3.f * scale;
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x, y, width, height), radius, radius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &borderBrush);
            pRenderTarget->DrawRoundedRectangle(rect, borderBrush.Get(), 2.0f * scale);
        }
        else if (iStateId == 2)
        {
            D2D1_ROUNDED_RECT rect = D2D1::RoundedRect(D2D1::RectF(x-1, y-1, width+1, height+1), cornerRadius, cornerRadius);
            Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 144, 144, 144), &fillBrush);
            pRenderTarget->FillRoundedRectangle(rect, fillBrush.Get());
        }
    }

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintHeader(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != HP_HEADERITEM)
        return FALSE;

    if (iStateId % 3 == 1) return TRUE;
    INT index = (iStateId % 3 == 2) ? 0 : 1;
    
    if (!g_themeCache.header[index])
        if (!g_themeCache.CacheHeader(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.header[index], pRect, 12, 0, 11, 12);
    return TRUE;
}

BOOL CThemeCache::CacheHeader(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 6.f * scale;
    INT x = 0, y = 0;
    INT width = 24, height = 24;

    if(!g_themeCache.CreateDIB(g_themeCache.header[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.header[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    switch (iStateId)
    {
        case HIS_HOT: case HIS_SORTEDHOT:
        case HIS_ICONHOT: case HIS_ICONSORTEDHOT:
            fillColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case HIS_PRESSED: case HIS_SORTEDPRESSED:
        case HIS_ICONPRESSED: case HIS_ICONSORTEDPRESSED:
            fillColor = MyD2D1Color(64, 144, 144, 144);
            break;
        case HIS_NORMAL: case HIS_SORTEDNORMAL:
        case HIS_ICONNORMAL: case HIS_ICONSORTEDNORMAL:
            return TRUE;
    }
    Microsoft::WRL::ComPtr<ID2D1PathGeometry> geometry;
    Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
    pRenderTarget->BeginDraw();

    g_d2dFactory->CreatePathGeometry(&geometry);
    geometry->Open(&sink);
    sink->BeginFigure(D2D1::Point2F(x, y), D2D1_FIGURE_BEGIN_FILLED);
    sink->AddLine(D2D1::Point2F(width, y));
    sink->AddLine(D2D1::Point2F(width, height - cornerRadius));
    sink->AddArc(D2D1::ArcSegment(
        D2D1::Point2F(width - cornerRadius, height),
        D2D1::SizeF(cornerRadius, cornerRadius), 0.0f, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(cornerRadius, height));
    sink->AddArc(D2D1::ArcSegment(
        D2D1::Point2F(x, height - cornerRadius),
        D2D1::SizeF(cornerRadius, cornerRadius), 0.0f, D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
    sink->AddLine(D2D1::Point2F(x, y));
    sink->EndFigure(D2D1_FIGURE_END_CLOSED);
    sink->Close();
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    pRenderTarget->FillGeometry(geometry.Get(), brush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintPreviewPaneSeparator(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 3 && iPartId != 4))
        return FALSE;

    if (!g_themeCache.previewseparator[0])
        if (!g_themeCache.CachePreviewPaneSeparator())
            return FALSE;
    
    RECT rc{pRect->left+1, pRect->top, pRect->right, pRect->bottom};
    DrawNineGridStretch(hdc, g_themeCache.previewseparator[0], &rc, 1, 0, 0, 0);
    return TRUE;
}

BOOL CThemeCache::CachePreviewPaneSeparator()
{
    INT x = 0, y = 0;
    INT width = 3, height = 3;
    if(!g_themeCache.CreateDIB(g_themeCache.previewseparator[0], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.previewseparator[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(128, 160, 160, 160) : MyD2D1Color(128, 0, 0, 0), &brush);

    pRenderTarget->BeginDraw();
    pRenderTarget->DrawLine(D2D1_POINT_2F(x, y), D2D1_POINT_2F(x, height), brush.Get());
    auto hr = pRenderTarget->EndDraw();

    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId != 3) || !g_d2dFactory)
        return FALSE;
    // Let windows theme paint its (transparent) buttons
    if (iStateId == 1 || iStateId == 6) return FALSE;
    INT index = iStateId - 2; 

    if (!g_themeCache.modulebutton[index])
        if (!g_themeCache.CacheModuleButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.modulebutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.modulebutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulebutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    D2D1_COLOR_F borderColor = MyD2D1Color(255, 255, 255);
    FLOAT Border2pxOffset = 0.f;
    switch (iStateId) 
    {
        case 2: fillColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case 3: fillColor = MyD2D1Color(64, 144, 144, 144);
            break;
        case 4: Border2pxOffset = 1.f * scale;
            break;
        case 5: 
            fillColor = MyD2D1Color(96, 144, 144, 144);
            Border2pxOffset = 1.f * scale;
            break;
    }

    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(Border2pxOffset, Border2pxOffset,
                    width -Border2pxOffset, height -Border2pxOffset) ,
        cornerRadius, cornerRadius
    };

    pRenderTarget->BeginDraw();
    if (iStateId != 4)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());
    }
    if (iStateId == 4 || iStateId == 5)
    {
        Border2pxOffset += 1.f;
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
        pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
        pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), Border2pxOffset);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleLocation(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if ((iPartId != 9) || !g_d2dFactory)
        return FALSE;
    if (iStateId == 6) return FALSE;
    INT index = iStateId - 1; 

    if (!g_themeCache.modulelocationbutton[index])
        if (!g_themeCache.CacheModuleLocationButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.modulelocationbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleLocationButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;
    if(!g_themeCache.CreateDIB(g_themeCache.modulelocationbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulelocationbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_COLOR_F fillColor;
    D2D1_COLOR_F borderColor = MyD2D1Color(255, 255, 255);
    FLOAT Border2pxOffset = 0.f;
    switch (iStateId) 
    {
        case 1:
            fillColor = MyD2D1Color(96, 78, 78, 78);
            borderColor = MyD2D1Color(96, 112, 112, 112);
            break;
        case 2:
            fillColor = MyD2D1Color(96, 96, 96, 96);
            borderColor = MyD2D1Color(96, 144, 144, 144);
            break;
        case 3:
            fillColor = MyD2D1Color(96, 88, 88, 88);
            borderColor = MyD2D1Color(96, 80, 80, 80);
            break;
        case 4:
            Border2pxOffset = 1.f * scale;
            borderColor = MyD2D1Color(255, 255, 255);
            break;
    }

    D2D1_ROUNDED_RECT roundedRect = {
        D2D1::RectF(Border2pxOffset, Border2pxOffset,
                    width -Border2pxOffset, height -Border2pxOffset) ,
        cornerRadius, cornerRadius
    };

    pRenderTarget->BeginDraw();
    if (iStateId != 4)
    {
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());
    }

    Border2pxOffset += 1.f;
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> borderBrush;
    pRenderTarget->CreateSolidColorBrush(borderColor, &borderBrush);
    pRenderTarget->DrawRoundedRectangle(&roundedRect, borderBrush.Get(), Border2pxOffset);

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintModuleSplitButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != 4 && iPartId != 5))
        return FALSE;
    if (iStateId == 1 || iStateId == 6) return FALSE;
    INT index = (iPartId == 4) ? iStateId - 2 : iStateId + 2; 

    if (!g_themeCache.modulesplitbutton[index])
        if (!g_themeCache.CacheModuleSplitButton(iPartId, iStateId, index))
            return FALSE;
    RECT newRc = (iPartId == 4 && iStateId == 4) ? RECT{pRect->left, pRect->top, pRect->right+2, pRect->bottom} : *pRect;
    DrawNineGridStretch(hdc, g_themeCache.modulesplitbutton[index], &newRc, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheModuleSplitButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 18, height = 18;

    if(!g_themeCache.CreateDIB(g_themeCache.modulesplitbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.modulesplitbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor;
    if (iStateId == 2) fillColor = MyD2D1Color(96, 144, 144, 144);
    else if (iStateId == 3 || iStateId == 5) fillColor = MyD2D1Color(64, 144, 144, 144);
    if (iStateId == 4) {
        y = x += 1.f;
        width = height -= 1;
    }

    pRenderTarget->BeginDraw();
    if (iPartId == 4)
    {
        Microsoft::WRL::ComPtr<ID2D1PathGeometry> path;
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
        g_d2dFactory->CreatePathGeometry(&path);
        path->Open(&sink);

        sink->BeginFigure(D2D1::Point2F(width, y), D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(D2D1::Point2F(x + cornerRadius, y));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x, cornerRadius + y), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(x, height - cornerRadius));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(x + cornerRadius, height), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(width, height));
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        if (iStateId == 2 || iStateId == 3 || iStateId == 5)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillGeometry(path.Get(), brush.Get());
        }
        else if (iStateId == 4)
        {
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawGeometry(path.Get(), brush.Get(), 2.f * scale);
        }
    }
    else if (iPartId == 5)
    {
        Microsoft::WRL::ComPtr<ID2D1PathGeometry> path;
        Microsoft::WRL::ComPtr<ID2D1GeometrySink> sink;
        g_d2dFactory->CreatePathGeometry(&path);
        path->Open(&sink);

        sink->BeginFigure(D2D1::Point2F(x, y), D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(D2D1::Point2F(width - cornerRadius, y));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width, y + cornerRadius), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(width, height - cornerRadius));
        sink->AddArc(D2D1::ArcSegment(D2D1::Point2F(width - cornerRadius, height), D2D1::SizeF(cornerRadius, cornerRadius),
            0.f,
            D2D1_SWEEP_DIRECTION_CLOCKWISE,
            D2D1_ARC_SIZE_SMALL
        ));
        sink->AddLine(D2D1::Point2F(x, height));
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
        if (iStateId == 2 || iStateId == 3 || iStateId == 5)
        {
            pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
            pRenderTarget->FillGeometry(path.Get(), brush.Get());
        }
        else if (iStateId == 4)
        {
            pRenderTarget->CreateSolidColorBrush(MyD2D1Color(255, 255, 255), &brush);
            pRenderTarget->DrawGeometry(path.Get(), brush.Get(), 2.f * scale);
        }
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintNavigationButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;
    INT index = (iPartId == NAV_BACKBUTTON) ? iStateId - 1 : (iPartId == NAV_FORWARDBUTTON) ? iStateId + 3 : iStateId + 7;

    if (!g_themeCache.navigationbutton[index])
        if (!g_themeCache.CacheNavigationButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.navigationbutton[index], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheNavigationButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT x = 0, y = 0;
    INT width = 30 * scale, height = 30 * scale;
    
    if (iPartId == NAV_MENUBUTTON)
        width = 13 * scale, height = 27 * scale;
    
    if(!g_themeCache.CreateDIB(g_themeCache.navigationbutton[stateIndex], width, height))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { x, y, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.navigationbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor, arrowColor;
    switch (iStateId) 
    {
        case NAV_BB_NORMAL:
            arrowColor = g_IsSysThemeDarkMode ? MyD2D1Color(255, 255, 255) : MyD2D1Color(32, 32, 32);
            fillColor = MyD2D1Color(0, 0, 0, 0);
            break;
        case NAV_BB_HOT:
            fillColor = MyD2D1Color(32, 255, 255, 255);
            arrowColor = g_IsSysThemeDarkMode ? MyD2D1Color(200, 255, 255, 255) : MyD2D1Color(200, 32, 32, 32);
            break;
        case NAV_BB_PRESSED:
            fillColor = MyD2D1Color(16, 255, 255, 255);
            arrowColor = g_IsSysThemeDarkMode ?MyD2D1Color(200, 160, 160, 160) : MyD2D1Color(200, 96, 96, 96);
            break;
        case NAV_BB_DISABLED:
            arrowColor = MyD2D1Color(160, 64, 64, 64);
            fillColor = MyD2D1Color(0, 0, 0, 0);
            break;
    }

    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    pRenderTarget->BeginDraw();

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    if (iPartId == NAV_BACKBUTTON)
    {
        FLOAT centerY = height / 2.f;
        FLOAT tailLength = width / 2.5f;
        FLOAT tailStartX = width - (tailLength / 1.5f);
        FLOAT tailEndX = tailStartX - tailLength;

        FLOAT headSpand = tailLength * .5f;
        FLOAT headOffset = headSpand * 0.866f;

        pRenderTarget->DrawLine(
        D2D1::Point2F(tailStartX, centerY),
        D2D1::Point2F(tailEndX+1.5f, centerY),
        arrowBrush.Get(), 1.5f
        );
        
        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX + headOffset, centerY + headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );

        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX + headOffset, centerY - headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );  
    }
    else if (iPartId == NAV_FORWARDBUTTON)
    {
        FLOAT centerY = height / 2.f;
        FLOAT tailLength = width / 2.5f;
        FLOAT tailStartX = tailLength / 1.5f;
        FLOAT tailEndX = tailStartX + tailLength;

        FLOAT headSpand = tailLength * .5f;
        FLOAT headOffset = headSpand * 0.866f;

        pRenderTarget->DrawLine(
        D2D1::Point2F(tailStartX, centerY),
        D2D1::Point2F(tailEndX-1.5f, centerY),
        arrowBrush.Get(), 1.5f
        );
        
        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX - headOffset, centerY - headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 1.5f
        );

        pRenderTarget->DrawLine(
            D2D1::Point2F(tailEndX - headOffset, centerY + headOffset),
            D2D1::Point2F(tailEndX, centerY),
            arrowBrush.Get(), 2.f
        );  
    }
    else if (iPartId == NAV_MENUBUTTON)
    {
        FLOAT centerX = width / 2.f;
        FLOAT centerY = height / 2.f;

        FLOAT arrowLength = std::min(width, height) * 0.33f;
        // 60 degree angle
        FLOAT dx = arrowLength * 0.866f;
        FLOAT dy = arrowLength * 0.5f;

        D2D1_POINT_2F ptTip   = D2D1::Point2F(centerX, centerY + dy);
        D2D1_POINT_2F ptLeft  = D2D1::Point2F(centerX - dx, centerY - dy);
        D2D1_POINT_2F ptRight = D2D1::Point2F(centerX + dx, centerY - dy);

        pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 2.f);
        pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 2.f);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintToolbarButton(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || (iPartId != TP_BUTTON && iPartId != TP_DROPDOWNBUTTON && iPartId != TP_SPLITBUTTON))
        return FALSE;
    if (iStateId == TS_NORMAL || iStateId == TS_DISABLED || iStateId == TS_NEARHOT) return FALSE;

    INT index = (iStateId == TS_HOTCHECKED) ? 0 : (iStateId == TS_PRESSED) ? 1 : (iStateId == TS_CHECKED) ? 2 : 3;

    if (!g_themeCache.toolbarbutton[index])
        if (!g_themeCache.CacheToolbarButton(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.toolbarbutton[index], pRect, 9, 9, 8, 8);
    return TRUE;
}

BOOL CThemeCache::CacheToolbarButton(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if (!g_themeCache.CreateDIB(g_themeCache.toolbarbutton[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.toolbarbutton[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor = (iStateId == TS_HOT || iStateId == TS_OTHERSIDEHOT) ? MyD2D1Color(96, 144, 144, 144) :
                             (iStateId == TS_PRESSED || iStateId == TS_CHECKED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(80, 144, 144, 144);

    pRenderTarget->BeginDraw();

    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());

    if (iStateId == TS_HOTCHECKED || iStateId == TS_CHECKED)
    {
        FLOAT pillOffset = width * 0.2f;
        D2D1_COLOR_F pillColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
        fillBrush->SetColor(pillColor);
        pRenderTarget->DrawLine(D2D1::Point2F(pillOffset, height-1), D2D1::Point2F(width - pillOffset, height-1), fillBrush.Get(), 2.0f);
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintToolbarSplitDropDown(HDC hdc, INT iPartId,  INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != TP_SPLITBUTTONDROPDOWN)
        return FALSE;
    
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = RECTWIDTH(pRect), height = RECTHEIGHT(pRect);

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F fillColor = (iStateId == TS_HOT || iStateId == TS_HOTCHECKED || iStateId == TS_OTHERSIDEHOT) ? MyD2D1Color(96, 144, 144, 144) : 
                             (iStateId == TS_PRESSED || iStateId == TS_CHECKED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(0, 0, 0, 0);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &brush);
    
    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(1.f, 0.f, (FLOAT)width, (FLOAT)height),cornerRadius, cornerRadius);
    FLOAT centerX = width/2.f + 1;
    FLOAT centerY = height/2.f;

    FLOAT arrowLen = width * .25f;
    FLOAT dx = arrowLen * 0.707f;

    pRenderTarget->BeginDraw();

    pRenderTarget->FillRoundedRectangle(&Rect, brush.Get());
    if (iStateId == TS_DISABLED) 
        brush->SetColor(MyD2D1Color(64, 64, 64));
    else
        brush->SetColor( g_IsSysThemeDarkMode ?  MyD2D1Color(255, 255, 255) : MyD2D1Color(0, 0, 0));

    if (iStateId == TS_PRESSED) {
        pRenderTarget->DrawLine(D2D1::Point2F(centerX , centerY + arrowLen/2.f), D2D1::Point2F(centerX - dx , centerY - arrowLen/2.f), brush.Get(), scale * 1.5f);
        pRenderTarget->DrawLine(D2D1::Point2F(centerX , centerY + arrowLen/2.f), D2D1::Point2F(centerX + dx, centerY - arrowLen/2.f), brush.Get(), scale * 1.5f);
    }
    else {
        pRenderTarget->DrawLine(D2D1::Point2F(centerX + arrowLen/2.f, centerY), D2D1::Point2F(centerX - arrowLen/2.f, centerY - dx), brush.Get(), scale * 1.5f);
        pRenderTarget->DrawLine(D2D1::Point2F(centerX + arrowLen/2.f, centerY), D2D1::Point2F(centerX - arrowLen/2.f, centerY + dx), brush.Get(), scale * 1.5f);
    }

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintAddressBand(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != 1)
        return FALSE;
    INT index = iStateId - 1;

    if (!g_themeCache.addressband[index])
        if (!g_themeCache.CacheAddressBand(iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.addressband[index], pRect, 12, 12, 11, 11);
    return TRUE;
}

BOOL CThemeCache::CacheAddressBand(INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 5.f * scale;
    INT width = 24, height = 24;

    if (!g_themeCache.CreateDIB(g_themeCache.addressband[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.addressband[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    D2D1_COLOR_F fillColor, borderColor;
    switch (iStateId) 
    {
        case 1:
            fillColor = MyD2D1Color(48, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 2:
            fillColor = MyD2D1Color(96, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 3:
            fillColor = MyD2D1Color(24, 96, 96, 96);
            borderColor = MyD2D1Color(64, 255, 255, 255);
            break;
        case 4:
            fillColor = g_IsSysThemeDarkMode ? MyD2D1Color(0, 0, 0) : MyD2D1Color(255, 255, 255);
            borderColor = IsAccentColorPossibleD2D(105, 205, 255, SystemAccentColorLight2);
            break;
    }
    D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);

    pRenderTarget->BeginDraw();

    pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    fillBrush->SetColor(borderColor);
    pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2, height-.5f), D2D1::Point2F(width-cornerRadius/2, height-.5f), fillBrush.Get());
    pRenderTarget->DrawLine(D2D1::Point2F(cornerRadius/2 - 1.5f, height-1.5f), D2D1::Point2F(width - cornerRadius/2 + 1.5f, height-1.5f), fillBrush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintMenu(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    // Part:14 (Win10) - Part:27 (Win11)
    if (!g_d2dFactory || (iPartId != 27 && iPartId != MENU_POPUPITEM && iPartId != MENU_BARITEM && iPartId != MENU_POPUPSEPARATOR))
        return FALSE;
    if ((iPartId == 27 || iPartId == MENU_POPUPITEM) && iStateId != 2) return FALSE;
    if ((iPartId == MENU_BARITEM) && 
        (iStateId == MBI_NORMAL || iStateId == MBI_DISABLED || iStateId == MBI_DISABLEDPUSHED)) return FALSE;

    INT index = (iPartId == MENU_POPUPSEPARATOR) ? 0 : (iPartId == 27 || iPartId == MENU_POPUPITEM) ? 1 : (iPartId == MENU_BARITEM && iStateId == MBI_PUSHED) ?  3 : 2;

    if (!g_themeCache.menuitem[index])
        if (!g_themeCache.CacheMenuItem(iPartId, iStateId, index))
            return FALSE;
    if (iPartId != MENU_POPUPSEPARATOR)
        DrawNineGridStretch(hdc, g_themeCache.menuitem[index], pRect, 9, 9, 8, 8);
    else
        DrawNineGridStretch(hdc, g_themeCache.menuitem[index], pRect, 1, 5, 0, 0);
    return TRUE;
}

BOOL CThemeCache::CacheMenuItem(INT iPartId, INT iStateId, INT indexState)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    FLOAT cornerRadius = 4.f * scale;
    INT width = 18, height = 18;

    if (iPartId == MENU_POPUPSEPARATOR) {
        width = 1;
        height = 5;
    }

    if (!g_themeCache.CreateDIB(g_themeCache.menuitem[indexState], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.menuitem[indexState], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    pRenderTarget->BeginDraw();
    
    if (iPartId == MENU_POPUPITEM || iPartId == 27)
    {
        D2D1_COLOR_F fillColor = IsAccentColorPossibleD2D(0, 160, 255, SystemAccentColorLight1);
        D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    }
    else if (iPartId == MENU_POPUPSEPARATOR) {
        D2D1_COLOR_F lineColor = (g_IsSysThemeDarkMode) ? MyD2D1Color(96, 255, 255, 255) : MyD2D1Color(64, 0, 0, 0);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> lineBrush;
        pRenderTarget->CreateSolidColorBrush(lineColor, &lineBrush);

        pRenderTarget->DrawLine({0, (FLOAT)height/2}, {(FLOAT)width, (FLOAT)height/2}, lineBrush.Get());
    }
    else {
        D2D1_COLOR_F fillColor = (iStateId == MBI_PUSHED) ? MyD2D1Color(64, 144, 144, 144) : MyD2D1Color(128, 96, 96, 96);
        D2D1_ROUNDED_RECT Rect = D2D1::RoundedRect(D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius);
        Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
        pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);
        pRenderTarget->FillRoundedRectangle(&Rect, fillBrush.Get());
    }
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintDragDrop(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory || iPartId != DD_IMAGEBG)
        return FALSE;

    if (!g_themeCache.dragdrop[0])
        if (!g_themeCache.CacheDragDrop())
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.dragdrop[0], pRect);
    return TRUE;
}

BOOL CThemeCache::CacheDragDrop()
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 108, height = 108;
    FLOAT cornerRadius = 4.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.dragdrop[0], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.dragdrop[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = { D2D1::RectF(0, 0, width, height), cornerRadius, cornerRadius};
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->BeginDraw();

    pRenderTarget->CreateSolidColorBrush(MyD2D1Color(128, 96, 96, 96), &brush);
    pRenderTarget->FillRoundedRectangle(&roundedRect, brush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintSpinArrowGlyph(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    INT width = RECTWIDTH(pRect);
    INT height = RECTHEIGHT(pRect);

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(hdc, pRect, g_d2dFactory, &pRenderTarget)))
        return FALSE;

    D2D1_COLOR_F arrowColor =
        (iStateId == UPS_HOT)      ? MyD2D1Color(255, 255, 255) :
        (iStateId == UPS_PRESSED)  ? MyD2D1Color(128, 128, 128)  :
        (iStateId == UPS_DISABLED) ? MyD2D1Color(64, 64, 64)  :
                                     MyD2D1Color(192, 192, 192);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> arrowBrush;
    pRenderTarget->CreateSolidColorBrush(arrowColor, &arrowBrush);

    FLOAT centerX = width / 2.f;
    FLOAT centerY = height / 2.f;
    FLOAT arrowLength = (iPartId == SPNP_UP || iPartId == SPNP_DOWN) ? std::min(width, height) * 0.5f
                        : std::min(width, height) * 0.3f;
    FLOAT dx = arrowLength * 0.866f;
    FLOAT dy = arrowLength * .5f;

    D2D1_POINT_2F ptTip, ptLeft, ptRight;

    if (iPartId == SPNP_UP) {
        ptTip   = { centerX,      centerY - dy };
        ptLeft  = { centerX - dx, centerY + dy };
        ptRight = { centerX + dx, centerY + dy };
    }
    else if (iPartId == SPNP_DOWN) {
        ptTip   = {centerX, centerY + dy};
        ptLeft  = {centerX - dx, centerY - dy};
        ptRight = {centerX + dx, centerY - dy};
    }
    else if (iPartId == SPNP_DOWNHORZ)
    {
        ptTip   = { centerX - dy, centerY };
        ptLeft  = { centerX + dy, centerY - dx };
        ptRight = { centerX + dy, centerY + dx };
    }
    else if (iPartId == SPNP_UPHORZ)
    {
        ptTip   = { centerX + dy, centerY };
        ptLeft  = { centerX - dy, centerY - dx };
        ptRight = { centerX - dy, centerY + dx };
    }

    pRenderTarget->BeginDraw();

    pRenderTarget->DrawLine(ptLeft, ptTip, arrowBrush.Get(), 1.5f);
    pRenderTarget->DrawLine(ptRight, ptTip, arrowBrush.Get(), 1.5f);
    
    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

BOOL PaintSpin(HDC hdc, INT iPartId, INT iStateId, LPCRECT pRect)
{
    if (!g_d2dFactory)
        return FALSE;

    INT index = (iStateId == UPS_HOT) ? 1 : (iStateId == UPS_PRESSED) ? 2
            : (iStateId == UPS_DISABLED) ? 3 : 0;

    index = (iPartId == SPNP_DOWNHORZ || iPartId == SPNP_UPHORZ) ? index + 4 : index;
    
    // Clean previous paintings
    PatBlt(hdc, pRect->left, pRect->top, RECTWIDTH(pRect), RECTHEIGHT(pRect), BLACKNESS);

    if (!g_themeCache.spin[index])
        if (!g_themeCache.CacheSpinButton(iPartId, iStateId, index))
            return FALSE;
    DrawNineGridStretch(hdc, g_themeCache.spin[index], pRect, 6, 5, 6, 5);

    // Custom glyphs aren't cached due to no image stretching, draw them at runtime
    if (PaintSpinArrowGlyph(hdc, iPartId, iStateId, pRect))
        return TRUE;
    else {
        // Erase any previous custom drawing
        PatBlt(hdc, pRect->left, pRect->top, RECTWIDTH(pRect), RECTHEIGHT(pRect), BLACKNESS);
        return FALSE;
    }
}

BOOL CThemeCache::CacheSpinButton(INT iPartId, INT iStateId, INT stateIndex)
{
    FLOAT scale = (FLOAT)g_Dpi / USER_DEFAULT_SCREEN_DPI;
    INT width = 12, height = 12;
    FLOAT cornerRadius = 2.f * scale;

    if (!g_themeCache.CreateDIB(g_themeCache.spin[stateIndex], width, height))
        return FALSE;

    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    RECT rc = { 0, 0, width, height};
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.spin[stateIndex], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    D2D1_ROUNDED_RECT roundedRect = {{0.f, 0.f, (FLOAT)width, (FLOAT)height}, cornerRadius, cornerRadius};
    D2D1_RECT_F Rect = {0.f, 0.f, (FLOAT)width, (FLOAT)height};

    D2D1_COLOR_F fillColor =
        (iStateId == UPS_HOT)      ? MyD2D1Color(128, 96, 96, 96) :
        (iStateId == UPS_PRESSED)  ? MyD2D1Color(180, 60, 60, 60)  :
        (iStateId == UPS_DISABLED) ? MyD2D1Color(160, 0, 0, 0)  :
                                     MyD2D1Color(96, 80, 80, 80);

    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> fillBrush;
    pRenderTarget->CreateSolidColorBrush(fillColor, &fillBrush);

    pRenderTarget->BeginDraw();

    if (iPartId == SPNP_UP || iPartId == SPNP_DOWN)
        pRenderTarget->FillRectangle(&Rect, fillBrush.Get());
    else
        pRenderTarget->FillRoundedRectangle(&roundedRect, fillBrush.Get());

    auto hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

HRESULT WINAPI HookedDrawThemeBackground(
    HTHEME hTheme,
    HDC hdc,
    INT iPartId,
    INT iStateId,
    LPCRECT pRect,
    LPCRECT pClipRect)
{       
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ScrollBar")
    {
        if (PaintScroll(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintScrollBarArrows(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Button")
    {
        if (PaintPushButton(hdc, iPartId, iStateId, pRect, pClipRect))
            return S_OK;
        else if (PaintRadioButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCheckBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLink(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLinkGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (iPartId == BP_GROUPBOX)
        {
            HTHEME hThemeGroupBox = nullptr;
            if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeGroupBox, L"Button"))
            {
                if (PaintGroupBox(hdc, iPartId, iStateId, pRect, pClipRect)) {
                    CloseThemeData(hThemeGroupBox);
                    return S_OK;
                }
            }
            
            if (hThemeGroupBox)
                CloseThemeData(hThemeGroupBox);
        }
    }
    else if (ThemeClassName == L"Tab")
    {
        if (PaintTab(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ComboBox")
    {
        // The Win32 address bar uses both the "Combobox" and "ComboBox" theme classes along with other classes
        // ComboBox is used when the address bar is selected, while combobox is used when the drop-down window is open
        if (SanitizeAddressCombobox(hTheme, hdc, iPartId, iStateId))
            return S_OK;
        else if (PaintDropDownArrow(hdc, iPartId, iStateId, pRect, TRUE))
            return S_OK;
    }
    else if (ThemeClassName == L"Combobox")
    {
        if (PaintCombobox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintDropDownArrow(hdc, iPartId, iStateId, pRect, FALSE))
            return S_OK;
    }
    else if (ThemeClassName == L"Listbox")
    {
        if (PaintListBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Edit")
    {
        if (PaintEditBox(hTheme, hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"TrackBar")
    {
        if (PaintTrackbar(hdc, iPartId, iStateId, pRect))
            return S_OK;
        if (PaintTrackbarThumb(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintTrackBarPointedThumb(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Progress")
    {
        // The exported GetThemeClass function does not provide
        // full string of theme class names of derived theme classes
        // Use the OpenThemeData API instead.
        HTHEME hThemeProgress = NULL;
        if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeProgress, L"Indeterminate::Progress"))
        {
            if (PaintIndeterminateProgressBar(hdc, iPartId, iStateId, pRect))
            {
                CloseThemeData(hThemeProgress);
                return S_OK;
            }
            CloseThemeData(hThemeProgress);
        }
        else if (PaintProgressBar(hdc, iPartId, iStateId, pRect)) 
        {
            CloseThemeData(hThemeProgress);
            return S_OK;
        }
        if (hThemeProgress)
            CloseThemeData(hThemeProgress);
    } 
    else if (ThemeClassName == L"ListView")
    {
        if (PaintListView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"TreeView")
    {
        if (PaintTreeViewButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        if (PaintTreeViewGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Header")
    {
        if (PaintHeader(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Navigation")
    {
        if (PaintNavigationButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Toolbar")
    {
        HTHEME hThemeToolbar = NULL;
        if (SetThemeHandle(WindowFromDC(hdc), hThemeToolbar, L"BB::Toolbar"))
        {
            if (PaintToolbarSplitDropDown(hdc, iPartId, iStateId, pRect)) {
                CloseThemeData(hThemeToolbar);
                return S_OK;
            }
        }
        if (PaintToolbarButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"AddressBand" || ThemeClassName == L"SearchBox")
    {
        if (PaintAddressBand(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Menu")
    {
        if (PaintMenu(hdc, iPartId, iStateId, pRect))
            return S_OK;
        // Force menu white glyphs
        else if (iPartId <= MENU_SYSTEMRESTORE && iPartId >= MENU_SYSTEMCLOSE && g_IsSysThemeDarkMode) {
            HTHEME hThemeMenu = NULL;
            if (SetThemeHandle(WindowFromDC(hdc), hThemeMenu, L"DarkMode::Menu")) {
                auto hr = DrawThemeBackground_orig(hThemeMenu, hdc, iPartId, iStateId, pRect, pClipRect);
                CloseThemeData(hThemeMenu);
                return hr;
            }
        }
    }
    else if (ThemeClassName == L"DragDrop")
    {
        if (PaintDragDrop(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Spin")
    {
        if (PaintSpin(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }

    HRESULT hr = DrawThemeBackground_orig(hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
    
    if((ThemeClassName == L"Rebar" && (iPartId == RP_BAND || iPartId == RP_BACKGROUND) && iStateId == 0)
        || (ThemeClassName == L"Header" && (iPartId == THEMECLS_COMMONPROPS_PART || (iPartId == HP_HEADERITEM && (iStateId == HIS_NORMAL || iStateId == HIS_SORTEDNORMAL || iStateId == HIS_ICONNORMAL))))
        || (ThemeClassName == L"TaskDialog" && iPartId == TDLG_FOOTNOTEPANE && iStateId == 0)
        || (ThemeClassName == L"Tab" && iPartId == TABP_PANE)
        || (ThemeClassName == L"Status" && iPartId == THEMECLS_COMMONPROPS_PART)
        || (ThemeClassName == L"Tooltip" && (iPartId == TTP_STANDARD || iPartId == TTP_BALLOON || iPartId == TTP_BALLOONSTEM)))
    {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    else if (ThemeClassName == L"Menu" && (iPartId == MENU_BARBACKGROUND || iPartId == MENU_BARITEM))
    {
        RECT clipRect{*pRect};
        if (pClipRect)
            IntersectRect(&clipRect, pRect, pClipRect);
        FillRect(hdc, &clipRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    else if (ThemeClassName == L"Menu" && (iPartId == MENU_POPUPBACKGROUND || iPartId == MENU_POPUPBORDERS || iPartId == MENU_POPUPGUTTER || 
        iPartId == MENU_POPUPCHECKBACKGROUND || ((iPartId == MENU_POPUPITEM || iPartId == 27) && iStateId != MPI_HOT)))
    {
        RECT clipRect{*pRect};
        if (pClipRect)
            IntersectRect(&clipRect, pRect, pClipRect);
        if (g_settings.FlyoutsEffects)
            FillRect(hdc, &clipRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        else if (g_settings.FillBg) {
            HBRUSH brush = CreateSolidBrush(RGB(32, 32, 32));
            FillRect(hdc, &clipRect, brush);
            DeleteObject(brush);
        }
        return S_OK;
    }
    else if (ThemeClassName == L"Toolbar" && iPartId == THEMECLS_COMMONPROPS_PART) {
        HTHEME hThemeToolbar = nullptr;
        if ((SetThemeHandle(WindowFromDC(hdc), hThemeToolbar, L"Placesbar::Toolbar"))) {
            FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
            CloseThemeData(hThemeToolbar);
            return S_OK;
        }
    }
    return hr;
}

HRESULT WINAPI HookedDrawThemeBackgroundEx(
    HTHEME hTheme,
    HDC hdc,
    INT iPartId,
    INT iStateId,
    LPCRECT pRect,
    const DTBGOPTS* pOptions)
{    
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    if (ThemeClassName == L"ScrollBar")
    {
        if (PaintScroll(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintScrollBarArrows(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ListView")
    {
        if (PaintListView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Edit")
    {
        if (PaintEditBox(hTheme ,hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Button")
    {
        RECT rcClip = *pRect;
        if(pOptions && pOptions->dwFlags & DTBG_CLIPRECT)
            rcClip = pOptions->rcClip;
        if (PaintPushButton(hdc, iPartId, iStateId, pRect, &rcClip))
            return S_OK;
        else if (PaintRadioButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCheckBox(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLink(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintCommandLinkGlyph(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"ItemsView")
    {
        if (PaintItemsView(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Header")
    {
        if (PaintHeader(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"PreviewPane")
    {
        if (PaintPreviewPaneSeparator(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }
    else if (ThemeClassName == L"Progress")
    {
        HTHEME hThemeProgress = NULL;
        if (hTheme == SetThemeHandle(WindowFromDC(hdc), hThemeProgress, L"Indeterminate::Progress"))
        {
            if (PaintIndeterminateProgressBar(hdc, iPartId, iStateId, pRect))
            {
                CloseThemeData(hThemeProgress);
                return S_OK;
            }
        }
        else if (PaintProgressBar(hdc, iPartId, iStateId, pRect)) 
        {
            CloseThemeData(hThemeProgress);
            return S_OK;
        }

        if (hThemeProgress)
            CloseThemeData(hThemeProgress);
    } 
    else if (ThemeClassName == L"CommandModule")
    {
        if (PaintModuleButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintModuleSplitButton(hdc, iPartId, iStateId, pRect))
            return S_OK;
        else if (PaintModuleLocation(hdc, iPartId, iStateId, pRect))
            return S_OK;
    }

    HRESULT hr = DrawThemeBackgroundEx_orig(hTheme, hdc, iPartId, iStateId, pRect, pOptions);

    if ((ThemeClassName == L"Rebar" && (iPartId == RP_BAND || iPartId == RP_BACKGROUND) && iStateId == 0) 
        || (ThemeClassName == L"TreeView" && iPartId == THEMECLS_COMMONPROPS_PART))
    {
        return S_OK;    
    }
    else if ((ThemeClassName == L"PreviewPane" && iPartId == 1)
        || (ThemeClassName == L"Header" && iPartId == THEMECLS_COMMONPROPS_PART)
        || (ThemeClassName == L"CommandModule" && iPartId == 1 && iStateId == 0)
        || (ThemeClassName == L"TaskDialog" && (iPartId == TDLG_CONTENTPANE || iPartId == TDLG_FOOTNOTESEPARATOR ||  iPartId == TDLG_FOOTNOTEPANE || iPartId == TDLG_SECONDARYPANEL) && iStateId == 0)
        || (ThemeClassName == L"TaskDialog" && iPartId == TDLG_PRIMARYPANEL)
        || (ThemeClassName == L"AeroWizard" && (iPartId == AW_TITLEBAR || iPartId == AW_HEADERAREA || iPartId == AW_CONTENTAREA || iPartId == AW_COMMANDAREA))
        || (ThemeClassName == L"CommonItemsDialog" && iPartId == 1)
        || (ThemeClassName == L"ControlPanel" && (iPartId == CPANEL_CONTENTPANE || iPartId == CPANEL_CONTENTPANELINE || iPartId == CPANEL_BANNERAREA || iPartId == CPANEL_LARGECOMMANDAREA || iPartId == CPANEL_SMALLCOMMANDAREA)))
    {
        FillRect(hdc, pRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }
    return hr;
}

// Remove white rect below menubar (e.g. seen in mmc.exe)
HRESULT WINAPI HookedDrawThemeEdge(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, const RECT *pDestRect, UINT uEdge, UINT uFlags, RECT *pContentRect)
{
    std::wstring ThemeClass = GetThemeClass(hTheme);

    if (ThemeClass == L"Rebar" && iPartId == RP_BAND) {
        FillRect(hdc, pContentRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
        return S_OK;
    }

    return DrawThemeEdge_orig(hTheme, hdc, iPartId, iStateId, pDestRect, uEdge, uFlags, pContentRect);
}

HRESULT WINAPI HookedGetThemeMargins(HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, INT iPropId, RECT* prc, MARGINS *pMargins)
{
    std::wstring ThemeClassName = GetThemeClass(hTheme);

    auto ret = GetThemeMargins_orig(hTheme, hdc, iPartId, iStateId, iPropId, prc, pMargins);

    if (ThemeClassName == L"Tooltip" && iPartId == TTP_STANDARD) {
        if (iPropId == TMT_CONTENTMARGINS)
            *pMargins = {8, 8, 8, 8};
        else if (iPropId == TMT_CAPTIONMARGINS)
            *pMargins = {10, 10, 10, 10};
    }
    else if (ThemeClassName == L"Menu")
    {
        if (iPartId == MENU_POPUPITEM || iPartId == 27 || iPartId == 26) 
        {
            if (iPropId == TMT_CONTENTMARGINS)
                *pMargins = {2, 2, 4, 4};
            else if (iPropId == TMT_SIZINGMARGINS)
                *pMargins = {10, 10, 10, 10};
            else if (iPropId == 10000)
                *pMargins = {0, 0, 4, 4};
        }
        else if (iPartId == MENU_BARITEM) {
            if (iPropId == 10000)
                *pMargins = {9, 9, 3, 3};
        }
    }
    else if (ThemeClassName == L"Edit")
    {
        if (iPropId == TMT_SIZINGMARGINS)
            *pMargins = {8, 8, 8, 8};
    }   
    
    return ret;
}

HRESULT WINAPI HookedGetThemeFont (HTHEME hTheme, HDC hdc, INT iPartId, INT iStateId, INT iPropId, LOGFONTW* pFont)
{
    auto hr = GetThemeFont_orig(hTheme, hdc, iPartId, iStateId, iPropId, pFont);
    std::wstring ThemeClassName = GetThemeClass(hTheme);
    
    if (ThemeClassName == L"Menu" && iPropId == TMT_FONT) 
    {
        // Return if it's not the original font
        if (wcscmp(pFont->lfFaceName, L"Segoe UI"))
            return hr;
        wcscpy_s(pFont->lfFaceName, LF_FACESIZE, L"Segoe UI Variable Small");
        pFont->lfHeight = -13;
        pFont->lfWeight = 400;
        pFont->lfQuality = CLEARTYPE_QUALITY;
        pFont->lfPitchAndFamily = DEFAULT_PITCH;
    }
    else if (ThemeClassName == L"ControlPanelStyle" && iPartId == CPANEL_TITLE && iPropId == TMT_FONT) {
        wcscpy_s(pFont->lfFaceName, LF_FACESIZE, L"Segoe UI Variable Display Semib");
        pFont->lfHeight = -24;
    }
    return hr;
}

//https://github.com/ALTaleX531/TranslucentFlyouts/blob/master/TFMain/EffectHelper.hpp
// Required for flyouts with DWM SYSTEMBACKDROP effects
VOID TriggerWindowNCRendering(HWND hwnd)
{
    // NOTICE WINDOWS THAT WE HAVE ACTIVATED THE WINDOW
    DefWindowProcW(hwnd, WM_NCACTIVATE, TRUE, 0);
    //SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_DRAWFRAME | SWP_NOACTIVATE);
}

VOID DwmMakeWindowTransparent(HWND hwnd)
{
    DWM_BLURBEHIND bb{ DWM_BB_ENABLE | DWM_BB_BLURREGION | DWM_BB_TRANSITIONONMAXIMIZED, TRUE, CreateRectRgn(0, 0, -1, -1), TRUE };
    DwmEnableBlurBehindWindow(hwnd, &bb);
    DeleteObject(bb.hRgnBlur);
}

VOID EnableBlurBehind(HWND hWnd)
{
    // Does not interfere with the Windows Terminal, GameBar overlay
    if(!(IsWindowClass(hWnd, L"CASCADIA_HOSTING_WINDOW_CLASS") || IsWindowClass(hWnd, L"ApplicationFrameWindow")))
    {
        ACCENT_POLICY accentPolicy = {};
        WINCOMPATTRDATA winCompositionAttrib = {};
        DWM_BLURBEHIND dwmBlurBehindData = { };

        dwmBlurBehindData.fEnable = TRUE;
        dwmBlurBehindData.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION | DWM_BB_TRANSITIONONMAXIMIZED;
        // Blurs window client area
        HRGN hRgn = CreateRectRgn(0, 0, -1, -1);
        dwmBlurBehindData.hRgnBlur = hRgn;
        dwmBlurBehindData.fTransitionOnMaximized = TRUE;

        DwmEnableBlurBehindWindow(hWnd, &dwmBlurBehindData);
        DeleteObject(hRgn);

        accentPolicy.AccentState = ACCENT_STATE_ENABLE_ACRYLICBLURBEHIND;
        accentPolicy.GradientColor = g_settings.AccentBlurBehindClr;

        winCompositionAttrib.Attrib = WCA_ACCENT_POLICY;
        winCompositionAttrib.pvData = &accentPolicy;
        winCompositionAttrib.cbData = sizeof(accentPolicy);

        if (SetWindowCompositionAttribute)
            SetWindowCompositionAttribute(hWnd, &winCompositionAttrib);    
    }
}

static LRESULT WINAPI HookedDefWindowProcW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{    
    if (msg == WM_SETTINGCHANGE) 
    {
        // System theme change
        if (lParam && wcscmp((LPCWSTR)lParam, L"ImmersiveColorSet") == 0) 
        {
            // Fetch the actual current theme file path from registry
            std::wstring currentTheme = GetCurrentWindowsThemePath();

            AcquireSRWLockExclusive(&g_ThemeChangeLock);

            COLORREF crAccent = (g_settings.AccentColorize) ? GetAccentColor() : g_settings.AccentColor;

            if (currentTheme != g_LastThemePath || g_settings.AccentColor != crAccent) 
            {
                g_LastThemePath = currentTheme; 

                // Process the theme change
                g_themeCache.ClearCache();
                g_IsSysThemeDarkMode = ShouldSystemUseDarkMode();
                g_AccentPalette.LoadAccentPalette();
                
                if (g_settings.AccentColorize)
                    g_settings.AccentColor = crAccent;

                if (g_settings.SetSystemColors)
                    ColorizeSysColors();

                AcquireSRWLockExclusive(&g_SysColorsLock);
                for (HBRUSH& brush : g_themeCachedCustomSysColorBrushes) {
                    if (brush) { 
                        DeleteObject(brush); brush = nullptr; 
                    }
                }
                ReleaseSRWLockExclusive(&g_SysColorsLock);
            }
            
            ReleaseSRWLockExclusive(&g_ThemeChangeLock);
        }
    }   

    if (IsWindowClass(hWnd, L"ViewControlClass") && msg == WM_NCPAINT) {
        UINT borderType = DWMWCP_ROUND;
        DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &borderType, sizeof(UINT));
    }
    return DefWindowProc_orig(hWnd, msg, wParam, lParam);
}

VOID HandleEffects(HWND hWnd)
{
    BOOL isFlyoutWindow = isWindowFlyout(hWnd);

    if (g_IsSysThemeDarkMode) 
        DwmSetWindowAttribute(hWnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &ENABLE, sizeof(UINT));

    if(g_settings.BgType == g_settings.AccentBlurBehind)
        EnableBlurBehind(hWnd);
    else if (g_settings.BgType > g_settings.AccentBlurBehind)
    {
        if (isFlyoutWindow) {
            DwmMakeWindowTransparent(hWnd);
            TriggerWindowNCRendering(hWnd);
        }
        DwmSetWindowAttribute(hWnd, DWMWA_SYSTEMBACKDROP_TYPE, &g_settings.BgType, sizeof(UINT));
    }

    if (!isFlyoutWindow && g_settings.BgType != g_settings.Default) {
        MARGINS margins = {-1, -1, -1, -1};
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    }
    
    if (isFlyoutWindow) {
        UINT borderType = DWMWCP_ROUND;
        DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &borderType, sizeof(UINT));
    }
    
    return;
}

VOID NewWindowShown(HWND hWnd)
{
    if(!IsWindowEligible(hWnd))
        return;

    HandleEffects(hWnd);

    if (IsExcelProcess())
        ApplyExcelWorksheetTransparencyToChildren(hWnd);
}

VOID DwmExpandFrameIntoClientAreaHook() {
    WindhawkUtils::SetFunctionHook(DwmExtendFrameIntoClientArea, HookedDwmExtendFrameIntoClientArea, &DwmExtendFrameIntoClientArea_orig);
}

VOID DwmSetWindowAttributeHook() {
    WindhawkUtils::SetFunctionHook(DwmSetWindowAttribute, HookedDwmSetWindowAttribute, &DwmSetWindowAttribute_orig); 
}

HRESULT WINAPI HookedGetThemeTransitionDuration(HTHEME hTheme, INT iPartId, INT iStateIdFrom, INT iStateIdTo, INT iPropId, DWORD *pdwDuration)
{
    auto hr = GetThemeTransitionDuration_orig(hTheme, iPartId, iStateIdFrom, iStateIdTo, iPropId, pdwDuration);
    std::wstring ThemeClassStr = GetThemeClass(hTheme);
    
    if (ThemeClassStr == L"ScrollBar" && (iPartId == SBP_ARROWBTN || iPartId == SBP_THUMBBTNHORZ || iPartId == SBP_THUMBBTNVERT) && iStateIdTo == SCRBS_NORMAL)
        *pdwDuration = 40;
    else if (ThemeClassStr == L"ScrollBar" && (iPartId == SBP_ARROWBTN && iStateIdFrom == SCRBS_HOT && iStateIdTo == SCRBS_HOVER))
        *pdwDuration = 40;
    
    return hr;
}

LRESULT (STDCALL *CThemeMenu_MenuKeyboardMsgProc_orig)(INT, WPARAM, LPARAM);
LRESULT STDCALL HookedCThemeMenu_MenuKeyboardMsgProc_orig(INT code, WPARAM wParam, LPARAM lParam)
{
    auto res = CThemeMenu_MenuKeyboardMsgProc_orig(code, wParam, lParam);

    #ifdef _WIN64
        INT archOffset = 1;
    #else
        INT archOffset = 2;
    #endif

    UINT msg = *reinterpret_cast<DWORD*>(lParam + 16 / archOffset);
    HWND hWnd = *reinterpret_cast<HWND*>(lParam + 24 / archOffset);

    if (IsWindowClass(hWnd, MENUPOPUP_CLASS) && (msg == WM_NCPAINT || msg == WM_PRINT))
        HandleEffects(hWnd);

    return res;
}

HRESULT (__fastcall *_GetBrushesForPart_orig)(HTHEME, INT, COLORREF, HBITMAP*, HBRUSH*);
HRESULT __fastcall Hooked_GetBrushesForPart(HTHEME hTheme, INT iPartId, COLORREF Color, HBITMAP *phBitmap, HBRUSH *phBrush)
{
   std::wstring ThemeClass = GetThemeClass(hTheme);
    
    if (ThemeClass == L"Tab" && (iPartId == TABP_BODY || iPartId == TABP_AEROWIZARDBODY)) {
        if (!*phBrush || *phBrush != GetSysColorBrush(COLOR_WINDOW)) {
            *phBrush = GetSysColorBrush(COLOR_WINDOW);
            return S_OK;
        }
    }
    
    return _GetBrushesForPart_orig(hTheme, iPartId, Color, phBitmap, phBrush);
}

void (__fastcall *_BorderRect_orig)(HDC, COLORREF, LPRECT, INT, INT);
void __fastcall Hooked_BorderRect(HDC hdc, COLORREF color, LPRECT pRect, INT cxThickness, INT cyThickness)
{
    if (!pRect) return;

    auto BorderComposition = [&](RECT rcBorder)
    {
        BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };
        params.dwFlags = BPPF_ERASE | BPPF_NOCLIP;
        HDC memDC = NULL;

        HPAINTBUFFER hpb = BeginBufferedPaint(hdc, &rcBorder, BPBF_TOPDOWNDIB, &params, &memDC);
        if (!hpb) {
            Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
            return _BorderRect_orig(hdc, color, pRect, cxThickness, cyThickness);
        }

        SetBkColor(memDC, color);
        ExtTextOutW(memDC, pRect->left, pRect->top, ETO_OPAQUE, pRect, NULL, NULL, NULL);
        BufferedPaintMakeOpaque(hpb, pRect);
        EndBufferedPaint(hpb, TRUE);
    };

    RECT rcBorder;
    // 1. Bottom Border
    rcBorder = *pRect;
    rcBorder.top = rcBorder.bottom - cyThickness;
    BorderComposition(rcBorder);

    // 2. Right Border
    rcBorder = *pRect;
    rcBorder.left = rcBorder.right - cxThickness;
    BorderComposition(rcBorder);

    // 3. Left Border
    rcBorder = *pRect;
    rcBorder.right = rcBorder.left + cxThickness;
    BorderComposition(rcBorder);

    // 4. Top Border
    rcBorder = *pRect;
    rcBorder.bottom = rcBorder.top + cyThickness;
    BorderComposition(rcBorder);

    return;
}

VOID UxThemeHooks(BOOL isFlyoutEffectEnabled)
{
    WindhawkUtils::SYMBOL_HOOK uxtheme_dll_hooks[] =
    {   
        // Inlined symbol in ARM64 system, avoid hooking.
        #ifdef _M_ARM64
        #else
            {
                {
                    #ifdef _WIN64
                        L"void __cdecl _BorderRect(struct HDC__ *,unsigned long,struct tagRECT const *,int,int)"
                    #else
                        L"void __stdcall _BorderRect(struct HDC__ *,unsigned long,struct tagRECT const *,int,int)"
                    #endif
                },
                &_BorderRect_orig,
                Hooked_BorderRect,
                FALSE
            },
        #endif
        {
            {
                #ifdef _WIN64
                    L"long __cdecl _GetBrushesForPart(void *,int,int,struct HBITMAP__ * *,struct HBRUSH__ * *)"
                #else
                    L"long __stdcall _GetBrushesForPart(void *,int,int,struct HBITMAP__ * *,struct HBRUSH__ * *)"
                #endif
            },
            &_GetBrushesForPart_orig,
            Hooked_GetBrushesForPart,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"protected: static __int64 __cdecl CThemeMenu::MenuKeyboardMsgProc(int,unsigned __int64,__int64)"
                #else
                    L"protected: static long __stdcall CThemeMenu::MenuKeyboardMsgProc(int,unsigned int,long)"
                #endif
            },
            &CThemeMenu_MenuKeyboardMsgProc_orig,
            HookedCThemeMenu_MenuKeyboardMsgProc_orig,
            FALSE
        },
    };

    HMODULE hUxTheme = LoadLibraryEx(L"uxtheme.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hUxTheme) {
        Wh_Log(L"Failed to load uxtheme.dll");
        return;
    }

    // If flyout effects setting isn't enabled hook to all symbols except the last one -> CThemeMenu::MenuKeyboardMsgProc
    if (!WindhawkUtils::HookSymbols(hUxTheme, uxtheme_dll_hooks, !isFlyoutEffectEnabled ? ARRAYSIZE(uxtheme_dll_hooks) - 1 : ARRAYSIZE(uxtheme_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in uxtheme.dll");
        return;
    }
}

VOID RestoreWindowCustomizations(HWND hWnd)
{
    if(!IsWindowEligible(hWnd))
        return;

    ACCENT_POLICY accentPolicy = {};
    WINCOMPATTRDATA winCompositionAttrib = {};
    DWM_BLURBEHIND dwmBlurBehindData = {};

    // Disabling AccentBlurBehind temp workaround
    dwmBlurBehindData.fEnable = FALSE;
    dwmBlurBehindData.dwFlags = DWM_BB_ENABLE;
    DwmEnableBlurBehindWindow(hWnd, &dwmBlurBehindData);

    accentPolicy.AccentState = ACCENT_STATE_DISABLED;

    winCompositionAttrib.Attrib = WCA_ACCENT_POLICY;
    winCompositionAttrib.pvData = &accentPolicy;
    winCompositionAttrib.cbData = sizeof(accentPolicy);

    if (SetWindowCompositionAttribute)
        SetWindowCompositionAttribute(hWnd, &winCompositionAttrib);
    
    DWM_SYSTEMBACKDROP_TYPE backdrop = DWMSBT_NONE;
    DwmSetWindowAttribute(hWnd, DWMWA_SYSTEMBACKDROP_TYPE , &backdrop, sizeof(UINT));

    // Manually restore frame extension
    if(!(IsWindowClass(hWnd,  L"TaskManagerWindow") && g_settings.BgType != g_settings.Default))
    {
        MARGINS margins = { 0, 0, 0, 0 };
        DwmExtendFrameIntoClientArea(hWnd, &margins);
    }
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) 
{
    DWORD dwProcessId = 0;
    // Pass console window, it might be called from other processes like Clink:https://github.com/chrisant996/clink
    if ((!GetWindowThreadProcessId(hWnd, &dwProcessId) || dwProcessId != GetCurrentProcessId()) && !IsWindowClass(hWnd, L"ConsoleWindowClass")) 
        return TRUE;
    else
    {
        HWND hParentWnd = GetAncestor(hWnd, GA_PARENT);
        if (hParentWnd && hParentWnd != GetDesktopWindow())
            return TRUE;
        else if(g_settings.Unload)
            RestoreWindowCustomizations(hWnd);
        else
            NewWindowShown(hWnd);
    }
    return TRUE;
}

VOID ApplyForExistingWindows()
{
    EnumWindows(EnumWindowsProc, 0);
}

COLORREF GetColorSetting(LPCWSTR hexColor) 
{
    if (!hexColor)
        return DWMWA_COLOR_NONE;
    else 
    {
        size_t len = wcslen(hexColor);
        if (len != 6 && len != 8)
        {
            Wh_Log(L"[ERROR] Invalid color length");
            return FALSE;
        }
        
        auto hexToByte = [](WCHAR c) -> INT {
            if (c >= L'0' && c <= L'9') return c - L'0';
            if (c >= L'A' && c <= L'F') return 10 + (c - L'A');
            if (c >= L'a' && c <= L'f') return 10 + (c - L'a');
            return -1;
        };

        BYTE alpha = 0x00;
        BYTE rgb[3] = { 0 };

        if (len == 8) 
        {
            alpha = 0XFF;
            INT alphaHigh = hexToByte(hexColor[0]);
            INT alphaLow  = hexToByte(hexColor[1]);
            if (alphaHigh < 0 || alphaLow < 0)
                return FALSE;
            alpha = (alphaHigh << 4) | alphaLow;
            hexColor += 2;
        }

        for (INT i = 0; i < 3; ++i) 
        {
            INT high = hexToByte(hexColor[i * 2]);
            INT low  = hexToByte(hexColor[i * 2 + 1]);
            if (high < 0 || low < 0)
                return FALSE;
            rgb[i] = (high << 4) | low;
        }

        return (alpha << 24) | (rgb[2] << 16) | (rgb[1] << 8) | rgb[0];
    }
}

// ---------------------------------------------------------------------------------------------
// User32.dll internal operations in most cases use the gpsi pointer (global pointer shared info) in order to fetch useful attributes about the system session
// one of them being the system color buffer, gpsi pointing to offest 4568 to system COLORREFs and offset 4696 to system BRUSHES
//
// Kernel operations (e.g. win32kfull.sys) use: W32GetUserSessionState() + offset (<20016> as of Win11 26200.8655) + <System color offset>
//
// System color offsets:
//
//     -System colors-                      -System brushes-
//
// 4568: COLOR_SCROLLBAR                4696: COLOR_SCROLLBAR
// 4572: COLOR_BACKGROUND               4704: COLOR_BACKGROUND
// 4576: COLOR_ACTIVECAPTION            4712: COLOR_ACTIVECAPTION
// 4580: COLOR_INACTIVECAPTION          4720: COLOR_INACTIVECAPTION
// 4584: COLOR_MENU                     4728: COLOR_MENU
// 4588: COLOR_WINDOW                   4736: COLOR_WINDOW
// 4592: COLOR_WINDOWFRAME              4744: COLOR_WINDOWFRAME
// 4596: COLOR_MENUTEXT                 4752: COLOR_MENUTEXT
// 4600: COLOR_WINDOWTEXT               4760: COLOR_WINDOWTEXT
// 4604: COLOR_CAPTIONTEXT              4768: COLOR_CAPTIONTEXT
// 4608: COLOR_ACTIVEBORDER             4776: COLOR_ACTIVEBORDER
// 4612: COLOR_INACTIVEBORDER           4784: COLOR_INACTIVEBORDER
// 4616: COLOR_APPWORKSPACE             4792: COLOR_APPWORKSPACE
// 4620: COLOR_HIGHLIGHT                4800: COLOR_HIGHLIGHT
// 4624: COLOR_HIGHLIGHTTEXT            4808: COLOR_HIGHLIGHTTEXT
// 4628: COLOR_BTNFACE                  4816: COLOR_BTNFACE
// 4632: COLOR_BTNSHADOW                4824: COLOR_BTNSHADOW
// 4636: COLOR_GRAYTEXT                 4832: COLOR_GRAYTEXT
// 4640: COLOR_BTNTEXT                  4840: COLOR_BTNTEXT
// 4644: COLOR_INACTIVECAPTIONTEXT      4848: COLOR_INACTIVECAPTIONTEXT
// 4648: COLOR_BTNHIGHLIGHT             4856: COLOR_BTNHIGHLIGHT
// 4652: COLOR_3DDKSHADOW               4864: COLOR_3DDKSHADOW
// 4656: COLOR_3DLIGHT                  4872: COLOR_3DLIGHT
// 4660: COLOR_INFOTEXT                 4880: COLOR_INFOTEXT
// 4664: COLOR_INFOBK                   4888: COLOR_INFOBK
// 4668: COLOR_HOTLIGHT                 4896: COLOR_HOTLIGHT
// 4672: COLOR_GRADIENTACTIVECAPTION    4904: COLOR_GRADIENTACTIVECAPTION
// 4676: COLOR_GRADIENTACTIVECAPTION    4912: COLOR_GRADIENTACTIVECAPTION
// 4680: COLOR_MENUHIGHLIGHT            4920: COLOR_MENUHIGHLIGHT
// 4688: COLOR_MENUBAR                  4928: COLOR_MENUBAR
// ---------------------------------------------------------------------------------------------

// Replace the gpsi pointer inside user32 internal symbols with SysColor APIs (GetSysColor()/GetSysColorBrush())
LRESULT MyRealDefWindowProcWorker(UINT msg, WPARAM wParam)
{
    COLORREF sysColorBk = 0;
    COLORREF sysColorTxt = 0;
    HBRUSH sysBrush = nullptr;
    if (msg == WM_CTLCOLOR || msg == WM_CTLCOLOREDIT || msg == WM_CTLCOLORLISTBOX)
    {
        sysColorBk = GetSysColor(COLOR_WINDOW);                                 // Default: *gpsi + 4588 (COLOR_WINDOW)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4600 (COLOR_WINDOWTEXT)
        sysBrush = GetSysColorBrush(COLOR_WINDOW);                              // Default: *gpsi + 4736 (COLOR_WINDOW)
    }
    else if (msg == WM_CTLCOLORMSGBOX || msg == WM_CTLCOLORDLG || msg == WM_CTLCOLORSTATIC)
    {
        sysColorBk = GetSysColor(COLOR_BTNFACE);                                // Default: *gpsi + 4628 (COLOR_BTNTEXT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4600 (COLOR_WINDOWTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNFACE);                             // Default: *gpsi + 4816 (COLOR_BTNTEXT)
    }
    else if (msg == WM_CTLCOLORBTN)
    {
        sysColorBk = GetSysColor(COLOR_BTNFACE);                                // Default: *gpsi + 4628 (COLOR_BTNTEXT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4816 (COLOR_BTNTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNFACE);                             // Default: *gpsi + 4816 (COLOR_BTNTEXT)
    }
    else if (msg == WM_CTLCOLORSCROLLBAR)
    {
        sysColorBk = GetSysColor(COLOR_BTNHIGHLIGHT);                           // Default: *gpsi + 4648 (COLOR_BTNHIGHLIGHT)
        sysColorTxt = g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0); // Default: *gpsi + 4840 (COLOR_BTNTEXT)
        sysBrush = GetSysColorBrush(COLOR_BTNHIGHLIGHT);                        // Default: *gpsi + 4856 (COLOR_BTNHIGHLIGHT)
    }

    HDC hdc = reinterpret_cast<HDC>(wParam);

    SetTextColor(hdc, sysColorTxt);
    SetBkColor(hdc, sysColorBk);
    return reinterpret_cast<LRESULT>(sysBrush);
}

#ifdef _WIN64
    LRESULT (__fastcall *RealDefWindowProcWorker_orig)(struct tagWND*, UINT, WPARAM, LPARAM, UINT);
    LRESULT __fastcall HookedRealDefWindowProcWorker(struct tagWND* pwnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT flags)
    {
        switch (msg)
        {
            case WM_CTLCOLOR:
            case WM_CTLCOLORMSGBOX:
            case WM_CTLCOLOREDIT:
            case WM_CTLCOLORLISTBOX:
            case WM_CTLCOLORBTN:
            case WM_CTLCOLORDLG:
            case WM_CTLCOLORSCROLLBAR:
            case WM_CTLCOLORSTATIC:
            {
                LRESULT res = MyRealDefWindowProcWorker(msg, wParam);
                return res;
            }
        }

        return RealDefWindowProcWorker_orig(pwnd, msg, wParam, lParam, flags);
    }
#else
    LRESULT (__fastcall *RealDefWindowProcWorker_orig)(UINT, WPARAM, struct tagWND*, UINT, LPARAM, UINT);
    LRESULT __fastcall HookedRealDefWindowProcWorker(UINT msg, WPARAM wParam, struct tagWND* pwnd, UINT msg_dup, LPARAM lParam, UINT flags)
    {
        switch (msg)
        {
            case WM_CTLCOLOR:
            case WM_CTLCOLORMSGBOX:
            case WM_CTLCOLOREDIT:
            case WM_CTLCOLORLISTBOX:
            case WM_CTLCOLORBTN:
            case WM_CTLCOLORDLG:
            case WM_CTLCOLORSCROLLBAR:
            case WM_CTLCOLORSTATIC:
            {
                LRESULT res = MyRealDefWindowProcWorker(msg, wParam);
                return res;
            }
        }

        return RealDefWindowProcWorker_orig(msg, wParam, pwnd, msg_dup, lParam, flags);
    }
#endif

// Paints the background of message boxes
HBRUSH (STDCALL *MB_DlgProc_orig)(HWND, UINT, WPARAM, LPARAM);
HBRUSH STDCALL Hooked_MB_DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_CTLCOLORDLG || msg == WM_CTLCOLORSTATIC)
        return GetSysColorBrush(COLOR_WINDOW); // Default: gpsi + 4736 (COLOR_WINDOW)
    return MB_DlgProc_orig(hwnd, msg, wParam, lParam);
}

// Paints the lower part of message boxes
void (THISCALL *DrawCommandRectangle_orig)(HWND);
void THISCALL Hooked_DrawCommandRectangle(HWND hWnd)
{
    PAINTSTRUCT ps{};
    HDC hdc = BeginPaint(hWnd, &ps);
    if (!hdc)
        return;

    // Get window or client rectangle
    RECT rc{};
    GetClientRect(hWnd, &rc);

    // Match USER behavior
    HBRUSH hBrush = CreateSolidBrush(GetSysColor(COLOR_WINDOW)); // Default: gpsi + 4736 (COLOR_WINDOW)
    HGDIOBJ oldBrush = SelectObject(hdc, hBrush);

    HPEN hPen = CreatePen(PS_NULL, 0, 0);
    HGDIOBJ oldPen = SelectObject(hdc, hPen);

    Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

    // Restore
    SelectObject(hdc, oldPen);
    DeleteObject(hPen);

    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);

    EndPaint(hWnd, &ps);
}

// Modifying the background and text color of the classic Win32 tooltip (e.g., the one that appears when hovering the pointer over title bar buttons) which uses the gpsi pointer.
// Additionally, enlarging the tooltip window and applying mod's effects.
void (__fastcall *RenderTooltip_orig)(HWND, HDC, HGDIOBJ*);
void __fastcall HookedRenderTooltip(HWND hWnd, HDC hdc, HGDIOBJ *a3)
{
    HGDIOBJ oldObj = SelectObject(hdc, a3[1]);
    
    LPCWCHAR lpString = reinterpret_cast<LPCWCHAR>(*a3);
    UINT cch = wcslen(lpString); 

    SIZE textSize;
    GetTextExtentPoint32W(hdc, lpString, static_cast<INT>(cch), &textSize);

    RECT clientRect {0};
    GetClientRect(hWnd, &clientRect);

    // Inflate tooltip window rect by x1.8
    if (clientRect.bottom < static_cast<LONG>(textSize.cy * 1.8)) 
    {
        RECT winRect {0};
        GetWindowRect(hWnd, &winRect);
        
        INT newWidth = static_cast<INT>((winRect.right - winRect.left) * 1.8);
        INT newHeight = static_cast<INT>((winRect.bottom - winRect.top) * 1.8);

        // Start with the X and Y coordinates the system originally gave it
        INT newX = winRect.left;
        INT newY = winRect.top;

        // Screen Edge Detection
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        
        // Find out exactly which monitor the cursor is currently on
        HMONITOR hMonitor = MonitorFromPoint(cursorPos, MONITOR_DEFAULTTONEAREST);
        MONITORINFO mi = { sizeof(mi) };
        GetMonitorInfoW(hMonitor, &mi);

        // Check if our new width pushes it past the right edge of this monitor
        if ((newX + newWidth) > mi.rcMonitor.right)
            // Shift X leftwards so the right edge of the tooltip matches the screen edge
            // (Subtracting an extra 2 pixels so it doesn't touch the absolute physical bezel)
            newX = mi.rcMonitor.right - newWidth - 2;

        // Optional bonus: Do the same check for the bottom edge, just in case
        if ((newY + newHeight) > mi.rcMonitor.bottom)
            newY = mi.rcMonitor.bottom - newHeight - 2;

        // Apply the new position and dimensions
        SetWindowPos(hWnd, NULL, newX, newY, newWidth, newHeight,
                     SWP_NOZORDER | SWP_NOACTIVATE
                     );
        
        GetClientRect(hWnd, &clientRect);
    }

    COLORREF oldTextClr = SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));  // Default: gpsi + 4660 (COLOR_WINDOWTEXT)
    COLORREF oldBkClr = SetBkColor(hdc, RGB(0, 0, 0));                                                  // Default: gpsi + 4888 (COLOR_INFOTEXT)

    INT textX = (clientRect.right - textSize.cx) / 2;
    INT textY = (clientRect.bottom - textSize.cy) / 2;
    
    if (textX < 0) textX = 2;
    if (textY < 0) textY = 1;

    ExtTextOutW(hdc, textX, textY, ETO_OPAQUE, &clientRect, lpString, cch, 0);
    
    SetTextColor(hdc, oldTextClr);
    SetBkColor(hdc, oldBkClr);
    SelectObject(hdc, oldObj);
    
    return;
}

VOID User32Hooks(BOOL areSysColorsApplied)
{
    WindhawkUtils::SYMBOL_HOOK user32_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"__int64 __cdecl RealDefWindowProcWorker(struct tagWND *,unsigned int,unsigned __int64,__int64,unsigned long)"
                #else
                    L"long __stdcall RealDefWindowProcWorker(struct tagWND *,unsigned int,unsigned int,long,unsigned long)"
                #endif
            },
            &RealDefWindowProcWorker_orig,
            HookedRealDefWindowProcWorker,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"void __cdecl RenderTooltip(struct HWND__ *,struct HDC__ *,struct TooltipInfo *)"
                #else
                    L"void __stdcall RenderTooltip(struct HWND__ *,struct HDC__ *,struct TooltipInfo *)"
                #endif
            },
            &RenderTooltip_orig,
            HookedRenderTooltip,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"__int64 __cdecl MB_DlgProc(struct HWND__ *,unsigned int,unsigned __int64,__int64)"
                #else
                    L"int __stdcall MB_DlgProc(struct HWND__ *,unsigned int,unsigned int,long)"
                #endif

            },
            &MB_DlgProc_orig,
            Hooked_MB_DlgProc,
            FALSE
        },
        {
            {
                #ifdef _WIN64
                    L"void __cdecl DrawCommandRectangle(struct HWND__ *)"
                #else
                    L"void __stdcall DrawCommandRectangle(struct HWND__ *)"
                #endif

            },
            &DrawCommandRectangle_orig,
            Hooked_DrawCommandRectangle,
            FALSE
        }
    };

    HMODULE hUser32 = LoadLibraryEx(L"user32.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hUser32) {
        Wh_Log(L"Failed to load user32.dll");
        return;
    }

    // If SetSysColors API is executed then hook only the first two symbols of the array -> RealDefWindowProcWorker, RenderTooltip routines
    if (!WindhawkUtils::HookSymbols(hUser32, user32_dll_hooks, areSysColorsApplied ? 2 : ARRAYSIZE(user32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in user32.dll");
        return;
    }
}

// Change Desktop items text and shadow colors in light theme
int (__fastcall *DrawShadowTextEx_orig)(HDC, LPCWSTR, INT, LPRECT, UINT, COLORREF, COLORREF, INT, INT, BYTE, BOOL);
int __fastcall HookedDrawShadowTextEx(HDC hdc, LPCWSTR lpchText, INT cchText, LPRECT pRect, UINT uformat, 
                COLORREF crText, COLORREF crShadow, INT ixOffset, INT iyOffset, BYTE bAlpha, BOOL InitBufferPaintFlag)
{
    if (!g_IsSysThemeDarkMode && g_InsideExplorerProc) {
        crText = RGB(0, 0, 0);
        crShadow = RGB(255, 255, 255);
    }
    return DrawShadowTextEx_orig(hdc, lpchText, cchText, pRect, uformat, crText, crShadow, ixOffset, iyOffset, bAlpha, InitBufferPaintFlag);
}

void (__fastcall *SHThemeDrawText_orig)(void*, HDC, INT, INT, DTTOPTS*, LPCWSTR, LPRECT, INT, UINT, INT, __int64, COLORREF, COLORREF);
void __fastcall Hooked_SHThemeDrawText(void *hTheme, HDC hdc, INT iPartId, INT iStateId, DTTOPTS *pOptions, LPCWSTR lpString, LPRECT pRect, INT iLVGroupAlignFlag, UINT uFormat, INT a10, __int64 a11, COLORREF crText, COLORREF crBackground)
{
    if (!g_InsideTaskMgrProc)
        crText = g_IsSysThemeDarkMode && (crText & 0x00ffffff) <= RGB(96, 96, 96) ? RGB(255, 255, 255) : !g_IsSysThemeDarkMode ? RGB(0, 0, 0) : crText;

    SHThemeDrawText_orig(hTheme, hdc, iPartId, iStateId, pOptions, lpString, pRect, iLVGroupAlignFlag, uFormat, a10, a11, crText, crBackground);
    return;

}

// Alpha blend highlighted text rectangle
void (__fastcall *SHThemeFillTextRect_orig)(HDC, LPRECT, COLORREF, INT);
void __fastcall HookedSHThemeFillTextRect(HDC hDC, LPRECT lprc, COLORREF color, INT sysColorCode)
{
    if (color != GetSysColor(COLOR_HIGHLIGHT))
        return SHThemeFillTextRect_orig(hDC, lprc, color, sysColorCode);
    
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hDC, lprc, BPBF_TOPDOWNDIB, &params, &memDC); 
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return SHThemeFillTextRect_orig(hDC, lprc, color, sysColorCode); 
    }

    SHThemeFillTextRect_orig(memDC, lprc, color, sysColorCode);

    BufferedPaintMakeOpaque(hpb, lprc);
    EndBufferedPaint(hpb, TRUE); 
}

// Alpha blend highlighted text rectangle
COLORREF (__fastcall *FillRectClr_orig)(HDC, LPRECT, COLORREF);
COLORREF __fastcall HookedFillRectClr(HDC hdc, LPRECT lprect, COLORREF color)
{
    if (color != GetSysColor(COLOR_HIGHLIGHT))
        return FillRectClr_orig(hdc, lprect, color);
        
    BP_PAINTPARAMS params = { sizeof(BP_PAINTPARAMS) };

    HDC memDC = nullptr;
    HPAINTBUFFER hpb = BeginBufferedPaint(hdc, lprect, BPBF_TOPDOWNDIB, &params, &memDC);
    if (!hpb) {
        Wh_Log(L"Failed BeginBufferedPaint error:0x%08x", GetLastError());
        return FillRectClr_orig(hdc, lprect, color);
    }

    HBRUSH highlightedBrush = GetSysColorBrush(COLOR_HIGHLIGHT);
    FillRect(memDC, lprect, highlightedBrush);

    BufferedPaintMakeOpaque(hpb, lprect);
    EndBufferedPaint(hpb, TRUE); 
    
    return color;
}

// As of Win11 26200.8655 - Listbox background fill color return COLOR_WINDOW system color
// We return white color so the black text inside listboxes are readable on system light theme.
HBRUSH (__fastcall *ListBox_GetBrush_orig)(struct tagLBIV*, HBRUSH*);
HBRUSH __fastcall HookedListBox_GetBrush(struct tagLBIV *a1, HBRUSH *hbr)
{   
    // Default return brush: GetSysColorBrush(COLOR_WINDOW)
    HBRUSH ret = g_IsSysThemeDarkMode ? ListBox_GetBrush_orig(a1, hbr) : (HBRUSH)GetStockObject(WHITE_BRUSH);
    return ret;
}

// As of Win11 26200.8655 - The ComboBox control (e.g., the Windows address bar) draws an internal rectangle using a brush with the COLOR_WINDOW system color.
// Since the custom COLOR_WINDOW is black, whereas the rest of the ComboBox control's background is intended to be drawn in white,
// we intervene to correct this behavior in light theme mode.
void (__fastcall *ComboEx_OnDrawItem_orig)(struct COMBOEX*, struct tagDRAWITEMSTRUCT*);
void __fastcall HookedComboEx_OnDrawItem(struct COMBOEX *a1, struct tagDRAWITEMSTRUCT *a2)
{
    if (!g_IsSysThemeDarkMode) 
    {
        InflateRect(&a2->rcItem, 1, 1);
        FillRect(a2->hDC, &a2->rcItem, (HBRUSH)GetStockObject(WHITE_BRUSH));
        InflateRect(&a2->rcItem, -1, -1);
    }
    ComboEx_OnDrawItem_orig(a1, a2);
    return;
}

VOID Comctl32Hooks()
{
    WindhawkUtils::SYMBOL_HOOK comctl32_dll_hooks[] =
    {   
        // 32-bit version contains complex color specification, avoid it.
        #ifdef _WIN64
        {
            {
                L"SHThemeDrawText"
            },
            &SHThemeDrawText_orig,
            Hooked_SHThemeDrawText,
            FALSE
        },
        #endif
        {
            {
                #ifdef _WIN64
                    L"DrawShadowTextEx"
                #else
                    L"_DrawShadowTextEx@44"
                #endif
            },
            &DrawShadowTextEx_orig,
            HookedDrawShadowTextEx,
            FALSE
        },
        // Symbols are inlined in ARM64, avoid hooking.
        #ifdef _M_ARM64
        #else
            // SHThemeFillTextRect available only to 64-bit version.
            // Color specification for the 32-bit version is implemented within SHThemeDrawText()
            // Color specification for the 64-bit version is implemented within SHThemeDrawText() -> SHThemeComputeTextColors()
            #ifdef _WIN64
            {
                {
                    L"SHThemeFillTextRect"
                },
                &SHThemeFillTextRect_orig,
                HookedSHThemeFillTextRect,
                FALSE
            },
            #endif
            {
                {
                    #ifdef _WIN64
                        L"FillRectClr"
                    #else
                        L"_FillRectClr@12"
                    #endif
                },
                &FillRectClr_orig,
                HookedFillRectClr,
                FALSE
            },
            {
                {
                    #ifdef _WIN64
                        L"struct HBRUSH__ * __cdecl ListBox_GetBrush(struct tagLBIV *,struct HBRUSH__ * *)"
                    #else
                        L"struct HBRUSH__ * __stdcall ListBox_GetBrush(struct tagLBIV *,struct HBRUSH__ * *)"
                    #endif
                },
                &ListBox_GetBrush_orig,
                HookedListBox_GetBrush,
                FALSE
            },
        #endif
        {
            {
                #ifdef _WIN64
                    L"void __cdecl ComboEx_OnDrawItem(struct COMBOEX *,struct tagDRAWITEMSTRUCT *)"
                #else
                    L"void __stdcall ComboEx_OnDrawItem(struct COMBOEX *,struct tagDRAWITEMSTRUCT *)"
                #endif
            },
            &ComboEx_OnDrawItem_orig,
            HookedComboEx_OnDrawItem,
            FALSE
        },           
    };

    HMODULE hComCtl32 = LoadComCtlModule();
    if (!hComCtl32) {
        Wh_Log(L"Failed to load comctl32.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hComCtl32, comctl32_dll_hooks, ARRAYSIZE(comctl32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in comctl32.dll");
        return;
    }
}

BOOL CThemeCache::CacheNavigationDivider()
{
    FLOAT x = 0, y = 0;
    FLOAT width = 2, height = 2;

    if(!g_themeCache.CreateDIB(g_themeCache.navigationdivider[0], width, height))
        return FALSE;

    RECT rc = {(INT)x, (INT)y, (INT)width, (INT)height};
    
    Microsoft::WRL::ComPtr<ID2D1DCRenderTarget> pRenderTarget;
    if (FAILED(CreateBoundD2DRenderTarget(g_themeCache.navigationdivider[0], &rc, g_d2dFactory, &pRenderTarget)))
        return FALSE;
    
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;
    pRenderTarget->CreateSolidColorBrush(g_IsSysThemeDarkMode ? MyD2D1Color(96, 160, 160, 160) : MyD2D1Color(96, 0, 0, 0), &brush);

    pRenderTarget->BeginDraw();

    // 0.5f makes stroke height 1px
    pRenderTarget->DrawLine(D2D1_POINT_2F(x, y + .5f), D2D1_POINT_2F(width, y + .5f), brush.Get());

    HRESULT hr = pRenderTarget->EndDraw();
    if (FAILED(hr)) {Wh_Log(L"Failed D2D drawing [ERROR]: 0x%08X\n", hr); return FALSE;}
    return TRUE;
}

// Internal symbol returning Systreeview window handle
__int64 (THISCALL *CNscTree_GetWindowsDDT_orig)(class CNscTree*, HWND *, HWND *);

// Render custom D2D alpha blended navigation pane divider
void (THISCALL *CNscTree_DrawDivider_orig)(class CNscTree* , HDC, struct _TREEITEM*);
void THISCALL Hooked_CNscTree_DrawDivider(CNscTree *__this, HDC hdc, struct _TREEITEM *hTreeItem)
{
    auto Fallback = [&](LPCWSTR errorMessage = NULL) {
        if (errorMessage)
            Wh_Log(L"%s", errorMessage);
        CNscTree_DrawDivider_orig(__this, hdc, hTreeItem);
        return;
    };

    HWND hwndTreeView = nullptr;
    // CNscTree_GetWindowsDDT returns 0 if succeeded
    if (CNscTree_GetWindowsDDT_orig && CNscTree_GetWindowsDDT_orig(__this, &hwndTreeView, &hwndTreeView))
        return Fallback(L"Failed acquiring treeview window handle");
    
    RECT treeItemRect = {0};
    *reinterpret_cast<HTREEITEM*>(&treeItemRect) = (HTREEITEM)hTreeItem;
    
    if (!SendMessageW(hwndTreeView, TVM_GETITEMRECT, 0, (LPARAM)&treeItemRect))
        return Fallback();
    
    if (!g_d2dFactory)
        return Fallback();

    if (!g_themeCache.navigationdivider[0] && !g_themeCache.CacheNavigationDivider())
        return Fallback();
    
    RECT lineRc = treeItemRect;
    INT middlePoint = RECTHEIGHT(&treeItemRect) / 4.f;
    lineRc.top = treeItemRect.top + middlePoint - 1;
    lineRc.bottom = treeItemRect.top + middlePoint + 1;
    lineRc.left = treeItemRect.left + RECTWIDTH(&treeItemRect) * 0.05f; // default horizontal bounds offset
    lineRc.right = treeItemRect.right - lineRc.left;

    DrawNineGridStretch(hdc, g_themeCache.navigationdivider[0], &lineRc, 1, 1, 0, 0);
    return;
}

VOID ExplorerFrameHooks()
{
    WindhawkUtils::SYMBOL_HOOK explorerframe_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"private: void __cdecl CNscTree::DrawDivider(struct HDC__ *,struct _TREEITEM *)"
                #else
                    L"private: void __thiscall CNscTree::DrawDivider(struct HDC__ *,struct _TREEITEM *)"
                #endif
            },
            &CNscTree_DrawDivider_orig,
            Hooked_CNscTree_DrawDivider,
            FALSE
        },
        // We're getting only the symbol address.
        {
            {
                #ifdef _WIN64
                    L"public: virtual long __cdecl CNscTree::GetWindowsDDT(struct HWND__ * *,struct HWND__ * *)"
                #else
                    L"public: virtual long __thiscall CNscTree::GetWindowsDDT(struct HWND__ * *,struct HWND__ * *)"
                #endif
            },
            &CNscTree_GetWindowsDDT_orig,
            nullptr,
            FALSE
        },          
    };

    HMODULE hExplorerFrame = LoadLibraryEx(L"ExplorerFrame.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hExplorerFrame) {
        Wh_Log(L"Failed to load ExplorerFrame.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hExplorerFrame, explorerframe_dll_hooks, ARRAYSIZE(explorerframe_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in ExplorerFrame.dll");
        return;
    }
}

// Branding images are painted using TransparentBlt() with white transparency mask.
// Paint everything except the image text into white in order to force transparency to the background.
void RecolorBrandingLogoBackground(HBITMAP hbm)
{
    if (!hbm) 
        return;

    BITMAP bm{};
    if (!GetObject(hbm, sizeof(bm), &bm)) 
        return;

    BITMAPINFO bmi{};
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = bm.bmWidth;
    bmi.bmiHeader.biHeight      = bm.bmHeight;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    HDC hdc = CreateCompatibleDC(nullptr);
    if (!hdc) 
        return;

    size_t pixels = static_cast<size_t>(bm.bmWidth) * bm.bmHeight;
    
    auto px = std::make_unique<COLORREF[]>(pixels);

    if (GetDIBits(hdc, hbm, 0, bm.bmHeight, px.get(), &bmi, DIB_RGB_COLORS))
    {
        // Check if the first pixel is RGB(240, 240, 240). If not, it's probably a custom image -> abort.
        if ((px[0] & 0x00FFFFFF) == 0x00F0F0F0)
        {
            // Target color to keep: RGB(0, 120, 212)
            constexpr COLORREF targetColor = 0x000078D4; 

            for (size_t i = 0; i < pixels; ++i)
            {
                if ((px[i] & 0x00FFFFFF) != targetColor)
                    px[i] = 0xFFFFFFFF; // Turn white
                else
                    px[i] = g_settings.AccentColorize ?
                            // bgr -> rgb 
                            (0xFF000000 | ((g_settings.AccentColor & 0x0000FF) << 16) | (g_settings.AccentColor & 0x00FF00) | ((g_settings.AccentColor & 0xFF0000) >> 16))
                            : px[i];
            }
            SetDIBits(hdc, hbm, 0, bm.bmHeight, px.get(), &bmi, DIB_RGB_COLORS);
        }
    }
    DeleteDC(hdc); 
}

// Intercept the windows branding logo image (e.g winver, shutdown dialog, regedit etc.)
// Winver loads the bitmap using LoadAboutBitmaps() routine, shutdown dialog using LoadBrandingBitmap().
HANDLE (STDCALL *BrandingLoadImage_orig)(LPCWSTR, UINT, UINT, INT, INT, UINT);
HANDLE STDCALL HookedBrandingLoadImage(LPCWSTR pszBrand, UINT uID, UINT type, INT cx, INT cy, UINT  fuLoad)
{   
    auto hImage = BrandingLoadImage_orig(pszBrand, uID, type, cx, cy, fuLoad);

    // The image resource is fetched from basebrd.dll resource image 121.
    if (!wcscmp(pszBrand, L"Basebrd") && uID == 121)
        RecolorBrandingLogoBackground(reinterpret_cast<HBITMAP>(hImage));
    return hImage;
}

VOID WinbrandHooks()
{
    WindhawkUtils::SYMBOL_HOOK winbrand_dll_hooks[] =
    {
        {
            {
                #ifdef _WIN64
                    L"BrandingLoadImage"
                #else
                    L"_BrandingLoadImage@24"
                #endif
            },
            &BrandingLoadImage_orig,
            HookedBrandingLoadImage,
            FALSE
        },
    };

    HMODULE hWinbrand = LoadLibraryEx(L"winbrand.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hWinbrand ) {
        Wh_Log(L"Failed to load winbrand.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hWinbrand , winbrand_dll_hooks, ARRAYSIZE(winbrand_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in winbrand.dll");
        return;
    }
}

// Imitate the internal pseudohandle logic and replace gpsi pointer with GetSysColorBrush getter API.
BOOL WINAPI HookedFillRect(HDC hdc, LPCRECT lprc, HBRUSH hbr)
{    
    ULONG_PTR pseudoSystemBrush = (ULONG_PTR)hbr - 1;
    if (pseudoSystemBrush <= 30)
        return FillRect_orig(hdc, lprc, GetSysColorBrush((INT)pseudoSystemBrush));    

    return FillRect_orig(hdc, lprc, hbr);
}

// Paint the explorer dialogs bottom part background
BOOL (__fastcall *SetDarkThemeColors_orig)(void **, HDC);
BOOL __fastcall HookedSetDarkThemeColors(void **Brush, HDC hdc)
{
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));
    //if ( !*Brush )
        *Brush = (void*)GetSysColorBrush(COLOR_WINDOW);
    return *Brush != nullptr;
}

// Paint the explorer dialogs editbox background
LRESULT (STDCALL *CFileNameComboBox_s_ComboBoxRootSubclass_orig)(HWND, UINT, HDC, LPARAM, UINT_PTR, DWORD_PTR);
LRESULT STDCALL HookedCFileNameComboBox_s_ComboBoxRootSubclass(HWND hWnd, UINT uMsg, HDC wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    auto ret = CFileNameComboBox_s_ComboBoxRootSubclass_orig(hWnd, uMsg, wParam, lParam, uIdSubclass, dwRefData);

    // Intercept the paint messages
    if (uMsg != WM_CTLCOLOREDIT && uMsg != WM_CTLCOLORLISTBOX && uMsg != WM_CTLCOLORSTATIC) 
        return ret;
    
    HDC hdc = reinterpret_cast<HDC>(wParam);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));
    return reinterpret_cast<LRESULT>(GetSysColorBrush(COLOR_WINDOW));
}

// Paint the explorer dialogs editbox background
BOOL (STDCALL *CComboBoxExBase_OnWinEvent_orig)(class CComboBoxExBase *, HWND, UINT, HDC, LPARAM, LRESULT*);
BOOL STDCALL HookedCComboBoxExBase_OnWinEvent(class CComboBoxExBase *__this, HWND hWnd, UINT uMsg, HDC hdc, LPARAM lParam, LRESULT* pResult)
{
    auto ret = CComboBoxExBase_OnWinEvent_orig(__this, hWnd, uMsg, hdc, lParam, pResult);

    // Intercept the paint messages
    if (uMsg != WM_CTLCOLOREDIT && uMsg != WM_CTLCOLORLISTBOX && uMsg != WM_CTLCOLORSTATIC) 
        return ret;

    if (ret == false && pResult != nullptr && *pResult != 0) 
    {
        // C. Overwrite the original SetBkColor and SetTextColor
        SetBkColor(hdc, RGB(0, 0, 0));          // Black Background
        SetTextColor(hdc, g_IsSysThemeDarkMode ? RGB(255, 255, 255) : RGB(0, 0, 0));  // White Text

        // D. Replace the original Dark Gray brush in the out-parameter with our Black Brush
        *pResult = reinterpret_cast<LRESULT>(GetSysColorBrush(COLOR_WINDOW));
    }
    return ret;
}

VOID Comdlg32Hooks()
{
    WindhawkUtils::SYMBOL_HOOK comdlg32_dll_hooks[] =
    {
        
        {
            {
                #ifdef _WIN64
                    L"bool __cdecl SetDarkThemeColors(class wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct HBRUSH__ *,int (__cdecl*)(void *),&int __cdecl DeleteObject(void *),struct wistd::integral_constant<unsigned __int64,0>,struct HBRUSH__ *,struct HBRUSH__ *,0,std::nullptr_t> > > &,struct HDC__ *)"
                #else
                    L"bool __stdcall SetDarkThemeColors(class wil::unique_any_t<class wil::details::unique_storage<struct wil::details::resource_policy<struct HBRUSH__ *,int (__stdcall*)(void *),&int __stdcall DeleteObject(void *),struct wistd::integral_constant<unsigned int,0>,struct HBRUSH__ *,struct HBRUSH__ *,0,std::nullptr_t> > > &,struct HDC__ *)"
                #endif
            },
            &SetDarkThemeColors_orig,
            HookedSetDarkThemeColors,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"private: static __int64 __cdecl CFileNameComboBox::s_ComboBoxRootSubclass(struct HWND__ *,unsigned int,unsigned __int64,__int64,unsigned __int64,unsigned __int64)"
                #else
                    L"private: static long __stdcall CFileNameComboBox::s_ComboBoxRootSubclass(struct HWND__ *,unsigned int,unsigned int,long,unsigned int,unsigned long)"
                #endif
            },
            &CFileNameComboBox_s_ComboBoxRootSubclass_orig,
            HookedCFileNameComboBox_s_ComboBoxRootSubclass,
            FALSE
        },
        
        {
            {
                #ifdef _WIN64
                    L"public: virtual long __cdecl CComboBoxExBase::OnWinEvent(struct HWND__ *,unsigned int,unsigned __int64,__int64,__int64 *)"
                #else
                    L"public: virtual long __stdcall CComboBoxExBase::OnWinEvent(struct HWND__ *,unsigned int,unsigned int,long,long *)"
                #endif
            },
            &CComboBoxExBase_OnWinEvent_orig,
            HookedCComboBoxExBase_OnWinEvent,
            FALSE
        },
        
    };

    HMODULE hComDlg32 = LoadLibraryEx(L"comdlg32.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!hComDlg32 ) {
        Wh_Log(L"Failed to load comdlg32.dll");
        return;
    }

    if (!WindhawkUtils::HookSymbols(hComDlg32 , comdlg32_dll_hooks, ARRAYSIZE(comdlg32_dll_hooks))) {
        Wh_Log(L"Failed to hook one or more symbol functions in comdlg32.dll");
        return;
    }
}

VOID CustomRenderingHooks()
{
    InitDirect2D();
    #ifdef _WIN64
        CplDuiHook();
    #endif
    WindhawkUtils::SetFunctionHook(DefWindowProc, HookedDefWindowProcW, &DefWindowProc_orig);
    WindhawkUtils::SetFunctionHook(GetThemeColor, HookedGetColorTheme, &GetThemeColor_orig);   
    WindhawkUtils::SetFunctionHook(DrawThemeBackground, HookedDrawThemeBackground, &DrawThemeBackground_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeBackgroundEx, HookedDrawThemeBackgroundEx, &DrawThemeBackgroundEx_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeEdge, HookedDrawThemeEdge, &DrawThemeEdge_orig);
    ExplorerFrameHooks();
    Comctl32Hooks();
    if (g_IsSysThemeDarkMode)
        Comdlg32Hooks();
    WinbrandHooks();
    User32Hooks(g_settings.SetSystemColors);
    if (!g_settings.SetSystemColors) {
        WindhawkUtils::SetFunctionHook(FillRect, HookedFillRect, &FillRect_orig);
        WindhawkUtils::SetFunctionHook(GetSysColor, HookedGetSysColor, &GetSysColor_orig);
        WindhawkUtils::SetFunctionHook(GetSysColorBrush, HookedGetSysColorBrush, &GetSysColorBrush_orig);
    }
    WindhawkUtils::SetFunctionHook(DrawTextWithGlow, HookedDrawTextWithGlow, &DrawTextWithGlow);
    WindhawkUtils::SetFunctionHook(DrawTextW, HookedDrawTextW, &DrawTextW_orig);
    WindhawkUtils::SetFunctionHook(ExtTextOutW, HookedExtTextOutW, &ExtTextOutW_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeText, HookedDrawThemeText, &DrawThemeText_orig);
    WindhawkUtils::SetFunctionHook(DrawThemeTextEx, HookedDrawThemeTextEx, &DrawThemeTextEx_orig);
    UxThemeHooks(g_settings.FlyoutsEffects);
    if (g_settings.FlyoutsEffects)
        WindhawkUtils::SetFunctionHook(GetThemeMargins, HookedGetThemeMargins, &GetThemeMargins_orig);
    WindhawkUtils::SetFunctionHook(GetThemeTransitionDuration, HookedGetThemeTransitionDuration, &GetThemeTransitionDuration_orig);
    WindhawkUtils::SetFunctionHook(GetThemeFont, HookedGetThemeFont, &GetThemeFont_orig);
}

VOID ApplyHooks()
{
    if(g_settings.FillBg)
        CustomRenderingHooks();
    if (g_settings.BgType != g_settings.Default) {
        DwmSetWindowAttributeHook();
        DwmExpandFrameIntoClientAreaHook();
    }        
}

// Normalizes a path: flips slashes, trims trailing slashes, lowercases.
std::wstring NormalizeRule(std::wstring path) 
{
    if (path.empty()) return path;

    // 1. Normalize slashes
    for (auto& ch : path)
        if (ch == L'/') 
            ch = L'\\';

    // 2. Trim trailing slashes (now guaranteed to be backslashes)
    while (!path.empty() && path.back() == L'\\')
        path.pop_back();
    
    if (path.empty()) 
        return path;

    // 3. Lowercase
    LCMapStringEx(LOCALE_NAME_USER_DEFAULT, LCMAP_LOWERCASE, 
                  path.c_str(), (INT)path.length(), &path[0], (INT)path.length(), 
                  nullptr, nullptr, 0);

    return path;
}

struct CurrentProcessInfo {
    std::wstring fullPath;   // (e.g. c:\windows\system32\notepad.exe)
    std::wstring fileName;   // (e.g. notepad.exe)
    std::wstring directory;  // (e.g. c:\windows\system32)
};

CurrentProcessInfo GetCurrentProcessInfo() 
{
    WCHAR modulePath[MAX_PATH];
    GetModuleFileNameW(nullptr, modulePath, MAX_PATH);

    CurrentProcessInfo info;
    info.fullPath = modulePath;

    // FIX 1: Strip Windows long path prefix if present, otherwise string matches fail
    if (info.fullPath.find(L"\\\\?\\") == 0) {
        info.fullPath.erase(0, 4);
    }

    // FIX 2: Process paths can occasionally contain forward slashes depending on launch method.
    for (auto& ch : info.fullPath) {
        if (ch == L'/') ch = L'\\';
    }

    // Lowercase the main string once
    LCMapStringEx(LOCALE_NAME_USER_DEFAULT, LCMAP_LOWERCASE, 
                  info.fullPath.c_str(), (INT)info.fullPath.length(), 
                  &info.fullPath[0], (INT)info.fullPath.length(), 
                  nullptr, nullptr, 0);

    // Extract substrings cleanly 
    size_t pos = info.fullPath.find_last_of(L'\\');
    if (pos != std::wstring::npos) {
        info.fileName = info.fullPath.substr(pos + 1);
        info.directory = info.fullPath.substr(0, pos);
    } else {
        info.fileName = info.fullPath;
        info.directory = L""; 
    }

    return info;
}

bool MatchesProcessRule(const std::wstring& rawEntry, const CurrentProcessInfo& proc) 
{
    std::wstring entry = NormalizeRule(rawEntry);
    if (entry.empty()) return false;

    // Exact full path or directory match
    if (entry == proc.fullPath || entry == proc.directory)
        return true;

    // Bare name, e.g. "mspaint.exe"
    if (entry.find(L'\\') == std::wstring::npos) {
        return entry == proc.fileName;
    }

    // FIX 3: Subfolder match. Use .find() == 0 for a bulletproof "starts_with" check.
    std::wstring prefix = entry + L"\\";
    if (proc.fullPath.find(prefix) == 0)
        return true;

    return false;
}

VOID LoadWindowProcessRules()
{
    CurrentProcessInfo currProc = GetCurrentProcessInfo();

    for (INT i = 0;; i++) 
    {
        auto program = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].target", i));
        
        if (!*program)
            break; 

        if (MatchesProcessRule(program.get(), currProc))
        {
            g_settings.FillBg = Wh_GetIntSetting(L"RuledPrograms[%d].RenderingMod.ThemeBackground", i);
            
            BOOL globalSetting_CustomTheme = Wh_GetIntSetting(L"RenderingMod.ThemeBackground");
            if (!globalSetting_CustomTheme)
                GenerateTextAlphaGammaLUT();
            
            g_settings.AccentColorize = Wh_GetIntSetting(L"RuledPrograms[%d].RenderingMod.AccentColorControls", i);
            if (g_settings.AccentColorize)
                g_settings.AccentColor = GetAccentColor();
            
            BOOL globalSetting_SetSysColorAPI = Wh_GetIntSetting(L"RenderingMod.Syscolors");

            // Reset system colors to default values if the system color setting is disabled for the specific ruled process
            if (!g_settings.FillBg && globalSetting_SetSysColorAPI)
                g_DefaultSysColors = TRUE;
            
            // Hook all necessary APIs to restore system colors when SetSysColors API has been executed by the mod
            if (g_DefaultSysColors) {
                WindhawkUtils::SetFunctionHook(GetSysColor, HookedGetSysColor, &GetSysColor_orig);
                WindhawkUtils::SetFunctionHook(GetSysColorBrush, HookedGetSysColorBrush, &GetSysColorBrush_orig);               
                WindhawkUtils::SetFunctionHook(FillRect, HookedFillRect, &FillRect_orig);
                User32Hooks(g_settings.SetSystemColors);
            }   

            auto strStyle = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].BackgroundEffects.type", i));
            if (0 == wcscmp(strStyle, L"acrylicblur"))
                g_settings.BgType = g_settings.AccentBlurBehind;
            else if (0 == wcscmp(strStyle, L"acrylicsystem"))
                g_settings.BgType = g_settings.AcrylicSystemBackdrop;
            else if (0 == wcscmp(strStyle, L"mica"))
                g_settings.BgType = g_settings.Mica;
            else if (0 == wcscmp(strStyle, L"mica_tabbed"))
                g_settings.BgType = g_settings.MicaAlt;
            else 
                g_settings.BgType = g_settings.Default;

            g_settings.AccentBlurBehindClr = GetColorSetting(WindhawkUtils::StringSetting(Wh_GetStringSetting(L"RuledPrograms[%d].BackgroundEffects.AccentBlurBehind", i)));
            
            break;
        }
    }
}

VOID LoadSettings()
{
    g_settings.AccentColorize = Wh_GetIntSetting(L"RenderingMod.AccentColorControls");
    if (g_settings.AccentColorize)
       g_settings.AccentColor = GetAccentColor();

    g_settings.FillBg = Wh_GetIntSetting(L"RenderingMod.ThemeBackground");
    if (g_settings.FillBg)
        GenerateTextAlphaGammaLUT();
    
    g_settings.SetSystemColors = Wh_GetIntSetting(L"RenderingMod.Syscolors");
    // SetSysColors API available only in theme customization
    if (g_settings.SetSystemColors && g_settings.FillBg)
        ColorizeSysColors();
    
    auto strStyle = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"BackgroundEffects.type"));
    if (0 == wcscmp(strStyle, L"acrylicblur"))
        g_settings.BgType = g_settings.AccentBlurBehind;
    else if (0 == wcscmp(strStyle, L"acrylicsystem"))
        g_settings.BgType = g_settings.AcrylicSystemBackdrop;
    else if (0 == wcscmp(strStyle, L"mica"))
        g_settings.BgType = g_settings.Mica;
    else if (0 == wcscmp(strStyle, L"mica_tabbed"))
        g_settings.BgType = g_settings.MicaAlt;
    else 
        g_settings.BgType = g_settings.Default;
    
    g_settings.AccentBlurBehindClr = GetColorSetting(WindhawkUtils::StringSetting(Wh_GetStringSetting(L"BackgroundEffects.AccentBlurBehind")));

    g_settings.FlyoutsEffects = Wh_GetIntSetting(L"FlyoutsEffects");
        
    LoadWindowProcessRules();
    
    ApplyHooks();
}


#undef GetCurrentTime

namespace FileExplorerStyler {


struct ThemeTargetStyles {
    PCWSTR target;
    std::vector<PCWSTR> styles;
};

enum class BackgroundTranslucentEffect {
    kDefault,
    kBlur,
    kAcrylic,
    kMica,
    kMicaAlt,
    kNone,
};

struct Theme {
    std::vector<ThemeTargetStyles> targetStyles;
    std::vector<PCWSTR> styleConstants;
    std::vector<PCWSTR> themeResourceVariables;
    int explorerFrameContainerHeight = 0;
    BackgroundTranslucentEffect backgroundTranslucentEffect =
        BackgroundTranslucentEffect::kDefault;
};

// clang-format off

const Theme g_themeTranslucent_Explorer11 = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness=0,0,0,1",
        L"BorderBrush=#40A0A0A0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas > Microsoft.UI.Xaml.Shapes.Path#SelectedBackgroundPath", {
        L"Fill=#40404040"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=<AcrylicBrush TintColor=\"#121212\" Opacity=\"0.3\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
}, {}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeMicaBar = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource LayerOnMicaBaseAltFillColorDefault}\"/>",
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
}};

const Theme g_themeNoCommandBar = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,1"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeMinimal_Explorer11 = {{
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root@CommonStates > Border#AppBarButtonInnerBorder", {
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.07\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Pressed:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Disabled:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root@CommonStates > Border#AppBarButtonInnerBorder", {
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Pressed:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.12\"/>",
        L"Background@Disabled:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>"}},
    ThemeTargetStyles{L"AppBarButton#refreshButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#upButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.AddressBarControl > Grid#PART_LayoutRoot > Grid#NormalModeGrid", {
        L"BorderThickness=0,0,0,1",
        L"BorderBrush=#A0A0A0"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,3,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=4",
        L"Margin=0,-3,0,3",
        L"Height=28"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>",
        L"Background@PointerOverSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.13\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PressedSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.35\"/>"}},
    ThemeTargetStyles{L"Grid#FileExplorerAddressBarGrid", {
        L"Grid.ColumnSpan=2",
        L"Margin=0,0,10,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root", {
        L"Padding=2"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root", {
        L"Padding=2"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton > Grid#Root > Grid#ContentRoot > Viewbox#ContentViewbox", {
        L"Margin=9"}},
    ThemeTargetStyles{L"AppBarButton#backButton > Grid#Root > Grid#ContentRoot > Viewbox#ContentViewbox", {
        L"Margin=9"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"MinHeight=28",
        L"Height=28"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Margin=0,0,20,4"}},
    ThemeTargetStyles{L"Border#ScrollIncreaseButtonContainer", {
        L"Margin=0,0,0,4"}},
    ThemeTargetStyles{L"Border#ScrollDecreaseButtonContainer", {
        L"Margin=0,0,0,4"}},
    ThemeTargetStyles{L"Grid#FileExplorerAddressBarGrid", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl#NavigationBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Margin=100,0,0,-15",
        L"Grid.RowSpan=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl > Grid#NavigationBarControlGrid", {
        L"Margin=0,0,0,-18",
        L"Background=Transparent",
        L"Width=100",
        L"HorizontalAlignment=0"}},
}, {}, {}, /*explorerFrameContainerHeight=*/42};

const Theme g_themeTabless = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=$NavigationBarGrid"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=$CommandBarGrid"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid > Border", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer > Microsoft.UI.Xaml.Controls.Button#CloseButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Canvas", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource SystemChromeLowColor}\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.ContentPresenter > Microsoft.UI.Xaml.Controls.StackPanel > Microsoft.UI.Xaml.Controls.TextBlock", {
        L"FontFamily=Segoe UI, Segoe Fluent Icons",
        L"FontWeight=Normal"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Height=36"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Padding=1,0,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem", {
        L"Margin=0,-8,0,0"}},
}, {
    L"NavigationBarGrid=2",
    L"CommandBarGrid=1",
}};

const Theme g_themeMatter = {{
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment  = 1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Background=Transparent",
        L"Visibility = 1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=5",
        L"Margin=2,4,0,4",
        L"Height=29"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background = Transparent",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:= $accentColor2",
        L"Background@PointerOverSelected:= $accentColor",
        L"Background@PointerOver:= $accentColor2",
        L"Background@Normal=$accentColor",
        L"Background@PressedSelected:=$accentColor2",
        L"Background@Pressed := $accentColor2"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility  = 0",
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background :=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.4\" />",
        L"CornerRadius = 6",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Margin = 0,-5,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background :=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.4\" />",
        L"CornerRadius = 6",
        L"BorderThickness = 0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Cut]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Copy]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Paste]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Rename]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Share]", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility  = 1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#ScrollDecreaseButtonContainer", {
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#ScrollIncreaseButtonContainer", {
        L"Margin = 0,0,0,3"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Visibility  =1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton[ToolTipService.ToolTip = Create a new item in the current location.]", {
        L"Visibility  = 1"}},
}, {
    L"accentColor=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" />",
    L"accentColor2=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight1}\" Opacity=\"0.5\" />",
}};

const Theme g_themeWindowGlass = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#PART_LayoutRoot", {
        L"Background=Transparent",
        L"RenderTransform:=<TranslateTransform X=\"0\"/>"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FirstCrumbStackPanelControl#FirstCrumbStackPanel", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Grid#RootCommandSearchGrid > Windows.UI.Xaml.Controls.Border#BorderElement", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.NavigationViewItemPresenter#NavigationViewItemPresenter > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot", {
        L"BorderThickness=$BorderThickness",
        L"Background:=$ButtonBackground",
        L"BorderBrush:=$ButtonBorder"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar", {
        L"RenderTransform:=<TranslateTransform X=\"0\" Y=\"0\" />",
        L"HorizontalAlignment=Center",
        L"Margin=-4",
        L"Padding=10"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerSecondaryCommandBar", {
        L"RenderTransform:=<TranslateTransform X=\"Auto\" />",
        L"HorizontalAlignment=Center",
        L"Margin=-4",
        L"Padding=10",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"CornerRadius=$CornerRadius",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush=Transparent",
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerSecondaryCommandBar > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"CornerRadius=$CornerRadius",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"Background=#10808080",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"ColumnDefinitions:=<ColumnDefinitionCollection><ColumnDefinition Width=\"Auto\"/><ColumnDefinition Width=\"*\"/><ColumnDefinition Width=\"430\"/></ColumnDefinitionCollection>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"BorderBrush:=$MainContentBG",
        L"CornerRadius=8",
        L"BorderThickness=0",
        L"Margin=0,0,8,8",
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"BorderBrush:=$MainContentBG",
        L"CornerRadius=8",
        L"BorderThickness=0",
        L"Margin=0,0,8,8",
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid > Grid#GalleryRootGrid", {
        L"Background:=$MainContentBG"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=$Background"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=8",
        L"Margin=5",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>",
        L"Background@PointerOverSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.13\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"Transparent\" Opacity=\"0.05\"/>",
        L"Background@PressedSelected:=<SolidColorBrush Color=\"#808080\" Opacity=\"0.10\"/>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.CommandBarFlyoutCommandBar > Grid#LayoutRoot > Grid#OuterContentRoot > Grid#ContentRoot > Grid#PrimaryItemsRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"Margin=0,0,0,-5",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Grid#OuterOverflowContentRootV2 > Grid#OverflowContentRoot > CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"MenuFlyoutPresenter > Border", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$Background",
        L"BorderThickness=$BorderThickness",
        L"BorderBrush:=$BorderBrush",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$CornerRadius",
        L"Margin=0,0,180,0",
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"MaxWidth=750",
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#PART_AutoSuggestBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$CornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#NavigationCommands", {
        L"Margin=180,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#RootContainer", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border > Microsoft.UI.Xaml.Controls.Button#AddButton", {
        L"RenderTransform:=<TranslateTransform Y=\"-6\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TextBlock#TextLabel", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#SubItemChevronPanel > Microsoft.UI.Xaml.Controls.FontIcon#SubItemChevron", {
        L"RenderTransform:=<TranslateTransform X=\"-5\" Y=\"12\" />"}},
}, {
    L"Background=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15323232\"/>",
    L"BorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"{ThemeResource SystemChromeHighColor}\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SystemChromeLowColor}\" Offset=\"0.15\" /><GradientStop Color=\"{ThemeResource SystemChromeHighColor}\" Offset=\"0.95\" /></LinearGradientBrush>",
    L"BorderThickness=0.3,1,0.3,0.3",
    L"ButtonBackground=<SolidColorBrush Color=\"{ThemeResource SystemAccentColor}\" Opacity=\"1\" />",
    L"ButtonBorder=<SolidColorBrush Color=\"{ThemeResource SystemAccentColorLight3}\" Opacity=\"1\" />",
    L"CornerRadius=8",
    L"Background2=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"0\" />",
    L"MainContentBG=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"1\" />",
}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeAddressSearchOnly = {{
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=0",
        L"Background=Transparent",
        L"MinHeight=48",
        L"Margin=0,26,0,1"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#refreshButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#upButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#backButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AppBarButton#forwardButton", {
        L"Visibility=Collapsed"}},
}, {}, {}, /*explorerFrameContainerHeight=*/80};

const Theme g_themeTintedGlass = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=$CommonBgBrush",
        L"BorderThickness=0,0,0,0",
        L"BorderBrush=$CommonBgBrush"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas > Microsoft.UI.Xaml.Shapes.Path#SelectedBackgroundPath", {
        L"Fill:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"ToolTip", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background:=$CommonBgBrush"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background:=$CommonBgBrush"}},
}, {
    L"CommonBgBrush=<WindhawkBlur BlurAmount=\"18\" TintColor=\"#80000000\"/>",
}, {}, /*explorerFrameContainerHeight=*/0, BackgroundTranslucentEffect::kAcrylic};

const Theme g_themeLiquidGlass = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#PART_LayoutRoot", {
        L"Background=Transparent",
        L"HorizontalAlignment=Stretch"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FirstCrumbStackPanelControl#FirstCrumbStackPanel", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Grid#RootCommandSearchGrid > Windows.UI.Xaml.Controls.Border#BorderElement", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.NavigationViewItemPresenter#NavigationViewItemPresenter > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot", {
        L"BorderThickness=$ElementBorderThickness",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorder",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background:=Transparent",
        L"BorderBrush:=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderThickness=$ElementBorderThickness",
        L"Margin=4,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderThickness=$ElementBorderThickness",
        L"Margin=4,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid > Grid#GalleryRootGrid", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"ToolTip", {
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Margin=5",
        L"Height=35",
        L"BorderThickness=$ElementBorderThickness",
        L"CornerRadius=$ElementCornerRadius",
        L"BorderBrush:=$ElementBorderBrush"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderBrush=Transparent"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=$ElementBackground",
        L"Background@PointerOverSelected:=$AccentBackground",
        L"Background@PointerOver:=$AccentBackground",
        L"Background@Normal:=$ElementBackground",
        L"Background@PressedSelected:=$ButtonBackground2"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Visibility=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Grid#LayoutRoot", {
        L"Background:=$ElementBackground",
        L"BorderThickness=$ElementBorderThickness",
        L"BorderBrush:=$ElementBorderBrush",
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$ElementCornerRadius",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"CornerRadius=$ElementCornerRadius",
        L"Background:=$ElementBackground",
        L"BorderBrush:=$ElementBorderBrush",
        L"BorderThickness=$ElementBorderThickness"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#PART_AutoSuggestBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"CornerRadius=$ElementCornerRadius"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#RootContainer", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border > Microsoft.UI.Xaml.Controls.Button#AddButton", {
        L"RenderTransform:=<TranslateTransform Y=\"-8\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TextBlock#TextLabel", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#SubItemChevronPanel > Microsoft.UI.Xaml.Controls.FontIcon#SubItemChevron", {
        L"RenderTransform:=<TranslateTransform X=\"-5\" Y=\"12\" />"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Height = 28"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Visibility=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,1"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Background:=Transparent"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail", {
        L"Background:=Transparent"}},
}, {
    L"ContentBG=<SolidColorBrush Color=\"{ThemeResource SystemChromeAltHighColor}\" Opacity=\"1\" />",
    L"Background=<WindhawkBlur BlurAmount=\"15\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.2\" />",
    L"ElementBackground=<WindhawkBlur BlurAmount=\"20\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.4\" />",
    L"ElementBackground2=<WindhawkBlur BlurAmount=\"20\" TintColor=\"{ThemeResource SystemAltLowColor}\" TintOpacity=\"0.2\" />",
    L"AccentBackground=<WindhawkBlur BlurAmount=\"15\" TintColor=\"{ThemeResource SystemAccentColorLight1}\" TintOpacity=\"0.2\" />",
    L"BorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"#50808080\" Offset=\"0.0\" /><GradientStop Color=\"#50404040\" Offset=\"0.25\" /><GradientStop Color=\"#50808080\" Offset=\"1\" /></LinearGradientBrush>",
    L"ElementBorderBrush=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"0,1\"><GradientStop Color=\"#50808080\" Offset=\"1\" /><GradientStop Color=\"#50606060\" Offset=\"0.15\" /></LinearGradientBrush>",
    L"BorderThickness=0.3,1,0.3,0.3",
    L"ElementBorderThickness=0.3,0.3,0.3,1",
    L"CornerRadius=12",
    L"ElementCornerRadius=8",
}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeMicaTabless = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#ContentRoot", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.Row=$NavigationBarGrid"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=$CommandBarGrid"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid > Border", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer > Microsoft.UI.Xaml.Controls.Button#CloseButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.Canvas", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background:=<SolidColorBrush Color=\"{ThemeResource SystemChromeLowColor}\" />"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.ContentPresenter > Microsoft.UI.Xaml.Controls.StackPanel > Microsoft.UI.Xaml.Controls.TextBlock", {
        L"FontFamily=Segoe UI, Segoe Fluent Icons",
        L"FontWeight=Normal"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"BorderThickness=0,0,0,1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"Height=36"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainer", {
        L"Padding=1,0,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox#IconBox", {
        L"Margin=0,0,4,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.TabViewItem", {
        L"Margin=0,-8,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#DetailsViewControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Opacity=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Background:="}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Microsoft.UI.Xaml.Controls.Grid", {
        L"Background:="}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#HomeViewRootGrid", {
        L"Background:="}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.StackPanel#DetailsViewThumbnail > Microsoft.UI.Xaml.Controls.Grid", {
        L"Background:="}},
}, {
    L"NavigationBarGrid=1",
    L"CommandBarGrid=2",
}};

const Theme g_themeOS26_Liquid_Glass = {{
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=12",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment=1"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Background=Transparent",
        L"MinHeight=0"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"CornerRadius=12",
        L"Margin=2,4,0,4",
        L"Height=27",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#35ffffff\" />",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15ffffff\" />"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,2",
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-6,0,0,0"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=14",
        L"BorderThickness=1",
        L"Margin=2",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=14",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\" />",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#OuterOverflowContentRootV2", {
        L"CornerRadius=20"}},
    ThemeTargetStyles{L"Button#MoreButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Margin=0,9,9,0"}},
}};

const Theme g_themeOS26_Liquid_Glass_variant_Compact = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.SuggestionsPopup", {
        L"Margin=0,0,0,900"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=12",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Button#MoreButton", {
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,2,3,2",
        L"Width=45",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton > Grid@CommonStates", {
        L"Background@Disabled:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid > OuterOverflowContentRootV2", {
        L"CornerRadius=250"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter > Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter", {
        L"Background=transparent"}},
    ThemeTargetStyles{L"AppBarButton[7]", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0",
        L"Margin=0,0,0,0",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox > ContentViewB", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Grid.Row=0",
        L"Grid.RowSpan=1",
        L"CornerRadius:=15",
        L"Width=400",
        L"HorizontalAlignment=Left",
        L"Background:=transparent",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Grid#OverflowSeparator", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > ItemsControl#PrimaryItemsControl", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Visibility=Visible",
        L"Margin=0,40,0,-20"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Margin=370,1,0,1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=150",
        L"Height=40",
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2,2,0,2",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#20ffffff\"/>",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,4",
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=",
        L"BorderBrush:="}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates", {
        L"BorderThickness=1",
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#15ffffff\"/>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=10",
        L"Margin=-90,0,90,0",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-8,0,90,0"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background=Transparent",
        L"CornerRadius=8",
        L"Margin=2,1,2,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<LinearGradientBrush StartPoint=\"-0.3,-0.3\" EndPoint=\"1.3,1.3\"><GradientStop Color=\"#55f0f07d\" Offset=\"0.0\"/><GradientStop Color=\"#2AF0F0F0\" Offset=\"0.3\"/><GradientStop Color=\"#00F0F0F0\" Offset=\"0.6\"/></LinearGradientBrush>",
        L"BorderBrush:=<LinearGradientBrush StartPoint=\"0,0\" EndPoint=\"1,1\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\" /><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\" /><GradientStop Color=\"#80ffffff\" Offset=\"1\" /></LinearGradientBrush>",
        L"CornerRadius=12",
        L"BorderThickness=1",
        L"Margin=3,2,3,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#OuterOverflowContentRootV2", {
        L"CornerRadius=20"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility=Visible",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#stopButton", {
        L"Visibility=Collapsed",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeZEUSosX_044 = {{
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background=Transparent",
        L"BorderThickness=0",
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"HorizontalAlignment=Left",
        L"VerticalAlignment=Top",
        L"Width=155",
        L"Margin=197,-30,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar", {
        L"Background=Transparent",
        L"HorizontalAlignment=Left",
        L"VerticalAlignment=Top"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"ColumnDefinitions:=<ColumnDefinitionCollection><ColumnDefinition Width=\"Auto\"/><ColumnDefinition Width=\"*\"/><ColumnDefinition Width=\"380\"/></ColumnDefinitionCollection>",
        L"Margin=0,-16,0,-21"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Grid.Row=0",
        L"HorizontalAlignment=Left",
        L"Margin=100,0,0,0",
        L"Width=1",
        L"MaxWidth=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.FileExplorerTabControl", {
        L"HorizontalAlignment=Left",
        L"Margin=100,0,0,0",
        L"Width=1",
        L"MaxWidth=1"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid > Grid#LayoutRoot > TextBox > Grid@CommonStates > Border#BorderElement", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AutoSuggestBox#FileExplorerSearchBox > Microsoft.UI.Xaml.Controls.Grid#LayoutRoot > Microsoft.UI.Xaml.Controls.TextBox#TextBox", {
        L"Margin=0,0,140,0",
        L"Background=Transparent",
        L"BorderBrush=Transparent",
        L"TextAlignment=Center",
        L"HorizontalContentAlignment=Center"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"HorizontalAlignment=Stretch",
        L"Height=28",
        L"Margin=155,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox", {
        L"HorizontalAlignment=Stretch",
        L"Height=28",
        L"Margin=-7,-1,7,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBar#FileExplorerCommandBar Button", {
        L"FontSize=14"}},
}, {}, {}, /*explorerFrameContainerHeight=*/44, BackgroundTranslucentEffect::kMica};

const Theme g_themeCompact_Explorer11 = {{
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.SuggestionsPopup", {
        L"Margin=0,0,0,900"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=10",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=2,6,2,6",
        L"Padding@Disabled=0,-7"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Button#MoreButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=3,2,3,2",
        L"Width=45",
        L"Height=32"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius@Disabled=11",
        L"BorderThickness@Disabled=1",
        L"Margin@Disabled=0,0,0,0",
        L"Height@Disabled=32",
        L"Width@Disabled=20",
        L"Padding@Disabled=0,-2,0,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton > Grid@CommonStates", {
        L"Background@Disabled:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>"}},
    ThemeTargetStyles{L"Grid#DetailsViewControlRootGrid", {
        L"Margin=20,20,20,1",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"StackPanel#DetailsViewThumbnail > Grid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid > OuterOverflowContentRootV2", {
        L"CornerRadius=250"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter > Microsoft.UI.Xaml.Controls.CommandBarOverflowPresenter", {
        L"Background=transparent"}},
    ThemeTargetStyles{L"AppBarButton[7]", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0",
        L"Margin=0,0,0,0",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Viewbox > ContentViewB", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#HomeViewRootGrid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"FileExplorerExtensions.GalleryViewControl#GalleryViewControl > Grid", {
        L"Margin=20,20,20,0",
        L"Background:=<WindhawkBlur BlurAmount=\"30\" TintColor=\"#2D101010\" TintOpacity=\"0.4\"/>",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#GalleryRootGrid", {
        L"Margin=10",
        L"Background:=transparent",
        L"CornerRadius=15"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar", {
        L"Grid.Row=0",
        L"Grid.RowSpan=1",
        L"CornerRadius:=15",
        L"Width=400",
        L"HorizontalAlignment=Left",
        L"Background:=transparent",
        L"Padding=0,0,0,0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > Grid#OverflowSeparator", {
        L"Visibility=Collapsed",
        L"Width=0",
        L"MinWidth=0"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerCommandBar > Grid#LayoutRoot > Grid#ContentRoot > ItemsControl#PrimaryItemsControl", {
        L"HorizontalAlignment=Left"}},
    ThemeTargetStyles{L"CommandBar#FileExplorerSecondaryCommandBar", {
        L"Visibility=Visible",
        L"Margin=0,40,0,-20"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid", {
        L"Margin=370,1,0,1"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"Width=150",
        L"Height=40",
        L"Margin=0,0,8,0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=2,2,0,2",
        L"Height=35"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#30ffffff\"/>",
        L"Background@PointerOverSelected:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#40ffffff\"/>",
        L"Background@Normal:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#20ffffff\"/>"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,4",
        L"Background:=<WindhawkBlur BlurAmount=\"15\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=0",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Background:=",
        L"BorderBrush:="}},
    ThemeTargetStyles{L"Grid#NavigationBarControlGrid", {
        L"Background=Transparent"}},
    ThemeTargetStyles{L"Grid#PART_LayoutRoot", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=1"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1, FileExplorerExtensions.CommandBarControl", {
        L"Grid.Row=0",
        L"Grid.RowSpan=2",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"AutoSuggestBox#FileExplorerSearchBox > Grid#LayoutRoot > TextBox > Grid@CommonStates", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"Margin=-90,0,90,0",
        L"Height=30"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#FileExplorerAddressBarGrid", {
        L"Margin=-8,0,90,0"}},
    ThemeTargetStyles{L"CommandBarOverflowPresenter#SecondaryItemsControl > Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background=Transparent",
        L"CornerRadius=4",
        L"BorderThickness=0",
        L"Margin=0,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#25ffffff\"/>",
        L"CornerRadius=10",
        L"BorderThickness=1",
        L"Margin=3,2,3,2"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarToggleButton", {
        L"Background:=<WindhawkBlur BlurAmount=\"8\" TintColor=\"#2D101010\"/>",
        L"CornerRadius=8",
        L"BorderThickness=1",
        L"Margin=3,0,3,1",
        L"BorderBrush:=<LinearGradientBrush EndPoint=\"1,1\" StartPoint=\"0,0\"><GradientStop Color=\"#80ffffff\" Offset=\"0.0\"/><GradientStop Color=\"{ThemeResource SurfaceStrokeColorDefault}\" Offset=\"0.55\"/><GradientStop Color=\"#80ffffff\" Offset=\"1\"/></LinearGradientBrush>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarSeparator", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#backButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#forwardButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Visible"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#upButton", {
        L"Margin=0,9,9,0",
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#refreshButton", {
        L"Visibility=Visible",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.AppBarButton#stopButton", {
        L"Visibility=Collapsed",
        L"Margin=0,9,9,0"}},
    ThemeTargetStyles{L"FileExplorerExtensions.NavigationBarControl", {
        L"Grid.RowSpan=2"}},
}, {}, {}, /*explorerFrameContainerHeight=*/87};

const Theme g_themeFloat = {{
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot@CommonStates", {
        L"Background@Selected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.6\"/>",
        L"Background@PointerOverSelected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.7\"/>",
        L"Background@PointerOver:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.3\"/>",
        L"Background@Normal:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0\"/>",
        L"Background@PressedSelected:=<AcrylicBrush TintColor=\"{ThemeResource Tab}\" TintOpacity=\"0.9\" Opacity=\"0.9\"/>",
        L"CornerRadius=6"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Grid#TabContainer", {
        L"Background=Transparent",
        L"BorderThickness=0"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot > Canvas", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem > Grid#LayoutRoot", {
        L"BorderThickness=1",
        L"Margin=2,0,0,0",
        L"Height=35"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#BottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"TabViewItem", {
        L"CornerRadius=4"}},
    ThemeTargetStyles{L"Grid#TabContainerGrid > Border > Button#AddButton", {
        L"Visibility=Visible",
        L"Margin=0,0,0,3",
        L"CornerRadius=10",
        L"BorderThickness=0",
        L"Width=24",
        L"Height=24"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#TabContainerGrid", {
        L"Height=44"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#RightBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Border#LeftBottomBorderLine", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Grid#NavigationBarControlGrid", {
        L"CornerRadius=6",
        L"Margin=8,4,8,0",
        L"Height=54"}},
    ThemeTargetStyles{L"FileExplorerExtensions.CommandBarControl_Wave1 > Grid, Grid#CommandBarControlRootGrid", {
        L"Margin=0,8,0,0",
        L"BorderThickness=0,1,0,1"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.Primitives.TabViewListView#TabListView", {
        L"Margin=-3,0,0,0"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#RightRadiusRenderArc", {
        L"Visibility=Collapsed"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Shapes.Path#LeftRadiusRenderArc", {
        L"Visibility=Collapsed"}},
}, {}, {
    L"Tab@Light=#ffffffff",
    L"Tab@Dark=#000000",
}, /*explorerFrameContainerHeight=*/160};

// clang-format on

enum class BackgroundTranslucentEffectRegion {
    kEntireWindow,
    kExplorerFrame,
};

enum class XamlDiagnosticsHandling {
    kAlert,
    kBlock,
    kAllow,
};

struct {
    std::optional<BackgroundTranslucentEffect> backgroundTranslucentEffect;
    BackgroundTranslucentEffectRegion backgroundTranslucentEffectRegion;
    int explorerFrameContainerHeight;
    XamlDiagnosticsHandling xamlDiagnosticsHandling;
} g_settings;

BackgroundTranslucentEffect g_themeBackgroundTranslucentEffect;
int g_themeExplorerFrameContainerHeight;

std::atomic<bool> g_initialized;
thread_local bool g_initializedForThread;

// An InstanceHandle is the address of an interface on the element, so it names
// an element only for as long as that element lives: an element allocated over
// a destroyed one is reported under the same handle. Everything the mod records
// is therefore keyed by an id minted per reported element, which is never
// reused, rather than by the handle itself.
enum class ElementId : uint64_t { None = 0 };

ElementId GetOrCreateElementId(
    InstanceHandle handle,
    winrt::Windows::Foundation::IInspectable const& element);
ElementId FindElementId(InstanceHandle handle);
void ForgetElementId(InstanceHandle handle);

void ApplyCustomizations(ElementId elementId,
                         winrt::Microsoft::UI::Xaml::FrameworkElement element,
                         PCWSTR fallbackClassName);
void CleanupCustomizations(ElementId elementId);
void QueueDiagnosticsRelease(InstanceHandle handle);
void FlushDiagnosticsReleasesIfQuiet();

HMODULE GetCurrentModuleHandle() {
    HMODULE module;
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                               GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                           L"", &module)) {
        return nullptr;
    }

    return module;
}

////////////////////////////////////////////////////////////////////////////////
// clang-format off

#pragma region winrt_hpp


// Alias some long namespaces for convenience. The WinRT headers are
// included at global scope, so explicitly refer to the global winrt namespace.
namespace wf = ::winrt::Windows::Foundation;
namespace mux = ::winrt::Microsoft::UI::Xaml;

// A weak reference for the object, or an empty one when the object is null or
// doesn't support weak references: cppwinrt's make_weak dereferences a null
// pointer for an object without that support instead of reporting it. Throws,
// as make_weak does, when the object supports weak references but one can't be
// made.
winrt::weak_ref<wf::IInspectable> TryMakeWeak(wf::IInspectable const& object)
{
    if (!object.try_as<::IWeakReferenceSource>())
    {
        return nullptr;
    }

    return winrt::make_weak(object);
}

#pragma endregion  // winrt_hpp

#pragma region visualtreewatcher_hpp


// XamlDiagnostics implements this interface too, and xamlom.h does not declare
// it. UnregisterInstance closes the runtime object cached for a handle, the
// only reference the diagnostics keep to an element once it was reported.
static constexpr GUID IID_IXamlDiagnosticsTestHooks =
    {0x735941a2, 0x3ee3, 0x495a, {0x8d, 0xa9, 0x97, 0x26, 0x27, 0x00, 0x30, 0x75}};

struct IXamlDiagnosticsTestHooks : IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE UnregisterInstance(InstanceHandle handle) = 0;
    virtual HRESULT STDMETHODCALLTYPE TryGetDispatcherQueueForObject(InstanceHandle handle, void** dispatcherQueue) = 0;
};

// The handle a mutation callback would report for an element, for elements
// which were reached some other way, e.g. by walking the visual tree. Derived
// the way the diagnostics derive it, by querying IInspectable and taking the
// pointer, and not through GetHandleFromIInspectable: that one creates the
// runtime object when none is cached, so asking it about an element whose
// reference was released would take a new reference and pin it again.
InstanceHandle HandleFromInspectable(wf::IInspectable const& instance)
{
    winrt::com_ptr<::IInspectable> inspectable;
    winrt::check_hresult(reinterpret_cast<::IUnknown*>(winrt::get_abi(instance))->QueryInterface(winrt::guid_of<wf::IInspectable>(), inspectable.put_void()));
    return reinterpret_cast<InstanceHandle>(inspectable.get());
}

class VisualTreeWatcher : public winrt::implements<VisualTreeWatcher, IVisualTreeServiceCallback2, winrt::non_agile>
{
public:
    VisualTreeWatcher(winrt::com_ptr<IUnknown> site);

    VisualTreeWatcher(const VisualTreeWatcher&) = delete;
    VisualTreeWatcher& operator=(const VisualTreeWatcher&) = delete;

    VisualTreeWatcher(VisualTreeWatcher&&) = delete;
    VisualTreeWatcher& operator=(VisualTreeWatcher&&) = delete;

    ~VisualTreeWatcher();

    void UnadviseVisualTreeChange();

    bool ReleaseDiagnosticsReference(InstanceHandle handle);

private:
    HRESULT STDMETHODCALLTYPE OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) override;
    HRESULT STDMETHODCALLTYPE OnElementStateChanged(InstanceHandle element, VisualElementState elementState, LPCWSTR context) noexcept override;

    wf::IInspectable FromHandle(InstanceHandle handle)
    {
        wf::IInspectable obj;
        winrt::check_hresult(m_XamlDiagnostics->GetIInspectableFromHandle(handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(obj))));
        return obj;
    }

    winrt::com_ptr<IXamlDiagnostics> m_XamlDiagnostics = nullptr;
    winrt::com_ptr<IXamlDiagnosticsTestHooks> m_XamlDiagnosticsTestHooks = nullptr;
};

#pragma endregion  // visualtreewatcher_hpp

#pragma region visualtreewatcher_cpp

VisualTreeWatcher::VisualTreeWatcher(winrt::com_ptr<IUnknown> site) :
    m_XamlDiagnostics(site.as<IXamlDiagnostics>())
{
    Wh_Log(L"Constructing VisualTreeWatcher");

    HRESULT hr = m_XamlDiagnostics->QueryInterface(IID_IXamlDiagnosticsTestHooks, m_XamlDiagnosticsTestHooks.put_void());
    if (FAILED(hr)) {
        Wh_Log(L"IXamlDiagnosticsTestHooks is unavailable, elements will be leaked: %08X", hr);
    }

    // winrt::check_hresult(m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(this));

    // Calling AdviseVisualTreeChange from the current thread causes the app to
    // hang in Advising::RunOnUIThread sometimes. Creating a new thread and
    // calling it from there fixes it.
    HANDLE thread = CreateThread(
        nullptr, 0,
        [](LPVOID lpParam) -> DWORD {
            auto watcher = reinterpret_cast<VisualTreeWatcher*>(lpParam);
            HRESULT hr = watcher->m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(watcher);
            watcher->Release();
            if (FAILED(hr)) {
                Wh_Log(L"Error %08X", hr);
            }
            return 0;
        },
        this, 0, nullptr);
    if (thread) {
        AddRef();
        CloseHandle(thread);
    }
}

VisualTreeWatcher::~VisualTreeWatcher()
{
    Wh_Log(L"Destructing VisualTreeWatcher");
}

void VisualTreeWatcher::UnadviseVisualTreeChange()
{
    Wh_Log(L"UnadviseVisualTreeChange VisualTreeWatcher");
    HRESULT hr = m_XamlDiagnostics.as<IVisualTreeService3>()->UnadviseVisualTreeChange(this);
    if (FAILED(hr)) {
        Wh_Log(L"UnadviseVisualTreeChange failed with error %08X", hr);
    }
}

// Reports whether dropping the reference destroyed the element, which is what
// tells the caller that the handle is free to name a different element from now
// on and that the id recorded for this one has to go.
bool VisualTreeWatcher::ReleaseDiagnosticsReference(InstanceHandle handle)
{
    if (!m_XamlDiagnosticsTestHooks) {
        return false;
    }

    winrt::weak_ref<wf::IInspectable> weakElement;
    {
        // Not through FromHandle: a handle whose runtime object is already gone
        // fails to resolve routinely, and throwing for it would pay for an
        // originate with a stack capture every time. The strong reference has
        // to be gone again before the release below, hence the scope.
        wf::IInspectable element;
        HRESULT hr = m_XamlDiagnostics->GetIInspectableFromHandle(handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(element)));
        if (SUCCEEDED(hr) && element) {
            try {
                weakElement = TryMakeWeak(element);
            } catch (...) {
                Wh_Log(L"Error %08X", winrt::to_hresult());
            }
        }
    }

    HRESULT hr = m_XamlDiagnosticsTestHooks->UnregisterInstance(handle);
    if (FAILED(hr)) {
        Wh_Log(L"UnregisterInstance failed with error %08X", hr);
        return false;
    }

    // Not every reported object supports weak references, and then the release
    // just proceeds unobserved.
    return weakElement && !weakElement.get();
}

HRESULT VisualTreeWatcher::OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) try
{
    Wh_Log(L"========================================");

    switch (mutationType)
    {
    case Add:
        Wh_Log(L"Mutation type: Add %llu", element.Handle);
        break;

    case Remove:
        Wh_Log(L"Mutation type: Remove %llu", element.Handle);
        break;

    default:
        Wh_Log(L"Mutation type: %d %llu", static_cast<int>(mutationType), element.Handle);
        break;
    }

    Wh_Log(L"Element type: %s", element.Type);

    if (!g_initializedForThread)
    {
        Wh_Log(L"Not initialized for thread %u", GetCurrentThreadId());
        return S_OK;
    }

    // Caught here rather than by the handler below, so that the bookkeeping
    // which hands the element's reference back still runs when the styling work
    // throws. Otherwise a single failed element would be held for good.
    try
    {
        if (mutationType == Add)
        {
            const auto inspectable = FromHandle(element.Handle);
            auto elementId = GetOrCreateElementId(element.Handle, inspectable);
            auto frameworkElement = inspectable.try_as<mux::FrameworkElement>();
            if (frameworkElement)
            {
                Wh_Log(L"FrameworkElement name: %s", frameworkElement.Name().c_str());
                if (elementId == ElementId::None)
                {
                    Wh_Log(L"Skipping element which can't be given an id");
                }
                else
                {
                    ApplyCustomizations(elementId, frameworkElement, element.Type);
                }
            }
            else
            {
                Wh_Log(L"Skipping non-FrameworkElement");
            }
        }
        else if (mutationType == Remove)
        {
            CleanupCustomizations(FindElementId(element.Handle));
        }
    }
    catch (...)
    {
        Wh_Log(L"Error %08X", winrt::to_hresult());
    }

    // A tree discarded whole is never dismantled, so it reports no removals to
    // be released by.
    FlushDiagnosticsReleasesIfQuiet();

    if (mutationType == Add)
    {
        QueueDiagnosticsRelease(element.Handle);
        QueueDiagnosticsRelease(relation.Parent);
    }
    else if (mutationType == Remove)
    {
        // Queued rather than released outright: this report arrives from inside
        // the Leave walk which is still visiting the subtree being removed.
        QueueDiagnosticsRelease(element.Handle);
        ForgetElementId(element.Handle);
    }

    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);

    // Returning an error prevents (some?) further messages, always return
    // success.
    // return hr;
    return S_OK;
}

HRESULT VisualTreeWatcher::OnElementStateChanged(InstanceHandle, VisualElementState, LPCWSTR) noexcept
{
    return S_OK;
}

#pragma endregion  // visualtreewatcher_cpp

#pragma region tap_hpp


// Read by the UI threads while the thread which injects or uninitializes the TAP
// replaces it.
[[clang::no_destroy]] winrt::com_ptr<VisualTreeWatcher> g_visualTreeWatcher;
SRWLOCK g_visualTreeWatcherLock = SRWLOCK_INIT;

// {C85D8CC7-5463-40E8-A432-F5916B6427E5}
static constexpr CLSID CLSID_WindhawkTAP = { 0xc85d8cc7, 0x5463, 0x40e8, { 0xa4, 0x32, 0xf5, 0x91, 0x6b, 0x64, 0x27, 0xe5 } };

class WindhawkTAP : public winrt::implements<WindhawkTAP, IObjectWithSite, winrt::non_agile>
{
public:
    HRESULT STDMETHODCALLTYPE SetSite(IUnknown *pUnkSite) override;
    HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, void **ppvSite) noexcept override;

private:
    winrt::com_ptr<IUnknown> site;
};

#pragma endregion  // tap_hpp

#pragma region tap_cpp

winrt::com_ptr<VisualTreeWatcher> GetVisualTreeWatcher()
{
    AcquireSRWLockShared(&g_visualTreeWatcherLock);
    auto watcher = g_visualTreeWatcher;
    ReleaseSRWLockShared(&g_visualTreeWatcherLock);
    return watcher;
}

// Hands the previous watcher back to be unadvised and released outside the
// lock: both can wait on the UI threads, which take it.
winrt::com_ptr<VisualTreeWatcher> ExchangeVisualTreeWatcher(winrt::com_ptr<VisualTreeWatcher> watcher)
{
    AcquireSRWLockExclusive(&g_visualTreeWatcherLock);
    std::swap(g_visualTreeWatcher, watcher);
    ReleaseSRWLockExclusive(&g_visualTreeWatcherLock);
    return watcher;
}

HRESULT WindhawkTAP::SetSite(IUnknown *pUnkSite) try
{
    // Only ever 1 VTW at once.
    if (auto previous = ExchangeVisualTreeWatcher(nullptr))
    {
        previous->UnadviseVisualTreeChange();
    }

    site.copy_from(pUnkSite);

    if (site)
    {
        // Decrease refcount increased by InitializeXamlDiagnosticsEx.
        FreeLibrary(GetCurrentModuleHandle());

        ExchangeVisualTreeWatcher(winrt::make_self<VisualTreeWatcher>(site));
    }

    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

HRESULT WindhawkTAP::GetSite(REFIID riid, void **ppvSite) noexcept
{
    return site.as(riid, ppvSite);
}

#pragma endregion  // tap_cpp

#pragma region simplefactory_hpp


template<class T>
struct SimpleFactory : winrt::implements<SimpleFactory<T>, IClassFactory, winrt::non_agile>
{
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override try
    {
        if (!pUnkOuter)
        {
            *ppvObject = nullptr;
            return winrt::make<T>().as(riid, ppvObject);
        }
        else
        {
            return CLASS_E_NOAGGREGATION;
        }
    }
    catch (...)
    {
        HRESULT hr = winrt::to_hresult();
        Wh_Log(L"Error %08X", hr);
        return hr;
    }

    HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override
    {
        return S_OK;
    }
};

#pragma endregion  // simplefactory_hpp

#pragma region module_cpp


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdll-attribute-on-redeclaration"

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) try
{
    if (rclsid == CLSID_WindhawkTAP)
    {
        *ppv = nullptr;
        return winrt::make<SimpleFactory<WindhawkTAP>>().as(riid, ppv);
    }
    else
    {
        return CLASS_E_CLASSNOTAVAILABLE;
    }
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllCanUnloadNow()
{
    if (winrt::get_module_lock())
    {
        return S_FALSE;
    }
    else
    {
        return S_OK;
    }
}

#pragma clang diagnostic pop

#pragma endregion  // module_cpp

#pragma region api_cpp

bool g_inInjectWindhawkTAP = false;

using PFN_INITIALIZE_XAML_DIAGNOSTICS_EX = decltype(&InitializeXamlDiagnosticsEx);

HRESULT InjectWindhawkTAP() noexcept
{
    HMODULE module = GetCurrentModuleHandle();
    if (!module)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR location[MAX_PATH];
    switch (GetModuleFileName(module, location, ARRAYSIZE(location)))
    {
    case 0:
    case ARRAYSIZE(location):
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const HMODULE wux(GetModuleHandle(L"Microsoft.Internal.FrameworkUdk.dll"));
    if (!wux) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const auto ixde = reinterpret_cast<PFN_INITIALIZE_XAML_DIAGNOSTICS_EX>(GetProcAddress(wux, "InitializeXamlDiagnosticsEx"));
    if (!ixde) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    // I didn't find a better way than trying many connections until one works.
    // Reference:
    // https://github.com/microsoft/microsoft-ui-xaml/blob/d74a0332cf0d5e58f12eddce1070fa7a79b4c2db/src/dxaml/xcp/dxaml/lib/DXamlCore.cpp#L2782
    g_inInjectWindhawkTAP = true;

    HRESULT hr;
    for (int i = 0; i < 10000; i++)
    {
        WCHAR connectionName[256];
        wsprintf(connectionName, L"WinUIVisualDiagConnection%d", i + 1);

        hr = ixde(connectionName, GetCurrentProcessId(), L"", location, CLSID_WindhawkTAP, nullptr);
        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
        {
            break;
        }
    }

    g_inInjectWindhawkTAP = false;

    return hr;
}

#pragma endregion  // api_cpp

// clang-format on
////////////////////////////////////////////////////////////////////////////////



using namespace std::string_view_literals;




using namespace winrt::Microsoft::UI::Xaml;

namespace muxc = winrt::Microsoft::UI::Xaml::Controls;
namespace wge = winrt::Windows::Graphics::Effects;
namespace muc = winrt::Microsoft::UI::Composition;
namespace muxh = mux::Hosting;
namespace awge = ABI::Windows::Graphics::Effects;

// https://stackoverflow.com/a/51274008
template <auto fn>
struct deleter_from_fn {
    template <typename T>
    constexpr void operator()(T* arg) const {
        fn(arg);
    }
};
using string_setting_unique_ptr =
    std::unique_ptr<const WCHAR[], deleter_from_fn<Wh_FreeStringSetting>>;

using PropertyKeyValue =
    std::pair<DependencyProperty, winrt::Windows::Foundation::IInspectable>;

using PropertyValuesUnresolved =
    std::vector<std::pair<std::wstring, std::wstring>>;
using PropertyValues = std::vector<PropertyKeyValue>;
using PropertyValuesMaybeUnresolved =
    std::variant<PropertyValuesUnresolved, PropertyValues>;

struct ElementMatcher {
    enum class Kind {
        Element,   // Normal element matcher.
        Wildcard,  // '*': matches zero or more intermediate ancestors.
        Root,      // ':root': asserts the next element has no parent.
    };
    Kind kind = Kind::Element;
    std::wstring type;
    std::wstring name;
    std::optional<std::wstring> visualStateGroupName;
    int oneBasedIndex = 0;
    PropertyValuesMaybeUnresolved propertyValues;
};

// A `Property[@VisualState][:]=value` rule that sets a control property.
// `value` may contain `{{...}}` placeholders, in which case `isDynamic()`
// returns true and the rule is re-resolved on every apply.
struct ValueRule {
    std::wstring propertyName;
    std::wstring visualState;
    std::wstring value;
    bool isXamlValue = false;

    bool isDynamic() const { return value.find(L"{{") != std::wstring::npos; }
};

// A `Property=>VarName` rule that observes a control property and writes its
// current value into the named mod-global style variable.
struct CaptureRule {
    std::wstring propertyName;
    std::wstring varName;
};

// Parsed-but-not-yet-resolved rules for one target. Captures and value-rules
// are intentionally split: they live in different fields of `ResolvedRules`
// post-resolution, and the parser already validates that captures cannot carry
// `:=` or `@VisualState`.
struct UnresolvedRules {
    std::vector<ValueRule> valueRules;
    std::vector<CaptureRule> captureRules;
};

struct XamlBlurBrushParams {
    float blurAmount;
    winrt::Windows::UI::Color tint;
    std::optional<uint8_t> tintOpacity;
    std::wstring tintThemeResourceKey;  // Empty if not from ThemeResource
    std::optional<float> tintLuminosityOpacity;
    std::optional<float> tintSaturation;
    std::optional<float> noiseOpacity;
    std::optional<float> noiseDensity;
    std::optional<winrt::Windows::UI::Color> fallbackColor;
    std::wstring fallbackThemeResourceKey;  // Empty if not from ThemeResource
};

// Holds the raw rule body for a style whose value depends on `{{...}}`
// substitutions. Re-resolved on every apply and on every variable change.
// `propertyName` is kept alongside the value because Windows.UI.Xaml's
// DependencyProperty does not expose its name, and the re-resolution path needs
// to feed the name back to the XAML parser.
struct DynamicStyleTemplate {
    std::wstring propertyName;
    std::wstring rawValue;
    bool isXamlValue = false;
};

// Tagged value for one (property, visualState) cell of PropertyOverrides.
// Possible states:
// - IInspectable        : fully resolved WinRT value (literal or static XAML).
//                         Apply directly via SetValue.
// - XamlBlurBrushParams : parsed `<WindhawkBlur .../>` parameters. The brush
//                         instance is constructed at apply time (needs the live
//                         UIElement).
// - DynamicStyleTemplate: rule body contains `{{...}}` substitutions.
//                         Re-resolved on every apply and on every variable
//                         change. This arm appears only inside
//                         PropertyOverrides cells; it is never stored in
//                         ElementPropertyCustomizationState::customValue (see
//                         notes there).
using PropertyOverrideValue =
    std::variant<winrt::Windows::Foundation::IInspectable,
                 XamlBlurBrushParams,
                 DynamicStyleTemplate>;

// Property -> visual state -> value.
using PropertyOverrides =
    std::unordered_map<DependencyProperty,
                       std::unordered_map<std::wstring, PropertyOverrideValue>>;

// Resolved counterpart to CaptureRule: the property name string has been turned
// into an actual DependencyProperty by the XAML parser, so the apply path can
// call RegisterPropertyChangedCallback / GetValue directly without re-resolving
// on every use.
struct CaptureSpec {
    DependencyProperty property{nullptr};
    std::wstring varName;
};

struct ResolvedRules {
    PropertyOverrides propertyOverrides;
    std::vector<CaptureSpec> captures;
    // Whether this target consumes style variables. Lets ApplyCustomizations
    // skip the visual-tree bookkeeping that only variable users need.
    bool hasDynamicValues = false;
};

using PropertyOverridesMaybeUnresolved =
    std::variant<UnresolvedRules, ResolvedRules>;

// A `{{Var}}` reference resolved for one consuming property. The owner lets a
// value change on some other capture of the same name be skipped.
struct StyleVariableDependency {
    std::wstring name;
    ElementId owner = ElementId::None;  // None when the variable was undefined
};

// Interned node of an element's visual-tree spine. Nodes are shared by every
// tracked element under the same ancestor, so the pool holds one node per
// distinct ancestor rather than a full path per element. Once a node exists its
// `parent` and `depth` are final; an element that is later reparented keeps the
// spine it was first seen with, and only the nodes of a spine interned before
// its root object was attached (see GetOrCreateElementTreeNode) are ever
// replaced.
struct ElementTreeNode {
    // A node can outlive the object it describes -- descendant nodes and
    // not-yet-cleaned-up ElementCustomizationState entries keep it alive -- so
    // this is what proves a pool hit isn't a recycled address.
    winrt::weak_ref<DependencyObject> ref;
    std::shared_ptr<ElementTreeNode> parent;
    uint32_t depth = 0;
    // The depth-0 node this spine hangs from, `this` for a root itself. The
    // parent chain keeps it alive, so a raw pointer is enough.
    ElementTreeNode* root = nullptr;
};

// Keyed by the object's IUnknown pointer: COM only guarantees a stable pointer
// for that interface, and the same element is reached both as a
// FrameworkElement and as a VisualTreeHelper::GetParent result.
thread_local std::unordered_map<void*, std::weak_ptr<ElementTreeNode>>
    g_elementTreeNodes;

// Expired pool entries are reaped once the map grows past this, which is then
// set to twice the surviving size, making the sweep amortized O(1).
thread_local size_t g_elementTreeNodesReapThreshold = 64;

void* ElementIdentityKey(DependencyObject const& object) {
    return winrt::get_abi(object.as<winrt::Windows::Foundation::IUnknown>());
}

// A depth-0 node is a placeholder root until proven otherwise: if its object
// has since gained a parent, the spine was interned before that object was
// attached and stops short of the real root. Asked of any node on the spine,
// not just of the root itself, so that a descendant interned through a
// placeholder root is repaired too.
bool IsStaleSpine(ElementTreeNode const& node) {
    auto object = node.root->ref.get();
    return object && Media::VisualTreeHelper::GetParent(object);
}

// Fetch (or build) the spine node for `object`. Uses
// VisualTreeHelper::GetParent rather than Parent(), same reason as in
// FindElementPropertyOverrides. Returns nullptr if a node can't be built,
// leaving callers with no proximity information rather than a wrong answer.
std::shared_ptr<ElementTreeNode> GetOrCreateElementTreeNode(
    DependencyObject object) {
    if (!object) {
        return nullptr;
    }

    std::shared_ptr<ElementTreeNode> node;

    // Ancestors still lacking a node, innermost first. The walk stops at the
    // first ancestor that is already interned, so a new sibling of an
    // already-seen element costs one GetParent call.
    std::vector<DependencyObject> missing;

    try {
        for (auto iter = object; iter;
             iter = Media::VisualTreeHelper::GetParent(iter)) {
            auto key = ElementIdentityKey(iter);

            if (auto it = g_elementTreeNodes.find(key);
                it != g_elementTreeNodes.end()) {
                auto existing = it->second.lock();
                // A weak_ref never resolves to an object other than its own, so
                // a live ref proves this address hasn't been recycled since.
                if (!existing || !existing->ref.get()) {
                    Wh_Log(L"Replacing stale tree node for a reused address");
                    g_elementTreeNodes.erase(it);
                } else if (!IsStaleSpine(*existing)) {
                    node = std::move(existing);
                    break;
                } else {
                    // Drop the node and keep walking: the ancestors above it
                    // are stale for the same reason, up to the placeholder
                    // root, above which the real spine gets built. A stale
                    // shared_ptr already cached elsewhere (see
                    // EnsureElementTreeNode) is refreshed the same way on its
                    // own next use, so no element is stuck unrankable.
                    Wh_Log(L"Rebuilding tree node interned before attachment");
                    g_elementTreeNodes.erase(it);
                }
            }

            missing.push_back(iter);
        }

        for (auto it = missing.rbegin(); it != missing.rend(); ++it) {
            auto fresh = std::make_shared<ElementTreeNode>();
            fresh->ref = *it;
            fresh->depth = node ? node->depth + 1 : 0;
            fresh->root = node ? node->root : fresh.get();
            fresh->parent = std::move(node);
            g_elementTreeNodes[ElementIdentityKey(*it)] = fresh;
            node = std::move(fresh);
        }
    } catch (winrt::hresult_error const& ex) {
        Wh_Log(L"Error %08X: %s", ex.code(), ex.message().c_str());
        return nullptr;
    }

    return node;
}

void ReapElementTreeNodesIfNeeded() {
    if (g_elementTreeNodes.size() < g_elementTreeNodesReapThreshold) {
        return;
    }

    std::erase_if(g_elementTreeNodes,
                  [](const auto& item) { return item.second.expired(); });
    g_elementTreeNodesReapThreshold =
        std::max<size_t>(64, g_elementTreeNodes.size() * 2);
}

// Depth of the lowest common ancestor of two spine nodes, or -1 when they have
// none (separate visual trees, or a node that couldn't be built). A node counts
// as its own ancestor, so an element on the other's parent chain scores its own
// depth -- the deepest score that element can reach.
int ElementTreeLcaDepth(ElementTreeNode const* a, ElementTreeNode const* b) {
    if (!a || !b) {
        return -1;
    }

    while (a->depth > b->depth) {
        a = a->parent.get();
    }
    while (b->depth > a->depth) {
        b = b->parent.get();
    }

    while (a != b) {
        a = a->parent.get();
        b = b->parent.get();
        if (!a || !b) {
            return -1;
        }
    }

    return static_cast<int>(a->depth);
}

struct ElementCustomizationRules {
    ElementMatcher elementMatcher;
    std::vector<ElementMatcher> parentElementMatchers;
    PropertyOverridesMaybeUnresolved propertyOverrides;
};

thread_local std::vector<ElementCustomizationRules>
    g_elementsCustomizationRules;

struct ElementPropertyCustomizationState {
    std::optional<winrt::Windows::Foundation::IInspectable> originalValue;
    // The most recently applied value, re-pushed by the per-DP property-
    // changed callback when something external (animation, system Setter)
    // overrides it. Although PropertyOverrideValue's variant declares a
    // DynamicStyleTemplate arm, customValue here is always either IInspectable
    // or XamlBlurBrushParams in practice -- dynamic styles get resolved into
    // one of those before being stored, and the source template lives
    // separately in `dynamicTemplate` below.
    std::optional<PropertyOverrideValue> customValue;
    // The value SetOrClearValue wrote for customValue, which is what a write
    // by something else is told apart from.
    winrt::Windows::Foundation::IInspectable lastAppliedValue{nullptr};
    int64_t propertyChangedToken = 0;
    // Source template for dynamic styles whose value contains `{{...}}`
    // substitutions; re-evaluated whenever a referenced variable changes, with
    // the resolved result written back into `customValue`. Empty for static
    // styles.
    std::optional<DynamicStyleTemplate> dynamicTemplate;
    // Style variables this property's value depends on, each with the capture
    // that supplied it. Populated alongside `dynamicTemplate`; empty for static
    // styles.
    std::vector<StyleVariableDependency> variableDependencies;
    // Makes this property re-resolve on any change to any of its variables:
    // expansion aborts at the first failure, so the names past that point have
    // no recorded owner and a targeted propagation would never reach them.
    bool lastResolveFailed = false;
};

struct CapturePropertyCustomizationState {
    std::wstring varName;
    int64_t propertyChangedToken = 0;
};

struct ElementCustomizationStateForVisualStateGroup {
    std::unordered_map<DependencyProperty, ElementPropertyCustomizationState>
        propertyCustomizationStates;
    winrt::event_token visualStateGroupCurrentStateChangedToken;
};

struct ElementCustomizationState {
    winrt::weak_ref<FrameworkElement> element;

    // Scores how close each capture of a style variable is to this element.
    // Only built for elements that capture or consume a variable.
    std::shared_ptr<ElementTreeNode> treeNode;

    // Capture state lives at the element level: capture rules (`Prop=>Var`) are
    // intentionally not visual-state-aware (the parser rejects `@VisualState`
    // on them), and a single element observed by multiple targets with
    // different VSGs should still only register one
    // RegisterPropertyChangedCallback per DP and one SizeChanged subscription.
    std::unordered_map<DependencyProperty, CapturePropertyCustomizationState>
        captureCustomizationStates;

    // ActualWidth/ActualHeight (and other layout-driven DPs) do not fire
    // RegisterPropertyChangedCallback on UWP, so any element with capture rules
    // also subscribes to `FrameworkElement.SizeChanged` to pick up size
    // changes.
    winrt::event_token captureSizeChangedToken;

    // Use list to avoid reallocations on insertion, as pointers to items are
    // captured in callbacks and stored.
    std::list<std::pair<std::optional<winrt::weak_ref<VisualStateGroup>>,
                        ElementCustomizationStateForVisualStateGroup>>
        perVisualStateGroup;
};

thread_local std::unordered_map<ElementId, ElementCustomizationState>
    g_elementsCustomizationState;

// The weak reference is what keeps an id honest. A handle is an address, so a
// destroyed element can be replaced by one reporting the same handle, and an
// entry whose element is gone, or is no longer the element being asked about,
// belongs to that destroyed predecessor and must not name the new one.
struct ElementIdEntry {
    ElementId id = ElementId::None;
    winrt::weak_ref<wf::IInspectable> element;
};

thread_local std::unordered_map<InstanceHandle, ElementIdEntry> g_elementIds;
thread_local uint64_t g_lastElementId;

ElementId GetOrCreateElementId(InstanceHandle handle,
                               wf::IInspectable const& element) {
    if (!handle || !element) {
        return ElementId::None;
    }

    auto& entry = g_elementIds[handle];
    if (entry.id != ElementId::None && entry.element.get() == element) {
        return entry.id;
    }

    entry.id = static_cast<ElementId>(++g_lastElementId);

    winrt::weak_ref<wf::IInspectable> weakElement;
    try {
        weakElement = TryMakeWeak(element);
    } catch (winrt::hresult_error const& ex) {
        Wh_Log(L"Error %08X: %s", ex.code(), ex.message().c_str());
    }

    if (!weakElement) {
        // Without a weak reference the entry cannot be told apart from one for
        // a successor at the same address, so neither it nor the id it names is
        // kept: an id no lookup can reach again would key state that nothing
        // could ever tear down, on an element nothing would then hold back from
        // being released.
        g_elementIds.erase(handle);
        return ElementId::None;
    }

    entry.element = std::move(weakElement);
    return entry.id;
}

// By handle alone, for the element which is being reported as removed: it is
// the element the entry was made for, and a stale entry names something already
// destroyed, whose state is due for teardown either way.
ElementId FindElementId(InstanceHandle handle) {
    auto it = g_elementIds.find(handle);
    return it != g_elementIds.end() ? it->second.id : ElementId::None;
}

void ForgetElementId(InstanceHandle handle) {
    g_elementIds.erase(handle);
}

// Dead entries are reaped once the map grows past this, which is then set to
// twice the surviving size, making the sweep amortized O(1).
thread_local size_t g_elementIdsReapThreshold = 64;

// An element whose diagnostics reference was handed back is destroyed without a
// removal being reported for it, so what the mod keys by that element has to be
// found rather than told. An entry whose weak reference no longer resolves
// names such an element, and is torn down the way its removal would have.
void ReapDeadElementIdsIfNeeded() {
    if (g_elementIds.size() < g_elementIdsReapThreshold) {
        return;
    }

    // Collected before anything is torn down: CleanupCustomizations runs XAML
    // work which can re-enter ApplyCustomizations and rehash the map.
    std::vector<std::pair<InstanceHandle, ElementId>> dead;
    for (const auto& [handle, entry] : g_elementIds) {
        if (!entry.element.get()) {
            dead.push_back({handle, entry.id});
        }
    }

    if (!dead.empty()) {
        Wh_Log(L"Reaping %zu of %zu element ids", dead.size(),
               g_elementIds.size());
    }

    for (const auto& [handle, elementId] : dead) {
        CleanupCustomizations(elementId);
        g_elementIds.erase(handle);
    }

    g_elementIdsReapThreshold = std::max<size_t>(64, g_elementIds.size() * 2);
}

// The element's spine node. An element can be matched before its subtree is
// attached, in which case the eager build in ApplyCustomizations interns a
// spine that stops at a placeholder root; re-checked on every use so it's
// rebuilt once the subtree is actually in the tree.
ElementTreeNode* EnsureElementTreeNode(
    ElementCustomizationState& elementCustomizationState) {
    if (!elementCustomizationState.treeNode ||
        IsStaleSpine(*elementCustomizationState.treeNode)) {
        if (auto element = elementCustomizationState.element.get()) {
            elementCustomizationState.treeNode =
                GetOrCreateElementTreeNode(element);
        }
    }

    return elementCustomizationState.treeNode.get();
}

// Mod-global style variable registry. Populated by `Property=>VarName` capture
// rules and consumed by `{{VarName}}` substitutions in other styles. Every
// capturing element gets its own entry, so a name stays defined until its last
// capture goes away, and a consumer reading the name resolves to whichever
// capture is closest to it in the visual tree.
struct StyleVariableValue {
    std::wstring stringForm;        // invariant-formatted text representation
    std::optional<double> numeric;  // only present when source was numeric
    // True for primitive captures whose `stringForm` is meaningful to insert
    // verbatim into a XAML attribute (numeric, boolean, string). False for
    // opaque types -- their stringForm is the captured class name, kept only
    // for diagnostics; bare-identifier substitution skips such variables.
    bool substitutable = false;
};

// One element's capture of a variable. FindElementPropertyOverrides dedupes
// captures by name, so (name, elementId) identifies an entry.
struct StyleVariableCapture {
    ElementId elementId;
    StyleVariableValue value;
};

struct StyleVariableConsumer {
    ElementId elementId;
    DependencyProperty property{nullptr};
    // Each consumer remembers its own fallbackClassName so that propagation can
    // re-resolve dynamic styles using the consumer's match-site context, not
    // the (potentially different) capturer's.
    std::wstring fallbackClassName;
};

// Mod-global style variable registry. The struct mirrors the per-XamlRoot state
// used by the taskbar styler so the variable-resolution call paths stay aligned
// across the styler mods, but here all elements share one registry.
struct StyleVariableState {
    std::unordered_map<std::wstring, std::vector<StyleVariableCapture>>
        variables;
    std::unordered_map<std::wstring, std::vector<StyleVariableConsumer>>
        consumers;
    // How many entries the two maps above hold for each element. They're keyed
    // by variable name, so without this, asking whether an element appears in
    // either of them means walking every name.
    std::unordered_map<ElementId, size_t> elementRefs;
};

thread_local StyleVariableState g_styleVariableState;

// Non-zero while PropagateStyleVariableChange is running, so nested calls queue
// instead of recursing.
thread_local int g_styleVariablePropagationDepth;

struct PendingStyleVariablePropagation {
    StyleVariableState* state;
    std::wstring varName;
    std::optional<ElementId> changedOwner;

    bool operator==(const PendingStyleVariablePropagation&) const = default;
};

void AddStyleVariableElementRef(StyleVariableState* state,
                                ElementId elementId) {
    state->elementRefs[elementId]++;
}

void ReleaseStyleVariableElementRefs(StyleVariableState* state,
                                     ElementId elementId,
                                     size_t count) {
    if (!count) {
        return;
    }

    auto it = state->elementRefs.find(elementId);
    if (it == state->elementRefs.end()) {
        return;
    }

    if (it->second > count) {
        it->second -= count;
    } else {
        state->elementRefs.erase(it);
    }
}

// Propagations queued while another one is running, drained by the outermost
// PropagateStyleVariableChange frame.
thread_local std::vector<PendingStyleVariablePropagation>
    g_pendingStyleVariablePropagations;

StyleVariableState* GetStyleVariableState() {
    return &g_styleVariableState;
}

thread_local bool g_elementPropertyModifying;

// An image with a remote source fails to load when the process starts before
// the network is up. Such images are tracked so that the load can be retried
// once there's internet access, and are cached in a file in the mod storage
// folder, which is what's loaded when it's there, so that the image shows up at
// once and offline. Only a target which has no image is retried, and only a
// source which isn't showing anything is replaced, so an image that's currently
// displayed can't be blanked out.
struct TrackedImage {
    // An ImageBrush or an Image element. Both hold an image source which can
    // fail to load and both report the outcome, but through unrelated types, so
    // the source is addressed by DependencyProperty and each type gets its own
    // revoker pair.
    winrt::weak_ref<DependencyObject> target;
    DependencyProperty sourceProperty{nullptr};
    // The remote address: the entry's identity and what's downloaded, even
    // while the cached file is what's loaded.
    winrt::Windows::Foundation::Uri uri{nullptr};
    std::wstring url;
    // The cached copy of the image, empty when there's no cache folder.
    std::filesystem::path cachePath;

    // Decode properties of the BitmapImage the style declared, reapplied to the
    // BitmapImage a retry creates.
    int32_t decodePixelWidth = 0;
    int32_t decodePixelHeight = 0;
    Media::Imaging::DecodePixelType decodePixelType =
        Media::Imaging::DecodePixelType::Physical;
    Media::Imaging::BitmapCreateOptions createOptions =
        Media::Imaging::BitmapCreateOptions::None;
    bool autoPlay = true;

    Media::ImageBrush::ImageFailed_revoker brushImageFailedRevoker;
    Media::ImageBrush::ImageOpened_revoker brushImageOpenedRevoker;
    Controls::Image::ImageFailed_revoker elementImageFailedRevoker;
    Controls::Image::ImageOpened_revoker elementImageOpenedRevoker;

    // Whether the target has an image. Retries target the ones which don't.
    bool loaded = false;

    // Whether the target is loading from the cached file rather than from the
    // remote address, which is what a load failure is judged by.
    bool usingCache = false;

    ULONGLONG lastRetryTick = 0;
    int retryCount = 0;
};

struct TrackedImagesForThread {
    // Entries are held by shared_ptr so that event handlers can reference them
    // via a weak_ptr and do nothing once an entry is gone.
    std::list<std::shared_ptr<TrackedImage>> images;
    winrt::Microsoft::UI::Dispatching::DispatcherQueue dispatcher{nullptr};
    winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer retryTimer{nullptr};
    winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer::Tick_revoker
        retryTimerTickRevoker;
    // Tick the scheduled retry round is due at, zero if none is scheduled.
    ULONGLONG retryDueTick = 0;
};

thread_local TrackedImagesForThread g_trackedImagesForThread;

// The remote address of each cached file which has been substituted for one, so
// that a target given an already substituted source is tracked as well.
// Outlives the entries, since the style value it describes is shared by targets
// which come and go. Thread local like that value.
thread_local std::unordered_map<std::wstring, winrt::Windows::Foundation::Uri>
    g_imageCacheUriRemotes;

// A single connectivity transition raises several network status events, and
// the state right after the first one isn't final yet.
constexpr DWORD kNetworkChangeDebounceMs = 2000;

// Minimum delay between the retries of an image, doubling with each attempt up
// to about five minutes. Also keeps a retry from being started while the
// previous one is still loading.
constexpr ULONGLONG kImageRetryBaseDelayMs = 5000;
constexpr int kImageRetryMaxBackoffShift = 6;
constexpr ULONGLONG kImageRetryMaxDelayMs = kImageRetryBaseDelayMs
                                            << kImageRetryMaxBackoffShift;

// Caps the attempts of an image, bounding the series of retries which a failure
// starts. The count starts over once the image has been idle for the maximum
// delay, so connectivity which returns much later can still recover it.
constexpr int kImageRetryMaxCount = 20;

// Guards the globals below it. The network status handler acquires it, so it
// must never be held while adding or removing that handler: the event source
// can wait for an invocation which is already in flight, and registering from a
// UI thread pumps messages, which can re-enter this code on the same thread.
std::mutex g_imageRetryMutex;
bool g_imageRetryActive;
// The dispatcher of each UI thread which has tracked images, used to run a
// retry on the thread that owns the image.
std::vector<winrt::weak_ref<winrt::Microsoft::UI::Dispatching::DispatcherQueue>>
    g_imageRetryDispatchers;
winrt::event_token g_networkStatusChangedToken;
// Set while a thread is registering the handler outside the mutex, so that a
// concurrent or re-entrant call doesn't register a second one.
bool g_networkStatusChangedRegistering;
// Callbacks which are on their way into mod code, counted so that the module
// isn't freed out from under them.
size_t g_imageRetryPendingCallbacks;
std::condition_variable g_imageRetryPendingCallbacksCv;

// A cached file is fetched again once it's this old, and its write time is
// stamped whether or not the fetch gets through, so that the write time doubles
// as when the file was last known to be in use.
constexpr ULONGLONG kImageCacheRefreshIntervalMs = 7ULL * 24 * 60 * 60 * 1000;
// A file which nothing stamps ages until it's swept. Long enough for a theme
// which is switched away from and back to keep its images.
constexpr ULONGLONG kImageCacheMaxUnusedMs = 30ULL * 24 * 60 * 60 * 1000;

// Guards the globals below it.
std::mutex g_imageDownloadMutex;
// The URL of each image to fetch, or an empty string for a cache sweep. The
// path a URL is cached at follows from the URL, so it isn't carried along.
std::list<std::wstring> g_imageDownloadQueue;
// The URL of every queued and in flight job, so that one image isn't fetched
// twice at once. A job which failed is dropped: the retries of the image it's
// for are what ask again, and they're already paced and capped.
std::unordered_set<std::wstring> g_imageDownloadUrls;
// The URL of every cached file which failed to load, taking the images it's
// for back to the remote address for the rest of the process. Not per entry,
// since the file is what was rejected and the entries which share the URL
// would otherwise hand it out again. Global for the same reason: the file is
// process wide, not thread wide.
std::unordered_set<std::wstring> g_imageCacheRejectedUrls;
PTP_WORK g_imageDownloadWork;
// Whether a callback is draining the queue; a job added meanwhile joins it.
bool g_imageDownloadRunning;
bool g_imageDownloadStopping;

enum class ResourceVariableTheme {
    None,
    Dark,
    Light,
};

enum class ResourceVariableType {
    String,
    Xaml,
    ThemeResourceReference,
};

struct ResourceVariableEntry {
    std::wstring key;
    std::wstring value;
    ResourceVariableTheme theme;
    ResourceVariableType type;
};

thread_local std::vector<ResourceVariableEntry> g_resourceVariables;

// Track original resource values for restoration (per-thread since
// Application::Current().Resources() is per-thread).
thread_local std::unordered_map<std::wstring,
                                winrt::Windows::Foundation::IInspectable>
    g_originalResourceValues;

// Track our merged theme dictionary for cleanup (per-thread).
thread_local ResourceDictionary g_resourceVariablesThemeDict{nullptr};

// For listening to theme color changes (per-thread).
thread_local winrt::Windows::UI::ViewManagement::UISettings g_uiSettings{
    nullptr};
thread_local winrt::event_token g_colorValuesChangedToken;

winrt::Windows::Foundation::IInspectable ReadLocalValueWithWorkaround(
    DependencyObject elementDo,
    DependencyProperty property) {
    auto value = elementDo.ReadLocalValue(property);
    if (value) {
        // A workaround for ColumnDefinitionCollection of
        // NavigationBarControlGrid which can't be read by ReadLocalValue for
        // some reason, even though it seems to be a local property.
        if (value == DependencyProperty::UnsetValue()) {
            auto grid = elementDo.try_as<Controls::Grid>();
            if (grid && grid.Name() == L"NavigationBarControlGrid") {
                auto value2 = elementDo.GetValue(property);
                if (value2 && winrt::get_class_name(value2) ==
                                  L"Microsoft.UI.Xaml.Controls."
                                  L"ColumnDefinitionCollection") {
                    Wh_Log(
                        L"Using GetValue workaround for "
                        L"ColumnDefinitionCollection");
                    value = std::move(value2);
                }
            }
        }

        // TODO: Is this still needed?
#if 0
        auto className = winrt::get_class_name(value);
        if (className == L"Windows.UI.Xaml.Data.BindingExpressionBase" ||
            className == L"Windows.UI.Xaml.Data.BindingExpression") {
            // BindingExpressionBase was observed to be returned for XAML
            // properties that were declared as following:
            //
            // <Border ... CornerRadius="{TemplateBinding CornerRadius}" />
            //
            // Calling SetValue with it fails with an error, so we won't be able
            // to use it to restore the value. As a workaround, we use
            // GetAnimationBaseValue to get the value.
            Wh_Log(L"ReadLocalValue returned %s, using GetAnimationBaseValue",
                   className.c_str());
            value = elementDo.GetAnimationBaseValue(property);
        }
#endif
    }

    Wh_Log(L"Read property value %s",
           value ? (value == DependencyProperty::UnsetValue()
                        ? L"(unset)"
                        : winrt::get_class_name(value).c_str())
                 : L"(null)");

    return value;
}

////////////////////////////////////////////////////////////////////////////////
// Noise generation
//
// Generates a tileable noise BMP in memory. Density controls the brightness
// distribution curve via a power function (lower density = sparser bright
// pixels). Opacity is handled downstream by the composition effect graph.
winrt::Windows::Storage::Streams::IRandomAccessStream CreateNoiseStream(
    float density) {
    // Cache the last stream to avoid regenerating when density hasn't changed.
    // The cached stream is never read directly; callers get independent clones
    // via CloneStream() so they don't share a seek cursor.
    thread_local float cachedDensity = std::numeric_limits<float>::quiet_NaN();
    thread_local winrt::Windows::Storage::Streams::InMemoryRandomAccessStream
        cachedStream{nullptr};

    if (density == cachedDensity && cachedStream) {
        return cachedStream.CloneStream();
    }

    // Use 256x256 to minimize visible tiling seams.
    constexpr int kSize = 256;
    constexpr DWORD kBpp = 32;
    constexpr DWORD rowSize = kSize * (kBpp / 8);
    constexpr DWORD dataSize = rowSize * kSize;

    BITMAPFILEHEADER fileHeader{
        .bfType = 0x4D42,  // "BM"
        .bfSize =
            sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dataSize,
        .bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER),
    };

    BITMAPINFOHEADER infoHeader{
        .biSize = sizeof(BITMAPINFOHEADER),
        .biWidth = kSize,
        .biHeight = kSize,
        .biPlanes = 1,
        .biBitCount = kBpp,
        .biSizeImage = dataSize,
    };

    std::vector<uint8_t> pixels(dataSize);

    // Precompute the density power curve as a lookup table so that
    // std::pow is called 256 times instead of once per pixel (65536).
    float safeDensity = std::clamp(density, 0.001f, 1.0f);
    float exponent = 1.0f / safeDensity;

    uint8_t lut[256];
    for (int i = 0; i < 256; i++) {
        lut[i] = static_cast<uint8_t>(std::pow(i / 255.0f, exponent) * 255.0f);
    }

    std::mt19937 rng(0);
    std::uniform_int_distribution<int> dist(0, 255);

    for (size_t i = 0; i < pixels.size(); i += 4) {
        uint8_t gray = lut[dist(rng)];

        // Fully opaque; opacity is applied downstream by ColorMatrixEffect.
        pixels[i] = gray;
        pixels[i + 1] = gray;
        pixels[i + 2] = gray;
        pixels[i + 3] = 255;
    }

    winrt::Windows::Storage::Streams::InMemoryRandomAccessStream stream;
    winrt::Windows::Storage::Streams::DataWriter writer(stream);
    writer.WriteBytes(winrt::array_view<const uint8_t>(
        reinterpret_cast<const uint8_t*>(&fileHeader), sizeof(fileHeader)));
    writer.WriteBytes(winrt::array_view<const uint8_t>(
        reinterpret_cast<const uint8_t*>(&infoHeader), sizeof(infoHeader)));
    writer.WriteBytes(pixels);
    writer.StoreAsync().get();
    writer.DetachStream();

    cachedStream = std::move(stream);
    cachedDensity = density;

    return cachedStream.CloneStream();
}

// Blur background implementation, copied from TranslucentTB.
////////////////////////////////////////////////////////////////////////////////
// clang-format off

typedef enum MY_D2D1_GAUSSIANBLUR_OPTIMIZATION
{
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED = 0,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED = 1,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY = 2,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_FORCE_DWORD = 0xffffffff

} MY_D2D1_GAUSSIANBLUR_OPTIMIZATION;

////////////////////////////////////////////////////////////////////////////////
// XamlBlurBrush.h
class XamlBlurBrush : public Media::XamlCompositionBrushBaseT<XamlBlurBrush>
{
public:
    XamlBlurBrush(UIElement element,
                  float blurAmount,
                  winrt::Windows::UI::Color tint,
                  std::optional<uint8_t> tintOpacity,
                  winrt::hstring tintThemeResourceKey,
                  std::optional<float> tintLuminosityOpacity,
                  std::optional<float> tintSaturation,
                  std::optional<float> noiseOpacity,
                  std::optional<float> noiseDensity,
                  std::optional<winrt::Windows::UI::Color> fallbackColor,
                  winrt::hstring fallbackThemeResourceKey);
    ~XamlBlurBrush();

    void OnConnected();
    void OnDisconnected();

private:
    void RefreshThemeTint();
    void RefreshFallbackColor();
    bool ShouldUseFallback() const;
    void RefreshBrush();
    muc::CompositionBrush CreateEffectBrush();
    muc::CompositionBrush CreateFallbackBrush();

    muc::Compositor m_compositor;
    float m_blurAmount;
    winrt::Windows::UI::Color m_tint;
    std::optional<uint8_t> m_tintOpacity;
    winrt::hstring m_tintThemeResourceKey;
    std::optional<float> m_tintLuminosityOpacity;
    std::optional<float> m_tintSaturation;
    std::optional<float> m_noiseOpacity;
    std::optional<float> m_noiseDensity;
    std::optional<winrt::Windows::UI::Color> m_fallbackColor;
    winrt::hstring m_fallbackThemeResourceKey;
    Media::SolidColorBrush m_proxyBrush{nullptr};
    Media::SolidColorBrush m_fallbackProxyBrush{nullptr};
    winrt::weak_ref<FrameworkElement> m_weakProxyElement;
    winrt::hstring m_proxyKey;
    winrt::hstring m_fallbackProxyKey;
    winrt::Windows::UI::ViewManagement::UISettings m_uiSettings{nullptr};
    winrt::event_token m_advancedEffectsEnabledChangedToken{};
    winrt::event_token m_energySaverStatusChangedToken{};
    winrt::Microsoft::UI::Dispatching::DispatcherQueue m_dispatcher{nullptr};
    HKEY m_powerKey{nullptr};
    HANDLE m_regNotifyEvent{nullptr};
    HANDLE m_regWaitHandle{nullptr};

    static void CALLBACK OnEnergySaverRegistryChanged(PVOID context,
                                                      BOOLEAN timerOrWaitFired);
};

////////////////////////////////////////////////////////////////////////////////
