#ifndef VEHICLE_h
#define VEHICLE_h

#include <string>
#include <iostream>

#include "Date.h"

class Vehicle
{
private:
    std::string registrationNumber;
    float weightInTones;
    unsigned short numberOfSeats;
    std::string chassisNumber;
    std::string engineNumber;
    std::string owner;
    Date dateRegistered;
    Date dateRegisteredInCountry;
public:
    Vehicle();
    Vehicle(
        std::string regNumber,
        float tonesWeight,
        unsigned short seatsCount,
        std::string chassisNum,
        std::string engineNum,
        std::string aOwner,
        Date dateOfRegistration,
        Date dateOfRegistrationInCountry);
    ~Vehicle();
    std::string toString();
    std::string getRegistrationNumber();
};

#endif // !VEHICLE_h
