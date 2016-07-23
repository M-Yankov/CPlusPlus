#include <iostream>
#include "EnergyCalculator.h"

using namespace CollisionFramework;

/// <summary>
/// http://hyperphysics.phy-astr.gsu.edu/hbase/flobj.html
/// http://www.one-school.net/Malaysia/UniversityandCollege/SPM/revisioncard/physics/forceandmotion/images/gravitationalpeformula.png
/// Collision detector is not implemented.
/// </summary>
/// <returns></returns>
int main()
{
	Environment earth;
	Object testObject = Object(17.1f);
	float height = 3.4f;
	std::cout << EnergyCalculator::calculatePotentialEnergy(earth, testObject, height) << std::endl;
	std::cout << EnergyCalculator::calculateKineticEnergy(earth, testObject, height) << std::endl;
	return 0;
}