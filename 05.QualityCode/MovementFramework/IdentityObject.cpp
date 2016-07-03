#include "IdentityObject.h"

using namespace MovementFramework;

IdentityObject::IdentityObject(unsigned int identifier, std::string objectName) :
	id(identifier),
	name(objectName)
{
}

unsigned int IdentityObject::getIdentifier()
{
	return this->id;
}

std::string IdentityObject::getName()
{
	return this->name;
}

