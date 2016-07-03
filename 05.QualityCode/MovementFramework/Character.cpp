#include "Character.h"

using namespace MovementFramework;

Character::Character(unsigned int id, std::string name, float mass, float jumpSpeed) :
	IdentityObject(id, name),
	massInKg(mass),
	jumpSpeedInKMs(jumpSpeed)
{
}

float Character::getMass()
{
	return this->massInKg;
}

float Character::getJumpSpeed()
{
	return this->jumpSpeedInKMs;
}