#include "Student.h"

Student::Student(std::string newName, long faculcynumber, int gNumber, int theCourseNumber) 
    :
    name(newName),
    facNumber(faculcynumber), 
    groupNumber(gNumber), 
    courseNumber(theCourseNumber)
{
}

Student::Student(Student & student) : Student(student.name, student.facNumber, student.groupNumber, student.courseNumber)
{
}

Student::~Student()
{
}

void Student::addMark(std::string discipline, int mark)
{
    if (mark < 2 || 6 < mark)
    {
        throw "Mark must be between 2 and 6.";
    }

    this->marks[discipline].push_back(mark);
}

void Student::addDiscipline(std::string discipline)
{
    this->marks[discipline] = std::vector<float>();
}

float Student::averageGrade()
{
    int totalMarks = 0;
    float currentSum = 0.0;

    for (std::pair<std::string, std::vector<float>> pair : this->marks)
    {
        for (float mark : pair.second)
        {
            currentSum += mark;
            totalMarks++;
        }
    }

    return currentSum / totalMarks;
}

std::string Student::toString()
{
    std::stringstream ss;
    ss << "# " << this->facNumber << std::endl
        << "Name: " << this->name << std::endl
        << "Grade: " << this->averageGrade() << std::endl
        << "Group # : " << this->groupNumber << std::endl
        << "Course # : " << this->courseNumber << std::endl;

    return ss.str();
}

long Student::getFacNumber()
{
    return this->facNumber;
}
