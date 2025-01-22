#ifndef GAUSSIAN_ELIM_H
#define GAUSSIAN_ELIM_H


namespace linalg::solvers
{

template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template <typename T, size_t rows, size_t cols>
class GaussianEliminationSolver
{
	static Vector<T, rows> solve(Matrix<T, rows, cols>& matrix, )
	{
		
	}
};
}

#endif