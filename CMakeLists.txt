cmake_minimum_required(VERSION 3.14)

project(FlipSolver LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FlipSolver STATIC
  flipsolver.cpp
  flipsolver.h
)

target_compile_definitions(FlipSolver PRIVATE FLIPSOLVER_LIBRARY)
