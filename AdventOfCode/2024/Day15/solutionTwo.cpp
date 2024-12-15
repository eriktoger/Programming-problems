#include "solutionTwo.h"

struct Box
{
    Coordinate leftPosition;
    Coordinate rightPosition;

    Box(Coordinate left, Coordinate right) : leftPosition(left), rightPosition(right) {}

    bool operator==(const Box &other) const
    {
        return leftPosition == other.leftPosition && rightPosition == other.rightPosition;
    }
};

struct Coordhash
{
    size_t operator()(const Coordinate &coord) const
    {
        size_t h1 = std::hash<int>{}(coord.row);
        size_t h2 = std::hash<int>{}(coord.col);
        return h1 ^ (h2 * 31);
    }
};
struct Boxhash
{
    size_t operator()(const Box &box) const
    {
        size_t h1 = Coordhash{}(box.leftPosition);
        size_t h2 = Coordhash{}(box.rightPosition);
        return h1 ^ (h2 * 37);
    }
};

bool canWePushVertical(vector<string> &grid, Coordinate currentPoistion, Coordinate direction, unordered_set<Box, Boxhash> &affectedBoxes)
{
    auto tempPosition = currentPoistion + direction;
    auto currentToken = grid[tempPosition.row][tempPosition.col];
    if (currentToken == wallToken)
    {
        return false;
    }
    if (currentToken == freeToken)
    {
        return true;
    }

    if (currentToken == leftBoxToken)
    {
        auto leftBoxPosition = tempPosition;
        auto rightBoxPosition = leftBoxPosition + rightDirection;
        auto box = Box(leftBoxPosition, rightBoxPosition);
        affectedBoxes.insert(box);
        return canWePushVertical(grid, leftBoxPosition, direction, affectedBoxes) && canWePushVertical(grid, rightBoxPosition, direction, affectedBoxes);
    }

    auto rightBoxPosition = tempPosition;
    auto leftBoxPosition = rightBoxPosition + leftDirection;
    auto box = Box(leftBoxPosition, rightBoxPosition);
    affectedBoxes.insert(box);
    return canWePushVertical(grid, rightBoxPosition, direction, affectedBoxes) && canWePushVertical(grid, leftBoxPosition, direction, affectedBoxes);
}

void pullVertical(vector<string> &grid, Coordinate startPosition, Coordinate direction, unordered_set<Box, Boxhash> &affectedBoxes)
{

    vector<Box> boxes(affectedBoxes.begin(), affectedBoxes.end());

    sort(boxes.begin(), boxes.end(), [direction](const Box &a, const Box &b)
         {

             if (direction == upDirection)
             {
                 return a.leftPosition.row < b.leftPosition.row;
             }
             if (direction == downDirection)
             {
                 return a.leftPosition.row > b.leftPosition.row;
             }
             if (direction == leftDirection)
             {
                 return a.leftPosition.col < b.leftPosition.col;
             }
             if (direction == rightDirection)
             {
                 return a.leftPosition.col > b.leftPosition.col;
             }
             return false; });

    for (const auto &box : boxes)
    {
        auto newLeftBoxPosition = box.leftPosition + direction;
        auto newRightBoxPosition = box.rightPosition + direction;

        grid[newLeftBoxPosition.row][newLeftBoxPosition.col] = grid[box.leftPosition.row][box.leftPosition.col];
        grid[newRightBoxPosition.row][newRightBoxPosition.col] = grid[box.rightPosition.row][box.rightPosition.col];

        grid[box.leftPosition.row][box.leftPosition.col] = freeToken;
        grid[box.rightPosition.row][box.rightPosition.col] = freeToken;
    }
}

void updateRobot(vector<string> &grid, Coordinate &robotPosition, Coordinate direction)
{
    grid[robotPosition.row][robotPosition.col] = freeToken;
    robotPosition += direction;
    grid[robotPosition.row][robotPosition.col] = robotToken;
}

bool canWePushHorizontal(vector<string> &grid, Coordinate currentPoistion, Coordinate direction)
{
    while (true)
    {
        currentPoistion += direction;

        auto currentToken = grid[currentPoistion.row][currentPoistion.col];
        if (currentToken == wallToken)
        {
            return false;
        }
        if (currentToken == freeToken)
        {
            return true;
        }
    }
}

void pushHorizontal(vector<string> &grid, Coordinate startPosition, Coordinate direction)
{
    char prevToken = grid[startPosition.row][startPosition.col];
    auto currentPosition = startPosition;
    while (true)
    {
        auto tempPosition = currentPosition + direction;
        auto tempToken = grid[tempPosition.row][tempPosition.col];

        if (tempToken == freeToken)
        {
            grid[tempPosition.row][tempPosition.col] = prevToken;
            grid[startPosition.row][startPosition.col] = freeToken;
            break;
        }
        grid[tempPosition.row][tempPosition.col] = prevToken;
        prevToken = tempToken;
        currentPosition = tempPosition;
    }
}

void moveRobot2(vector<string> &grid, Coordinate &robotPosition, const Coordinate &direction)
{
    auto tempRobotPosition = robotPosition;

    tempRobotPosition += direction;
    auto currentToken = grid[tempRobotPosition.row][tempRobotPosition.col];

    if (currentToken == wallToken)
    {
        return;
    }

    if (currentToken == freeToken)
    {
        updateRobot(grid, robotPosition, direction);
        return;
    }

    if (direction == downDirection || direction == upDirection)
    {
        unordered_set<Box, Boxhash> affectedBoxes;
        if (canWePushVertical(grid, robotPosition, direction, affectedBoxes))
        {
            pullVertical(grid, robotPosition, direction, affectedBoxes);
            updateRobot(grid, robotPosition, direction);
        }
    }
    else
    {
        if (canWePushHorizontal(grid, robotPosition, direction))
        {
            pushHorizontal(grid, robotPosition, direction);
            updateRobot(grid, robotPosition, direction);
        }
    }
}

vector<string> solutionTwo(vector<string> const &input)
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

    vector<string> extendedGrid;
    for (const auto &row : grid)
    {
        string currentRow;
        for (const auto &token : row)
        {
            if (token == wallToken)
            {
                currentRow += wallToken;
                currentRow += wallToken;
            }
            else if (token == boxToken)
            {
                currentRow += leftBoxToken;
                currentRow += rightBoxToken;
            }
            else if (token == freeToken)
            {
                currentRow += freeToken;
                currentRow += freeToken;
            }
            else if (token == robotToken)
            {
                currentRow += robotToken;
                currentRow += freeToken;
            }
        }
        extendedGrid.emplace_back(currentRow);
    }
    grid.clear();

    Coordinate robotPosition;
    for (int row = 0; row < extendedGrid.size(); row++)
    {
        for (int col = 0; col < extendedGrid[0].size(); col++)
        {
            if (extendedGrid[row][col] == robotToken)
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
                moveRobot2(extendedGrid, robotPosition, upDirection);
            }
            else if (token == rightToken)
            {
                moveRobot2(extendedGrid, robotPosition, rightDirection);
            }
            else if (token == downToken)
            {
                moveRobot2(extendedGrid, robotPosition, downDirection);
            }
            else if (token == leftToken)
            {
                moveRobot2(extendedGrid, robotPosition, leftDirection);
            }
        }
    }

    long long sum = 0;
    for (int row = 0; row < extendedGrid.size(); row++)
    {
        for (int col = 0; col < extendedGrid[0].size(); col++)
        {
            if (extendedGrid[row][col] == leftBoxToken)
            {
                sum += 100 * row + col;
            }
        }
    }

    return {to_string(sum)};
}
