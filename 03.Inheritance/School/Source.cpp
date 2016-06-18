#include "StudentStorage.h"
#include "TeacherStorage.h"
#include "GuestTeacherStorage.h"
#include "Student.h"
#include "Teacher.h"
#include "GuestTeacher.h"

#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

const int MIN_OPTION = 1;
const int MAX_OPTION = 6;

void WorkWithStudentStorage(int choice)
{
	StudentStorage studentStorage = StudentStorage();
	if (choice < 4)
	{
		unsigned short id;
		printf("Enter student id (number less than %d): ", USHRT_MAX);
		if (cin >> id)
		{
			cout << studentStorage.GetInfo(id) << endl;
		}
		else
		{
			cout << "id is not valid" << endl;
		}
	}
	else
	{
		unsigned short id;
		cout << "Enter student id " << "(" << 0 << "-" << USHRT_MAX << "):";
		cin >> id;

		string name;
		cout << "Enter student name: ";
		cin.ignore();
		getline(cin, name);

		int currentCourse;
		cout << "Enter student current course (int): ";
		cin >> currentCourse;

		int currentPoints;
		cout << "Enter student current points (int): ";
		cin >> currentPoints;

		// validation is missing - I am tired...
		Student student = Student(id, name, currentCourse, currentPoints);
		cout << studentStorage.AddToStorage(student) << endl;
	}

}

void WorkWithTeacherStorage(int choice)
{
	TeacherStorage teacherStorage = TeacherStorage();
	if (choice < 4)
	{
		unsigned short id;
		printf("Enter teacher id (number less than %d): ", USHRT_MAX);
		if (cin >> id)
		{
			cout << teacherStorage.GetInfo(id) << endl;
		}
		else
		{
			cout << "id is not valid" << endl;
		}
	}
	else
	{
		unsigned short  id;
		cout << "Enter teacher id " << "(" << 0 << "-" << USHRT_MAX << "):";
		cin >> id;

		string name;
		cout << "Enter teacher name: ";
		cin.ignore();
		getline(cin, name);

		int currentCourse;
		cout << "Enter teacher current course (int): ";
		cin >> currentCourse;

		float salary;
		cout << "Enter teacher salary (float): ";
		cin >> salary;

		unsigned short daysInSoftUni;
		cout << "Enter teacher days in SoftUni " << "(" << 0 << "-" << USHRT_MAX << "):";
		cin >> daysInSoftUni;

		// validation is missing - I am tired...
		Teacher teacher = Teacher(id, name, currentCourse, salary, daysInSoftUni);
		cout << teacherStorage.AddTeacherStorage(teacher) << endl;
	}
}

void WorkWithGuestTeacherStorage(int choice)
{
	GuestTeacherStorage guestTeacherStorage = GuestTeacherStorage();
	if (choice < 4)
	{
		unsigned short id;
		printf("Enter guest teacher id (number less than %d): ", USHRT_MAX);
		if (cin >> id)
		{
			cout << guestTeacherStorage.GetInfo(id) << endl;
		}
		else
		{
			cout << "id is not valid" << endl;
		}
	}
	else
	{
		unsigned short  id;
		cout << "Enter guest teacher id " << "(" << 0 << "-" << USHRT_MAX << "):";
		cin >> id;

		string name;
		cout << "Enter guest teacher name: ";
		cin.ignore();
		getline(cin, name);

		int currentCourse;
		cout << "Enter guest teacher current course (int): ";
		cin >> currentCourse;

		float salary;
		cout << "Enter guest teacher salary for course (float): ";
		cin >> salary;

		// validation is missing - I am tired...
		GuestTeacher teacher = GuestTeacher(id, name, currentCourse, salary);
		cout << guestTeacherStorage.AddToStorage(teacher) << endl;
	}
}

int main()
{
	// UINT16_MAX = 65535

	// cout << UINT16_MAX << endl;
	// cout << USHRT_MAX << endl;

	// print Menu
	vector<string> menuOptions =
	{
		"Get data for student with ID",
		"Get data for teacher with ID",
		"Get data for guest teacher with ID",
		"Add data for new student",
		"Add data for new teacher",
		"Add data for new guest teacher"
	};

	cout << "Menu:" << endl;
	for (size_t i = 0; i < menuOptions.size(); i++)
	{
		cout << i + 1 << ". " + menuOptions[i] << endl;
	}

	cout << "Enter an option number: ";
	int choice;

	while (!(cin >> choice) || MIN_OPTION > choice || choice > MAX_OPTION)
	{
		cout << "please enter a number between " << MIN_OPTION << " and " << MAX_OPTION << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	int storageChoice = choice % 3;
	switch (storageChoice)
	{
	case 1:
		WorkWithStudentStorage(choice);
		break;
	case 2:
		WorkWithTeacherStorage(choice);
		break;
	case 0:
		WorkWithGuestTeacherStorage(choice);
		break;
	default:
		throw "Invalid operation";
		break;
	}

	cout << "\n\nEnd execution of program." << endl;
	return 0;
}