#include "solutionTwo.h"
#include "utils.h"
#include "constants.h"

bool isMonotonicWithFaultTolerence(const std::vector<std::string> &report, int initialValue, std::function<bool(int, int)> comparison)
{
    for (int i = 0; i < report.size(); i++)
    {
        bool isValid = true;
        int lastLevel = initialValue;

        for (int j = 0; j < report.size(); j++)
        {
            auto skippingOneLevel = i == j;
            if (skippingOneLevel)
            {
                continue;
            }
            int currentLevel = stoi(report[j]);
            auto isFaulty = !comparison(currentLevel, lastLevel) && lastLevel != initialValue;
            if (isFaulty)
            {
                isValid = false;
                break;
            }
            lastLevel = currentLevel;
        }

        if (isValid)
        {
            return true;
        }
    }

    return false;
};

vector<string> solutionTwo(vector<string> const &input)
{
    auto reports = splitLinesToWords(input);
    int safeCounter = 0;

    for (const auto &report : reports)
    {

        auto isIncreasing = isMonotonicWithFaultTolerence(report, initialIncreasingValue, increasingComparison);
        auto isDecreasing = isMonotonicWithFaultTolerence(report, initialDecreasingValue, decreasingComparison);
        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }

    return {to_string(safeCounter)};
}
