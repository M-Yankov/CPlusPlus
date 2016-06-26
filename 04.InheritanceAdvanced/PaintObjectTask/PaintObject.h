#pragma once

#include "Size.h"

class PaintObject
{
public:
	Size sheetSize;
	Size size;
	unsigned char rgbColor[3];
	unsigned char backgroundRgbColor[3];
	PaintObject();
	PaintObject(Size sheetSize, Size size);
};

