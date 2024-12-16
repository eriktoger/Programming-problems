#include "solutionTwo.h"

struct DPEntry
{
    int cost;
    vector<vector<Coordinate>> paths;
};

struct State2
{
    int cost;
    int row;
    int col;
    int direction;
    vector<Coordinate> path;
    bool operator>(const State2 &other) const
    {
        return cost > other.cost;
    }
};

vector<string> solutionTwo(const vector<string> &input)
{
    int rows = input.size();
    int cols = input[0].size();

    vector<vector<vector<DPEntry>>> dp(rows, vector<vector<DPEntry>>(cols, vector<DPEntry>(4, {INT_MAX, {}})));

    Coordinate startCoordinate;
    Coordinate endCoordinate;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (input[r][c] == startToken)
                startCoordinate = {r, c};
            else if (input[r][c] == endToken)
                endCoordinate = {r, c};
        }
    }

    auto comparator = [](const State2 &a,
                         const State2 &b)
    {
        return a.cost > b.cost;
    };

    priority_queue<State2, vector<State2>, decltype(comparator)> pq(comparator);

    for (int dir = 0; dir < 4; ++dir)
    {
        dp[startCoordinate.row][startCoordinate.col][dir].cost = 0;
        dp[startCoordinate.row][startCoordinate.col][dir].paths.push_back({startCoordinate});
        pq.emplace(0, startCoordinate.row, startCoordinate.col, dir, vector<Coordinate>{startCoordinate});
    }

    while (!pq.empty())
    {
        auto top = pq.top();
        auto currentCost = top.cost;
        auto row = top.row;
        auto col = top.col;
        auto direction = top.direction;
        auto path = top.path;

        pq.pop();

        if (dp[row][col][direction].cost < currentCost)
        {
            continue;
        }

        for (int newDirection = 0; newDirection < 4; ++newDirection)
        {
            int newRow = row + directions[newDirection].row;
            int newCol = col + directions[newDirection].col;

            if (input[newRow][newCol] == wallToken)
            {
                continue;
            }

            int additionalCost = (newDirection == direction) ? 1 : 1001;
            int newCost = currentCost + additionalCost;
            vector<Coordinate> newPath = path;
            newPath.emplace_back(newRow, newCol);

            if (newCost < dp[newRow][newCol][newDirection].cost)
            {
                dp[newRow][newCol][newDirection].cost = newCost;
                dp[newRow][newCol][newDirection].paths = {newPath};
                pq.emplace(newCost, newRow, newCol, newDirection, newPath);
            }
            else if (newCost == dp[newRow][newCol][newDirection].cost)
            {
                dp[newRow][newCol][newDirection].paths.push_back(newPath);
                pq.emplace(newCost, newRow, newCol, newDirection, newPath);
            }
        }
    }

    int minCost = INT_MAX;
    vector<vector<Coordinate>> allPaths;

    for (int dir = 0; dir < 4; ++dir)
    {
        if (dp[endCoordinate.row][endCoordinate.col][dir].cost < minCost)
        {
            minCost = dp[endCoordinate.row][endCoordinate.col][dir].cost;
            allPaths = dp[endCoordinate.row][endCoordinate.col][dir].paths;
        }
    }

    unordered_set<Coordinate, CoordinateHash> uniquePaths;
    for (auto &paths : allPaths)
    {
        for (auto &path : paths)
        {
            uniquePaths.insert(path);
        }
    }

    return {to_string(uniquePaths.size())};
}
