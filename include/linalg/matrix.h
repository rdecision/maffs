#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <initializer_list>
#include "vector.h"

namespace linalg
{
template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template<numeric T, size_t rows, size_t cols>
class Matrix
{
public:
	Matrix(std::initializer_list<initializer_list<T>> init)
	{
		// try row major for now
		for (size_t i = 0; i < init.size(); ++i)
		{
			for (size_t j = 0; j < init.size(); ++j)
			{
				data[rows * i + j] = init[i][j]
			}
		}
	}

	Vector<T, cols> row(int row_num)
	{
		std::array<T, cols> construct{};
		size_t start = cols * (row_num - 1);
		size_t end = cols * row_num; 
		for (size_t i = cols * (row_num - 1); i < cols - 1; --i)
		{
			construct[i] = data[i];
		}

		return Vector<T,cols>(construct);
	}
private:
	std::array<rows * cols> data {};

};
	
}

#endif
