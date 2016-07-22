#include <iostream>

#include "GeometricCalculations.h"

using namespace GeometricCalculations;

int main()
{
	Square square = Square(2.1);
	Rectangle rect = Rectangle(2.3, 3.61);
	Circle circle = Circle(3.13);

	Cube cube = Cube(3);
	Sphere sphere = Sphere(1.3);
	Parallelepiped threeDimesionalRectancle = Parallelepiped(2, 3, 4);

	IPerimeterCalulatable * permiterObjects[] = { &square, &rect, &circle };
	ISurfaceCalculatable * surfaceObjects[] = { &square, &rect, &circle, &cube, &threeDimesionalRectancle, &sphere };
	IVolumeCalculatable * volumeObjects[] = { &cube, &threeDimesionalRectancle, &sphere };
	
	InformationPrinter & printer = InformationPrinter();
	
	// It can be 
	for (IPerimeterCalulatable * perimetePtr : permiterObjects)
	{
		printer.printPerimeter(*perimetePtr);
	}

	for (ISurfaceCalculatable * surfacePtr : surfaceObjects)
	{
		printer.printSurface(*surfacePtr);
	}

	for (IVolumeCalculatable * volumePtr : volumeObjects)
	{
		printer.printVolume(*volumePtr);
	}

	return 0;
}
