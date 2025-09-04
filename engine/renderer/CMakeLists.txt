add_library(renderer_mock STATIC RendererMock.cpp)
target_include_directories(renderer_mock PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(renderer_mock PUBLIC)