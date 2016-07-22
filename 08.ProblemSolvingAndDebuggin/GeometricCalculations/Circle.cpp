#include "Circle.h"

using namespace GeometricCalculations;

Circle::Circle(float radiusCm) : radius(radiusCm)
{
}

float Circle::CalculateSurface()
{
	return this->radius * this->radius * M_PI;
}

float Circle::CalculatePerimeter()
{
	return 2 * M_PI * this->radius;
}
