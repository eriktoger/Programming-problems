#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{

    vector<Coordinate> originCoordinates = getStartEndCoordinates(input);
    Coordinate startCoordinate = originCoordinates[0];
    Coordinate endCoordinate = originCoordinates[1];

    auto result = solver(input, startCoordinate, INT_MAX, wallToken);

    auto stepsWithoutCheating = result[endCoordinate.row][endCoordinate.col];
    auto tempInput = input;
    unordered_map<int, int> nrOfStepsSaved;
    auto timeToBeat = result[endCoordinate.row][endCoordinate.col] - 100;

    for (int row = 1; row < input.size() - 1; row++)
    {
        for (int col = 1; col < input[row].size() - 1; col++)
        {

            if (input[row][col] == wallToken)
            {
                tempInput[row][col] = freeToken;
                auto result = solver(tempInput, startCoordinate, timeToBeat, wallToken);
                auto stepsWithCheating = result[endCoordinate.row][endCoordinate.col];
                auto diff = stepsWithoutCheating - stepsWithCheating;
                nrOfStepsSaved[diff]++;
                tempInput[row][col] = wallToken;
            }
        }
    }

    auto totalStepsSaved = getTotalSavedSteps(nrOfStepsSaved);
    return {to_string(totalStepsSaved)};
}
