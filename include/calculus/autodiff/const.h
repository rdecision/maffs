#ifndef CONST_H
#define CONST_H

#include <string>
#include "differentiable_sym_op.h"


class Const : public DifferentiableSymOp
{
public:
	Const(double init_value);
	std::shared_ptr<DifferentiableSymOp> backward(std::shared_ptr<DifferentiableSymOp> var) const override;
	double compute() override;
	std::string toString() override;

private:
	double value;
};

#endif