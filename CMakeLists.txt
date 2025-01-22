cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(maffs)

include(FetchContent)
add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("benchmark")


