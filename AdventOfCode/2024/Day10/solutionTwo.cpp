#include "solutionTwo.h"

int calcScore2(vector<string> const &input, Coordinate const &startingZone, Coordinate const &currentZone)
{
    if (isOutOfBound(input, currentZone))
    {
        return 0;
    }

    if (isFinished(input, currentZone))
    {
        return 1;
    }

    vector<int> scores;
    for (const auto &directon : directions)
    {
        Coordinate nextZone = {currentZone.row + directon.row, currentZone.col + directon.col};

        if (isOutOfBound(input, nextZone))
        {
            continue;
        }

        int oldHeight = input[currentZone.row][currentZone.col] - '0';
        int newHeight = input[nextZone.row][nextZone.col] - '0';
        bool isCorrectHeight = oldHeight + 1 == newHeight;

        if (isCorrectHeight)
        {
            scores.emplace_back(calcScore2(input, startingZone, nextZone));
        }
    }

    return accumulate(scores.begin(), scores.end(), 0);
}

vector<string> solutionTwo(vector<string> const &input)
{
    vector<Coordinate> startingZones;

    for (size_t row = 0; row < input.size(); row++)
    {
        for (size_t col = 0; col < input[0].size(); col++)
        {
            if (input[row][col] == '0')
            {
                startingZones.emplace_back(row, col);
            }
        }
    }

    int sum = 0;

    for (const auto &startingZone : startingZones)
    {
        sum += calcScore2(input, startingZone, startingZone);
    }

    return {std::to_string(sum)};
}
