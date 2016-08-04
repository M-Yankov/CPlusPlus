#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <sstream>

#define BUNNYCHAR 'B'
#define PLAYERCHAR 'P'

class Cell
{
public:
    Cell(int newRow, int newCoulmn) : row(newRow), column(newCoulmn) {}
    int row;
    int column;
    bool operator==(const Cell & other) const
    {
        return this->row == other.row && this->column == other.column;
    }
};

namespace std
{
    template<> struct hash<Cell>
    {
        size_t operator ()(const Cell & cell) const
        {
            return (51 + hash<int>()(cell.row)) * 51 + hash<int>()(cell.column);
        }
    };
}

std::vector<int> parseArray(std::string input)
{
    std::vector<int> values;
    int n;
    std::stringstream stream(input);
    while (stream >> n)
    {
        values.push_back(n);
    }

    return values;
}

void ptintEndGame(std::string status, int row, int column)
{
    std::printf("%s: %d %d\n", status.c_str(), row, column);
}

void printLair(std::vector<std::string> * lair)
{
    std::for_each(lair->begin(), lair->end(), [](std::string row)
    {
        std::cout << row << std::endl;
    });
}

void addNeibhorCellsToList(std::unordered_set<Cell> & cells, int rows, int columns, const Cell & cell )
{
    // add next cell for place B
    // L
    if (cell.column - 1 >= 0)
    {
        cells.insert(Cell(cell.row, cell.column - 1));
    }

    // U
    if (cell.row - 1 >= 0)
    {
        cells.insert(Cell(cell.row - 1, cell.column));
    }

    // R
    if (cell.column + 1 < columns)
    {
        cells.insert(Cell(cell.row, cell.column + 1));
    }

    // D
    if (cell.row + 1 < rows)
    {
        cells.insert(Cell(cell.row + 1, cell.column));
    }
}

// true if dead.
bool multiplyBunny(std::unordered_set<Cell> & cells, std::vector<std::string> * lair, Cell & playerCell)
{
    std::unordered_set<Cell> cellsToMultiply;
    int rows = lair->size();
    int columns = lair->at(0).size();

    bool isPlayerDead = false;

    for (Cell cell : cells)
    {
        std::string * row = &lair->at(cell.row);
        char * firstChar = &row->at(cell.column);

        if (*firstChar == PLAYERCHAR)
        {
            isPlayerDead = true;
            playerCell.row = cell.row;
            playerCell.column = cell.column;
        }

        *firstChar = BUNNYCHAR;

        addNeibhorCellsToList(cellsToMultiply, rows, columns, cell);
    }

    if (isPlayerDead)
    {
        // printLair(lair);
        // ptintEndGame("dead", rowDead, columnDead);
        return true;
    }

    cells.clear();
    cells = cellsToMultiply;
    return false;
}

// true if dead or win
std::string movePlayer(char direction, std::vector<std::string> * lair, Cell & playerCell)
{
    int rows = lair->size();
    int columns = lair->at(0).size();

    int nextRow;
    int nextColumn;
    switch (direction)
    {
    case 'L':
        nextRow = playerCell.row;
        nextColumn = playerCell.column - 1;
        break;
    case 'U':
        nextRow = playerCell.row - 1;
        nextColumn = playerCell.column;
        break;
    case 'R':
        nextRow = playerCell.row;
        nextColumn = playerCell.column + 1;
        break;
    case 'D':
        nextRow = playerCell.row + 1;
        nextColumn = playerCell.column;
        break;
    default:
        throw "Invalid direction";
    }

    // can exit
    if (0 > nextRow || nextRow >= rows || 0 > nextColumn || nextColumn >= columns)
    {
        *&lair->at(playerCell.row).at(playerCell.column) = '.';
        /*printLair(lair);
        ptintEndGame("won", playerCell.row, playerCell.column);*/
        return "won";
    }
    
    // step on a bunny;
    if (lair->at(nextRow).at(nextColumn) == BUNNYCHAR)
    {
        *&lair->at(playerCell.row).at(playerCell.column) = '.';
        playerCell.column = nextColumn;
        playerCell.row = nextRow;
       /* printLair(lair);
        ptintEndGame("dead", nextRow, nextColumn);*/
        return "dead";
    }

    // :D
    // this strange syntax changes the cell to other value;
    *&lair->at(playerCell.row).at(playerCell.column) = '.';
    
    playerCell.column = nextColumn;
    playerCell.row = nextRow;

    *&lair->at(playerCell.row).at(playerCell.column) = PLAYERCHAR;
    return "";
}

int main()
{
    // the matrix
    std::vector<std::string> lair;

    std::string input;
    std::getline(std::cin, input);
    std::vector<int> lairDimensions = parseArray(input);

    // row and column indexes to multiply, i.e. only the new 'B' cell. 
    std::unordered_set<Cell> cells;
    Cell playerCell = Cell(-1, -1);
    int rows = lairDimensions[0];

    for (int i = 0; i < rows; i++)
    {
        std::string row;
        std::getline(std::cin, row);
        for (int col = 0; col < row.size(); col++)
        {
            if (row.at(col) == BUNNYCHAR)
            {
                addNeibhorCellsToList(cells, rows, lairDimensions[1], Cell(i, col));
                //cells.insert(Cell(i, col));
            }
            else if (row.at(col) == PLAYERCHAR)
            {
                playerCell.row = i;
                playerCell.column = col;
            }
        }

        lair.push_back(row);
    }

    std::string directions;
    std::getline(std::cin, directions);

    for (int i = 0; i < directions.size(); i++)
    {
        std::string playerResult = movePlayer(directions.at(i), &lair, playerCell);
        bool bunnyResult = multiplyBunny(cells, &lair, playerCell);
        
        if (playerResult != "")
        {
            printLair(&lair);
            ptintEndGame(playerResult, playerCell.row, playerCell.column);
            break;
        }

        if (bunnyResult)
        {
            printLair(&lair);
            ptintEndGame("dead", playerCell.row, playerCell.column);
            break;
        }
    }

    return 0;
}
