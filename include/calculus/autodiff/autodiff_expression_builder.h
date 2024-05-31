#include "const.h"
#include "var.h"
#include "sum.h"
#include "mul.h"

class AutoDiffExpBuilder
{
public:
	static std::shared_ptr<Const> CreateConst(double value)
	{
		return std::make_shared<Const>(value);
	}

	static std::shared_ptr<Var> CreateVar(std::string name, const std::optional<double>& value = std::nullopt)
	{
		return std::make_shared<Var>(name, value);
	}

	static std::shared_ptr<Sum> CreateSum(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y)
	{
		return std::make_shared<Sum>(x, y);
	}

	static std::shared_ptr<Mul> CreateMul(std::shared_ptr<DifferentiableSymOp> x, std::shared_ptr<DifferentiableSymOp> y)
	{
		return std::make_shared<Mul>(x, y);
	}

	AutoDiffExpBuilder() = delete;

};