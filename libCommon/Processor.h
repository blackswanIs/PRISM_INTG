#pragma once

#include "Interface.h"

#include <vector>
#include <tuple>

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

	enum class EProcType
	{
		T2T,
		T2F,
		F2F,
		F2T
	};

	struct ProcessorInterface
	{
		virtual~ProcessorInterface() {}
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


		EProcState initialize(sampleInfo inProcSize, EProcType inEProcType, ProcessorInterface* inProcessorInterface)
		{
			if (inProcSize > 0)
			{
				procState = EProcState::RUN_POSSIBLE;

				initializeImpl(inEProcType, inProcessorInterface);
			}
			else
			{
				procState = EProcState::RUN_IMPOSSIBLE;
			}

			return procState;
		}
		EProcState execute()
		{
			if (procState == EProcState::RUN_POSSIBLE)
			{
				executeImpl();

				procState = EProcState::RUNNING;
			}

			return procState;
		}
		EProcState terminate()
		{
			terminateImpl();

			return procState;
		}

		virtual void initializeImpl(EProcType inEProcType, ProcessorInterface* inProcessorInterface) = 0;
		virtual void executeImpl() = 0;

		virtual void terminateImpl() = 0;

	};

	struct FilterInterface : public ProcessorInterface
	{

	};

	class Filter : public Processor
	{
	private:
		FilterInterface param;
	public:
		virtual ~Filter() {}

		void initializeImpl(EProcType inEProcType, ProcessorInterface* inProcessorInterface) override
		{
			param = *static_cast<FilterInterface*>(inProcessorInterface);
		}
		void executeImpl() override
		{

		}
		void terminateImpl() override
		{

		}


	};

	struct ResampleInterface : public ProcessorInterface
	{

	};

	class Resampler : public Processor
	{
	private:
		ResampleInterface param;
	public:
		void initializeImpl(EProcType inEProcType, ProcessorInterface* inProcessorInterface) override
		{
			param = *static_cast<ResampleInterface*>(inProcessorInterface);
		}
		void executeImpl() override
		{

		}
		void terminateImpl() override
		{

		}

	};

	using ProcComponent = std::tuple<EProcType, ProcessorInterface*, std::shared_ptr<Processor>>;
	
	class Overlap
	{
	public:
		Overlap() {}
		virtual ~Overlap() {}
		void initialize() {}

		void doOverlap() {}
		void extractOverlap() {}

	private:

	};


	class ProcessorHandler
	{
	private:
		std::vector<ProcComponent> processors;
		Overlap m_Overlap;

	public:
		ProcessorHandler()
		{
			
		}

		void addProcessor(ProcComponent proc)
		{
			processors.push_back(proc);
		}
		void addProcessors()
		{

		}

		template<typename... ProcComp>
		void addProcessors(ProcComponent firstProcComp, ProcComp... ProcComps)
		{
			addProcessor(firstProcComp);
			addProcessors(ProcComps...);
		}

		void initialize(size_t frameSize)
		{
			m_Overlap.initialize();
			for (auto curProc : processors)
			{
				std::get<2>(curProc)->initialize(frameSize, std::get<0>(curProc), std::get<1>(curProc));
			}
		}

		void execute()
		{
			for (auto curProc : processors)
			{
				if (std::get<0>(curProc) == EProcType::T2T || std::get<0>(curProc) == EProcType::T2F )
				{
					m_Overlap.doOverlap();
				}
				std::get<2>(curProc)->execute();
				if (std::get<0>(curProc) == EProcType::T2T || std::get<0>(curProc) == EProcType::F2T)
				{
					m_Overlap.extractOverlap();
				}
			}
		}

	};

}

