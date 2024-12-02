#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    auto reports = splitLinesToWords(input);
    int safeCounter = 0;
    for (auto report : reports)
    {
        bool isIncreasing = true;
        int lastIncreasingLevel = -1;
        for (auto level : report)
        {
            auto currentLevel = stoi(level);

            if ((currentLevel <= lastIncreasingLevel || currentLevel - lastIncreasingLevel > 3) && lastIncreasingLevel != -1)
            {
                isIncreasing = false;
                break;
            }
            lastIncreasingLevel = currentLevel;
        }

        bool isDecreasing = true;
        int lastDecreasingLevel = 99999;
        for (auto level : report)
        {
            auto currentLevel = stoi(level);
            if ((currentLevel >= lastDecreasingLevel || lastDecreasingLevel - currentLevel > 3) && lastDecreasingLevel != 99999)
            {
                isDecreasing = false;
                break;
            }
            lastDecreasingLevel = currentLevel;
        }
        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }
    vector<string> result{to_string(safeCounter)};
    return result;
}
