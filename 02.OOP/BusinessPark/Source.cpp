#include <iostream>
#include <string>
#include <map>
#include <array>
#include <algorithm>


using namespace std;


class Building
{
private:
	// attributes
	char   *   _companyName;
	int _floors;
	int _offices;
	int _employees;
	int _freeWorkingSeats;

public:

	// constructors
	inline Building(char  *    companyName, int floors, int offices, int employees, int freeWorkingSeats)
	{
		_companyName = companyName;
		_floors = floors;
		_offices = offices;
		_employees = employees;
		_freeWorkingSeats = freeWorkingSeats;
	}

	inline Building(char* companyName)
	{
		_companyName = companyName;
		_floors = 0;
		_offices = 0;
		_employees = 0;
		_freeWorkingSeats = 0;
	}

	// destructor
	inline ~Building()
	{
		 printf("Building destructor called for %s \n",  _companyName);
		//cout << "Building destructor called for " << _companyName << endl;
	}

	// getters
	inline int employees()
	{
		return _employees;
	}

	inline string companyName()
	{
		return _companyName;
	}

	inline int freeWorkingSeats()
	{
		return _freeWorkingSeats;
	}

	// functions
	inline int officesPerFloor()
	{
		return _offices / _floors;
	}

	inline int peoplePerFloor()
	{
		return _employees / _floors;
	}

	inline int peoplePerOffice()
	{
		return _employees / _offices;
	}

	inline float coeficient()
	{
		return (float)_employees / (float)(_employees + _freeWorkingSeats);
	}
};

bool sortByEmpl(Building i, Building j) { return j.employees() > i.employees(); }

void firstSolution()
{
	Building businessPark[] =
	{
		Building("XYZ Industries", 6, 127, 600, 196),

		// 1 floor is restaurant - so instead of 8 it will be 7
		Building("Rapid Development Crew", 7, 210, 822, 85),
		Building("SoftUni", 11, 106, 200, 60)
	};

	int arrlength = sizeof(businessPark) / sizeof(*businessPark);

	// key, <name, value>
	// res[key].first means company name;
	// res[key].second means value;
	map<string, pair<string, float>> result;

	string defaultValue;

	string employeeKey = "empCount";
	string freePlacesKey = "freePlaces";
	string highestCoeficient = "hiCoef";
	string mostPeoplePerFloor = "pplPerFlor";
	string leastPeoplePerFloor = "lestPplPerFloor";
	string mostOfficesPerFloor = "mostOfficesPerFloor";
	string leastOfficesPerFloor = "leastOfficesPerFloor";
	string mostPeoplePerOffice = "mostPeoplePerOffice";
	string leastPeoplePerOffice = "leastPeoplePerOffice";

	result[employeeKey] = make_pair(defaultValue, 0);
	result[freePlacesKey] = make_pair(defaultValue, 0);
	result[highestCoeficient] = make_pair(defaultValue, 0);
	result[mostPeoplePerFloor] = make_pair(defaultValue, 0);
	result[leastPeoplePerFloor] = make_pair(defaultValue, INT_MAX);
	result[mostOfficesPerFloor] = make_pair(defaultValue, 0);
	result[leastOfficesPerFloor] = make_pair(defaultValue, INT_MAX);
	result[mostPeoplePerOffice] = make_pair(defaultValue, 0);
	result[leastPeoplePerOffice] = make_pair(defaultValue, INT_MAX);

	for (int i = 0; i < arrlength; i++)
	{
		if (result[employeeKey].second <= businessPark[i].employees())
		{
			result[employeeKey].first = businessPark[i].companyName();
			result[employeeKey].second = businessPark[i].employees();
		}

		if (result[freePlacesKey].second <= businessPark[i].freeWorkingSeats())
		{
			result[freePlacesKey].first = businessPark[i].companyName();
			result[freePlacesKey].second = businessPark[i].freeWorkingSeats();
		}

		if (result[highestCoeficient].second <= businessPark[i].coeficient())
		{
			result[highestCoeficient].first = businessPark[i].companyName();
			result[highestCoeficient].second = businessPark[i].coeficient();
		}

		if (result[mostPeoplePerFloor].second <= businessPark[i].peoplePerFloor())
		{
			result[mostPeoplePerFloor].first = businessPark[i].companyName();
			result[mostPeoplePerFloor].second = businessPark[i].peoplePerFloor();
		}

		if (result[leastPeoplePerFloor].second >= businessPark[i].peoplePerFloor())
		{
			result[leastPeoplePerFloor].first = businessPark[i].companyName();
			result[leastPeoplePerFloor].second = businessPark[i].peoplePerFloor();
		}

		if (result[mostOfficesPerFloor].second <= businessPark[i].officesPerFloor())
		{
			result[mostOfficesPerFloor].first = businessPark[i].companyName();
			result[mostOfficesPerFloor].second = businessPark[i].officesPerFloor();
		}

		if (result[leastOfficesPerFloor].second >= businessPark[i].officesPerFloor())
		{
			result[leastOfficesPerFloor].first = businessPark[i].companyName();
			result[leastOfficesPerFloor].second = businessPark[i].officesPerFloor();
		}
		if (result[mostPeoplePerOffice].second <= businessPark[i].peoplePerOffice())
		{
			result[mostPeoplePerOffice].first = businessPark[i].companyName();
			result[mostPeoplePerOffice].second = businessPark[i].peoplePerOffice();
		}

		if (result[leastPeoplePerOffice].second >= businessPark[i].peoplePerOffice())
		{
			result[leastPeoplePerOffice].first = businessPark[i].companyName();
			result[leastPeoplePerOffice].second = businessPark[i].peoplePerOffice();
		}
	}

	cout << "Most employees in " << result[employeeKey].first << " - " << result[employeeKey].second << endl;
	cout << "Most free working seats in " << result[freePlacesKey].first << " - " << result[freePlacesKey].second << endl;
	cout << "Highest coefficient " << result[highestCoeficient].first << " - " << result[highestCoeficient].second << endl;
	cout << "Most people per floor in  " << result[mostPeoplePerFloor].first << " - " << result[mostPeoplePerFloor].second << endl;
	cout << "Least people per floor in  " << result[leastPeoplePerFloor].first << " - " << result[leastPeoplePerFloor].second << endl;
	cout << "Most office per floor " << result[mostOfficesPerFloor].first << " - " << result[mostOfficesPerFloor].second << endl;
	cout << "Least office per floor " << result[leastOfficesPerFloor].first << " - " << result[leastOfficesPerFloor].second << endl;
	cout << "Most people per office " << result[mostPeoplePerOffice].first << " - " << result[mostPeoplePerOffice].second << endl;
	cout << "Least people per office " << result[leastPeoplePerOffice].first << " - " << result[leastPeoplePerOffice].second << endl;
}

void secondSolution()
{
	char* test = "asd";
	array<Building, 3> businessPark =
	{
		Building("XYZ Industries", 6, 127, 600, 196),

		// 1 floor is restaurant - so instead of 8 it will be 7
		Building("Rapid Development Crew", 7, 210, 822, 85),
		Building("SoftUni", 11, 106, 200, 60)
	};

	sort(businessPark.begin(), businessPark.end(), sortByEmpl);
	cout << businessPark[0].employees() << endl;
}


int main()
{
	firstSolution();
	// secondSolution();
	return 0;
}