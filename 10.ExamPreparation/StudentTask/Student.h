#ifndef STUDENT_h
#define STUDENT_h

#include <string>
#include <map>
#include <vector>
#include <sstream>

/// <summary>
/// Summary
/// </summary>
class Student
{
    std::string name;
    long facNumber;
    int groupNumber;
    int courseNumber;
    std::map<std::string, std::vector<float>> marks;
    //std::vector<std::string> disciplines;
public:
    Student(std::string newName, long faculcynumber, int gNumber, int theCourseNumber);
    Student(Student & student);
    ~Student();
    void addMark(std::string discipline, int mark);
    void addDiscipline(std::string discipline);
    float averageGrade();
    std::string toString();
    long getFacNumber();
};

#endif // !STUDENT_h