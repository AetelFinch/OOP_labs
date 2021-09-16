cmake_minimum_required(VERSION 3.20)
project(pack_1)

add_subdirectory(googletest-release-1.11.0)
include_directories(googletest-release-1.11.0/googletest/include/gtest)

add_compile_options(-std=gnu++0x)
add_executable(pack_1 main.cpp TritSet.cpp TritSet.h)
target_link_libraries(pack_1 gtest gtest_main)

set(CMAKE_CXX_STANDARD 17)