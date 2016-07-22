#pragma once

namespace GeometricCalculations
{
	class IVolumeCalculatable
	{
	public:
		IVolumeCalculatable() {};
		virtual float CalculateVolume()
		{
			return 0;
		}
	};
}