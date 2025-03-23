#if 1

#include "libCommon/Manager.h"

#include "libCommon/FrameSchema.h"

#include <chrono>
#include <thread>

using cm::ch::Manager;
using alg::SubFrame;
using alg::SigInformation;

int main()
{
	SigInformation sigInformation(10, 100, 0, 0);

	SubFrame subFrame(10, sigInformation);
	subFrame.execute();

	return 0;
}

#endif