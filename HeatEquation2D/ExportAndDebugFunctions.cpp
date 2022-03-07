#include <iostream>
#include <string>

#include <vtkNew.h>
#include <vtkProperty.h>
#include <vtkXMLImageDataWriter.h>
#include <vtkXMLImageDataReader.h>
#include <vtkImageData.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkDoubleArray.h>
#include <vtkNew.h>
#include <vtkRectilinearGrid.h>
#include <vtkRectilinearGridGeometryFilter.h>

#include "Functions.h"
#include "Consts.h"

void printArray(double** arr, int nRows, int nCols) {
	for (int i = 0; i < nRows; ++i)
	{
		for (int j = 0; j < nCols; ++j)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void writeStructuredGrid(const std::string& filename, double** arr, int nRows, int nCols)
{
	vtkNew<vtkImageData> imageData;
	imageData->SetDimensions(nCols, nRows, 1);
	imageData->AllocateScalars(VTK_DOUBLE, 1);

	int* dims = imageData->GetDimensions();

	int z = 0;
	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nCols; x++)
		{
			double* pixel =
				static_cast<double*>(imageData->GetScalarPointer(x, y, z));
			pixel[0] = arr[y][x];
		}
	}


	vtkNew<vtkXMLImageDataWriter> writer;
	writer->SetFileName(filename.c_str());
	writer->SetInputData(imageData);
	writer->Write();
}