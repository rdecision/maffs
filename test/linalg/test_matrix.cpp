#include <gtest/gtest.h>
#include "linalg/matrix.h"



TEST(test_matrix, init_list_constructor_works)
{
	auto a = linalg::Matrix<int, 2, 2>({ {1, 2}, {3, 4} });
	ASSERT_EQ(a(0, 0), 1);
	ASSERT_EQ(a(1, 0), 3);
	ASSERT_EQ(a(0, 1), 2);
	ASSERT_EQ(a(1, 1), 4);
}

TEST(test_matrix, swap_rows_works)
{
	auto a = linalg::Matrix<int, 3, 2>({ {1,2}, {3,4}, {5,6} });
	a.swap_rows(1, 2);
	ASSERT_EQ(a(0, 0), 1);
	ASSERT_EQ(a(0, 1), 2);
	ASSERT_EQ(a(1, 0), 5);
	ASSERT_EQ(a(1, 1), 6);
	ASSERT_EQ(a(2, 0), 3);
	ASSERT_EQ(a(2, 1), 4);
}
