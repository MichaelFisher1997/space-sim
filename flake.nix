{
  description = "SpaceSim - C++ SDL2 + Vulkan space simulation with AI agents";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # Build tools
            cmake
            ninja
            gcc
            gnumake

            # Graphics and windowing
            SDL2
            vulkan-loader
            vulkan-tools
            mesa

            # Development tools
            git
            pkg-config

            # Optional: for development
            clang-tools # for clang-format
            valgrind # for memory debugging
          ];

          shellHook = ''
            echo "SpaceSim development environment loaded!"
            echo "Available commands:"
            echo "  cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release"
            echo "  cmake --build build"
            echo "  ctest --test-dir build"
          '';
        };

        packages.default = pkgs.stdenv.mkDerivation {
          pname = "spacesim";
          version = "0.1.0";
          src = self;

          nativeBuildInputs = with pkgs; [
            cmake
            ninja
            pkg-config
          ];

          buildInputs = with pkgs; [
            SDL2
            vulkan-loader
            mesa
          ];

          configurePhase = ''
            cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
          '';

          buildPhase = ''
            cmake --build build
          '';

          installPhase = ''
            mkdir -p $out/bin
            cp build/apps/sandbox/sandbox $out/bin/
            cp build/apps/contract_check/contract_check $out/bin/
          '';
        };
      });
}