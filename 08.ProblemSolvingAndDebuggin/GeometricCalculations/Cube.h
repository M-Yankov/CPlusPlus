#pragma once

#include "ISurfaceCalculatable.h"
#include "IVolumecalculatable.h"

namespace GeometricCalculations
{
	class Cube : public ISurfaceCalculatable, public IVolumeCalculatable
	{
	private:
		float side;
	public:
		Cube(float sideInCm);
		virtual float CalculateSurface() override;
		virtual float CalculateVolume() override;
	};
}