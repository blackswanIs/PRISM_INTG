#include "Sinusoidal.h"

namespace libCom
{


	Sinusoidal::Sinusoidal(float _p, float _a, float _f, long _sNo) : phase{ _p }, amplitude{ _a }, frequency{ _f }, numberOfSamples{ _sNo }/*, Data(_sNo) */{}

	float Sinusoidal::getPhase()
	{
		return phase;
	}

	float Sinusoidal::getAmp()
	{
		return amplitude;
	}

	float Sinusoidal::getFreq()
	{
		return frequency;
	}

	long Sinusoidal::getSampleN()
	{
		return numberOfSamples;
	}

}