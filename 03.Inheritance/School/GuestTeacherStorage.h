#ifndef GUESTTEACHERSTORAGE_h
#define GUESTTEACHERSTORAGE_h
#include "GuestTeacher.h"

#include <string>
#include <vector>

class  GuestTeacherStorage
{
private:
	std::vector<GuestTeacher> _techers;
	std::vector<GuestTeacher>::iterator ExistsWithId(unsigned short id);
public:
	 GuestTeacherStorage();
	 std::string AddToStorage(const GuestTeacher &teacher);
	 std::string GetInfo(unsigned short id);
};

#endif // !GUESTTEACHERSTORAGE_h