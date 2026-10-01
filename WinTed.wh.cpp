// ==WindhawkMod==
// @id winted
// @name WinTed
// @description Windows 11 25H2 : Explorer translucide avec Blur (AccentBlurBehind) à 50 %, y compris la barre de commandes.
// @version 1.4.1
// @author Teddy
// @github https://github.com/PredaX6
// @include explorer.exe
// @architecture x86-64
// @compilerOptions -ldwmapi -lgdi32 -lruntimeobject
// ==/WindhawkMod==

#include <windows.h>
#include <dwmapi.h>
#include <xamlom.h>

#include <Unknwn.h>
#include <winrt/base.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>

namespace mux = winrt::Microsoft::UI::Xaml;
namespace muxc = winrt::Microsoft::UI::Xaml::Controls;
namespace muxm = winrt::Microsoft::UI::Xaml::Media;

constexpr DWORD WCA_ACCENT_POLICY = 19;
constexpr int ACCENT_ENABLE_BLURBEHIND = 3;
constexpr DWORD DWMWA_SYSTEMBACKDROP_TYPE_VALUE = 38;
constexpr int DWMSBT_TRANSIENTWINDOW_VALUE = 3;

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

    const int backdrop = DWMSBT_TRANSIENTWINDOW_VALUE;
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

// -----------------------------------------------------------------------------
// WinUI/XAML : rend uniquement la barre de commandes de l'Explorer transparente.
// -----------------------------------------------------------------------------

static void MakeExplorerCommandBarTransparent(
    winrt::Windows::Foundation::IInspectable const& object) {
    try {
        auto element = object.try_as<mux::FrameworkElement>();
        if (!element)
            return;

        std::wstring className = winrt::get_class_name(element).c_str();
        std::wstring name = element.Name().c_str();

        const bool rootGrid =
            (className == L"Microsoft.UI.Xaml.Controls.Grid" ||
             className == L"Grid") &&
            (name == L"CommandBarControlRootGrid" ||
             name == L"NavigationBarControlGrid");

        const bool commandBar =
            (className == L"Microsoft.UI.Xaml.Controls.CommandBar" ||
             className == L"CommandBar") &&
            name == L"FileExplorerCommandBar";

        const bool commandBarWave1 =
            className == L"FileExplorerExtensions.CommandBarControl_Wave1";

        if (!rootGrid && !commandBar && !commandBarWave1)
            return;

        auto transparent =
            muxm::SolidColorBrush(
                winrt::Windows::UI::Color{0, 0, 0, 0});

        if (auto panel = element.try_as<muxc::Panel>())
            panel.Background(transparent);

        if (auto control = element.try_as<muxc::Control>())
            control.Background(transparent);
    } catch (...) {
        Wh_Log(L"WinTed: XAML transparency error %08X",
               winrt::to_hresult());
    }
}

class VisualTreeWatcher :
    public winrt::implements<
        VisualTreeWatcher,
        IVisualTreeServiceCallback2,
        winrt::non_agile> {
public:
    explicit VisualTreeWatcher(winrt::com_ptr<IUnknown> site)
        : diagnostics_(site.as<IXamlDiagnostics>()) {
        HRESULT hr = E_FAIL;

        HANDLE thread = CreateThread(
            nullptr, 0,
            [](LPVOID parameter) WINAPI -> DWORD {
                auto watcher =
                    reinterpret_cast<VisualTreeWatcher*>(parameter);

                HRESULT result =
                    watcher->diagnostics_.as<IVisualTreeService3>()
                        ->AdviseVisualTreeChange(watcher);

                if (FAILED(result)) {
                    Wh_Log(
                        L"WinTed: AdviseVisualTreeChange failed: %08X",
                        result);
                }

                watcher->Release();
                return 0;
            },
            this, 0, nullptr);

        if (thread) {
            AddRef();
            CloseHandle(thread);
        } else {
            hr = HRESULT_FROM_WIN32(GetLastError());
            Wh_Log(L"WinTed: XAML watcher thread failed: %08X", hr);
        }
    }

    ~VisualTreeWatcher() {
        if (diagnostics_) {
            diagnostics_.as<IVisualTreeService3>()
                ->UnadviseVisualTreeChange(this);
        }
    }

private:
    HRESULT STDMETHODCALLTYPE OnVisualTreeChange(
        ParentChildRelation,
        VisualElement element,
        VisualMutationType mutationType) override {
        if (mutationType != Add)
            return S_OK;

        try {
            winrt::Windows::Foundation::IInspectable object;

            HRESULT hr = diagnostics_->GetIInspectableFromHandle(
                element.Handle,
                reinterpret_cast<::IInspectable**>(
                    winrt::put_abi(object)));

            if (SUCCEEDED(hr) && object)
                MakeExplorerCommandBarTransparent(object);
        } catch (...) {
            Wh_Log(L"WinTed: XAML callback error %08X",
                   winrt::to_hresult());
        }

        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE OnElementStateChanged(
        InstanceHandle,
        VisualElementState,
        LPCWSTR) noexcept override {
        return S_OK;
    }

    winrt::com_ptr<IXamlDiagnostics> diagnostics_;
};

static winrt::com_ptr<VisualTreeWatcher> g_visualTreeWatcher;

static constexpr CLSID CLSID_WindTedTAP =
    {0x6f7a2c11, 0x2f0b, 0x4b5c,
     {0x91, 0x52, 0x5d, 0x31, 0x73, 0x4a, 0x8e, 0x20}};

class WindTedTAP :
    public winrt::implements<
        WindTedTAP, IObjectWithSite, winrt::non_agile> {
public:
    HRESULT STDMETHODCALLTYPE SetSite(IUnknown* site) override {
        g_visualTreeWatcher = nullptr;
        site_.copy_from(site);

        if (site_) {
            try {
                g_visualTreeWatcher =
                    winrt::make_self<VisualTreeWatcher>(site_);
            } catch (...) {
                Wh_Log(
                    L"WinTed: TAP initialization failed %08X",
                    winrt::to_hresult());
                return winrt::to_hresult();
            }
        }

        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetSite(
        REFIID riid,
        void** ppvSite) noexcept override {
        return site_.as(riid, ppvSite);
    }

private:
    winrt::com_ptr<IUnknown> site_;
};

template <class T>
struct SimpleFactory :
    winrt::implements<
        SimpleFactory<T>, IClassFactory, winrt::non_agile> {
    HRESULT STDMETHODCALLTYPE CreateInstance(
        IUnknown* outer,
        REFIID riid,
        void** object) override {
        if (outer)
            return CLASS_E_NOAGGREGATION;

        *object = nullptr;
        return winrt::make<T>().as(riid, object);
    }

    HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override {
        return S_OK;
    }
};

extern "C" __declspec(dllexport)
HRESULT WINAPI DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) {
    if (rclsid != CLSID_WindTedTAP)
        return CLASS_E_CLASSNOTAVAILABLE;

    return winrt::make<
        SimpleFactory<WindTedTAP>>().as(riid, ppv);
}

extern "C" __declspec(dllexport)
HRESULT WINAPI DllCanUnloadNow() {
    return winrt::get_module_lock() ? S_FALSE : S_OK;
}

using InitializeXamlDiagnosticsEx_t =
    HRESULT(WINAPI*)(
        PCWSTR,
        DWORD,
        PCWSTR,
        PCWSTR,
        CLSID,
        PCWSTR);

static InitializeXamlDiagnosticsEx_t
    g_InitializeXamlDiagnosticsEx = nullptr;

static HRESULT InjectWindTedTAP() {
    HMODULE module = nullptr;

    if (!GetModuleHandleExW(
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            reinterpret_cast<LPCWSTR>(&InjectWindTedTAP),
            &module)) {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR location[MAX_PATH];
    DWORD length = GetModuleFileNameW(
        module, location, ARRAYSIZE(location));

    if (!length || length >= ARRAYSIZE(location))
        return HRESULT_FROM_WIN32(GetLastError());

    HMODULE wux =
        GetModuleHandleW(L"Microsoft.Internal.FrameworkUdk.dll");
    if (!wux)
        return HRESULT_FROM_WIN32(GetLastError());

    g_InitializeXamlDiagnosticsEx =
        reinterpret_cast<InitializeXamlDiagnosticsEx_t>(
            GetProcAddress(
                wux, "InitializeXamlDiagnosticsEx"));

    if (!g_InitializeXamlDiagnosticsEx)
        return E_NOINTERFACE;

    HRESULT hr = E_FAIL;

    for (int i = 0; i < 10000; ++i) {
        WCHAR connectionName[128];
        wsprintfW(
            connectionName,
            L"WinTedVisualDiagConnection%d",
            i + 1);

        hr = g_InitializeXamlDiagnosticsEx(
            connectionName,
            GetCurrentProcessId(),
            L"",
            location,
            CLSID_WindTedTAP,
            nullptr);

        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
            break;
    }

    return hr;
}

BOOL Wh_ModInit() {
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    if (!user32)
        return FALSE;

    g_SetWindowCompositionAttribute =
        reinterpret_cast<SetWindowCompositionAttribute_t>(
            GetProcAddress(
                user32, "SetWindowCompositionAttribute"));

    if (!g_SetWindowCompositionAttribute)
        return FALSE;

    EnumWindows(EnumWindowsProc, 0);

    HRESULT hr = InjectWindTedTAP();
    if (FAILED(hr)) {
        Wh_Log(
            L"WinTed: XAML diagnostics injection failed: %08X",
            hr);
    }

    return TRUE;
}

void Wh_ModUninit() {
    g_visualTreeWatcher = nullptr;
}
