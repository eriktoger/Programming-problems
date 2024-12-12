#include "solutionOne.h"
#include "utils.h"

struct GardenPlot
{
    int row;
    int col;
    int perimiters;
};

long long calcCost(vector<string> const &input, const std::vector<Coordinate> &connectedPlots, unordered_map<string, bool> &alreadyPermitorCalculated, char currentAreaToken)
{
    int perimiters = 0;
    for (auto gardenPlot : connectedPlots)
    {
        alreadyPermitorCalculated[to_string(gardenPlot.row) + "-" + to_string(gardenPlot.col)] = true;

        for (auto direction : directions)
        {
            int newRow = gardenPlot.row + direction.row;
            int newCol = gardenPlot.col + direction.col;
            if (isOutOfBounds(input, newRow, newCol))
            {
                perimiters++;
                continue;
            }

            auto newAreaToken = input[newRow][newCol];
            if (newAreaToken != currentAreaToken)
            {
                perimiters++;
            }
        }
    }
    return connectedPlots.size() * perimiters;
}

vector<string> solutionOne(vector<string> const &input)
{
    unordered_map<string, bool> alreadyVisited;
    unordered_map<string, bool> alreadyPermitorCalculated;
    long long totalSum = 0;

    for (size_t row = 0; row < input.size(); row++)
    {
        for (size_t col = 0; col < input[row].size(); col++)
        {

            string key = to_string(row) + "-" + to_string(col);
            char currentAreaToken = input[row][col];
            auto connectedPlots = findConnectedPlots(input, alreadyVisited, row, col, key, currentAreaToken);

            if (alreadyPermitorCalculated.contains(key))
            {
                continue;
            }

            totalSum += calcCost(input, connectedPlots, alreadyPermitorCalculated, currentAreaToken);
        }
    }
    return {to_string({totalSum})};
}
