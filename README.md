# Space Sim (SDL2 + Vulkan) — Starter

## Build
```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target all
ctest --test-dir build --output-on-failure
./build/apps/sandbox/sandbox
```

## Agents

* Three GitHub Actions agents (renderer, sim, ui) run via OpenCode and create PRs.
* Put `XAI_API_KEY` or `OPENROUTER_API_KEY` in repo **Settings → Secrets**.

## Boundaries

* Only `/contracts/*.hpp` are shared interfaces. Keep them stable.