#ifndef DATASTORAGE_h
#define DATASTORAGE_h

#include "Person.h"
#include <vector>
#include <algorithm>

class DataStorage
{
public:
	DataStorage() {};
	virtual std::string AddToStorage(const Person &objPerson) { return 0; };
	virtual std::string GetInfo(unsigned short id) { return 0; };

protected:
	

	std::vector<Person> _personStorage;
};

#endif // !DATASTORAGE