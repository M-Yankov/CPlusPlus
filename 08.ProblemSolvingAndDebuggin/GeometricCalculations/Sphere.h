#pragma once
#include "ISurfaceCalculatable.h"
#include "IVolumecalculatable.h"

#define _USE_MATH_DEFINES

#include <math.h>

namespace GeometricCalculations
{
	class Sphere : public ISurfaceCalculatable, public IVolumeCalculatable
	{
	private:
		float radiusInCm;
	public:
		Sphere(float radiusCm);

		virtual float CalculateSurface() override;
		virtual float CalculateVolume() override;
	};

}