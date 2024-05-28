#include <gtest/gtest.h>
#include "../../include/linalg/vector.h"


TEST(test_vector, init_list_constructor)
{
	
}

TEST(test_vector, int_vector_addition_is_correct)
{
	linalg::Vector<int, 2> a = { 1, 2 };
	linalg::Vector<int, 2> b = { 3, 4 };


	linalg::Vector<int, 2> result = a + b;

	ASSERT_EQ(result[0], 4);
	ASSERT_EQ(result[1], 6);

}

TEST(test_vector, vector_random_returns_random_vector)
{
	auto a = linalg::Vector<int,3>::Random();
	ASSERT_EQ(1, 1);
}
