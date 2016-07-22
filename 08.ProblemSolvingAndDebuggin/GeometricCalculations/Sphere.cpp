#include "Sphere.h"

using namespace GeometricCalculations;

Sphere::Sphere(float radiusCm) : radiusInCm(radiusCm)
{
}

float Sphere::CalculateSurface()
{
	return this->radiusInCm * this->radiusInCm * M_PI * 4;
}

float Sphere::CalculateVolume()
{
	return pow(this->radiusInCm, 3) * M_PI * (4/3);
}
