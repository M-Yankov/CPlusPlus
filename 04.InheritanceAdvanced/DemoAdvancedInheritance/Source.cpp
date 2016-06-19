#include "Mechanic.h"
// #include "Car.h" 
// #include "Man.h" 

#include <iostream>
#include <array>
#include <vector>

/*
class Car;

class Man
{
public:
	void CrashCar(Car &car);
};


class Car
{
private:
	bool isGoodCondition;
public:
	Car(int priceValue) : price(priceValue), isGoodCondition(true) {};

	friend class Mechanic;
	friend void Man::CrashCar(Car &car);
	int price;
};

class Mechanic
{
public:
	void RepairCar(Car &car)
	{
		car.isGoodCondition = true;
	}

	float RepairCost(Car &car)
	{
		if (car.isGoodCondition)
		{
			return 0;
		}

		return car.price * 0.05;
	}
};

void Man::CrashCar(Car &car)
{
	car.isGoodCondition = false;
};
*/

int main()
{
	Car carToCrash = Car(100);

	Mechanic mechanic;
	std::cout << "Before crash repair costs: $" << mechanic.RepairCost(carToCrash) << std::endl;
	Man manWithCar;
	manWithCar.CrashCar(carToCrash);

	std::cout << "After crash repair costs: $"<< mechanic.RepairCost(carToCrash) << std::endl;
	mechanic.RepairCar(carToCrash);
	std::cout << "Car after repair costs: $" << mechanic.RepairCost(carToCrash) << std::endl;
	
	return 0;
}