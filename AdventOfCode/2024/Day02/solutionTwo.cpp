#include "solutionTwo.h"

vector<string> solutionTwo(vector<string> const &input)
{
    auto reports = splitLinesToWords(input);
    int safeCounter = 0;
    for (auto report : reports)
    {

        bool isIncreasing = true;
        for (int i = 0; i < report.size(); i++)
        {
            int lastIncreasingLevel = -1;
            isIncreasing = true;
            for (int j = 0; j < report.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                auto level = report[j];
                auto currentLevel = stoi(level);

                if ((currentLevel <= lastIncreasingLevel || currentLevel - lastIncreasingLevel > 3) && lastIncreasingLevel != -1)
                {
                    isIncreasing = false;
                    break;
                }
                lastIncreasingLevel = currentLevel;
            }

            if (isIncreasing)
            {
                break;
            }
        }
        bool isDecreasing = true;
        for (int i = 0; i < report.size(); i++)
        {
            isDecreasing = true;
            int lastDecreasingLevel = 99999;

            for (int j = 0; j < report.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                auto level = report[j];
                auto currentLevel = stoi(level);
                if ((currentLevel >= lastDecreasingLevel || lastDecreasingLevel - currentLevel > 3) && lastDecreasingLevel != 99999)
                {
                    isDecreasing = false;
                    break;
                }
                lastDecreasingLevel = currentLevel;
            }

            if (isDecreasing)
            {
                break;
            }
        }

        if (isIncreasing || isDecreasing)
        {
            safeCounter++;
        }
    }
    vector<string> result{to_string(safeCounter)};
    return result;
}
