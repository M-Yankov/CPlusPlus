#pragma once

namespace CollisionFramework
{
	class Object
	{
	private:
		float massInKg;
	public:
		Object(float initalMass = 0.0001f);
		float getMass();
	};
}

