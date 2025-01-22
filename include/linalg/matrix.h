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
		// try row major for now
		for (size_t i = 0; i < init.size(); ++i)
		{
			for (size_t j = 0; j < init.size(); ++j)
			{
				data[rows * i + j] = *((*(init.begin() + i)).begin() + j);
			}
		}
	}

	Matrix(std::array<T, rows * cols> init) : data{init}
	{
	}

	T operator()(uint8_t i, uint8_t j)
	{
		return data[rows * i + j];
	}

	Matrix<T, rows, cols> operator+(const Matrix<T, rows, cols>& other)
	{
		std::array<T, rows * cols> new_data;

		std::transform(
			this.data.begin(), this.data.end(),
			other.data.begin(), other.data.end(),
			new_data.begin(), [](int a, int b) { return a + b; });

		return Matrix(new_data);
	}

	Matrix<T, rows, cols> operator-(const Matrix<T, rows, cols>& other)
	{
		std::array<T, rows * cols> new_data;

		std::transform(
			this.data.begin(), this.data.end(),
			other.data.begin(), other.data.end(),
			new_data.begin(), [](int a, int b) { return a - b; });

		return Matrix(new_data);
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
		uint8_t row_1_end = row_1_start + cols - 1;
		uint8_t row_2_start = row_idx_2 * cols;
		uint8_t row_2_end = row_2_start + cols - 1;

		std::copy(
			data.begin() + row_1_start,
			data.begin() + row_1_end,
			temp.begin());
	}

	void swap_cols(uint8_t row_idx_1, uint8_t row_idx_2)
	{
		
	}

private:
	std::array<T, rows * cols> data {};
};
	
}

#endif
