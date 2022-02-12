cmake_minimum_required(VERSION 3.14)

project(FlipSolver LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests)

set(HEADERS
    linearindexable3d.h
    fluidgrid.h
    flipsolver.h
    fluidcell.h
    vector2d.h
    vector3d.h
    sparsematrix.h
    dynamicsparsematrix.h
    pcgsolver.h
    vmath.h)

set(SOURCES
    linearindexable3d.cpp
    fluidgrid.cpp
    flipsolver.cpp
    fluidcell.cpp
    vector2d.cpp
    vector3d.cpp
    sparsematrix.cpp
    dynamicsparsematrix.cpp
    pcgsolver.cpp
    vmath.cpp)

add_library(FlipSolver STATIC
  ${HEADERS}
  ${SOURCES}
)

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
