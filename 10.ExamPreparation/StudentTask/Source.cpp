#include <iostream>
#include <thread>

#include "StudentGroupContainer.h"

// global is found;
void addDefaultDisciplines(StudentGroupContainer * studentGroupContainer);
void search(StudentGroupContainer * studentGroupContainer, long number);

bool isFound = false;

int main()
{
    int firstGroupNum = 1111;
    int secondGroupNum = 2222;
    int thirdGroupNum = 3333;

    Student pesho = Student("peshgo", 1313l, firstGroupNum, firstGroupNum);
    Student ivan = Student("ivan", 1314l, firstGroupNum, firstGroupNum);
    Student gosho = Student("gosho", 1315l, firstGroupNum, firstGroupNum);

    Student stamat = Student("stamat", 1316l, secondGroupNum, secondGroupNum);
    Student marika = Student("mariika", 1318l, secondGroupNum, secondGroupNum);
    Student drago = Student("drago", 1319l, secondGroupNum, secondGroupNum);
    Student kalin = Student("kalin", 1320l, secondGroupNum, secondGroupNum);

    Student penka = Student("penka", 1321l, thirdGroupNum, thirdGroupNum);
    Student stoika = Student("stoika", 1322l, thirdGroupNum, thirdGroupNum);

    StudentGroupContainer firstGroup = StudentGroupContainer();
    StudentGroupContainer secondGroup = StudentGroupContainer();
    StudentGroupContainer thirdGroup = StudentGroupContainer();

    firstGroup.addStudent(pesho);
    firstGroup.addStudent(ivan);
    firstGroup.addStudent(gosho);

    secondGroup.addStudent(stamat);
    secondGroup.addStudent(marika);
    secondGroup.addStudent(drago);
    secondGroup.addStudent(kalin);

    thirdGroup.addStudent(penka);
    thirdGroup.addStudent(stoika);

    addDefaultDisciplines(&firstGroup);
    addDefaultDisciplines(&secondGroup);
    addDefaultDisciplines(&thirdGroup);

    pesho.addMark("c++", 2);
    pesho.addMark("c++", 5);
    pesho.addMark("c++", 5);
    pesho.addMark("C#", 2);
    pesho.addMark("java", 3);
    pesho.addMark("java", 6);
    pesho.addMark("maths",6);

    std::string input;
    std::getline(std::cin, input);

    long facNum = std::stol(input);
    
    std::thread firstThread(search, &firstGroup, facNum);
    std::thread secondThread(search, &secondGroup, facNum);
    std::thread lastThread(search, &thirdGroup, facNum);

    firstThread.join();
    secondThread.join();
    lastThread.join();

    return 0;
}

void search(StudentGroupContainer * studentGroupContainer, long number)
{
    for (Student * stud: studentGroupContainer->students)
    {
        if (isFound)
        {
            return;
        }

        if (stud->getFacNumber() == number)
        {
            isFound = true;
            std::printf("%s", stud->toString().c_str());
            return;
        }
    }
}

void addDefaultDisciplines(StudentGroupContainer * studentGroupContainer)
{
    studentGroupContainer->addDiscipline("C++");
    studentGroupContainer->addDiscipline("maths");
    studentGroupContainer->addDiscipline("C#");
    studentGroupContainer->addDiscipline("Java");
}
