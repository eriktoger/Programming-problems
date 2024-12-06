#include "solutionTwo.h"

vector<string> solutionTwo(vector<string> const &input)
{
    auto guardPosition = findGuardPosition(input);

    Coordinate currentDirection = upDirection;
    auto startingKey = to_string(guardPosition.row) + "," + to_string(guardPosition.col);
    map<string, bool> distinctPositions;
    distinctPositions[startingKey] = true;
    while (true)
    {
        auto nextGuardPosition = guardPosition + currentDirection;

        bool outOfbound = nextGuardPosition.row < 0 || nextGuardPosition.row >= input.size() || nextGuardPosition.col < 0 || nextGuardPosition.col >= input[nextGuardPosition.row].size();
        if (outOfbound)
        {
            break;
        }

        if (input[nextGuardPosition.row][nextGuardPosition.col] == obstacle)
        {
            currentDirection = rotate(currentDirection);
            continue;
        }
        guardPosition = nextGuardPosition;
        auto mapKey = to_string(guardPosition.row) + "," + to_string(guardPosition.col);
        if (!distinctPositions.contains(mapKey))
        {

            distinctPositions[mapKey] = true;
        }
    }

    return {to_string(distinctPositions.size())};
}
