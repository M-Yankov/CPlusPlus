#pragma once
#include "IPerimeterCalulatable.h"
#include "ISurfaceCalculatable.h"

#define _USE_MATH_DEFINES

#include <math.h>

namespace GeometricCalculations
{
	class Circle : public IPerimeterCalulatable, public ISurfaceCalculatable
	{
	private:
		float radius;
	
	public:
		Circle(float radiusCm);

		virtual float CalculateSurface() override;
		virtual float CalculatePerimeter() override;
	};
}
