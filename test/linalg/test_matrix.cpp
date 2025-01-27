#include <gtest/gtest.h>
#include "linalg/matrix.h"



TEST(MatrixTest, init_list_constructor_works)
{
	auto a = linalg::Matrix<int, 2, 2>({ {1, 2}, {3, 4} });
	ASSERT_EQ(a(0, 0), 1);
	ASSERT_EQ(a(1, 0), 3);
	ASSERT_EQ(a(0, 1), 2);
	ASSERT_EQ(a(1, 1), 4);
}

TEST(MatrixTest, index_operator_works)
{
	auto a = linalg::Matrix<int, 3, 4>({
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
		});

	ASSERT_EQ(a(0, 0), 1);
	ASSERT_EQ(a(0, 1), 2);
	ASSERT_EQ(a(0, 2), 3);
	ASSERT_EQ(a(0, 3), 4);

	ASSERT_EQ(a(1, 0), 5);
	ASSERT_EQ(a(1, 1), 6);
	ASSERT_EQ(a(1, 2), 7);
	ASSERT_EQ(a(1, 3), 8);

	ASSERT_EQ(a(2, 0), 9);
	ASSERT_EQ(a(2, 1), 10);
	ASSERT_EQ(a(2, 2), 11);
	ASSERT_EQ(a(2, 3), 12);
}


TEST(MatrixTest, swap_rows_works)
{
	auto b = linalg::Matrix<int, 3, 2>({ {1,2}, {3,4}, {5,6} });
	b.swap_rows(1, 2);
	ASSERT_EQ(b(0, 0), 1);
	ASSERT_EQ(b(0, 1), 2);
	ASSERT_EQ(b(1, 0), 5);
	ASSERT_EQ(b(1, 1), 6);
	ASSERT_EQ(b(2, 0), 3);
	ASSERT_EQ(b(2, 1), 4);
}

TEST(MatrixTest, matrix_addition_works)
{
	auto a = linalg::Matrix<double, 3, 3>({
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}});

	auto b = linalg::Matrix<double, 3, 3>({ 
		{10, 11, 12},
		{13, 14, 15},
		{16, 17, 18}});

	auto res = a + b;

	ASSERT_EQ(res(0, 0), 11);
	ASSERT_EQ(res(0, 1), 13);
	ASSERT_EQ(res(0, 2), 15);
	ASSERT_EQ(res(1, 0), 17);
	ASSERT_EQ(res(1, 1), 19);
	ASSERT_EQ(res(1, 2), 21);
	ASSERT_EQ(res(2, 0), 23);
	ASSERT_EQ(res(2, 1), 25);
	ASSERT_EQ(res(2, 2), 27);
}

TEST(MatrixTest, matrix_subtraction_works)
{
	auto a = linalg::Matrix<double, 3, 3>({
		{10, 11, 12},
		{13, 14, 15},
		{16, 17, 18} });

	auto b = linalg::Matrix<double, 3, 3>({
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9} });

	auto res = a - b;

	ASSERT_EQ(res(0, 0), 9);
	ASSERT_EQ(res(0, 1), 9);
	ASSERT_EQ(res(0, 2), 9);
	ASSERT_EQ(res(1, 0), 9);
	ASSERT_EQ(res(1, 1), 9);
	ASSERT_EQ(res(1, 2), 9);
	ASSERT_EQ(res(2, 0), 9);
	ASSERT_EQ(res(2, 1), 9);
	ASSERT_EQ(res(2, 2), 9);
}

