cmake_minimum_required(VERSION 3.14)

project(benchmark)


include(FetchContent)

FetchContent_Declare(
	benchmark
	GIT_REPOSITORY https://github.com/google/benchmark.git
	GIT_TAG v1.8.2
)

FetchContent_MakeAvailable(benchmark)

add_executable(benchmark_vector "./linalg/benchmark_vector.cpp")
target_link_libraries(benchmark_vector PRIVATE benchmark::benchmark benchmark::benchmark_main)

