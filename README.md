# Space Sim (SDL2 + Vulkan) — Starter

## Build
```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target all
ctest --test-dir build --output-on-failure
./build/apps/sandbox/sandbox
```

## Run the agent workflow
1. Add `XAI_API_KEY` (or `OPENROUTER_API_KEY`) in **Settings → Secrets**.
2. Go to **Actions → SpaceSim Agents → Run workflow**.
3. Review the three PRs (renderer/sim/ui), merge, repeat.

## Agents

* Three GitHub Actions agents (renderer, sim, ui) run via OpenCode and create PRs.

## Boundaries

* Only `/contracts/*.hpp` are shared interfaces. Keep them stable.