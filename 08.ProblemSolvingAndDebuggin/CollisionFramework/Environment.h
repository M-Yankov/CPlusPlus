#pragma once

namespace CollisionFramework
{ 
	float const EARTH_GRAVITY =  9.807;
	
	class Environment
	{
	private:
		float gravityPower;
	public:
		Environment(float gravity = EARTH_GRAVITY);
		float getGravity();
	};
}

