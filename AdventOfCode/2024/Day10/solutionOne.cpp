#include "solutionOne.h"

int calcScore(vector<string> const &input, unordered_map<string, bool> &exits, Coordinate const &startingZone, Coordinate const &currentZone)
{
    if (isOutOfBound(input, currentZone))
    {
        return 0;
    }

    if (isFinished(input, currentZone))
    {
        string key = to_string(startingZone.row) + "," + to_string(startingZone.col) + "," + to_string(currentZone.row) + "," + to_string(currentZone.col);
        if (exits.contains(key))
        {
            return 0;
        }
        exits[key] = true;
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
            scores.emplace_back(calcScore(input, exits, startingZone, nextZone));
        }
    }

    return accumulate(scores.begin(), scores.end(), 0);
}

vector<string> solutionOne(vector<string> const &input)
{
    vector<Coordinate> startingZones;
    unordered_map<string, bool> exits;

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
        sum += calcScore(input, exits, startingZone, startingZone);
    }

    return {std::to_string(sum)};
}
