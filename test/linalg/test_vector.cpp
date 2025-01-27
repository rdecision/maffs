#include <gtest/gtest.h>
#include "../../include/linalg/vector.h"


TEST(VectorTest, init_list_constructor_works)
{
	linalg::Vector<int, 3> a({1,2,4});
	ASSERT_EQ(1, a[0]);
	ASSERT_EQ(2, a[1]);
	ASSERT_EQ(4, a[2]);
}

TEST(VectorTest, array_constructor_works)
{
	std::array b{1, 2, 4};
	linalg::Vector a(b);
	ASSERT_EQ(1, a[0]);
	ASSERT_EQ(2, a[1]);
	ASSERT_EQ(4, a[2]);
}

TEST(VectorTest, int_vector_addition_is_correct)
{
	linalg::Vector<int, 2> a = { 1, 2 };
	linalg::Vector<int, 2> b = { 3, 4 };


	linalg::Vector<int, 2> result = a + b;

	ASSERT_EQ(result[0], 4);
	ASSERT_EQ(result[1], 6);
}

TEST(VectorTest, double_vector_addition_is_correct)
{
	linalg::Vector<double, 2> a = { 1.0, 2.0 };
	linalg::Vector<double, 2> b = { 3.0, 4.0 };

	linalg::Vector<double, 2> result = a + b;

	ASSERT_DOUBLE_EQ(result[0], 4.0);
	ASSERT_DOUBLE_EQ(result[1], 6.0);
}

TEST(VectorTest, vector_equality_is_correct)
{
	linalg::Vector<double, 2> a = { 1.0, 2.0 };
	linalg::Vector<double, 2> b = { 1.0, 2.0 };

	ASSERT_EQ(a, b);
}

TEST(VectorTest, vector_random_returns_random_vector)
{
	auto a = linalg::Vector<int,3>::random();
	ASSERT_EQ(1, 1);
}

TEST(VectorTest, vector_size_method_works)
{
	auto a = linalg::Vector<double, 5>::random();
	ASSERT_EQ(a.size(), 5);
}

TEST(VectorTest, vector_dim_method_works)
{
	linalg::Vector<double, 5> a({1,2,3,4,5}, true);
	ASSERT_EQ(a.dim().first, 1);
	ASSERT_EQ(a.dim().second, 5);

	linalg::Vector<double, 5> b({ 1,2,3,4,5}, false);
	ASSERT_EQ(b.dim().first, 5);
	ASSERT_EQ(b.dim().second, 1);
}

TEST(TestVector, vector_dot_works)
{
	linalg::Vector<double, 3> a = { 1, 2, 3 };
	linalg::Vector<double, 3> b = { 4, 5, 6 };

	auto res = a.dot(b);

	ASSERT_DOUBLE_EQ(res, 32);
}

TEST(VectorTest, vector_euclidean_norm_works)
{
	linalg::Vector<double, 3> a = { 1.0, 2.0, 3.0 };

	double res = a.euclidean_norm();
	double expected = std::sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0);
	ASSERT_DOUBLE_EQ(res, expected);
}

TEST(VectorTest, vector_cross_works)
{
	linalg::Vector<double, 3> a = { 1, 2, 3 };
	linalg::Vector<double, 3> b = { 4, 5, 6 };

	auto res = a.cross(b);

	auto expected = linalg::Vector<double, 3> { -3, 6, -3 };

	ASSERT_EQ(res, expected);
}

