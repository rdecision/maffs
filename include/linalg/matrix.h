#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
namespace linalg
{
template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template<numeric T, size_t rows, size_t cols>
class Matrix
{
public:

private:



};
	
}

#endif
