#include "Student.h"
#include <string>

Student::Student(unsigned short id, std::string name, int currentPoints, int currentCourse) : Person(id, name)
{
	setCurrentPoints(currentPoints);
	this->setCurrentCourse(currentCourse);
}

void Student::setCurrentPoints(int points)
{
	if (points < 0)
	{
		this->_currentPoints = points;
		return;
	}

	this->_currentPoints = points;
}

float Student::getAverage()
{
	if (this->getCurrentCourse() == 1)
	{
		return 0;
	}

	return this->getCurrentCourse() / (float)this->_currentPoints;
}

std::string Student::toString()
{
	char buffer[50];
	std::sprintf(buffer, "%0.2f", this->getAverage());
	return Person::toString() + " and has average points " + buffer;
}