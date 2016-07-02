#pragma once
#include <iostream>

class IdentityObject
{
protected:
	unsigned int id;
	std::string name;
public:
	IdentityObject(unsigned int identifier, std::string objectName);
	unsigned int getIdentifier();
};

