file(GLOB LINALG_SOURCES *.cpp)
add_library(linalg ${LINALG_SOURCES})
target_include_directories(linalg PUBLIC ${CMAKE_SOURCE_DIR}/include)