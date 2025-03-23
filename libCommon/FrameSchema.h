#pragma once

#include "Sig.h"
#include "Processor.h"

namespace alg
{

	class LIBCOMMON_EXPORTS_API SubFrame : public Sig
	{
	private:
		sampleInfo subFrameSize;
		IQ_Bufsf subFrameData;

	public:
		SubFrame() = delete;
		virtual ~SubFrame() = default;
		SubFrame(sampleInfo inSubFrameSize, SigInformation inSigInformation) :
			subFrameSize(inSubFrameSize), Sig(inSigInformation){}

		void setSubFrame(sampleInfo inSubFrameSize, SigInformation inSigInformation)
		{
			subFrameSize = inSubFrameSize;
			Sig::setSig(inSigInformation);
		}

		
		void initialize(IQ_Bufsf& data, Processor* proc)
		{
			proc->initialize(100);
		}

		void initializes(IQ_Bufsf& data)
		{

		}

		template<class Processor, class... ProcTypes>
		void initializes(IQ_Bufsf& data, Processor* firstProc, ProcTypes... procs)
		{
			initialize(data, firstProc);
			initializes(data, procs...);
		}

		void execute()
		{
			IQ_Bufsf temp(100);
			auto resampleModule = std::make_unique<Resampler>();

			initializes(temp, resampleModule.get(), resampleModule.get());

		}
	};

}

