cmake_minimum_required(VERSION 3.20)
project(Parser)

add_library(Parser STATIC Parser.cpp)

target_include_directories(Parser PUBLIC ../../include)
target_include_directories(Parser PUBLIC ../Exception)