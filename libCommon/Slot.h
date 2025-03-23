#pragma once

#include "Sig.h"

#include <iostream>
#include <vector>

namespace alg
{
	namespace sig
	{

		//template<typename T, template<typename T> class C >
		//class Slot : Sig
		//{
		//private:
		//	C<T> data;
		//	std::vector<double> timeTable;

		//public:
		//	Slot(sigInfo inbandWidth, sigInfo insampleRate) : Sig(inbandWidth, insampleRate) { }
		//	void Gen(const size_t& N)
		//	{
		//		std::cout << " Slot Sinusodal Sig Gen !! " << std::endl;
		//		auto& dataRef = data.getBuff();

		//		dataRef.resize(N);
		//		timeTable.resize(N);

		//		auto Ts = 1 / getsampleRate();
		//		auto freq = getToneFreq();

		//		auto time = 0.0;
		//		for (size_t i = 0; i < dataRef.size(); i++)
		//		{
		//			time = Ts * i;
		//			dataRef[i] = sin(2 * std::atan(1) * freq * time);
		//			timeTable[i] = time;
		//		}

		//	}
		//	
		//	auto getData() { return data.getBuff(); }
		//	auto getTimeTable() { return timeTable; }
		//};


	}
}


