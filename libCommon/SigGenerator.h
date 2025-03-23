#pragma once
#include "config.h"
#include "Sinusoidal.h"

#include <complex>
#include <cmath>

namespace libCom
{
	class LIBCOMMON_EXPORTS_API SigGenerator : public Sinusoidal
	{
	private:
		
		float samplingRate;

	public:
		SigGenerator(float _sR, float _p, float _a, float _f, long _sNo);

	};
}
