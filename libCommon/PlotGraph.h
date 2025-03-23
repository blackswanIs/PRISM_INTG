#pragma once


#include "config.h"
#include "pGnuPlotU.h"


#include "Slot.h"

#include <memory>
#include <fstream>

namespace alg
{
	//using sig::Slot;
	/*using sig::Complex;
	using sig::Real;
	using sig::Data;*/

	class LIBCOMMON_EXPORTS_API CPlotGraph
	{
	private:
		std::unique_ptr<CpGnuplotU> gnuplot;

	public:
		CPlotGraph();

		//template<typename T >
		//void plotGraph(Slot<T, Complex>& slot)
		//{
		//	std::ofstream out("D:\\Dev\\PRISM_INTG\\data\\temp1.dat");

		//	if (!out)
		//	{

		//	}
		//	else
		//	{
		//		
		//		const auto data = slot.getData().getBuff();
		//		const auto timeTable = slot.getTimeTable();

		//		for (unsigned int i = 0; i < data.size(); i++)
		//		{
		//			out << static_cast<float>(timeTable[i]) << ", " << data[i].real() << ", " << data[i].imag() << "\n";
		//		}


		//	}
		//	
		//	out.close();

		//	gnuplot.get()->cmd(L"set title 'Simple Plot' font '100'");
		//	
		//	gnuplot.get()->cmd(L"set xlabel 'sec' ");
		//	gnuplot.get()->cmd(L"set ylabel 'Amplitude' ");

		//	
		//	//gnuplot.get()->cmd(L"set format x '%.3f s'");
		//	gnuplot.get()->cmd(L"set xtics");	
		//	//gnuplot.get()->cmd(L"set xtics 0.0, 0.1, 1.0");
		//	//gnuplot.get()->cmd(L"set xrange [0:100]");


		//	gnuplot.get()->cmd(L"set style line 1 linecolor rgb \"red\"");
		//	gnuplot.get()->cmd(L"set style line 2 linecolor rgb \"green\"");

		//	//gnuplot.get()->cmd(L"splot 'D:\\Dev\\PRISM_INTG\\data\\temp1.dat' with line");
		//	gnuplot.get()->cmd(L"plot 'D:\\Dev\\PRISM_INTG\\data\\temp1.dat' using 1:2 title 'graph 1' with lines linestyle 1, \\");
		//	gnuplot.get()->cmd(L"'D:\\Dev\\PRISM_INTG\\data\\temp1.dat' using 1:3 title 'graph 2' with lines linestype 2");

		//	getchar();


		//}
	};
}


