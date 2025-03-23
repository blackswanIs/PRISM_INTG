#pragma once

#include "Interface.h"

namespace alg
{
	struct SigInformation
	{
		sigInfo bandWidth{ 0 };
		sigInfo sampleRate{ 0 };
		sigInfo centerFreq{ 0 };
		sigInfo freqOffset{ 0 };
	};

	class Sig // 신호 정보
	{
	private:

		SigInformation m_sigInformation;


	public:
		
		Sig(SigInformation inSigInformation) :
			m_sigInformation(inSigInformation) {}

		void setSig(SigInformation inSigInformation)
		{
			inSigInformation = inSigInformation;
		}

	};

}
