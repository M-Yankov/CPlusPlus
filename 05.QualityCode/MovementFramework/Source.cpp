#include <iostream>
#include <string>

#include "JumpCalculator.h"

using namespace MovementFramework;

// the formulas is based on SoftUni's forum post: https://softuni.bg/forum/10621/domashno-5-kakva-formula-za-maksimalnata-visochina-na-skoka
// please check is all correct. I'm not good in physics.

void printData(Character & character, SurroundEnvironment & environment, float heightToPassInMeters);

int main()
{
	unsigned int intialStartId = 1;
	const float EarthGravity = 9.81f;

	Character testObject = Character(intialStartId++, "Peter", 85.0f, 10.00f);
	SurroundEnvironment planetEarth = SurroundEnvironment(intialStartId++, "Earth", EarthGravity);

	float heightToPassInMeters = 2;
	printData(testObject, planetEarth, heightToPassInMeters);

	const float AnotherGravity = 1.724f;
	SurroundEnvironment alienPlanet = SurroundEnvironment(intialStartId++, "AlienLandia", AnotherGravity);

	printData(testObject, alienPlanet, heightToPassInMeters);

	Character anotherTestObject = Character(intialStartId++, "George", 75.0f, 7.13f);
	printData(anotherTestObject, alienPlanet, heightToPassInMeters);

	return 0;
}

void printData(Character & character, SurroundEnvironment & environment, float heightToPassInMeters)
{
	std::printf("%s has %0.2f km/h jump speed.\n", character.getName().c_str(), character.getJumpSpeed());

	std::printf(
		"%s can jump: %0.2f meters on the %s where gravity is %0.2f m/s^2.\n",
		character.getName().c_str(),
		JumpCalculator::calculateJumpHeight(character, environment),
		environment.getName().c_str(),
		environment.getGravity());

	std::printf("Time of %s's jump is: %0.2f seconds.\n", character.getName().c_str(), JumpCalculator::calculateJumpTime(character, environment));

	std::cout << "Can " << character.getName() << " pass " << heightToPassInMeters << " meters?" << std::endl;
	std::cout << "A: ";

	if (JumpCalculator::isCapableToJumpOn(character, environment, heightToPassInMeters))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

	std::cout << std::endl << std::string(20, '-') << std::endl;
}