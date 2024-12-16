#include "solutionOne.h"

using namespace std;

struct State
{
    int cost;
    int row;
    int col;
    int direction;
    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};

vector<string> solutionOne(vector<string> const &input)
{
    int height = input.size();
    int width = input[0].size();

    vector<vector<vector<int>>> dp(height, vector<vector<int>>(width, vector<int>(4, INT_MAX)));

    Coordinate startCoordinate;
    Coordinate endCoordinate;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
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

    priority_queue<State, vector<State>, greater<State>> pq;

    int startDirection = 1;
    for (int i = 0; i < 4; i++)
    {
        dp[startCoordinate.row][startCoordinate.col][i] = 0;
        pq.emplace(0, startCoordinate.row, startCoordinate.col, startDirection);
    }

    while (!pq.empty())
    {
        auto top = pq.top();
        auto currentCost = top.cost;
        auto row = top.row;
        auto col = top.col;
        auto direction = top.direction;

        pq.pop();

        if (dp[row][col][direction] < currentCost)
        {
            continue;
        }

        for (int newDirection = 0; newDirection < directions.size(); newDirection++)
        {
            int newRow = row + directions[newDirection].row;
            int newCol = col + directions[newDirection].col;

            if (input[newRow][newCol] == wallToken)
            {
                continue;
            }

            int additionalCost = (newDirection == direction) ? 1 : 1001;
            int newCost = currentCost + additionalCost;

            if (newCost < dp[newRow][newCol][newDirection])
            {
                dp[newRow][newCol][newDirection] = newCost;
                pq.emplace(newCost, newRow, newCol, newDirection);
            }
        }
    }

    int minCost = INT_MAX;
    for (int i = 0; i < directions.size(); i++)
    {
        minCost = min(minCost, dp[endCoordinate.row][endCoordinate.col][i]);
    }

    return {to_string(minCost)};
}