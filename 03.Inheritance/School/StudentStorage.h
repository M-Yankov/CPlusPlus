#ifndef STUDENTSTORAGE_h
#define STUDENTSTORAGE_h

#include <vector>
#include "Student.h"

class StudentStorage // : public DataStorage
{
private:
	std::vector<Student>::iterator ExistsWithId(unsigned short id);
	std::vector<Student> _students;
public:
	StudentStorage();
	std::string AddToStorage(const Student &objPerson); //override;
	std::string GetInfo(unsigned short id); // override;
};
#endif // !STUDENTSTORAGE_h
