cmake_minimum_required(VERSION 3.20)
project(Arbiter)

add_library(Arbiter STATIC Arbiter.cpp)

target_include_directories(Arbiter PUBLIC ../Chip.h)
target_include_directories(Arbiter PUBLIC ../GameState.h)
target_include_directories(Arbiter PUBLIC ../gamefield/GameField.h)