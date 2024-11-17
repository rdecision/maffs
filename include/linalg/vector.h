#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <array>
#include <random>
#include <optional>

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

	const std::pair<int, int> dim() const { return dimension; }

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
		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] + data[i];
		}
		return result;
	}

	Vector<T, N> operator-(const Vector<T, N>& a) 
	{
		Vector<T, N> result = Vector<T, N>(is_row);
		for (int i = 0; i < size(); ++i)
		{
			result.data[i] = a.data[i] - data[i];
		}

		return result;
	}

	const T& operator[](int i) const
	{
		if (i > data.size() - 1)
			throw std::out_of_range("Index is out of range");

		return data[i];
	}

	T& operator[](int i)
	{
		if (i > data.size() - 1)
			throw std::out_of_range("Index is out of range");

		return data[i];
	}

	bool operator==(const Vector<T, N>& other) const
	{
		for (int i = 0; i < N; ++i)
		{
			if (data[i] != other[i])
				return false;
		}
		return true;
	}

	double dot(const Vector<T, N>& a) const
	{
		double res = 0;
		for (int i = 0; i < N; i++)
		{
			res += a[i] * data[i];
		}

		return res;
	}

	Vector<T, 3> cross(const Vector<T, 3>& other)
	{

		return Vector<T, 3> {
			(data[1] * other[2] - data[2] * other[1]),
				(data[2] * other[0] - data[0] * other[2]),
				(data[0] * other[1] - data[1] * other[0])
		};
	}

	double euclidean_norm() const
	{
		double res = 0;
		for (int i = 0; i < N; ++i)
		{
			res += pow(data[i], 2);
		}
		return sqrt(res);
	}

	auto begin()
	{
		return data.begin();
	}

	auto end()
	{
		return data.end();
	}

private:
	std::array<T, N> data {};

	bool is_row;

	int rows = is_row ? 1 : N;

	int cols = is_row ? N : 1;

	std::pair<int, int> dimension = std::pair(rows, cols);
};

}

#endif






