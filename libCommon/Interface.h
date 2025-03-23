#pragma once

#include "config.h"

#include <complex>

namespace alg
{
	using sampleInfo = unsigned long long;
	using sigInfo = unsigned int;

	using f32 = float;

	template<typename T>
	using IQ_Bufs = std::complex<T>;

	using IQ_Bufsf = IQ_Bufs<f32>;


	class PrismInterface
	{

	};


}

