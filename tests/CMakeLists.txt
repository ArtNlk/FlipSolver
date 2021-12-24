enable_testing()

include_directories(..)

add_executable(
  hello_test
  test_test.cc
)

target_link_libraries(
  hello_test
  gtest_main
  FlipSolver
)

include(GoogleTest)
gtest_discover_tests(hello_test)
