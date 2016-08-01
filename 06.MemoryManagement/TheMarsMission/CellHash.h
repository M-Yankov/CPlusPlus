#ifndef CELLHASH_h
#define CELLHASH_h

#include <unordered_set>
#include "Cell.h"

/// <summary>
/// http://stackoverflow.com/questions/18098178/how-do-i-use-unordered-set
/// </summary>
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

#endif // !CELLHASH_h
