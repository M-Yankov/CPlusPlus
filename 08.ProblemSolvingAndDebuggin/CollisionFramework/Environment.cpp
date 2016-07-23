#include "Environment.h"

using namespace CollisionFramework;

Environment::Environment(float initalGravity) : gravityPower(initalGravity)
{
}

float CollisionFramework::Environment::getGravity()
{
	return this->gravityPower;
}
