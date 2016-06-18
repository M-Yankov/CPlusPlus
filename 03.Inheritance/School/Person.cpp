
#include "Person.h"
#include <string>
#include <iostream>
#include <sstream>

Person::Person(unsigned short id, std::string name)
{
	this->setId(id);
	this->setName(name);
}

unsigned short Person::getId() const
{
	return this->_id;
}

void Person::setId(unsigned short id)
{
	// maybe it's unnecessary
	// USHRT_MAX = 65535
	if (id > USHRT_MAX)
	{
		throw "id must be positive number less than " + UCHAR_MAX;
	}

	this->_id = id;
}

std::string Person::getName()
{
	return this->_name;
}

void Person::setName(std::string name)
{
	this->_name = name;
}

int Person::getCurrentCourse()
{
	return this->_courseCount;
}

void Person::setCurrentCourse(int currentCourse)
{
	this->_courseCount = currentCourse;
}

std::string Person::toString()
{
	return std::to_string(this->_id) + ". " + this->_name + " - current course: " + std::to_string(this->_courseCount);
}

