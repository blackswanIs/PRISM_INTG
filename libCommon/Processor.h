#pragma once

#include "Interface.h"

namespace alg
{
	enum class EProcState
	{
		IDLE,
		RUNNING,
		RUN_POSSIBLE,
		RUN_IMPOSSIBLE
	};

	enum class EDomainState
	{
		TIMEDOMAIN,
		FREQDOMAIN
	};

	class Processor
	{
	private:
		EProcState procState{ EProcState::IDLE };
		EDomainState domainState{ EDomainState ::TIMEDOMAIN};
		sampleInfo procSize;

		sampleInfo overlapSize;
		sampleInfo frontSaveSize;
		sampleInfo backSaveSize;

	public:
		virtual ~Processor() {}

		EProcState initializeImpl(sampleInfo inProcSize)
		{
			if (inProcSize > 0 && procState == EProcState::IDLE)
			{
				procState = EProcState::RUN_POSSIBLE;
			}
			else
			{
				procState = EProcState::RUN_IMPOSSIBLE;
			}

			return procState;
		}
		EProcState executeImpl()
		{
			if (procState == EProcState::RUN_POSSIBLE)
			{
				procState = EProcState::RUNNING;
			}

			return procState;
		}
		EProcState terminateImpl()
		{

			return procState;
		}

		virtual EProcState initialize(sampleInfo inProcSize) = 0;
		virtual EProcState execute() = 0;

		virtual EProcState terminate() = 0;

		EProcState convertT2F()
		{
			if (domainState == EDomainState::TIMEDOMAIN)
			{
				domainState = EDomainState::FREQDOMAIN;
				procState = EProcState::RUN_POSSIBLE;
			}
			else
			{
				procState = EProcState::RUN_IMPOSSIBLE;
			}
			
			return procState;
		}

		EProcState convertF2T()
		{
			if (domainState == EDomainState::FREQDOMAIN)
			{
				domainState = EDomainState::TIMEDOMAIN;
				procState = EProcState::RUN_POSSIBLE;
			}
			else
			{
				procState = EProcState::RUN_IMPOSSIBLE;
			}

			return procState;
		}
	};

	class ProcTime2Freq : public Processor
	{
	private:
	public:
		virtual ~ProcTime2Freq() {}

		EProcState initialize(sampleInfo inProcSize) override
		{
			initializeImpl(inProcSize);
			return convertT2F();
		}
		EProcState execute() override
		{
			return EProcState::RUNNING;
		}
		virtual EProcState executeTime2Freq() = 0;
	};


	class Resampler : public ProcTime2Freq, public Processor
	{
	private:

	public:
		EProcState initialize(sampleInfo inProcSize) override
		{
			return EProcState::RUNNING;
		}

		EProcState execute() override
		{
			return EProcState::RUNNING;
		}


		EProcState terminate() override
		{
			return EProcState::RUNNING;
		}

		EProcState executeTime2Freq() override
		{
			return EProcState::RUNNING;
		}

	};
}

