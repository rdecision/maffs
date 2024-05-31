#include "linalg/vector.h"
#include "calculus/autodiff/const.h"
#include "calculus/autodiff/var.h"
#include "calculus/autodiff/mul.h"
#include "calculus/autodiff/autodiff_expression_builder.h"

using namespace linalg;

int main()
{
	auto y = AutoDiffExpBuilder::CreateVar("y", 2);
	auto x = AutoDiffExpBuilder::CreateVar("x", 3);

	// test on z = x^2 + 3xy + 1

	auto term_1 = AutoDiffExpBuilder::CreateMul(x, x);
	auto term_2 = AutoDiffExpBuilder::CreateMul(std::make_shared<Const>(3), std::make_shared<Mul>(x, y));
	auto term_3 = AutoDiffExpBuilder::CreateConst(1);


	auto z = AutoDiffExpBuilder::CreateSum(AutoDiffExpBuilder::CreateSum(term_1, term_2), term_3);

	auto str = term_2->toString();

	auto test = term_2->backward(x)->toString();


	return 0;

}