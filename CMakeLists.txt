cmake_minimum_required (VERSION 3.8)

project(maffs)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_subdirectory("test")

file(GLOB LIN_ALG "src/linalg/*.cpp")
add_library(linalg ${LIN_ALG})

add_executable(maffs "src/main.cpp")



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET maffs PROPERTY CXX_STANDARD 20)
endif()
