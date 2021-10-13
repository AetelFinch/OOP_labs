cmake_minimum_required(VERSION 3.20)
project(Workflow_Executor)

add_executable(Workflow_Executor src/main.cpp src/Parser.cpp)
target_include_directories(Workflow_Executor PUBLIC include)
