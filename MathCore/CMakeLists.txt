cmake_minimum_required(VERSION 3.14)

project(FlipSolver LANGUAGES CXX)

set(HEADERS
    vector2d.h
    vector3d.h)

set(SOURCES
    vector2d.cpp
    vector3d.cpp)

add_library(MathCore STATIC
    ${HEADERS}
    ${SOURCES})
