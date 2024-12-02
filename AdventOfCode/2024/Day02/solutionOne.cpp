#include "solutionOne.h"
#include "utils.h"

bool isMonotonic(const std::vector<std::string> &report, int initialValue, std::function<bool(int, int)> comparison)
{
    int lastLevel = initialValue;
    for (auto &level : report)
    {
        int currentLevel = stoi(level);
        auto isFaulty = !comparison(currentLevel, lastLevel) && lastLevel != initialValue;
        if (isFaulty)
        {
            return false;
        }
        lastLevel = currentLevel;
    }

    return true;
};

vector<string> solutionOne(vector<string> const &input)
{
    auto reports = splitLinesToWords(input);
    int safeCounter = 0;

    for (const auto &report : reports)
    {

        auto isIncreasing = isMonotonic(report, initialIncreasingValue, increasingComparison);
        auto isDecreasing = isMonotonic(report, initialDecreasingValue, decreasingComparison);
        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }

    return {to_string(safeCounter)};
}