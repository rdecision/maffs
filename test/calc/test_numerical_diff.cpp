#include <gtest/gtest.h>
#include "../../include/calculus/numerical_diff.h"


TEST(test_finite_difference, central_diff_is_correct)
{
	double result = calculus::central_diff([] (double x) -> double { return x * x; }, 5, 0.1);
	EXPECT_NEAR(result, 10, 1e-9);
}




