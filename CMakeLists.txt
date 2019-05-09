cmake_minimum_required(VERSION 3.0)
project(Test)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include lib/googletest-master/googlemock/include src)
add_executable(Test main.cpp src/Solver.cpp src/Solver.h Tests/test.cpp)
target_link_libraries(Test gtest gtest_main)