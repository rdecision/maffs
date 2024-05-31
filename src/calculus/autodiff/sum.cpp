#include <format>
#include "calculus/autodiff/sum.h"

Sum::Sum(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y)
{
	this->x = std::move(x);
	this->y = std::move(y);
}

std::shared_ptr<DifferentiableSymOp> Sum::backward(std::shared_ptr<DifferentiableSymOp> var) const
{
	return std::make_shared<Sum>(x->backward(var), y->backward(var));
}

double Sum::compute()
{
	return x->compute() + y->compute();
}

std::string Sum::toString()
{
	return std::format("{} + {}", x->toString(), y->toString());
}
