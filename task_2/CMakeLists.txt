cmake_minimum_required(VERSION 3.20)
project(task_2)

add_subdirectory(googletest-release-1.11.0)
include_directories(googletest-release-1.11.0/googletest/include/gtest)

add_executable(task_2 main.cpp HashTable.cpp HashTable.h)
target_link_libraries(task_2 gtest gtest_main)

set(CMAKE_CXX_STANDARD 17)