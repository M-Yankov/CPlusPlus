#include <iostream>
#include <array>
#include <math.h>
#include "Figure.h";

using namespace std;

#define VAL_MAL 2;
#define DEBUG 1;

void pointerExample()
{
	int variable = 5;
	// %p means for pointer
	printf("%d, with address %p\n", variable, &variable);

	// &variable - address to memory 
	// *pointerToVariable - what is the value on the given address
	int *pointerToVariable = &variable;
	printf("%d, pointing to address %p\n", *pointerToVariable, pointerToVariable);

	variable = 99669;
	printf("value after change %d \n", *pointerToVariable);
}

void arrayExample()
{
	//  siblings memory block for each array member 
	int arr[] = { 1, 3, 4, 5 };

	// points to first element of array
	// array uses memory block for each element, but the pointer only one block of the array type
	int *pointerToArray = arr;
	printf("Array value %d, pointer to array %d\n", arr[3], pointerToArray[3]);
}

void objectExample()
{
	class Human
	{
	public:
		char *name;
		unsigned int age;
		inline Human(char *newName, unsigned int newAge)
		{
			name = newName;
			age = newAge;
		}
	};

	Human pesho = Human("Peshko Peshaka", 2);
	Human *pointerToHuman = &pesho;
	printf("age: %d\n", pointerToHuman->age);

	pesho.age = 99;
	printf("age after change: %d\n", pointerToHuman->age);
}

class Point
{
public:
	double x;
	double y;
};

// Task
class Cube
{
public:
	double side;
};


double perimeter(const Cube &cube)
{
	// trainer said only bottom base surface;
	return cube.side * 4;
}

double calculateSurface(const Cube &cube)
{
	double surfaceOfOneSide = cube.side * cube.side;
	return surfaceOfOneSide * 6; // all sides
}

double calculateVolume(const Cube &cube)
{
	return pow(cube.side, 3);
}

enum Status
{
	complete,
	impcomplete,
	removed,
	paused,
	disabled
};


int	main()
{
	Status::complete;
	// pointerExample();
	// arrayExample();
	// objectExample();

#ifndef DEBUG
	cout << "DEbugging" << endl;
#endif // !DEBUG

#ifdef DEBUG
	cout << "DEbugging" << endl;
#endif // !DEBUG

	// notes:
	unsigned char color[3]; // RGB
	char redValue = 0xFF;
	// TODO: LinkedList C++
	// TODO: Extend Task Figure with Square

	// TOdO: Initiazlization constructor
	cout << INFINITY << endl;

	Cube transforemer = Cube();
	transforemer.side = 1;

	cout << "cube with side: " << transforemer.side << " has perimeter " << perimeter(transforemer) << endl;
	cout << "cube with side: " << transforemer.side << " has surface " << calculateSurface(transforemer) << endl;
	cout << "cube with side: "<< transforemer.side << " has volume " << calculateVolume(transforemer) << endl;

	// function overrideing
	// + means public 
	// # protected
	// - private 
	return 0;
}