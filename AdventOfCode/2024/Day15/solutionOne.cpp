#include "solutionOne.h"

void moveRobot(vector<string> &grid, Coordinate &robotPosition, const Coordinate &direction)
{
    auto firstFreePosition = Coordinate{-1, -1};
    auto tempRobotPosition = robotPosition;
    while (true)
    {
        tempRobotPosition += direction;

        auto currentToken = grid[tempRobotPosition.row][tempRobotPosition.col];
        if (currentToken == wallToken)
        {
            break;
        }
        if (currentToken == freeToken)
        {
            firstFreePosition = tempRobotPosition;
            break;
        }
    }

    if (firstFreePosition.row != -1)
    {
        grid[robotPosition.row][robotPosition.col] = freeToken;
        robotPosition += direction;

        if (grid[robotPosition.row][robotPosition.col] == boxToken)
        {
            grid[firstFreePosition.row][firstFreePosition.col] = boxToken;
        }
        grid[robotPosition.row][robotPosition.col] = robotToken;
    }
}

vector<string> solutionOne(vector<string> const &input)
{

    vector<string> grid;
    vector<string> commands;

    for (const auto &line : input)
    {
        if (line.starts_with("#"))
        {
            grid.emplace_back(line);
        }
        else
        {
            commands.emplace_back(line);
        }
    }

    Coordinate robotPosition;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == robotToken)
            {
                robotPosition.row = row;
                robotPosition.col = col;
            }
        }
    }

    for (const auto &command : commands)
    {
        for (const auto token : command)
        {
            if (token == upToken)
            {
                moveRobot(grid, robotPosition, upDirection);
            }
            else if (token == rightToken)
            {
                moveRobot(grid, robotPosition, rightDirection);
            }
            else if (token == downToken)
            {
                moveRobot(grid, robotPosition, downDirection);
            }
            else if (token == leftToken)
            {
                moveRobot(grid, robotPosition, leftDirection);
            }
        }
    }

    long long sum = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == boxToken)
            {
                sum += 100 * row + col;
            }
        }
    }

    return {to_string(sum)};
}
