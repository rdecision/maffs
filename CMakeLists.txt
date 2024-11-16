cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(maffs)

include_directories(include)
add_subdirectory("test")

file(GLOB LIN_ALG "src/linalg/*.cpp")
file(GLOB_RECURSE CALCULUS "src/calculus/*.cpp")

file(GLOB_RECURSE EVERY "src/*.cpp")

add_library(linalg ${LIN_ALG})
add_library(calculus ${CALCULUS})
add_library(every ${EVERY})


add_executable(maffs "src/main.cpp")
target_link_libraries(maffs every)
