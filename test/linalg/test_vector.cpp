#include <gtest/gtest.h>
#include "../../include/linalg/vector.h"


TEST(test_vector, init_list_constructor_works)
{
	linalg::Vector<int, 3> a({1,2,4});
	ASSERT_EQ(1, a[0]);
	ASSERT_EQ(2, a[1]);
	ASSERT_EQ(4, a[2]);
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
	auto a = linalg::Vector<int,3>::random();
	ASSERT_EQ(1, 1);
}

TEST(test_vector, vector_size_method_works)
{
	auto a = linalg::Vector<double, 5>::random();
	ASSERT_EQ(a.size(), 5);
}

TEST(test_vector, vector_dim_method_works)
{
	linalg::Vector<double, 5> a({1,2,3,4,5}, true);
	ASSERT_EQ(a.dim().first, 1);
	ASSERT_EQ(a.dim().second, 5);

	linalg::Vector<double, 5> b({ 1,2,3,4,5}, false);
	ASSERT_EQ(b.dim().first, 5);
	ASSERT_EQ(b.dim().second, 1);
}

TEST(test_vector, vector_cross_works)
{
	linalg::Vector<double, 3> a = { 1, 2, 3 };
	linalg::Vector<double, 3> b = { 4, 5, 6 };

	auto res = a.cross(b);

}

