#pragma once

#include "Car.h"

class Mechanic
{
public:
	void RepairCar(Car &car);	
	float RepairCost(Car &car);
};
