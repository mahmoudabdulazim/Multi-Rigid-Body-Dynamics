#include <blaze/math/StaticMatrix.h>
#include <blaze/math/StaticVector.h>
#include <initializer_list>
#include <iostream>

using namespace std;

using blaze::StaticMatrix;
using blaze::StaticVector;

namespace RGD
{
	template<typename Type>
	class SO3
	{
		public:
			inline Type& operator()(size_t i, size_t j){ return data(i,j); }

			inline const Type& operator()(size_t i, size_t j) const	{ return data(i,j); }

			inline SO3(){	}

			inline SO3(std::initializer_list<std::initializer_list<Type>> list)
			{
				data = StaticMatrix<Type,3UL,3UL,blaze::rowMajor>(list);
			}

			inline SO3(StaticMatrix<Type,3UL,3UL,blaze::rowMajor> input_data)
			{
				this->data = input_data;
			}

			inline SO3<Type> operator*(const SO3<Type>& R)
			{
				return SO3<Type> ((this->data)*R.data);
			}

			inline void operator*=(const SO3<Type>& R)
			{
				this->data *= R.data;
			}

			inline void operator=(const SO3<Type>& RHS)
			{
				this->data = RHS.data;
			}

			inline SO3<Type> operator/(const SO3<Type>& R)
			{
				return SO3<Type> (blaze::trans(this->data)*R.data);
			}

		private:
			StaticMatrix<Type,3UL,3UL,blaze::rowMajor> data;
	};

	inline ostream& operator<<(ostream& os,const SO3<Type>& mat)
	{
		os << "[ ";
		for (size_t i = 0UL; i<3;i++)
		{
			for (size_t j = 0UL; j < 3; j++)
			{
				os << mat(i,j);
			}
		}
	}
}
