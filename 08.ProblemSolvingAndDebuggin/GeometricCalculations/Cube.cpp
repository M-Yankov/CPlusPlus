#include "Cube.h"

using namespace GeometricCalculations;

Cube::Cube(float sideInCm) : side(sideInCm)
{
}

float Cube::CalculateSurface()
{
	return this->side * this->side * 6;
}

float GeometricCalculations::Cube::CalculateVolume()
{
	return this->side * this->side * this->side;
}
