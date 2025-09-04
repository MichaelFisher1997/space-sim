add_library(ui_mock STATIC UiMock.cpp)
target_include_directories(ui_mock PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(ui_mock PUBLIC)