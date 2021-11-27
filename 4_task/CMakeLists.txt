cmake_minimum_required(VERSION 3.20)
project(4_to_line)

set(CMAKE_CXX_STANDARD 14)

add_executable(4_to_line main.cpp)

target_include_directories(4_to_line PUBLIC entities/gamefield)

add_subdirectory(entities/gamefield)

target_link_libraries(4_to_line GameField)

