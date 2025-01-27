file(GLOB LINALG_TEST_SOURCES *.cpp)

add_executable(linalgtests ${LINALG_TEST_SOURCES})

target_link_libraries(linalgtests PRIVATE linalg PRIVATE gtest gtest_main)
set(CMAKE_BUILD_TYPE Debug)

include(GoogleTest)
gtest_discover_tests(linalgtests)
