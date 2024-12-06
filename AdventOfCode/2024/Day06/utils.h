#include <string>
#include <vector>
#include "constants.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_H
#define ADVENT_OF_CODE_UTILS_H

struct Coordinate
{
    int row;
    int col;

    Coordinate operator+(const Coordinate &rhs)
    {
        auto cord = Coordinate(this->row + rhs.row, this->col + rhs.col);
        return cord;
    }

    bool operator==(const Coordinate &rhs)
    {
        auto isEqual = this->row == rhs.row && this->col == rhs.col;
        return isEqual;
    }
};

struct GuardPosition
{
    Coordinate position;
    Coordinate direction;
};

Coordinate findGuardPosition(vector<string> const &input);

Coordinate rotate(Coordinate currentDirection);

extern Coordinate upDirection;
extern Coordinate downDirection;
extern Coordinate leftDirection;
extern Coordinate rightDirection;

extern char obstacle;
extern char freeSpace;
extern char guard;

#endif // ADVENT_OF_CODE_UTILS_H