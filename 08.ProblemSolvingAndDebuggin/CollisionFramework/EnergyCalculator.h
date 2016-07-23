#pragma once
#include "Environment.h"
#include "Object.h"
#include <math.h>

namespace CollisionFramework
{
	class EnergyCalculator
	{
	public:
		EnergyCalculator();
		static float calculatePotentialEnergy(Environment & env, Object & obj, float heightInMeters);
		static float calculateKineticEnergy(Environment & env, Object & obj, float heightInMeters);
	};
}

