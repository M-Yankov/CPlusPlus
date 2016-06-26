#include <iostream>
#include "Whale.h"

void calculateScale(Whale & whale);

/// <summary>
/// Mains this instance.
/// Source : http://study.com/academy/lesson/what-is-a-scale-factor-definition-formula-examples.html
/// </summary>
/// <returns>success value</returns>
int main()
{
	Whale testWhale = Whale(Size(15.13, 33.4), Size(13.4, 12.3), 3, 31, 51);
	Whale anotherTest = Whale(Size(11.12, 11.8695), Size(53.23, 72.3), 3, 31, 51);
	
	calculateScale(testWhale);
	calculateScale(anotherTest);
	return 0;
}

void calculateScale(Whale & whale)
{
	double sheetArea = whale.sheetSize.height * whale.sheetSize.width;
	double whaleArea = whale.size.height * whale.size.width;
	
	std::cout << "whaleArea : sheetArea " << std::endl;
	double scale = sheetArea / whaleArea;

	if (scale > 1)
	{
		std::printf("%9.0d : %f\n", 1, scale);
	}
	else
	{
		std::printf("%9.2f : %d\n", whaleArea / sheetArea, 1);
	}
}