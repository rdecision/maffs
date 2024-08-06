#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <array>
#include <random>


namespace linalg {

template<typename T>
concept numeric = std::is_arithmetic_v<T>;

template<numeric T, size_t N>
class Vector
{
public:
	Vector(bool is_row = false) : is_row(is_row) {}

	Vector(std::initializer_list<T> init, bool is_row = false) : is_row(is_row)
	{
		if (init.size() != N)
			throw std::invalid_argument("Initialiser list does not match size of vector");

		auto it = init.begin();
		for (size_t i = 0; i < N; ++i)
			data[i] = *it++;
	}

	size_t size() const { return N; }

	std::pair<int, int> dim() const { return dimension; }

	static Vector random(double min = 0, double max = 1, bool is_row_vector = false)
	{
		std::default_random_engine re;
		std::uniform_real_distribution distribution(min, max);

		auto result = Vector<T, N>(is_row_vector);

		for (int i = 0; i < N; ++i)
		{
			if constexpr (std::is_same_v<T, double>)
				result[i] = distribution(re);
		}

		return result;
	}

	Vector<T, N> operator+(const Vector<T, N>& a) 
	{
		static_assert(this.dim == a.dim);
		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] + data[i];
		}

		return result;
	}

	Vector<T, N> operator-(const Vector<T, N>& a) 
	{
		static_assert(this.dim == a.dim);
		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] - data[i];
		}

		return result;
	}

	double dot(const Vector<T, N>& a)
	{
		double res = 0;
		for (int i = 0; i < N; i++)
		{
			
		}
		return res;
	}

	Vector<T, 3> cross(const Vector<T, 3>& other)
	{

		return Vector<T, 3> {
			(this[1] * other[2] - this[2] * other[1]),
			(this[2] * other[0] - this[0] * other[2]),
			(this[0] * other[1] - this[1] * other[0])
		};
	}

	T& operator[](int i)
	{
		if (i > data.size() - 1)
			throw std::out_of_range("Index is out of range");

		return data[i];
	}

	bool operator==(const Vector<T, N>& other)
	{
		return (this.is_row == other.is_row) &&
			(this[0] == other[0]) &&
			(this[1] == other[1]) &&
			(this[2] == other[2]);
	}

private:
	std::array<T, N> data {};

	bool is_row;

	constexpr int rows = is_row ? 1 : N;

	constexpr int cols = is_row ? N : 1;

	constexpr std::pair<int, int> dimension = std::pair(rows, cols);
};



}

#endif






