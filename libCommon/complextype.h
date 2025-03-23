#pragma once

#include <complex>
#include <vector>

namespace alg
{
	namespace util
	{

		using i16 = short;
		using i32 = int;

		using d32 = float;
		using d64 = double;

		template<typename T> using cx = std::complex<T>;

		using cxi16 = cx<i16>;
		using cxi32 = cx<i32>;

		using cxd32 = cx<d32>;
		using cxd64 = cx<d64>;
		

		template<typename T> using vec = std::vector<T>;

		using vecCxi16 = vec<cxi16>;
		using vecCxi32 = vec<cxi32>;
		using vecCxd32 = vec<cxd32>;
		using vecCxd64 = vec<cxd64>;




	}


}