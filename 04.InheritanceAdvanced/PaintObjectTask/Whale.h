#pragma once
#include "PaintObject.h"

class Whale : public PaintObject
{
public:
	Whale(Size sheetSize, Size ownSize, char red, char green, char blue);
	double mass;
};

