#pragma once

namespace GeometricCalculations
{
	class ISurfaceCalculatable
	{
	public:
		ISurfaceCalculatable() {};
		virtual float CalculateSurface()
		{
			return 0;
		}
	};
}