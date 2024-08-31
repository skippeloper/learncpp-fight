cmake_minimum_required(VERSION 3.5.0)
project(fight VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(game)

add_executable(fight main.cpp)
target_link_libraries(fight PRIVATE game)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()
