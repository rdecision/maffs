#include "calculus/autodiff/const.h"
#include <format>


Const::Const(double init_value) : value(init_value) {}

std::shared_ptr<DifferentiableSymOp> Const::backward(std::shared_ptr<DifferentiableSymOp> var) const
{
	return std::make_shared<Const>(0);
}

double Const::compute()
{
	return value;
}

std::string Const::toString()
{
	return std::format("{}", value);
}
