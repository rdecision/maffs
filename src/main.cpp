#include "../include/linalg/vector.h"
#include "../include/linalg/matrix.h"

using namespace linalg;

int main()
{
	auto x = Vector<double, 2>::Random();

	Matrix a = Matrix();

	auto c = x * a;
	return 0;


}