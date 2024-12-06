cmake_minimum_required(VERSION 3.14)

project(test)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)


file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/test/**/*.cpp")


foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    get_filename_component(TEST_DIR ${TEST_FILE} DIRECTORY)
    add_executable(${TEST_NAME} ${TEST_FILE})


    if(TEST_DIR MATCHES ".*/test/linalg.*")
        target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main linalg)
    elseif(TEST_DIR MATCHES ".*/test/calc.*")
        target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main calculus)
    else()
        target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main) # Default
    endif()

    gtest_discover_tests(${TEST_NAME})
endforeach()
