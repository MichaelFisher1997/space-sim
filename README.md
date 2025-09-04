# Space Sim (SDL2 + Vulkan) — Starter

## Quick Start with Nix (Recommended)

```bash
# Enter development environment (includes Node.js for opencode CLI)
nix develop

# Install opencode CLI globally
npm install -g opencode

# Build and run
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --target all
ctest --test-dir build --output-on-failure
./build/apps/sandbox/sandbox
```

## Manual Build (Alternative)

```bash
# Install dependencies manually
sudo apt-get update
sudo apt-get install -y cmake ninja-build build-essential \
  libsdl2-dev libvulkan-dev vulkan-tools mesa-vulkan-drivers

# Build
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