#include "solutionTwo.h"

struct Position
{
    int cost;
    Coordinate coordinate;
};

int getDistence(Coordinate const &a, Coordinate const &b)
{
    return abs(a.row - b.row) + abs(a.col - b.col);
}

vector<string> solutionTwo(vector<string> const &input)
{

    vector<Coordinate> originCoordinates = getStartEndCoordinates(input);
    Coordinate startCoordinate = originCoordinates[0];
    Coordinate endCoordinate = originCoordinates[1];

    auto result = solver(input, startCoordinate, INT_MAX, wallToken);
    vector<Position> positions;
    for (int row = 0; row < result.size(); row++)
    {
        for (int col = 0; col < result[row].size(); col++)
        {
            auto cost = result[row][col];
            if (cost < INT_MAX)
            {
                positions.emplace_back(cost, Coordinate{row, col});
            }
        }
    }

    sort(positions.begin(), positions.end(), [](Position const &a, Position const &b)
         { return a.cost < b.cost; });

    unordered_map<int, int> nrOfStepsSaved;

    auto stepsWithoutCheating = result[endCoordinate.row][endCoordinate.col];
    auto tempInput = input;
    for (int i = 0; i < positions.size() - 1; i++)
    {
        for (int j = i + 1; j < positions.size(); j++)
        {
            auto dist = getDistence(positions[i].coordinate, positions[j].coordinate);
            if (dist > 20)
            {
                continue;
            }

            auto stepsTaken = positions[i].cost;
            auto cheatSteps = dist;
            auto stepsLeft = stepsWithoutCheating - positions[j].cost;
            auto steps = stepsTaken + cheatSteps + stepsLeft;
            auto stepsSaved = stepsWithoutCheating - steps;

            if (stepsSaved > 0)
            {
                nrOfStepsSaved[stepsSaved]++;
            }
        }
    }

    auto totalStepsSaved = getTotalSavedSteps(nrOfStepsSaved);

    return {to_string(totalStepsSaved)};
}