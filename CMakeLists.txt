cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

project(maffs)


include_directories(include)
add_subdirectory("test")

file(GLOB LIN_ALG "src/linalg/*.cpp")
add_library(linalg ${LIN_ALG})

add_executable(maffs "src/main.cpp")
