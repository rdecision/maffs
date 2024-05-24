cmake_minimum_required(VERSION 3.14)

project(test)

include(FetchContent)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(test_vector "./linalg/test_vector.cpp")
add_executable(test_finite_difference "calc/test_finite_difference.cpp")
target_link_libraries(test_vector GTest::gtest_main linalg)
target_link_libraries(test_finite_difference GTest::gtest_main calculus)

include(GoogleTest)
gtest_discover_tests(test_vector)