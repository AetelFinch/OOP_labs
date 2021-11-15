cmake_minimum_required(VERSION 3.20)
project(Workflow_Executor)

add_executable(Workflow_Executor src/Main/main.cpp)
target_include_directories(Workflow_Executor PUBLIC include)
target_include_directories(Workflow_Executor PUBLIC src/Workers/inc)
target_include_directories(Workflow_Executor PUBLIC src/Fabric)

add_subdirectory(src/Parser)
add_subdirectory(src/Fabric)

target_link_libraries(Workflow_Executor Parser)
target_link_libraries(Workflow_Executor Factory)

