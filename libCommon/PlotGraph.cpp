#include "PlotGraph.h"

#include <cstdio>

namespace alg
{

	CPlotGraph::CPlotGraph()
	{
		gnuplot = std::make_unique<CpGnuplotU>(L"C:\\Program Files\\gnuplot\\bin\\wgnuplot.exe");
	}

	
}
