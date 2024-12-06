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

    bool operator==(const Coordinate &rhs) const
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

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate leftDirection = {0, -1};
constexpr Coordinate rightDirection = {0, 1};

constexpr char obstacle = '#';
constexpr char freeSpace = '.';
constexpr char guard = '^';

#endif // ADVENT_OF_CODE_UTILS_H