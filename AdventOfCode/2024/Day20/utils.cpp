#include "utils.h"

vector<vector<int>> solver(const vector<string> &input, Coordinate startCoordinate, int timeToBeat, char stopToken)
{

    vector<vector<int>> dp(input.size(), vector<int>(input[0].size(), INT_MAX));

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

            if (isOutOfBounds(input, newRow, newCol) || input[newRow][newCol] == stopToken)
            {
                continue;
            }

            int newCost = currentCost + 1;

            if (newCost > timeToBeat)
            {
                continue;
            }

            auto isCheapestPath = newCost < dp[newRow][newCol];
            if (isCheapestPath)
            {
                dp[newRow][newCol] = newCost;
                pq.emplace(newCost, Coordinate(newRow, newCol));
            }
        }
    }

    return dp;
}

vector<Coordinate> getStartEndCoordinates(vector<string> const &input)
{

    Coordinate startCoordinate;
    Coordinate endCoordinate;

    for (int row = 1; row < input.size() - 1; row++)
    {
        for (int col = 1; col < input[row].size() - 1; col++)
        {
            char token = input[row][col];
            if (token == startToken)
            {
                startCoordinate = {row, col};
            }
            if (token == endToken)
            {
                endCoordinate = {row, col};
            }
        }
    }

    return {startCoordinate, endCoordinate};
}

unsigned long long getTotalSavedSteps(std::unordered_map<int, int> nrOfStepsSaved)
{
    auto totalStepsSaved = 0ull;

    for (auto [steps, count] : nrOfStepsSaved)
    {
        if (steps >= 100)
        {
            totalStepsSaved += count;
        }
    }
    return totalStepsSaved;
}