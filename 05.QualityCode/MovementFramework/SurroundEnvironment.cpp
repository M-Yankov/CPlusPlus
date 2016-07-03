#include "SurroundEnvironment.h"

using namespace MovementFramework;

SurroundEnvironment::SurroundEnvironment(unsigned int id, std::string name, float gravity) :
	IdentityObject(id, name),
	gravityInMetersPerSecord(gravity)
{
}

float SurroundEnvironment::getGravity()
{
	return this->gravityInMetersPerSecord;
}
