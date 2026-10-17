# All in One — reconstruction roadmap

## Goal

Rebuild incrementally with the highest priority being zero feature loss. Every candidate must be a complete Windhawk source file and must be compiled by the user before the next integration is treated as accepted.

## Baseline

- `All in One.wh.cpp` is the existing Windows Animations stage-1 baseline copied unchanged from the previously working integration branch.
- The baseline is a compile checkpoint, not a claim that the whole All in One project is complete.
- Original source snapshots under `sources/original/` are references and must not be edited.
- Windows 11 Taskbar Styler is excluded and must never be integrated.
- The original `GlassExplorerTaskSwitcher.wh.cpp` is immutable and must never be edited.

## Proposed integration order

1. **Windows Animations** — baseline already present. Validate this exact source on the clean branch first.
2. **Taskbar Button Scroll** — smallest remaining source and a relatively narrow Explorer/taskbar feature. First audit its hook/lifecycle and WinRT interactions; integrate only with isolated settings/state and Explorer-only activation.
3. **File Explorer Content Animation** — **skipped at the user's request**; do not integrate unless explicitly requested later.
4. **Translucent Windows** — current candidate after the skipped step. Broad process scope and system-wide visual side effects require isolated settings, shared-hook handling, and teardown checks.
5. **Windows 11 File Explorer Styler** — large XAML/COM-oriented component and likely interaction with Translucent Windows; integrate after the preceding Explorer-related components.
6. **Windows 11 Start Menu Styler** — separate Start/Search process targets and complex XAML/COM behavior.
7. **Windows 11 Notification Center Styler** — separate shell-host targets and complex XAML/COM behavior; final because shared infrastructure and lifecycle isolation need to be proven by prior integrations.

This is a provisional engineering order based on scope, size, and likely interaction risk, not a claim that any merge is already safe. File Explorer Content Animation is intentionally skipped at the user's request. The current candidate is `candidates/All in One - étape 3 - Translucent Windows.wh.cpp`; it still requires compilation and runtime testing before acceptance. Static source audits may change the order if they reveal a concrete dependency.

## Mandatory workflow per step

1. Audit original metadata, process filters, settings, global/static state, hooks, worker threads, COM/WinRT initialization, callbacks, and unload cleanup.
2. Keep original sources unchanged.
3. Integrate exactly one component into a separate candidate source; never overwrite the accepted checkpoint until the user reports successful compilation and tests.
4. Check for duplicate symbols, metadata/settings collisions, process-target mistakes, initialization ordering, and teardown symmetry.
5. Provide the complete source link and a concise change log.
6. User compiles/tests; use the full compiler log to fix errors. Never claim compilation/runtime success without evidence.
7. Test component settings/defaults and regressions against every previously accepted component before moving on.

## Release gate

No release is considered complete until all seven included components have been checked for compile success, process targeting, settings load/save/reload, interaction regressions, hook/thread/resource cleanup, unload/reload, and uninstall. Compilation alone is necessary but not sufficient.
