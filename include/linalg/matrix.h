#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include "vector.h"

namespace linalg
{
template<numeric T, size_t rows, size_t cols>
class Matrix
{
public:
	Matrix(std::initializer_list<std::initializer_list<T>> init)
	{
		size_t i = 0;
		for (const auto& row : init) {
			size_t j = 0;
			for (const auto& val : row) {
				data[cols * i + j] = val;
				++j;
			}
			++i;
		}
	}

	Matrix(std::array<T, rows * cols> init) : data{init}
	{
	}

	T operator()(uint8_t i, uint8_t j)
	{
		return data[cols * i + j];
	}

	Matrix<T, rows, cols> operator+(const Matrix<T, rows, cols>& other)
	{
		std::array<T, rows * cols> new_data;

		std::transform(
			data.begin(), data.end(),
			other.data.begin(),
			new_data.begin(), [](int a, int b) { return a + b; });

		return Matrix(new_data);
	}

	Matrix<T, rows, cols> operator-(const Matrix<T, rows, cols>& other)
	{
		std::array<T, rows * cols> new_data;

		std::transform(
			data.begin(), data.end(),
			other.data.begin(),
			new_data.begin(), [](int a, int b) { return a - b; });

		return Matrix(new_data);
	}

	bool operator==(const Matrix<T, rows, cols>& other)
	{
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (data[i] != other->data[i])
			{
				return false;
			}
		}

		return true;
	}

	Matrix<T, 1, cols> row(int row_num)
	{
		std::array<T, cols> construct{};
		size_t start = cols * (row_num - 1);
		size_t end = cols * row_num; 
		for (size_t i = cols * (row_num - 1); i < cols - 1; --i)
		{
			construct[i] = data[i];
		}

		return Matrix<T, 1, cols>(construct);
	}


	void map_function(std::function<void(T)>& func, uint8_t row_index = -1, uint8_t col_index = -1)
	{
		if (row_index == -1 && col_index == -1)
			std::for_each(data.begin(), data.end(), func);
	}

	void swap_rows(uint8_t row_idx_1, uint8_t row_idx_2)
	{
		/// row_idx arguments are 0 indexed
		std::array<T, cols> temp;

		uint8_t row_1_start = row_idx_1 * cols;
		uint8_t row_1_end = row_1_start + cols;
		uint8_t row_2_start = row_idx_2 * cols;

		std::copy(
			data.begin() + row_1_start,
			data.begin() + row_1_end,
			temp.begin());

		for (size_t i = 0; i < cols; ++i)
		{
			data[row_1_start + i] = data[row_2_start + i];
			data[row_2_start + i] = temp[i];
		}
	}

	void swap_cols(uint8_t row_idx_1, uint8_t row_idx_2)
	{
		
	}

private:
	std::array<T, rows * cols> data {};
};
	
}

#endif
