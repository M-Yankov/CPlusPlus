#include "Cell.h"

Cell::Cell(int newRow, int newColumn) : row(newRow), column(newColumn)
{
}

Cell::~Cell()
{
}

bool Cell::operator==(const Cell & other) const
{
    return this->row == other.row && this->column == other.column;
}