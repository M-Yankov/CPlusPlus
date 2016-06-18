#ifndef TEACHERSTORAGE_h
#define TEACHERSTORAGE

#include "Teacher.h"
#include <string>
#include <vector>

class TeacherStorage
{
private:
	std::vector<Teacher> _teachers;
	std::vector<Teacher>::iterator ExistsWithId(unsigned short id);
public:
	TeacherStorage();
	std::string AddTeacherStorage(const Teacher &teacher);
	std::string GetInfo(unsigned short id);
};

#endif // !TEACHERSTORAGE_h