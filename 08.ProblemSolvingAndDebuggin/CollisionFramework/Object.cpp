#include "Object.h"

using namespace CollisionFramework;
Object::Object(float initialMass) : massInKg(initialMass)
{
}

float Object::getMass()
{
	return this->massInKg;
}
