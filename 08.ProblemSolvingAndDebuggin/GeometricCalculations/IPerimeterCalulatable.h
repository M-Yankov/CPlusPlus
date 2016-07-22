#pragma once

namespace GeometricCalculations
{
	class IPerimeterCalulatable
	{
	public:
		IPerimeterCalulatable() {};
		virtual float CalculatePerimeter()
		{
			return 0;
		}
	};
}
