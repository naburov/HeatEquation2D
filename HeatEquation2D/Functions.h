#pragma once
#include <string>

double** directSimulation(double** prev, double xDelta, double yDelta, double timeDelta, double alpha, int nRows, int nCols);
void printArray(double** arr, int nRows, int nCols);
void writeStructuredGrid(const std::string& filename, double** arr, int nRows, int nCols);