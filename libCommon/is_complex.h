#pragma once
#include <type_traits>
#include <complex>

namespace alg
{
	namespace cm
	{
		namespace detail
		{
			template<class T, T val>
			struct MyStruct
			{
			public:
				static constexpr T value = val;

				/*using value_type = T;
				using type = MyStruct;*/

				using valu_type = std::is_floating_point<float>::value_type;
			};
			

			template<class T, typename U = void>
			struct  is_complex : public std::false_type {};

			template<class T, typename std::enable_if<std::is_floating_point<T>, T > >
			//struct  is_complex : public std::false_type {};


			template<class T>
			using is_complex_v = is_complex<T>::value_type;
		}
	}
}