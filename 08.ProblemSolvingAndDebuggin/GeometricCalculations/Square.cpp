#include "Square.h"

Square::Square(float sideWidthCm) : side(sideWidthCm)
{
}

float Square::CalculatePerimeter()
{
	return this->side * 4;
}

float Square::CalculateSurface()
{
	return this->side * this->side;
}
