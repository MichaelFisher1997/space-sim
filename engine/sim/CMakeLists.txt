add_library(sim_mock STATIC SimulationMock.cpp)
target_include_directories(sim_mock PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(sim_mock PUBLIC)