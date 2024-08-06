#include <utility>
#include <format>
#include "calculus/autodiff/sum.h"
#include "calculus/autodiff/mul.h"


Mul::Mul(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y)
{
	this->f = std::move(x);
	this->g = std::move(y);
}

std::shared_ptr<DifferentiableSymOp> Mul::backward(std::shared_ptr<DifferentiableSymOp> var) const
{

	auto f_prime = f->backward(var);
	auto g_prime = g->backward(var);

	auto term_1 = std::make_shared<Mul>(f, g_prime);
	auto term_2 = std::make_shared<Mul>(g, f_prime);

	auto res = std::make_shared<Sum>(term_1, term_2);
	return res;
}

double Mul::compute()
{
	return f->compute() * g->compute();
}

std::string Mul::toString()
{
	return std::format("({} * {})", f->toString(), g->toString());
}
