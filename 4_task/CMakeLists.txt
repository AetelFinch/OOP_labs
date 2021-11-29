cmake_minimum_required(VERSION 3.20)
project(4_to_line)

set(CMAKE_CXX_STANDARD 14)

add_executable(4_to_line main.cpp)

target_include_directories(4_to_line PUBLIC entities/gamefield)
target_include_directories(4_to_line PUBLIC entities/arbiter)
target_include_directories(4_to_line PUBLIC entities/player)
target_include_directories(4_to_line PUBLIC interactor)

add_subdirectory(entities/gamefield)
add_subdirectory(entities/arbiter)
add_subdirectory(entities/player)
add_subdirectory(interactor)

target_link_libraries(4_to_line GameField)
target_link_libraries(4_to_line Arbiter)
target_link_libraries(4_to_line Player)
target_link_libraries(4_to_line Model)
