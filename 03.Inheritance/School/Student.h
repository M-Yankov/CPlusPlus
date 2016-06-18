#ifndef Student_h
#define Student_h

#include "Person.h"

class Student : public Person
{
public:
	Student(unsigned short id, std::string name, int currentPoints, int currentCourse);
	float getAverage();
	void setCurrentPoints(int currentPoints);

	//std::ostream& operator<<(std::ostream& stream, const Student* person);
	std::string toString() override;
private:
	int _currentPoints;
};

#endif // !Student_h
