#ifndef SEARCHENGINE_h
#define SEARCHENGINE_h

#include <vector>
#include <thread>
#include <algorithm>

#include "Car.h"
#include "Truck.h"
#include "MotorCycle.h"

class SearchEngine
{
private:
    std::vector<Vehicle> cars;
    std::vector<Vehicle> motorcycles;
    std::vector<Vehicle> trucks;
    bool isFound;
    void search(std::string registrationNumber, std::vector<Vehicle> * vehicles, void aLambdaExpressionToBeExecutedWhenFound(bool vehicleFound, Vehicle * aVehicle));
public:
    SearchEngine();
    ~SearchEngine();
    void searchForACarWithRegistrationNumber(std::string registrationNumber, void aLambdaExpressionToBeExecutedWhenFound(bool vehicleFound, Vehicle * aVehicle));
};

#endif // !SEARCHENGINE_h