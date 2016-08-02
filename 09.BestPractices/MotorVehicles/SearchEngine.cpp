#include "SearchEngine.h"

SearchEngine::SearchEngine() : isFound(false)
{
    this->cars.push_back(Car("A2273MM", 1.0f, 5, "123123123123123", "D14A400192", "Martin Kuvandzhiev", Date(2000, 7, 29), Date(2014, 3, 14)));
    this->cars.push_back(Car("A2273MM", 2.1f, 2, "111111", "D143400192", "Pesho", Date(2001, 7, 8), Date(2016, 3, 14)));
    this->cars.push_back(Car("A2273SA", 3.5f, 4, "215551", "914A400192", "Gosho", Date(2002, 3, 1), Date(2015, 4, 13)));
    this->cars.push_back(Car("A2273ZA", 1.1f, 5, "12414154", "D14A410192", "Ivan", Date(1999, 4, 16), Date(2013, 5, 15)));
    this->cars.push_back(Car("A2273DE", 2.41f, 4, "14252", "A14A440192", "Toni", Date(1996, 1, 19), Date(2012, 5, 17)));
    this->cars.push_back(Car("A2273DD", 3.41f, 4, "1432543", "Z14Z400192", "Stark", Date(1995, 5, 22), Date(2011, 6, 18)));
    this->cars.push_back(Car("A2273QE", 4.1f, 4, "1242453", "4141410192", "Wars", Date(2001, 10, 29), Date(2010, 7, 18)));
    this->cars.push_back(Car("A2273QE", 5.0f, 4, "34566", "1346475", "Stamath", Date(2005, 10, 14), Date(2011, 8, 14)));
    this->cars.push_back(Car("A2273RR", 5.0f, 3, "1356", "D12342375", "Mariika", Date(2000, 3, 11), Date(2012, 9, 22)));
    this->cars.push_back(Car("A2273TH", 6.1f, 15, "135263", "DAC123141", "Gergana", Date(2000, 12, 10), Date(2013, 10, 22)));
    this->cars.push_back(Car("A2273FA", 1.1f, 2, "e13533", "ACAB1312", "Sophia", Date(2000, 12, 1), Date(2014, 11, 14)));
    this->cars.push_back(Car("A2273FY", 1.09f, 4, "8843322", "ACAD134235", "Karina", Date(2000, 7, 11), Date(2015, 12, 12)));

    this->motorcycles.push_back(MotorCycle("MIG2000", 0.5f, 2, "87963214", "ACAD123AA", "Marian", Date(2001, 7, 11), Date(2014, 5, 12)));
    this->motorcycles.push_back(MotorCycle("MIG2001", 0.245f, 1, "4687463", "ACAD34235CC", "Martina", Date(2002, 8, 10), Date(2013, 6, 19)));
    this->motorcycles.push_back(MotorCycle("MIG2006", 0.6544f, 1, "41987453", "ACAD1423BB", "Martin", Date(2003, 9, 11), Date(2012, 8, 12)));

    this->trucks.push_back(Truck("FAC2041", 13.24f, 3, "13412525", "51222131AF", "George", Date(2001, 1, 11), Date(2015, 4, 12)));
    this->trucks.push_back(Truck("FAC2051", 15.11f, 2, "1352362", "1555131AF", "Michel", Date(2002, 1, 1), Date(2013, 8, 23)));
    this->trucks.push_back(Truck("FAC2171", 18.94f, 3, "1245566", "15672131AF", "Nikolas", Date(2001, 2, 22), Date(2011, 5, 29)));
}

SearchEngine::~SearchEngine()
{
}

void SearchEngine::search(std::string registrationNumber, std::vector<Vehicle>* vehicles, void aLambdaExpressionToBeExecutedWhenFound(bool vehicleFound, Vehicle * aVehicle))
{
    std::for_each(vehicles->begin(), vehicles->end(), [&](Vehicle & vehicle)
    {
        if (this->isFound)
        {
            // Another thread has found the vehicle

            // I need to terminate the current thread, but how?
            //std::terminate();
            return;
        }

        if (vehicle.getRegistrationNumber() == registrationNumber)
        {
            this->isFound = true;
            aLambdaExpressionToBeExecutedWhenFound(true, &vehicle);
            // std::terminate();
            return;
        }
    });

    
}

void SearchEngine::searchForACarWithRegistrationNumber(std::string registrationNumber, void aLambdaExpressionToBeExecutedWhenFound(bool vehicleFound, Vehicle * aVehicle))
{
    // http://stackoverflow.com/questions/10673585/start-thread-with-member-function
    std::thread carsThread([&] { this->search(registrationNumber, &this->cars, aLambdaExpressionToBeExecutedWhenFound); });
    std::thread motocyclesThread([&] { this->search(registrationNumber, &this->motorcycles, aLambdaExpressionToBeExecutedWhenFound); });
    std::thread trucksThread([&] { this->search(registrationNumber, &this->trucks, aLambdaExpressionToBeExecutedWhenFound); });

    carsThread.join();
    motocyclesThread.join();
    trucksThread.join();

    if (!this->isFound)
    {
        aLambdaExpressionToBeExecutedWhenFound(false, nullptr);
    }

    this->isFound = false;
}
