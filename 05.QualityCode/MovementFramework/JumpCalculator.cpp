#include <math.h>

#include "JumpCalculator.h"

using namespace MovementFramework;

JumpCalculator::JumpCalculator()
{
}

float JumpCalculator::calculateJumpHeight(Character & character, SurroundEnvironment & environment)
{
	// h = (Vo^2) / (2*g);
	// h - stands for finalResult.
	// Vo - is initial speed.
	// g - is gravity.
	
	float jumpSpeedInMeters = character.getJumpSpeed() / 3.6;

	float jumpHeight = std::pow(jumpSpeedInMeters, 2) / (2 * environment.getGravity());
	return jumpHeight;
}

float JumpCalculator::calculateJumpTime(Character & character, SurroundEnvironment & environment)
{
	float jumpSpeedInMeters = character.getJumpSpeed() / 3.6;

	float jumpTime = (jumpSpeedInMeters / environment.getGravity()) * 2;
	return jumpTime;
}

bool JumpCalculator::isCapableToJumpOn(Character & character, SurroundEnvironment & environment, float heightToJump)
{
	float jumpHeigth = calculateJumpHeight(character, environment);
	
	// Here it should depends on many factors.
	// Example somewhere the true can be: jumpHeigth >= heightToJump.
	// But for now I assumed this:
	return jumpHeigth > heightToJump;
}
