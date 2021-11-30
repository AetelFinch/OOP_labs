cmake_minimum_required(VERSION 3.20)
project(Player)

add_library(Player STATIC HumanPlayerImpl.cpp BotPlayerImpl.cpp)
