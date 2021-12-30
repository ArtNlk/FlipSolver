enable_testing()

include_directories(..)

add_executable(
  FlipTests
  test_test.cc
  DynamicSparseMatrixTests.cc
  FluidGridTests.cc
  SparseMatrixTests.cc
)

target_link_libraries(
  FlipTests
  gtest_main
  FlipSolver
)

include(GoogleTest)
gtest_discover_tests(FlipTests)
