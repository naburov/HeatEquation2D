#define min(x,y) (((x) < (y)) ? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <sstream>  

#include "Consts.h"
#include "Functions.h"

int main()
{
	auto xDelta = a / nCols;
	auto yDelta = b / nRows;
	auto timeDelta = min(xDelta, yDelta) * min(xDelta, yDelta) / (4 * alpha);

	double** field = new double* [nRows];
	for (size_t i = 0; i < nRows; ++i) {
		field[i] = new double[nCols];
		std::fill_n(field[i], nCols, T0);
	}
	std::fill_n(field[(size_t)(nRows - 1)], nCols, Tya);
	const std::string filename = "./out/output";
	
	int filecounter = 0;
	std::stringstream ss;
	ss << filename << std::setfill('0') << std::setw(5) << filecounter++ << ".vti";
	

	writeStructuredGrid(ss.str(), field, nRows, nCols);
	for (double t = 0.0; t < tLast; t += timeDelta) {
		ss.str(std::string());
		ss << filename << std::setfill('0') << std::setw(5) << filecounter++ << ".vti";
		//std::cout << ss.str() << std::endl;

		std::cout << "Starting iteration t=" << t << "\r" << std::flush;
		field = directSimulation(field, xDelta, yDelta, timeDelta, alpha, nRows, nCols);
		writeStructuredGrid(ss.str(), field, nRows, nCols);
	}
	

	return 0;
}