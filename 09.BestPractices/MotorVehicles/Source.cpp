#include <iostream>
#include "Date.h"
#include "Vehicle.h"
#include "Car.h"
#include "SearchEngine.h"

// Check SearchEngine.cpp - there are sample vehicles to search by registration number.
int main(int argsCount, char * args[])
{
    SearchEngine vehicleSearch = SearchEngine();

    // lambda to print vehicle info
    auto searchLambda = [](bool isFound, Vehicle * vehicle)
    {
        if (isFound)
        {
            std::cout << vehicle->toString() << std::endl;
        }
        else
        {
            std::cout << "Cannot find that vehicle!" << std::endl;
        }
    };

    std::string input;
    while (input != "exit")
    {
        std::cout << "Please enter registration number of a vehicle to search or \"exit\" to leave: \n>";
        std::getline(std::cin, input);

        if (input == "exit")
        {
            break;
        }

        std::cout << "Searching" << std::endl;
        vehicleSearch.searchForACarWithRegistrationNumber(input, searchLambda);
    }
}