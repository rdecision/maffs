#include <gtest/gtest.h>
#include "../../include/calculus/finite_difference.h"


TEST(test_finite_difference, central_diff_is_correct)
{
	double result = calculus::central_diff([](double x) -> double { return x * x; }, 5, 0.1);
	ASSERT_EQ(result, 10.0);
}

