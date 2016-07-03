#pragma once
#include "IdentityObject.h"

namespace MovementFramework
{
	class SurroundEnvironment : public IdentityObject
	{
	private:
		float gravityInMetersPerSecord;
	public:
		SurroundEnvironment(unsigned int id, std::string name, float gravity);

		/// <summary>
		/// Gets the gravity of the environment.
		/// </summary>
		/// <returns>Returns the gravity in meters per second squared. (m/s²)</returns>
		float getGravity();
	};
}