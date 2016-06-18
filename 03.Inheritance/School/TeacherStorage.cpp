#include "TeacherStorage.h"
#include "Teacher.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

TeacherStorage::TeacherStorage()
{
	this->AddTeacherStorage(Teacher(1, "Miroslav", 2, 1300.43, 70));
	this->AddTeacherStorage(Teacher(2, "Pavel", 1, 990.11, 698));
	this->AddTeacherStorage(Teacher(3, "Ivailo Kenov", 1, 1451300.41563, 20));
}

std::string TeacherStorage::AddTeacherStorage(const Teacher &teacher)
{
	std::vector<Teacher>::iterator it = this->ExistsWithId(teacher.getId());

	if (it._Ptr == this->_teachers._Mylast())
	{
		this->_teachers.push_back(teacher);
		return "Teacher added";
	}
	else
	{
		char buffer[150];
		std::sprintf(buffer, "Cannot add teacher.\nTeacher with this id already exists.\nid: %d", teacher.getId());
		return buffer;
	}
}

std::string TeacherStorage::GetInfo(unsigned short id)
{
	std::vector<Teacher>::iterator it = this->ExistsWithId(id);

	if (it._Ptr == this->_teachers._Mylast())
	{
		char buffer[50];
		std::sprintf(buffer, "Cannot find teacher with id: %d", id);
		return buffer;
		
	}
	else
	{
		Teacher teacher = Teacher(*it._Ptr);
		return teacher.toString();
	}
}

std::vector<Teacher>::iterator TeacherStorage::ExistsWithId(unsigned short id)
{
	return std::find_if(
		this->_teachers.begin(),
		this->_teachers.end(),
		[id](const Teacher &teacher)
	{
		return teacher.getId() == id;
	});
}