#pragma once
#include <iostream>

namespace MovementFramework
{
	/// <summary>
	/// Abstract class includes common attributes.
	/// </summary>
	class IdentityObject
	{
	protected:
		unsigned int id;
		std::string name;
	public:
		IdentityObject(unsigned int identifier, std::string objectName);
		unsigned int getIdentifier();
		std::string getName();
	};
}