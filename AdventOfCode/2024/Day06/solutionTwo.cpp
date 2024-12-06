#include "solutionTwo.h"

string generateKey(Coordinate guardPosition, Coordinate currentDirection)
{
    return to_string(guardPosition.row) + "," + to_string(guardPosition.col) + "," + to_string(currentDirection.row) + "," + to_string(currentDirection.col);
}

bool isOutOfBound(vector<string> const &input, Coordinate nextGuardPosition)
{
    return nextGuardPosition.row < 0 || nextGuardPosition.row >= input.size() || nextGuardPosition.col < 0 || nextGuardPosition.col >= input[nextGuardPosition.row].size();
}

vector<Coordinate> getSteps(vector<string> const &input, Coordinate startPosition)
{
    vector<Coordinate> steps;
    Coordinate currentDirection = upDirection;
    auto guardPosition = startPosition;
    while (true)
    {
        auto nextGuardPosition = guardPosition + currentDirection;

        if (isOutOfBound(input, nextGuardPosition))
        {
            steps.emplace_back(guardPosition);
            break;
        }

        if (input[nextGuardPosition.row][nextGuardPosition.col] == obstacle)
        {
            currentDirection = rotate(currentDirection);
            continue;
        }

        if (guardPosition != startPosition)
        {
            steps.emplace_back(guardPosition);
        }

        guardPosition = nextGuardPosition;
    }
    return steps;
}

int calcObstacale(vector<string> &input, Coordinate startPosition, vector<Coordinate> const &steps)
{
    map<string, bool> visited;
    auto guardPosition = startPosition;
    Coordinate currentDirection = upDirection;
    int obstacaleCounter = 0;

    for (auto step : steps)
    {
        auto currentSpot = input[step.row][step.col];
        auto visitedKey = to_string(step.row) + "," + to_string(step.col);
        auto isVisited = visited.contains(visitedKey);

        if (currentSpot != freeSpace || isVisited)
        {
            continue;
        }

        visited[visitedKey] = true;
        input[step.row][step.col] = obstacle;
        map<string, bool> visitedSpots;
        guardPosition = startPosition;
        currentDirection = upDirection;

        while (true)
        {
            auto nextGuardPosition = guardPosition + currentDirection;

            if (isOutOfBound(input, nextGuardPosition))
            {
                break;
            }

            auto key = generateKey(nextGuardPosition, currentDirection);
            if (visitedSpots.contains(key))
            {
                obstacaleCounter++;
                break;
            }
            else
            {
                visitedSpots[key] = true;
            }

            if (input[nextGuardPosition.row][nextGuardPosition.col] == obstacle)
            {
                currentDirection = rotate(currentDirection);
                continue;
            }

            guardPosition = nextGuardPosition;
        }

        input[step.row][step.col] = freeSpace;
    }

    return obstacaleCounter;
}

vector<string> solutionTwo(vector<string> const &input)
{
    auto startPosition = findGuardPosition(input);

    Coordinate currentDirection = upDirection;
    auto startingKey = generateKey(startPosition, currentDirection);
    map<string, bool> distinctPositions;
    map<string, bool> visitedObstacles;
    distinctPositions[startingKey] = true;

    auto steps = getSteps(input, startPosition);
    auto copyInput = input;
    auto obstacaleCounter = calcObstacale(copyInput, startPosition, steps);

    return {to_string(obstacaleCounter)};
}
