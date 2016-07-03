#pragma once
#include "IdentityObject.h"

namespace MovementFramework
{
	class Character : public IdentityObject
	{
	private:
		float massInKg;
		float jumpSpeedInKMs;
	public:
		Character(unsigned int id, std::string name, float mass, float jumpSpeed);	
	
		/// <summary>
		/// Gets the mass of the character.
		/// </summary>
		/// <returns>Returns the mass in Kg.</returns>
		float getMass();
	
		/// <summary>
		/// Gets the jump speed of the character.
		/// </summary>
		/// <returns>Returns jump speed in Km.</returns>
		float getJumpSpeed();
	};
}