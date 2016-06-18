#include "GuestTeacher.h"
#include <string>

GuestTeacher::GuestTeacher(unsigned short id, std::string name, int courseCount, float salaryforCourse) : Person(id, name)
{
	this->setCurrentCourse(courseCount);
	this->setSalaryForCourse(salaryforCourse);
}

void GuestTeacher::setSalaryForCourse(float salary)
{
	if (salary < 0)
	{
		throw "salary must be a positive number";
	}

	this->_salaryForCourse = salary;
}

float GuestTeacher::getSalaryForCourse()
{
	return this->_salaryForCourse;
}

std::string GuestTeacher::toString()
{
	char buffer[50];
	std::sprintf(buffer, "$%0.2f", this->getSalaryForCourse());
	return Person::toString() + " guest teacher has salary: " + buffer;
}