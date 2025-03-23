#pragma once
#include "config.h"

namespace libCom
{

	class LIBCOMMON_EXPORTS_API Sinusoidal// : public Data
	{
	private:
		float phase;
		float amplitude;
		float frequency;
		long numberOfSamples;
	public:
		Sinusoidal(float _p, float _a, float _f, long _sNo);

		float getPhase();

		float getAmp();

		float getFreq();

		long getSampleN();
	};
}


