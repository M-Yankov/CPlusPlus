#include "Teacher.h"
#include "Person.h"
#include <string>

Teacher::Teacher(unsigned short id, std::string name, int currentCourse, float salary, unsigned short daysInSoftUni) : Person(id, name)
{
	this->setCurrentCourse(currentCourse);
	this->setDaysInSoftUni(daysInSoftUni);
}

void Teacher::setDaysInSoftUni(unsigned short daysInSoftUni)
{
	if (daysInSoftUni < 0 || USHRT_MAX < daysInSoftUni)
	{
		throw "daysInSoftUni should be a positive number less than " + USHRT_MAX;
	}

	this->_daysInSoftUni = daysInSoftUni;
}

unsigned short Teacher::getDaysInSoftUni()
{
	return this->_daysInSoftUni;
}

void Teacher::setSalary(float salary)
{
	if (salary < 0)
	{
		throw "salary should be a positive number";
	}

	this->_salary = salary;
}

float Teacher::getSalary()
{
	return this->_salary;
}

std::string Teacher::toString()
{
	char buffer[50];
	std::sprintf(buffer, "$%0.2f", this->getSalary());
	return Person::toString() + " has Monthly salary: " + buffer + " and has " + std::to_string(this->getDaysInSoftUni()) + " days in SoftUni";
}