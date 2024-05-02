add_executable(test_vector "linalg/test_vector.cpp")


target_link_libraries(test_vector linalg)
add_test(NAME test_vector COMMAND test_vector)