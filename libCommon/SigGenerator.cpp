#include "SigGenerator.h"

namespace libCom
{

	SigGenerator::SigGenerator(float _sR, float _p, float _a, float _f, long _sNo) :samplingRate{ _sR }, Sinusoidal(_p, _a, _f, _sNo) {}

}