#pragma once

#include "IVolumecalculatable.h"
#include "ISurfaceCalculatable.h"

namespace GeometricCalculations
{
	class Parallelepiped : public ISurfaceCalculatable, public IVolumeCalculatable
	{
	private:
		float widthInCm;
		float heightInCm;
		float depthInCm;

	public:
		Parallelepiped(float widthCm, float heightCm, float depthCm);

		virtual float CalculateSurface() override;
		virtual float CalculateVolume() override;
	};
}

