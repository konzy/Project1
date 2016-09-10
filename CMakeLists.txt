cmake_minimum_required(VERSION 3.5)
project(Project1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Student.cpp Student.h Logger.cpp Logger.h)
add_executable(Project1 ${SOURCE_FILES})