#pragma once

#include "../thirdparty/fftw3.h"
#include "complextype.h"

#include <complex>
#include <array>
#include <mutex>
#include <type_traits>
#include <vector>

namespace alg
{
	namespace sigProc
	{
		static std::mutex sMutex;
		template<typename T>
		class Plan
		{
		public:
			T plan;
		};


		template<typename T>
		struct VectorBuf
		{
		public:
			std::vector<T> in;
			std::vector<T> out;

			T* inPtr;
			T* outPtr;

			VectorBuf()
			{
				inPtr = in.data();
				outPtr = out.data();
			}

			template<typename IterType>
			void buffIn(const IterType& in_beg, const IterType& in_end)
			{
				std::copy(in_beg, in_end, in.begin());
			}

			template<typename IterType>
			void buffOut(const IterType& out_beg)
			{
				std::copy(out.begin(), out.end(), out_beg);
			}

		};
		enum class fftDirection
		{
			FWD = FFTW_FORWARD,
			BWD = FFTW_BACKWARD

		};


		template<typename T>
		struct fft_impl : public Plan<fftw_plan>
		{
			VectorBuf<T> memory;
			void plan_1d(fftDirection dir)
			{
				std::scoped_lock<std::mutex> lock(sMutex);
			}

			template<typename IterType>
			void execute(IterType in_beg, IterType in_end, IterType out_beg)
			{
				memory.buffIn(in_beg, in_end);
			}
		};

		template<>
		struct fft_impl<std::complex<double>> : public Plan<fftw_plan>
		{
			VectorBuf<std::complex<double>> memory;

			void plan_1d(fftDirection dir)
			{
				std::scoped_lock<std::mutex> lock(sMutex);
				fftw_init_threads();
				plan = fftw_plan_dft_1d(
					static_cast<int>(2048),
					reinterpret_cast<fftw_complex*>(memory.inPtr),
					reinterpret_cast<fftw_complex*>(memory.outPtr),
					static_cast<int>(-1), FFTW_MEASURE);
			}

			template<typename IterType>
			void execute(IterType in_beg, IterType in_end, IterType out_beg)
			{
				memory.buffIn(in_beg, in_end);
				fftw_execute(plan);

				memory.buffOut(out_beg);
			}
		};


		struct fft
		{
			template<typename IterType>
			fft(IterType in_beg, IterType out_beg, fftDirection dir)
			{
				fft_impl<typename std::iterator_traits<IterType>::value_type> impl;
				impl.plan_1d(dir);
				impl.execute(in_beg, out_beg);
			}
		};
	}
}


