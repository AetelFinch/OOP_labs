cmake_minimum_required(VERSION 3.20)
project(Controller)

add_library(Controller STATIC Controller.cpp)

target_include_directories(Controller PUBLIC ../../interactor)
target_include_directories(Controller PUBLIC ../entities)