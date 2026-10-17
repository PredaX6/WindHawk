# Architecture decision: preserve original mod behavior

Date: 2026-10-17
Status: Decision for the next implementation phase

## User priority

The highest priority is that every feature in the seven included mods continues to behave as it did before integration. Windows 11 Taskbar Styler is explicitly excluded.

## Decision

Do not attempt to ship the current generated `All in One.wh.cpp` as a single Windhawk mod. Keep it as an experimental artifact only.

The safest implementation is to preserve the original mods as independent Windhawk modules, each with its own original entry points, settings schema, process targeting, hooks, and unload/reload behavior. If the user needs one deliverable, package the unchanged modules together as a clearly documented bundle, rather than falsely treating them as one functional `.wh.cpp`.

A true single-`.wh.cpp` implementation may be reconsidered only after a substantial, deliberate refactor: shared WinRT/COM integration, isolated module state, per-component initialization failure handling, correct hook ordering and teardown, and settings migration. This is not a mechanical concatenation task.

## Why this is the stable choice

Windhawk compiles each mod source into a dynamic library and calls lifecycle callbacks for that loaded mod. Combining independent mods changes the lifecycle boundary and can alter failure handling, settings reloads, hook installation/removal, and COM exports. The three XAML stylers also have overlapping WinRT/COM support code and translation-unit-wide header/preprocessor assumptions.

The current candidate has not been compiled or tested and cannot be claimed to preserve original behavior.

## Acceptance criteria before any release

1. Compile with Windhawk's supported compiler and architectures intended for release.
2. Verify each component's target-process filters.
3. Verify initialization failure in one component cannot leave another component partially initialized or prevent its cleanup.
4. Verify settings load, edit, save, reload, and default behavior for each component.
5. Verify every hook is removed and every worker/thread/subclass/COM resource is cleaned up on unload.
6. Run side-by-side regression tests against each original mod, including settings changes and Windhawk reload/uninstall.
7. Keep all original source snapshots unchanged; do not change `main` until all checks pass.

## Source preservation

The seven snapshots in `sources/original/` remain reference copies. The original `GlassExplorerTaskSwitcher.wh.cpp` is immutable and must never be modified.
