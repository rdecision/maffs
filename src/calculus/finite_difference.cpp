#include "../../include/calculus/finite_difference.h"

double calculus::central_diff(std::function<double(double)> f, double a, double h)
{
	return (f(a + h) - f(a - h)) / 2*h
}

double calculus::first_order_upwind(std::function<double(double)> f, double a, double h)
{
	return (f(a + h) - f(a)) / h;
}
