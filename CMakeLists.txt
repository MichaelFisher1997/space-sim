# space-sim/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(space_sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTING "Build tests" ON)

# Dependencies (SDL2 + Vulkan dev headers)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
find_path(VULKAN_INCLUDE_DIR vulkan/vulkan.h)
find_library(VULKAN_LIB Vulkan)

add_subdirectory(engine/renderer)
add_subdirectory(engine/sim)
add_subdirectory(engine/ui)
add_subdirectory(apps/sandbox)

include(CTest)
if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(engine/renderer/tests)
  add_subdirectory(engine/sim/tests)
endif()