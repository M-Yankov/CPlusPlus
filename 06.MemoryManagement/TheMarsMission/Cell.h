#ifndef CELL_h
#define CELL_h

class Cell
{
public:
    int row;
    int column;
    Cell(int row, int column);
    ~Cell();
    bool operator ==(const Cell & other) const;
};

#endif // !CELL_h




