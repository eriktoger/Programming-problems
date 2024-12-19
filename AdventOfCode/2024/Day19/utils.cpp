#include "utils.h"

bool canTowelBeMade(const unordered_map<string, int> &towelPatternsLookup, unordered_set<string> &completeTowels, unordered_set<string> &partialIncompleteTowels, const string &towel, string currentPattern, int towelIndex)
{

    if (completeTowels.contains(towel))
    {
        return true;
    }

    if (towelIndex == towel.size())
    {
        auto isTowelMade = currentPattern.empty();
        if (isTowelMade)
        {
            completeTowels.insert(towel);
        }

        return isTowelMade;
    }

    bool isTowelMade = false;

    currentPattern += towel[towelIndex];

    auto incompleteTowelKey = towel.substr(0, towelIndex) + "-" + currentPattern + "-" + to_string(towelIndex);
    if (partialIncompleteTowels.contains(incompleteTowelKey))
    {
        return false;
    }

    if (towelPatternsLookup.contains(currentPattern))
    {
        auto findNumber = towelPatternsLookup.at(currentPattern);
        int newTowelIndex = towelIndex + 1;
        if (findNumber == bothFinds)
        {
            auto isPartialFind = canTowelBeMade(towelPatternsLookup, completeTowels, partialIncompleteTowels, towel, currentPattern, newTowelIndex);
            auto isFullFind = canTowelBeMade(towelPatternsLookup, completeTowels, partialIncompleteTowels, towel, "", newTowelIndex);
            isTowelMade |= isFullFind || isPartialFind;
        }
        else if (findNumber == fullFind)
        {
            isTowelMade |= canTowelBeMade(towelPatternsLookup, completeTowels, partialIncompleteTowels, towel, "", newTowelIndex);
        }
        else
        {
            isTowelMade |= canTowelBeMade(towelPatternsLookup, completeTowels, partialIncompleteTowels, towel, currentPattern, newTowelIndex);
        }
    }

    if (!isTowelMade)
    {

        partialIncompleteTowels.insert(incompleteTowelKey);
    }

    return isTowelMade;
}

unordered_map<string, int> generateOneTowelPatternsLookup(vector<string> const &input, string towel)
{

    auto towelPatternLine = input[0];
    auto towelPatterns = splitOnDelimiter({towelPatternLine}, ", ")[0];

    unordered_map<string, int> towelPatternsLookup;
    for (const auto &towelPattern : towelPatterns)
    {
        bool patternFound = towel.find(towelPattern) != std::string::npos;
        if (!patternFound)
        {
            continue;
        }

        for (int length = 1; length <= towelPattern.size(); length++)
        {
            auto part = towelPattern.substr(0, length);

            bool isPresent = towelPatternsLookup.contains(part);

            if (length == towelPattern.size())
            {
                if (isPresent)
                {
                    if (towelPatternsLookup.at(part) == partialFind)
                    {
                        towelPatternsLookup[part] = bothFinds;
                    }
                }
                else
                {
                    towelPatternsLookup[part] = fullFind;
                }
            }
            else
            {
                if (isPresent)
                {
                    if (towelPatternsLookup.at(part) == 2)
                    {
                        towelPatternsLookup[part] = bothFinds;
                    }
                }
                else
                {
                    towelPatternsLookup[part] = partialFind;
                }
            }
        }
    }
    return towelPatternsLookup;
}

unordered_set<string> calcCompleteTowels(vector<string> const &input)
{

    unordered_set<string> completeTowels;
    for (int i = 2; i < input.size(); i++)
    {
        string currentPattern = "";
        string towel = input[i];
        int towelIndex = 0;

        unordered_set<string> partialIncompleteTowels;
        auto towelPatternsLookup = generateOneTowelPatternsLookup(input, towel);
        canTowelBeMade(towelPatternsLookup, completeTowels, partialIncompleteTowels, towel, currentPattern, towelIndex);
    }

    return completeTowels;
}