cmake_minimum_required(VERSION 3.14)

project(FlipSolver LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    fluidgrid.h
    flipsolver.h
    fluidcell.h
    vector2d.h
    vector3d.h
    gridmatrix.h
    sparsematrix.h)

set(SOURCES
    fluidgrid.cpp
    flipsolver.cpp
    fluidcell.cpp
    vector2d.cpp
    vector3d.cpp
    gridmatrix.cpp
    sparsematrix.cpp)

add_library(FlipSolver STATIC
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(FlipSolver MathCore)

#set(Boost_USE_STATIC_LIBS        ON)
#set(Boost_USE_DEBUG_LIBS         ON)
#set(Boost_USE_RELEASE_LIBS       ON)
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
#find_package(Boost 1.77.0)
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    target_link_libraries(FlipSolver ${Boost_LIBRARIES})
#endif()

target_compile_definitions(FlipSolver PRIVATE FLIPSOLVER_LIBRARY)
