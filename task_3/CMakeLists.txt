cmake_minimum_required(VERSION 3.20)
project(Workflow_executor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Workflow_executor src/main.cpp src/Parser.cpp)
target_include_directories(Workflow_executor PUBLIC src/Workers)
target_include_directories(Workflow_executor PUBLIC src/Exception)
target_include_directories(Workflow_executor PUBLIC include)