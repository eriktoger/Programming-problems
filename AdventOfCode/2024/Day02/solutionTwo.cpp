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

int faultTolerenceLimit = 1;

bool isMonotonicWithFaultTolerenceRecursive(const std::vector<std::string> &report, int initialValue, std::function<bool(int, int)> comparison, int faultTolerence)
{

    if (faultTolerence > faultTolerenceLimit)
    {
        return false;
    }

    int lastLevel = initialValue;
    for (int i = 0; i < report.size(); i++)
    {
        int currentLevel = stoi(report.at(i));
        auto isFaulty = !comparison(currentLevel, lastLevel) && lastLevel != initialValue;
        if (isFaulty)
        {
            vector<string> removedFirstFault;
            vector<string> removedSecondFault;
            for (size_t j = 0; j < report.size(); j++)
            {
                if (i != j)
                {
                    removedFirstFault.push_back(report[j]);
                }
                if (i - 1 != j)
                {
                    removedSecondFault.push_back(report[j]);
                }
            }
            bool firstFault = isMonotonicWithFaultTolerenceRecursive(removedFirstFault, initialValue, comparison, faultTolerence + 1);
            bool secondFault = isMonotonicWithFaultTolerenceRecursive(removedSecondFault, initialValue, comparison, faultTolerence + 1);
            return firstFault || secondFault;
        }
        lastLevel = currentLevel;
    }

    return true;
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

vector<string> solutionTwoRecursive(vector<string> const &input)
{
    auto reports = splitLinesToWords(input);
    int safeCounter = 0;

    for (const auto &report : reports)
    {

        auto isIncreasing = isMonotonicWithFaultTolerenceRecursive(report, initialIncreasingValue, increasingComparison, 0);
        auto isDecreasing = isMonotonicWithFaultTolerenceRecursive(report, initialDecreasingValue, decreasingComparison, 0);
        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }

    return {to_string(safeCounter)};
}
