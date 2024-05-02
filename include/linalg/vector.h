#ifndef VECTOR_H
#define VECTOR_H
#include <type_traits>

namespace linalg
{
	template<typename T>
	class Vector
	{
	private:
		static_assert(std::is_arithmetic_v, "T must be a numeric type");
		T data[];


	public:
		Vector operator+(const Vector& a);
	};
}


#endif






