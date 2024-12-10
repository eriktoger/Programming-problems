#include "utils.h"

bool isOutOfBound(vector<string> const &input, Coordinate const &currentZone)
{
    return currentZone.row < 0 || currentZone.row >= input.size() || currentZone.col < 0 || currentZone.col >= input[0].size();
}

bool isFinished(vector<string> const &input, Coordinate const &currentZone)
{

    return input[currentZone.row][currentZone.col] == '9';
}