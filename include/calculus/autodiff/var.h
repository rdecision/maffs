#ifndef VAR_H
#define VAR_H

#include <optional>
#include <string>

#include "differentiable_sym_op.h"


class Var : public DifferentiableSymOp
{
public:
	Var(std::string name, std::optional<double> value = std::nullopt);
	std::shared_ptr<DifferentiableSymOp> backward(std::shared_ptr<DifferentiableSymOp> var) const override;
	double compute() override;
	std::string toString() override;

private:
	std::optional<double> value;
	std::string name;
};





#endif