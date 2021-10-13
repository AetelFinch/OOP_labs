add_subdirectory(test/googletest-release-1.11.0)
include_directories(test/googletest-release-1.11.0/googletest/include/gtest)
target_link_libraries(Workflow_executor gtest gtest_main)