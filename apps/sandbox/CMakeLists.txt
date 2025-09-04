add_executable(sandbox main.cpp)
target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(sandbox PRIVATE renderer_mock sim_mock ui_mock)
target_compile_definitions(sandbox PRIVATE SDL_MAIN_HANDLED)

# Link SDL2 and Vulkan dynamically for future; mocks don't use them yet.
target_include_directories(sandbox PRIVATE ${SDL2_INCLUDE_DIRS} ${VULKAN_INCLUDE_DIR})
target_link_libraries(sandbox PRIVATE ${SDL2_LIBRARIES} ${VULKAN_LIB})