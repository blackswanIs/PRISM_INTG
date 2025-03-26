#if 1

#include "libCommon/Manager.h"

#include "libCommon/FrameSchema.h"

#include <chrono>
#include <thread>

using namespace alg;

using cm::ch::Manager;



int main()
{
	/*SigInformation sigInformation(10, 100, 0, 0);

	SubFrame subFrame(10, sigInformation);
	subFrame.execute();*/

	FilterInterface pFilterInterface;
	ResampleInterface pResampleInterface;

	Filter filterModule;
	Resampler resampleModule;

	ProcessorHandler mProcessorHandler;

	mProcessorHandler.addProcessors(
		std::make_tuple(EProcType::T2F, &pFilterInterface, std::make_shared<Filter>()),
		std::make_tuple(EProcType::F2F, &pResampleInterface, std::make_shared<Resampler>()));

	mProcessorHandler.initialize(1000);

	return 0;
}

#endif