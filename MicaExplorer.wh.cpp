// ==WindhawkMod==
// @id              mica-explorer
// @name            Mica Explorer
// @description     Apply Mica or Mica Alt to Windows 11 File Explorer windows.
// @version         1.0.0
// @author          TeddySlexique
// @github          https://github.com/PredaX6/WindHawk
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -ldwmapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Mica Explorer

A focused mod for the Windows 11 File Explorer window background.

Available materials:
- **Mica**
- **Mica Alt**

The selected material is reapplied when Explorer creates a window and whenever
Explorer or another component requests a different system backdrop type.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- material: mica
  $name: Material
  $description: Choisissez le matériau utilisé pour l'arrière-plan de l'Explorateur.
  $options:
  - mica: Mica
  - micaAlt: Mica Alt
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <dwmapi.h>
#include <windhawk_utils.h>

#include <cwchar>

namespace {

enum class Material {
    Mica,
    MicaAlt,
};

Material g_material = Material::Mica;

Material LoadMaterial() {
    PWSTR value = Wh_GetStringSetting(L"material");
    Material material = Material::Mica;

    if (value && _wcsicmp(value, L"micaAlt") == 0) {
        material = Material::MicaAlt;
    }

    if (value) {
        Wh_FreeStringSetting(value);
    }

    return material;
}

int GetBackdropType() {
    return g_material == Material::MicaAlt ? DWMSBT_TABBEDWINDOW
                                           : DWMSBT_MAINWINDOW;
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

    const int backdropType = GetBackdropType();
    DwmSetWindowAttribute(hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &backdropType,
                          sizeof(backdropType));
}

BOOL CALLBACK EnumExplorerWindowsProc(HWND hwnd, LPARAM) {
    ApplyMaterial(hwnd);
    return TRUE;
}

using DwmSetWindowAttribute_t = decltype(&DwmSetWindowAttribute);
DwmSetWindowAttribute_t DwmSetWindowAttribute_Original;

HRESULT WINAPI DwmSetWindowAttribute_Hook(HWND hwnd,
                                          DWORD attribute,
                                          LPCVOID value,
                                          DWORD valueSize) {
    if (attribute == DWMWA_SYSTEMBACKDROP_TYPE && IsExplorerWindow(hwnd)) {
        const int backdropType = GetBackdropType();
        return DwmSetWindowAttribute_Original(
            hwnd, DWMWA_SYSTEMBACKDROP_TYPE, &backdropType,
            sizeof(backdropType));
    }

    return DwmSetWindowAttribute_Original(hwnd, attribute, value, valueSize);
}

using CreateWindowExW_t = decltype(&CreateWindowExW);
CreateWindowExW_t CreateWindowExW_Original;

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
