#include "EnergyCalculator.h"

using namespace CollisionFramework;

EnergyCalculator::EnergyCalculator()
{
}

float EnergyCalculator::calculatePotentialEnergy(Environment & env, Object & obj, float heightMeters)
{
	return env.getGravity() * obj.getMass() * heightMeters;
}

float EnergyCalculator::calculateKineticEnergy(Environment & env, Object & obj, float heightMeters)
{
	float beforeCalculateVelocity = 2.0f * env.getGravity() * heightMeters;
	float velocity = sqrt(beforeCalculateVelocity);

	float kineticEnergy = (obj.getMass() * pow(velocity, 2)) / 2;
	return kineticEnergy;
}
