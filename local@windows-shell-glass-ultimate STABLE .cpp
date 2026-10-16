// ==WindhawkMod==
// @id              windows-shell-glass-ultimate
// @name            Windows Shell Glass Ultimate
// @description     Target monitor engine
// @version         11.0
// @author          Teddy MELIN
// @include         explorer.exe
// ==/WindhawkMod==

// ==WindhawkModSettings==
/*
- EnableLogging: true
  $name: Logging
*/
// ==/WindhawkModSettings==

#include <windows.h>

static bool g_enableLogging;

struct ShellTargets
{
    HWND explorerWindow;
    HWND explorerXamlHost;
    HWND taskbarWindow;
    HWND taskbarCompositionHost;
    HWND startButton;
    HWND trayHost;
};

static ShellTargets g_targets{};

void ScanChildren(HWND parent)
{
    HWND child =
        GetWindow(
            parent,
            GW_CHILD);

    while (child)
    {
        wchar_t cls[256]{};

        GetClassNameW(
            child,
            cls,
            ARRAYSIZE(cls));

        if (wcscmp(
                cls,
                L"Microsoft.UI.Content.DesktopChildSiteBridge") == 0)
        {
            g_targets.explorerXamlHost =
                child;
        }

        if (wcscmp(
                cls,
                L"Windows.UI.Composition.DesktopWindowContentBridge") == 0)
        {
            g_targets.taskbarCompositionHost =
                child;
        }

        if (wcscmp(
                cls,
                L"Start") == 0)
        {
            g_targets.startButton =
                child;
        }

        if (wcscmp(
                cls,
                L"TrayNotifyWnd") == 0)
        {
            g_targets.trayHost =
                child;
        }

        ScanChildren(child);

        child =
            GetWindow(
                child,
                GW_HWNDNEXT);
    }
}

BOOL CALLBACK EnumProc(
    HWND hwnd,
    LPARAM)
{
    DWORD pid = 0;

    GetWindowThreadProcessId(
        hwnd,
        &pid);

    if (pid != GetCurrentProcessId())
        return TRUE;

    wchar_t cls[256]{};

    GetClassNameW(
        hwnd,
        cls,
        ARRAYSIZE(cls));

    if (wcscmp(
            cls,
            L"CabinetWClass") == 0)
    {
        g_targets.explorerWindow =
            hwnd;

        ScanChildren(hwnd);
    }

    if (wcscmp(
            cls,
            L"Shell_TrayWnd") == 0)
    {
        g_targets.taskbarWindow =
            hwnd;

        ScanChildren(hwnd);
    }

    if (wcscmp(
            cls,
            L"XamlExplorerHostIslandWindow") == 0)
    {
        g_targets.explorerXamlHost =
            hwnd;
    }

    return TRUE;
}

void RefreshTargets()
{
    ZeroMemory(
        &g_targets,
        sizeof(g_targets));

    EnumWindows(
        EnumProc,
        0);

    if (!g_enableLogging)
        return;

    Wh_Log(
        L"[MONITOR] Explorer=%p",
        g_targets.explorerWindow);

    Wh_Log(
        L"[MONITOR] ExplorerXaml=%p",
        g_targets.explorerXamlHost);

    Wh_Log(
        L"[MONITOR] Taskbar=%p",
        g_targets.taskbarWindow);

    Wh_Log(
        L"[MONITOR] TaskbarComposition=%p",
        g_targets.taskbarCompositionHost);

    Wh_Log(
        L"[MONITOR] Start=%p",
        g_targets.startButton);

    Wh_Log(
        L"[MONITOR] Tray=%p",
        g_targets.trayHost);
}

BOOL Wh_ModInit()
{
    g_enableLogging =
        Wh_GetIntSetting(
            L"EnableLogging") != 0;

    if (g_enableLogging)
    {
        Wh_Log(
            L"[WSGU] V11 Init");
    }

    RefreshTargets();

    return TRUE;
}

void Wh_ModAfterInit()
{
    RefreshTargets();
}

void Wh_ModSettingsChanged()
{
    g_enableLogging =
        Wh_GetIntSetting(
            L"EnableLogging") != 0;

    RefreshTargets();
}

void Wh_ModUninit()
{
    if (g_enableLogging)
    {
        Wh_Log(
            L"[WSGU] Unloaded");
    }
}