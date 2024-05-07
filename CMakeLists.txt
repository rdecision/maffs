cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(maffs)


include_directories(include)
add_subdirectory("test")

file(GLOB LIN_ALG "src/linalg/*.cpp")
add_library(linalg ${LIN_ALG} "include/hardware_check.h")

add_executable(maffs "src/main.cpp" "include/hardware_check.h")
target_link_libraries(maffs linalg)
