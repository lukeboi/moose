# cmake_minimum_required(VERSION <specify CMake version here>)
project(moose)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(include/maddy)

add_executable(moose main.cpp)