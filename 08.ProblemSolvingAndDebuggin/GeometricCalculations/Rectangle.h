#pragma once

#include "IPerimeterCalulatable.h"
#include "ISurfaceCalculatable.h"

namespace GeometricCalculations
{
	class Rectangle : public IPerimeterCalulatable, public ISurfaceCalculatable
	{
	private:
		float width;
		float height;
	public:
		Rectangle(float widthCm, float heightCm);
		float CalculatePerimeter() override;
		float CalculateSurface() override;
	};
}

