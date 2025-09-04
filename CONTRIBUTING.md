# Contributing

## Module boundaries
- Only `/contracts/*.hpp` are shared across modules.
- `engine/renderer`, `engine/sim`, `engine/ui` must not include each other's private headers.

## Style & CI
- `clang-format` required; warnings as errors later.
- Tests live under each module's `tests/`.

## PRs
- One module per PR.
- Keep contracts stable; breaking changes require `/contracts/VERSION.md` bump + shims.