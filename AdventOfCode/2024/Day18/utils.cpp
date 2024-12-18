#include "utils.h"

Board generateBoard(const vector<string> &input)
{
    vector<vector<char>> grid;
    int height = 0;
    int width = 0;
    vector<Coordinate> coordinates;
    for (const auto &line : input)
    {
        smatch match;
        regex_search(line, match, coordinatePattern);
        auto col = stoi(match[1]);
        auto row = stoi(match[2]);
        coordinates.emplace_back(row, col);

        if (col > width)
        {
            width = col;
        }
        if (row > height)
        {
            height = row;
        }
    }

    for (int row = 0; row <= height; row++)
    {
        vector<char> currentRow;
        for (int col = 0; col <= width; col++)
        {
            currentRow.emplace_back(freeToken);
        }
        grid.emplace_back(currentRow);
    }

    return Board{grid, width, height, coordinates};
}

bool isOutOfGrid(const vector<vector<char>> &grid, int row, int col)
{
    if (row < 0 || col < 0)
    {
        return true;
    }
    auto castedRow = static_cast<size_t>(row);
    auto castedCol = static_cast<size_t>(col);

    return castedRow >= grid.size() || castedCol >= grid[row].size();
}

int solver(const vector<vector<char>> &grid, int width, int height)
{

    vector<vector<int>> dp(height + 1, vector<int>(width + 1, INT_MAX));

    Coordinate startCoordinate = {0, 0};
    Coordinate endCoordinate = {width, height};

    priority_queue<State, vector<State>, greater<State>> pq;

    pq.emplace(0, startCoordinate);
    dp[startCoordinate.row][startCoordinate.col] = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        auto currentCost = top.cost;
        auto row = top.coordinate.row;
        auto col = top.coordinate.col;

        pq.pop();
        auto isThereACheaperPath = dp[row][col] < currentCost;
        if (isThereACheaperPath)
        {
            continue;
        }

        for (int newDirection = 0; newDirection < directions.size(); newDirection++)
        {
            int newRow = row + directions[newDirection].row;
            int newCol = col + directions[newDirection].col;

            if (isOutOfGrid(grid, newRow, newCol) || grid[newRow][newCol] == wallToken)
            {
                continue;
            }

            int newCost = currentCost + 1;
            auto isCheapestPath = newCost < dp[newRow][newCol];
            if (isCheapestPath)
            {
                dp[newRow][newCol] = newCost;
                pq.emplace(newCost, Coordinate(newRow, newCol));
            }
        }
    }

    return dp[endCoordinate.row][endCoordinate.col];
}