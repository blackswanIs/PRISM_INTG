#pragma once

#include "config.h"
#include "../thirdparty/fftw3.h"

#include <iterator>
#include <complex>
#include <mutex>

namespace alg
{
	namespace sigProc
	{
		using std::complex;

		template<typename T>
		class Plan
		{
			using Type = T;
		protected:
			T plan;
			size_t fftBin;
		};

		class LIBCOMMON_EXPORTS_API fftwfWrap : public Plan<fftwf_plan>
		{
		public:

			std::mutex m;

			fftwfWrap()
			{
				fftwf_init_threads();
				fftwf_plan_with_nthreads(16);
			}

			template<typename IteratorType,
				typename OIteratorType>
				void plan_1d(IteratorType ibeg, IteratorType iend, OIteratorType obeg)
			{
				m.lock();
				fftBin = std::distance(ibeg, iend);
				//plan = fftwf_plan_dft_1d(fftBin, 
				//	reinterpret_cast<fftwf_complex*>(&ibeg[0]), reinterpret_cast<fftwf_complex*>(&obeg[0]),
				//	FFTW_FORWARD, FFTW_ESTIMATE);
				m.unlock();
			}

			template<typename IteratorType>
			void fft_1d(IteratorType ibeg, IteratorType iend)
			{
				fftwf_execute(plan);
			}
		};
	}
}

