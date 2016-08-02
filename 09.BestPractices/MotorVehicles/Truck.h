#ifndef TRUCK_h
#define TRUCK_h

#include "Vehicle.h"
class Truck : public Vehicle
{
public:
    Truck();
    Truck(
        std::string regNumber,
        float tonesWeight,
        unsigned short seatsCount,
        std::string chassisNum,
        std::string engineNum,
        std::string aOwner,
        Date dateOfRegistration,
        Date dateOfRegistrationInCountry);
    ~Truck();
};

#endif // !TRUCK_h
