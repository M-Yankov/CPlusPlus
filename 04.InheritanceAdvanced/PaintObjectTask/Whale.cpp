#include "Whale.h"

Whale::Whale(Size sheetSize, Size ownSize, char redSkin, char green, char blue)
	: PaintObject(sheetSize, ownSize)
{
	rgbColor[0] = redSkin;
	rgbColor[1] = green;
	rgbColor[2] = blue;
}
