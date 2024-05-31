#ifndef DIFF_SYM_OPP_H
#define DIFF_SYM_OPP_H

#include <memory>
#include <string>

class DifferentiableSymOp
{
public:
	virtual std::shared_ptr<DifferentiableSymOp> backward(std::shared_ptr<DifferentiableSymOp> var) const = 0;
	virtual double compute() = 0; 
	virtual ~DifferentiableSymOp() = default;
	virtual std::string toString() = 0;
};

#endif