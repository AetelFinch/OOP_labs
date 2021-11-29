cmake_minimum_required(VERSION 3.20)
project(Model)

add_library(Model STATIC Model.cpp)

target_include_directories(Model PUBLIC ../entities/gamefield/GameField.h)
target_include_directories(Model PUBLIC ../entities/Chip.h)
target_include_directories(Model PUBLIC ../entities/GameState.h)