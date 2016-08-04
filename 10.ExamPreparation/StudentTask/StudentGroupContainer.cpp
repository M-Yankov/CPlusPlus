#include "StudentGroupContainer.h"



StudentGroupContainer::StudentGroupContainer()
{
}


StudentGroupContainer::~StudentGroupContainer()
{
}

void StudentGroupContainer::addStudent(Student & stud)
{
    this->students.push_back(&stud);
}

void StudentGroupContainer::addDiscipline(std::string discipline)
{
    for (Student * studPtr : this->students)
    {
        studPtr->addDiscipline(discipline);
    }
}

float StudentGroupContainer::averageGroupRate()
{
    std::set<float> grades;

    for (Student * studPtr : this->students)
    {
        grades.insert(studPtr->averageGrade());
    }

    // to try with rbegin
    std::set<float>::iterator max = grades.end();
    max--;
    return *max;
}
