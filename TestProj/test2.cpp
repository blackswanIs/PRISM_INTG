#if 0

#include <vector>
#include <algorithm>

#include "libCommon/Slot.h"
#include "libCommon/PlotGraph.h"

#include "libCommon/procFFT.h"
#include "libCommon/wrapFFT.h"

using alg::sig::Slot;
using alg::sig::Real;
using alg::sig::Complex;

using alg::util::fft::impl::fft;
using alg::util::fft::impl::fftDirection;

int main()
{
	
	double bandWidth = 1.0E3;
	double sampleRate = 1.0E3;
	double centerFreq = 500.0E6;

	double toneFreq = 100;
	double sigLevel = -70;

	size_t numOfSamples = 10E3;

	Slot<double, Complex> slotB(bandWidth, sampleRate, centerFreq, toneFreq);
	
	std::vector<std::complex<double>> out(10000);
	std::vector<std::complex<double>> in(10000);

	slotB.Gen(numOfSamples);
	
	auto data = slotB.getData();
	
	constexpr size_t fftBin = 2048;
	
	
	//fft(data.begin(), data.begin() + fftBin, fftDirection::FWD);
	fft<fftBin>(data.begin(), out.begin(), fftDirection::FWD);

	//fft<1024, float>

	//auto temp = reinterpret_cast<fftwf_complex*>(&in.begin()[0]);

	//for (int i = 0; i < 10; i++)
	//{
	//	fftwf.plan_1d(data.begin() + i * 1000,
	//		data.begin() + (i + 1) * 1000,
	//		out.begin() + i * 1000 );
	//}
	//

	//
	// 
	// alg::CPlotGraph plotModule;
	//plotModule.plotGraph(slotB);
	

	return 0;
}

#endif