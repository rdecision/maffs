FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY    https://github.com/google/benchmark.git
  GIT_TAG           d572f4777349d43653b21d6c2fc63020ab326db2 # version 1.7.1
)

FetchContent_MakeAvailable(
  googlebenchmark
)

add_subdirectory(linalg)
#add_subdirectory(calculus)