#ifndef Teacher_h
#define Teacher_h


#include "Person.h"

class Teacher : public Person
{
private:
	unsigned short _daysInSoftUni;
	float _salary;
public:
	Teacher(unsigned short id, std::string name, int currentCourse, float salary, unsigned short daysInSoftUni);
	float getSalary();
	void setSalary(float salary);
	unsigned short getDaysInSoftUni();
	void setDaysInSoftUni(unsigned short days);

	std::string toString() override;
};

#endif // !Teacher_h