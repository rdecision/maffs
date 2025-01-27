file(GLOB LINALG_BENCHMARK_SOURCES *.cpp)

add_executable(linalgbenchmarks ${LINALG_BENCHMARK_SOURCES})

target_link_libraries(linalgbenchmarks PRIVATE linalg PRIVATE benchmark::benchmark)

target_compile_options(linalgbenchmarks PRIVATE -O3)