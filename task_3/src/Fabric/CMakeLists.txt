cmake_minimum_required(VERSION 3.20)
project(Factory)

add_library(Factory STATIC Factory.cpp)

target_include_directories(Factory PUBLIC ../../include)
target_include_directories(Factory PUBLIC ../Exception)