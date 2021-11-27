cmake_minimum_required(VERSION 3.20)
project(GameField)

add_library(GameField STATIC GameField.cpp)

target_include_directories(GameField PUBLIC ../Chip.h)