#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

namespace linalg
{
	template<typename T, size_t N>
	class Vector
	{
	public:
		Vector<T, N> operator+(const Vector<T, N>& a)
		{
			if (size() != a.size())
				throw std::runtime_error("Vector sizes are not equal.");

			auto result = Vector<T, N>();

			for (int i = 0; i < size(); ++i)
			{
				result.data[i] = a.data[i] + data[i];
			}

			return result;
		}

		size_t size() const
		{
			return N;
		}


	private:
		T data[N];
	};
}


#endif






