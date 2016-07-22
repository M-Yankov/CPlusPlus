#pragma once

#include "IPerimeterCalulatable.h"
#include "ISurfaceCalculatable.h"
#include "IVolumecalculatable.h"

#include <iostream>

namespace GeometricCalculations
{
	class InformationPrinter
	{
	public:
		InformationPrinter();

		void printPerimeter(IPerimeterCalulatable & perimeterCalulateObject)
		{
			std::printf("Perimeter %5.5f \n", perimeterCalulateObject.CalculatePerimeter());
		}

		void printSurface(ISurfaceCalculatable & surfaceCalculatableObject)
		{
			std::printf("Surface %5.5f \n", surfaceCalculatableObject.CalculateSurface());
		}

		void printVolume(IVolumeCalculatable & volumeCalculateableObject)
		{
			std::printf("Volume %5.5f \n", volumeCalculateableObject.CalculateVolume());
		}
	};
}

