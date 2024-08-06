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
	Matrix(std::initializer_list<initializer_list<T> init)
	{
		
	}
private:
	std::array<std::array<>, > data {};

};
	
}

#endif
