#include "solutionTwo.h"
#include "utils.h"
#include "constants.h"

bool isMonotonicWithFaultTolerence(const std::vector<int> &report, int initialValue, std::function<bool(int, int)> comparison)
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
            int currentLevel = report[j];
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

int faultTolerenceLimit = 1;

bool isMonotonicWithFaultTolerenceRecursive(const std::vector<int> &report, int initialValue, std::function<bool(int, int)> comparison, int faultTolerence, int faultTolerenceIndex)
{

    if (faultTolerence > faultTolerenceLimit)
    {
        return false;
    }

    int lastLevel = initialValue;
    for (int i = 0; i < report.size(); i++)
    {

        if (faultTolerenceIndex != -1 && i == faultTolerenceIndex)
        {
            continue;
        }

        {
            int currentLevel = report.at(i);
            auto isFaulty = !comparison(currentLevel, lastLevel) && lastLevel != initialValue;
            if (isFaulty)
            {

                return isMonotonicWithFaultTolerenceRecursive(report, initialValue, comparison, faultTolerence + 1, i) || isMonotonicWithFaultTolerenceRecursive(report, initialValue, comparison, faultTolerence + 1, i - 1);
            }
            lastLevel = currentLevel;
        }
    }

    return true;
};

vector<string> solutionTwo(vector<string> const &input)
{
    auto reports = splitLinesToInts(input);
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

vector<string> solutionTwoRecursive(vector<string> const &input)
{
    auto reports = splitLinesToInts(input);
    int safeCounter = 0;

    for (const auto &report : reports)
    {

        auto isIncreasing = isMonotonicWithFaultTolerenceRecursive(report, initialIncreasingValue, increasingComparison, 0, -1);
        auto isDecreasing = isMonotonicWithFaultTolerenceRecursive(report, initialDecreasingValue, decreasingComparison, 0, -1);
        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }

    return {to_string(safeCounter)};
}
