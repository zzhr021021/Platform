## Quick orientation for AI coding agents

This repository is a curated collection of competitive programming solutions and algorithm/library snippets (single-file C++ programs), organized by topic. The guidance below focuses on immediately actionable patterns and workflows an AI agent should follow when editing, adding, or running code here.

### Big picture
- Top-level folders: `Codeforce/` (contest submissions), `Platform/` (library snippets grouped by topic: `Data structure/`, `Number theory/`, `String Processing/`, etc.).
- Each problem or snippet is typically a single `.cpp` file intended to compile/run standalone. Examples: `Codeforce/plat.cpp`, `Platform/Number theory/qpow and qcomb.cpp`.
- Most files follow the competitive-programming pattern: `#include <bits/stdc++.h>`, many macro helpers, global arrays sized for constraints (e.g. N=200500), and a `sol()` function called from `main()`.

### Build / run / debug (developer workflows)
- Preferred quick build (VS Code task): the workspace contains a C++ build task labeled like `C/C++: g++.exe build active file` which runs g++ to build the active file into an `.exe` next to the source. Check `.vscode/tasks.json` for the concrete command (paths vary across machines).

Example compile command (what the task runs):
```
D:\mingw64\bin\g++.exe -fdiagnostics-color=always -g <file.cpp> -o <fileDir>\<fileBasename>.exe
```

- Notes for Windows: many sources call `system("pause")` at the end — built `.exe` files are intended to run interactively on Windows. File and folder names often contain spaces, so quote paths when running commands.
- IntelliSense / language level: `.vscode/c_cpp_properties.json` sets `cppStandard` (e.g. `c++20`) — prefer compiling with a modern standard (`-std=c++17` or `-std=c++20`) when adding features.
- Debugging: there is no common `launch.json`. To debug, use the generated `.exe` with your local debugger (gdb or VS Code C++ extension). If adding a `launch.json`, use the active-file executable path as the program.

### Project-specific conventions and patterns
- Single-file solutions: preserve standalone behavior — avoid adding hidden module dependencies or project-wide build steps. Keep `sol()` + `main()` pattern when adding new contest solutions.
- Globals & sizes: many files use fixed global arrays (e.g. `ll a[200500];`). When changing sizes, search for other snippets reusing the same constant to avoid inconsistencies.
- Macros & helpers: common macro names: `rep`, `rep1`, `ll`, `vi`, `all`, `pb`, `yes/no`. Reuse existing macros where appropriate; prefer consistency with surrounding file.
- IO style: fast IO via `ios::sync_with_stdio(false); cin.tie(nullptr);` is common — maintain this pattern for performance-sensitive changes.

### Integration points & external deps
- There are no external package manifests. Compilation relies on a local C++ toolchain (MinGW / MSYS / g++). If you need additional libraries, document the toolchain change in the repo and prefer header-only libs when possible.

### What to edit vs what to preserve
- Safe edits: improving algorithm, fixing bugs in a single `.cpp`, small refactors that keep the file standalone.
- Risky edits: introducing multi-file builds, changing compiler/standard without updating tasks, or modifying shared macros used across many files without sweeping updates.

### Where to look for examples
- `Codeforce/plat.cpp` — canonical contest template (macros, `sol()` pattern).
- `Platform/Number theory/qpow and qcomb.cpp` — example of common numeric utilities and patterns for modular arithmetic.

### If you need to add tests or harnesses
- Keep them local to the problem file (e.g., add a `#ifdef LOCAL` block) or add a sibling script that compiles & runs the single `.cpp` — avoid changing global build infrastructure.

### Final notes for the human reviewer
- I merged no previous copilot-instructions file (none existed). If you want stricter rules (naming, forbidden macros, or a preferred compile command and standard), tell me and I will update this file to enforce them.

---
If any part of this is unclear or you want specific examples added (launch.json sample, standard flags, or a test harness template), tell me which and I'll iterate.
