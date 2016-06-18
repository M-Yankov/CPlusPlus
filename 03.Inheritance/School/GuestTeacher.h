#ifndef GuestTeacher_h
#define GuestTeacher_h
#include "Person.h"

class GuestTeacher : public Person
{
private:
	float _salaryForCourse;

public:
	GuestTeacher(unsigned short id, std::string name, int courseCount, float salaryforCourse);
	float getSalaryForCourse();
	void setSalaryForCourse(float salary);

	std::string toString() override;
};

#endif // !GuestTeacher_h