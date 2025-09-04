# apps/contract_check/CMakeLists.txt
add_executable(contract_check main.cpp)
target_include_directories(contract_check PRIVATE ${CMAKE_SOURCE_DIR})
# Only include contracts; do not link module libs