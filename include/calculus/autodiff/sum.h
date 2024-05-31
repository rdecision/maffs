#ifndef SUM_H
#define SUM_H

#include "differentiable_sym_op.h"

class Sum : public DifferentiableSymOp
{
public:
	Sum(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y);
	std::shared_ptr<DifferentiableSymOp> backward(std::shared_ptr<DifferentiableSymOp> var) const override;
	double compute() override;
	std::string toString() override;

private:
	std::shared_ptr<DifferentiableSymOp> x;
	std::shared_ptr<DifferentiableSymOp> y;
};

#endif