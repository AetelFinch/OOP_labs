cmake_minimum_required(VERSION 3.20)
project(View)

add_library(View STATIC ConsoleView.cpp)

target_include_directories(Controller PUBLIC ../../interactor)
target_include_directories(Controller PUBLIC ../entities)
