# All in One integration audit

Date: 2026-10-17

## Current candidate

`All in One.wh.cpp` is an experimental, uncompiled integration candidate containing the seven requested modules. Windows 11 Taskbar Styler is excluded.

## Static corrections made

- Removed leading whitespace from the Windhawk settings block markers so the parser can recognize them.
- Replaced six zero-length C++ arrays used for empty process-exclusion lists with a harmless empty-string sentinel. This avoids relying on a compiler extension for zero-length arrays.

These are source-level corrections only; they do not establish that the file compiles.

## Remaining blockers before the candidate can be called functional

1. **XAML/WinRT headers are not safely isolated by C++ namespaces.** File Explorer Styler uses Microsoft.UI.Xaml while Start Menu Styler and Notification Center Styler use Windows.UI.Xaml projections, with conditional compilation in the source. Headers have include guards and preprocessor state is translation-unit-wide. Moving all headers to one global preamble cannot preserve each original source's header/macro environment automatically.
2. **Overlapping COM exports.** The three XAML styler sources each define exported COM helper entry points such as `DllGetClassObject` and `DllCanUnloadNow`. Renaming two copies avoids duplicate C++ symbols but changes the expected export names; keeping the same names creates duplicate definitions. This needs an intentional shared implementation or a different architecture.
3. **Lifecycle semantics differ.** Windhawk calls lifecycle callbacks for a single loaded mod, whereas the originals were independent mods. The wrapper must faithfully handle per-module init failure, settings reload requests, and before-uninit ordering. That has not yet been proven.
4. **Settings schema and setting access must be tested together.** The candidate nests each original settings tree and prefixes literal setting paths. This must be validated by Windhawk's actual settings parser and each module's settings loader.
5. **No native build environment is available in this workflow.** No compile or runtime test has been performed, and the candidate must not be treated as release-ready.

## Recommended next technical step

Refactor the XAML styling components around one deliberately shared WinRT/COM integration layer, or keep the three XAML stylers as separate Windhawk mods. The latter is the safer way to preserve their original behavior without a substantial rewrite. After the architecture is settled, compile in Windhawk, test each target process separately, and compare behavior against each original mod.

The source snapshots under `sources/original/` remain the reference copies. Do not edit the original `GlassExplorerTaskSwitcher.wh.cpp` or merge this candidate into `main` before successful validation.
