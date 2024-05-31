#include <utility>
#include <format>
#include "calculus/autodiff/sum.h"
#include "calculus/autodiff/mul.h"


Mul::Mul(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y)
{
	this->x = std::move(x);
	this->y = std::move(y);
}

std::shared_ptr<DifferentiableSymOp> Mul::backward(std::shared_ptr<DifferentiableSymOp> var) const
{
	auto f = x;
	auto f_prime = x->backward(var);
	auto g = y;
	auto g_prime = y->backward(var);

	auto term_1 = std::make_shared<Mul>(f, g_prime);
	auto term_2 = std::make_shared<Mul>(g, f_prime);

	return std::make_shared<Sum>(term_1, term_2);
}

double Mul::compute()
{
	return x->compute() * y->compute();
}

std::string Mul::toString()
{
	return std::format("{} * {}", x->toString(), y->toString());
}
