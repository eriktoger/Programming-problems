#include "utils.h"

vector<Coordinate> findConnectedPlots(vector<string> const &input, unordered_map<string, bool> &visited, int row, int col, string key, char currentAreaToken)
{
    vector<Coordinate> visitedGardenPlots{Coordinate{row, col}};
    unordered_map<string, bool> visitedLocally;
    visitedLocally[key] = true;
    size_t gardenPlotIndex = 0;

    while (gardenPlotIndex < visitedGardenPlots.size())
    {
        auto currentGardenPlot = visitedGardenPlots[gardenPlotIndex];

        string key = to_string(currentGardenPlot.row) + "-" + to_string(currentGardenPlot.col);
        if (visited.contains(key))
        {
            gardenPlotIndex++;
            continue;
        }

        visited[key] = true;

        for (auto direction : directions)
        {
            int newRow = currentGardenPlot.row + direction.row;
            int newCol = currentGardenPlot.col + direction.col;
            if (isOutOfBounds(input, newRow, newCol))
            {
                continue;
            }

            auto newAreaToken = input[newRow][newCol];
            string newAreakey = to_string(newRow) + "-" + to_string(newCol);

            if (newAreaToken == currentAreaToken)
            {

                if (visited.contains(newAreakey) || visitedLocally.contains(newAreakey))
                {
                    continue;
                }
                visitedLocally[newAreakey] = true;
                visitedGardenPlots.emplace_back(Coordinate{newRow, newCol});
            }
        }
        gardenPlotIndex++;
    }
    return visitedGardenPlots;
}