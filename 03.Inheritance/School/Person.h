#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
private:
	unsigned short _id;
	std::string _name;
	int _courseCount;
	void setId(unsigned short id);
public:
	Person(unsigned short id, std::string name);
	unsigned short getId() const;
	std::string getName();
	void setName(std::string name);
	int getCurrentCourse();
	void setCurrentCourse(int currentCourses);

	virtual std::string toString();
};
#endif // PERSON_H