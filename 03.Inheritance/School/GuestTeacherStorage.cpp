#include "GuestTeacherStorage.h"
#include "GuestTeacher.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

GuestTeacherStorage::GuestTeacherStorage()
{
	this->AddToStorage(GuestTeacher(1, "Petyo Petrov", 5, 1954.11));
	this->AddToStorage(GuestTeacher(2, "Stoyan Germanov", 1, 4684.50));
	this->AddToStorage(GuestTeacher(3, "Kalin Lavov", 15, 2152.25));
}

std::string GuestTeacherStorage::AddToStorage(const GuestTeacher &teacher)
{
	std::vector<GuestTeacher>::iterator it = this->ExistsWithId(teacher.getId());

	if (it._Ptr == this->_techers._Mylast())
	{
		this->_techers.push_back(teacher);
		return "Guest Teacher added.";
	}
	else
	{
		char buffer[150];
		std::sprintf(buffer, "Cannot add guest teacher.\nTeacher with this id already exists.\nid: %d", teacher.getId());
		return buffer;
	}
};

std::string GuestTeacherStorage::GetInfo(unsigned short id)
{
	std::vector<GuestTeacher>::iterator it = this->ExistsWithId(id);

	if (it._Ptr == this->_techers._Mylast())
	{
		char buffer[150];
		std::sprintf(buffer, "Cannot find guest teacher with id: %d", id);
		return buffer;
	}
	else
	{
		GuestTeacher guestTeacher = GuestTeacher(*it._Ptr);
		return guestTeacher.toString();
	}
}

std::vector<GuestTeacher>::iterator GuestTeacherStorage::ExistsWithId(unsigned short id)
{
	return std::find_if(
		this->_techers.begin(),
		this->_techers.end(),
		[id](const GuestTeacher &guestTeacher)
	{
		return guestTeacher.getId() == id;
	});
};