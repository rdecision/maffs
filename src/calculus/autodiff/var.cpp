#include <regex>
#include "calculus/autodiff/var.h"
#include "calculus/autodiff/const.h"


Var::Var(std::string name, std::optional<double> value)
{
	if (std::regex_match(name, std::regex("^[A-Za-z]")))
		this->name = name;
	else
		throw std::exception("Invalid variable name.");
	this->value = value;
}

std::shared_ptr<DifferentiableSymOp> Var::backward(std::shared_ptr<DifferentiableSymOp> var) const
{
	if (var->toString() == name) // using a string comparison rather than a typecheck to ensure this is a var is a terrible idea
		return std::make_shared<Const>(1);

	return std::make_shared<Const>(0);
}

double Var::compute()
{
	if (!value.has_value())
	{
		throw std::exception("Autodiff variable value has been accessed before initialisation.");
	}
	return value.value();
}

std::string Var::toString()
{
	return this->name;
}
