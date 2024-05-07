#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <array>
#include <random>
#include <chrono>

namespace linalg {

template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template<numeric T, size_t N>
class Vector
{
public:



	Vector(T nums[N])
	{
			
	}

	Vector(std::initializer_list<T> init)
	{
		if (init.size() != N)
			throw std::invalid_argument("Initialiser list does not match size of vector");

		auto it = init.begin();
		for (size_t i = 0; i < N; ++i)
			data[i] = *it++;
	}

	size_t size() const { return N; }

	static Vector Random(double min = 0, double max = 1, bool is_row_vector = false)
	{
		auto result = Vector<T, N>(is_row_vector);

		for (int i = 0; i < N; ++i)
		{
			if constexpr (std::is_same_v<T, double>)
			result[i] = static_cast<T>(rand());
		}

		return result;
	}

	Vector<T, N> operator+(const Vector<T, N>& a) 
	{
		if (size() != a.size())
			throw std::runtime_error("Vector sizes are not equal.");

		Vector<T, N> result = Vector<T, N>(true);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] + data[i];
		}

		return result;
	}


	T operator[](int i)
	{
		if (i > data.size() - 1)
			throw std::out_of_range("Index is out of range");

		return data[i];
	}


private:
	Vector(bool is_row = false) : is_row(is_row) {}
	std::array<T, N> data {};
	bool is_row;
};



}

#endif






