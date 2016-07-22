#include "Parallelepiped.h"

using namespace GeometricCalculations;

Parallelepiped::Parallelepiped(float widthCm, float heightCm, float depthCm) :
	widthInCm(widthCm),
	heightInCm(heightCm),
	depthInCm(depthCm)
{
}

float Parallelepiped::CalculateSurface()
{
	float halfArea = (this->heightInCm * this->widthInCm) + 
					(this->widthInCm * this->depthInCm) + 
					(this->depthInCm * this->heightInCm);

	return halfArea * 2;
}

float Parallelepiped::CalculateVolume()
{
	return this->widthInCm * this->heightInCm * this->depthInCm;
}