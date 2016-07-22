#include "Rectangle.h"

using namespace GeometricCalculations;

Rectangle::Rectangle(float widthCm, float heightCm) : width(widthCm), height(heightCm)
{
}

float Rectangle::CalculatePerimeter()
{
	return (this->height * 2) + (this->width * 2);
}

float Rectangle::CalculateSurface()
{
	return this->height * this->width;
}
