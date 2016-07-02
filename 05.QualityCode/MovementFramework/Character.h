#pragma once
#include "IdentityObject.h"

class Character : public IdentityObject
{
private:
	unsigned int mass;
	unsigned int weightInKg;
public:
	Character(unsigned int id, std::string name);
};

