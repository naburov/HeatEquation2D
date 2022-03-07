#include "Functions.h"`
#include <iostream>
#include "Consts.h"

double** directSimulation(double** prev, double xDelta, double yDelta, double timeDelta, double alpha, int nRows, int nCols) {
	double** next = new double* [nRows];
	for (int i = 0; i < nRows; ++i)
		next[i] = new double[nCols];

	// T at y=a is T1
	std::fill_n(next[nRows - 1], nCols, Tya);

	for (int i = 1; i < nRows - 1; i++)
		for (int j = 1; j < nCols - 1; j++) {
			next[i][j] = prev[i][j] + timeDelta * alpha * (prev[i][j - 1] - 2 * prev[i][j] + prev[i][j + 1]) / (xDelta * xDelta)
				+ timeDelta * alpha * (prev[i - 1][j] - 2 * prev[i][j] + prev[i + 1][j]) / (yDelta * yDelta);
		}



	// dT/dx = 0 at x = 0
	for (int i = 0; i < nRows; i++) {
		next[i][0] = next[i][1];
	}

	// dT/dx = 0 at x = b
	for (int i = 0; i < nRows; i++) {
		next[i][nCols - 1] = next[i][nCols - 2];
	}

	// dT/dy = 0 at y=0
	for (int j = 0; j < nCols; j++) {
		next[0][j] = next[1][j];
	}

	return next;
}

