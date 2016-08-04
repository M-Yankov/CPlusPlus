#ifndef STUDENTGROUPCONTAINER_h
#define STUDENTGROUPCONTAINER_h

#include <vector>
#include <string>
#include <set>
#include "Student.h"

class StudentGroupContainer
{

public:
    std::vector<Student *> students;
    StudentGroupContainer();
    ~StudentGroupContainer();
    void addStudent(Student & stud);
    void addDiscipline(std::string discipline);
    float averageGroupRate();
};

#endif // !STUDENTGROUPCONTAINER_h
