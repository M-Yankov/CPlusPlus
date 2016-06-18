#include "StudentStorage.h"
#include "Student.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <array>

StudentStorage::StudentStorage()
{
	this->AddToStorage(Student(1, "Pesho", 141, 1));
	this->AddToStorage(Student(2, "Ivan", 144, 3));
	this->AddToStorage(Student(3, "Gosho", 1411, 5));
}

std::string StudentStorage::AddToStorage(const Student &person)
{
	std::vector<Student>::iterator it = ExistsWithId(person.getId());
	
	// check for null pointer
	if (it._Ptr == this->_students._Mylast())
	{
		this->_students.push_back(person);
		return "Success!";
	}
	else
	{
		char buffer[150];
		std::sprintf(buffer, "Cannot save student.\nStudent with this id already exist\n id: %d", person.getId());
		return buffer;
	}
}

std::string StudentStorage::GetInfo(unsigned short id)
{
	std::vector<Student>::iterator it = ExistsWithId(id);

	if (it._Ptr == this->_students._Mylast())
	{
		char buffer[50];
		std::sprintf(buffer, "Cannot find student with id: %d", id);
		return buffer;
	}
	else
	{
		Student pointer = Student(*it._Ptr);
		return pointer.toString();
	}
}

std::vector<Student>::iterator StudentStorage::ExistsWithId(unsigned short id)
{
	return std::find_if(
		this->_students.begin(),
		this->_students.end(),
		[id](const Student &person)
	{
		return person.getId() == id;
	});
}