#include "solutionTwo.h"
#include "utils.h"

array<Coordinate, 2> findNeighbours(Coordinate coordinate)
{
    if (coordinate == upDirection || coordinate == downDirection)
    {
        return rowNeighbours;
    }
    return colNeighbours;
}

string generateNeighbourKey(Coordinate gardenPlot, Coordinate neighbour, Coordinate direction)
{
    return to_string(gardenPlot.row + neighbour.row) + "," + to_string(gardenPlot.col + neighbour.col) + "," + to_string(direction.row) + "," + to_string(direction.col);
}

bool neighbourAlreadyCounted(Coordinate gardenPlot, Coordinate direction, const unordered_map<string, bool> &locallyAlreadyVisited)
{
    auto neighbours = findNeighbours(direction);
    string neighbourKey1 = generateNeighbourKey(gardenPlot, neighbours[0], direction);
    string neightbourKey2 = generateNeighbourKey(gardenPlot, neighbours[1], direction);
    return locallyAlreadyVisited.contains(neighbourKey1) || locallyAlreadyVisited.contains(neightbourKey2);
}

long long calcCostTwo(vector<string> const &input, std::vector<Coordinate> const &connectedPlots, unordered_map<string, bool> &calucatedPerimiters, char currentAreaToken)
{
    long long perimiters = 0;
    unordered_map<string, bool> locallyAlreadyVisited;

    for (auto gardenPlot : connectedPlots)
    {
        string calcKey = to_string(gardenPlot.row) + "-" + to_string(gardenPlot.col);
        calucatedPerimiters[calcKey] = true;
        for (auto direction : directions)
        {
            int newRow = gardenPlot.row + direction.row;
            int newCol = gardenPlot.col + direction.col;
            string currentKey = to_string(gardenPlot.row) + "," + to_string(gardenPlot.col) + "," + to_string(direction.row) + "," + to_string(direction.col);
            if (isOutOfBounds(input, newRow, newCol))
            {
                auto isNeighbourCounted = neighbourAlreadyCounted(gardenPlot, direction, locallyAlreadyVisited);
                if (isNeighbourCounted)
                {
                    locallyAlreadyVisited[currentKey] = true;
                    continue;
                }
                locallyAlreadyVisited[currentKey] = true;
                perimiters++;

                continue;
            }

            auto newAreaToken = input[newRow][newCol];
            if (newAreaToken != currentAreaToken)
            {
                auto isNeighbourCounted = neighbourAlreadyCounted(gardenPlot, direction, locallyAlreadyVisited);
                if (isNeighbourCounted)
                {
                    locallyAlreadyVisited[currentKey] = true;
                    continue;
                }
                locallyAlreadyVisited[currentKey] = true;
                perimiters++;
            }
        }
    }

    return connectedPlots.size() * perimiters;
}

vector<string> solutionTwo(vector<string> const &input)
{
    unordered_map<string, bool> visited;
    unordered_map<string, bool> calucatedPerimiters;
    long long totalSum = 0;

    for (size_t row = 0; row < input.size(); row++)
    {
        for (size_t col = 0; col < input[row].size(); col++)
        {

            string key = to_string(row) + "-" + to_string(col);
            char currentAreaToken = input[row][col];
            auto connectedPlots = findConnectedPlots(input, visited, row, col, key, currentAreaToken);

            if (calucatedPerimiters.contains(key))
            {
                continue;
            }

            sort(connectedPlots.begin(), connectedPlots.end());
            totalSum += calcCostTwo(input, connectedPlots, calucatedPerimiters, currentAreaToken);
        }
    }

    return {to_string({totalSum})};
}
