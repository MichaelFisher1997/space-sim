# Space Sim (SDL2 + Vulkan) — Starter

> **🧪 Experimental Project**: This repository is an experiment exploring parallel AI agent development workflows. Three specialized AI agents (renderer, simulation, UI) work simultaneously on different parts of the codebase, each creating focused pull requests to break down complex development tasks into manageable, parallel streams.

## Quick Start with Nix (Recommended)

```bash
# Enter development environment
nix develop

# Install opencode CLI
curl -fsSL https://opencode.ai/install | bash

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