#include "utils.h"

Coordinate findGuardPosition(vector<string> const &input)
{
    for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++)
    {
        auto row = input[rowIndex];
        for (size_t colIndex = 0; colIndex < row.size(); colIndex++)
        {
            if (row[colIndex] == guard)
            {
                return {rowIndex, colIndex};
            }
        }
    }

    return {-1, -1};
}

Coordinate rotate(Coordinate currentDirection)
{
    if (currentDirection == upDirection)
    {
        return rightDirection;
    }
    else if (currentDirection == rightDirection)
    {
        return downDirection;
    }
    else if (currentDirection == downDirection)
    {
        return leftDirection;
    }
    else
    {
        return upDirection;
    }
}
