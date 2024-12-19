#include "solutionTwo.h"

unsigned long long findVariations(std::unordered_map<std::string, int> patterns, unordered_map<string, unsigned long long> &cachedVariations, unsigned long long totalVariations, string towel, unsigned long long towelIndex)
{
    if (towelIndex == towel.size())
    {
        return 1;
    }

    if (towelIndex > towel.size())
    {
        return 0;
    }

    auto subTowel = towel.substr(towelIndex);

    if (cachedVariations.contains(subTowel))
    {
        return cachedVariations[subTowel];
    }

    auto tempTotalVariations = totalVariations;
    for (auto &pair : patterns)
    {
        if (pair.second == partialFind)
        {
            continue;
        }

        auto pattern = pair.first;

        if (towelIndex + pattern.size() > towel.size())
        {
            continue;
        }

        auto towelPart = towel.substr(towelIndex, pattern.size());
        if (towelPart != pattern)
        {
            continue;
        }

        totalVariations += findVariations(patterns, cachedVariations, tempTotalVariations, towel, towelIndex + pattern.size());
    }

    cachedVariations[subTowel] = totalVariations;

    return totalVariations;
}

vector<string> solutionTwo(vector<string> const &input)
{

    auto completeTowels = calcCompleteTowels(input);

    auto totalVariations = 0ull;
    for (auto &towel : completeTowels)
    {
        auto patternsOneTowel = generateOneTowelPatternsLookup(input, towel);
        unordered_set<string> partialIncompleteTowels;
        unordered_map<string, unsigned long long> cachedVariations;
        auto variations = findVariations(patternsOneTowel, cachedVariations, 0, towel, 0);
        totalVariations += variations;
    }

    return {to_string(totalVariations)};
}
