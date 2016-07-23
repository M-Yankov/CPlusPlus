#pragma once

#include "IPerimeterCalulatable.h"
#include "ISurfaceCalculatable.h"

namespace GeometricCalculations
{
	class Square : public IPerimeterCalulatable, public ISurfaceCalculatable
	{
		float side;
	public:
		Square(float side);
		float CalculatePerimeter() override;
		float CalculateSurface() override;
	};
}