#include "solutionTwo.h"

struct Banana
{
    int bananas;
    int diff;
};

int generateHash(const array<Banana, 4> &sequence, int sequenceIndex)
{
    int indexZero = (sequenceIndex) % 4;
    int indexOne = (sequenceIndex + 1) % 4;
    int indexTwo = (sequenceIndex + 2) % 4;
    int indexThree = (sequenceIndex + 3) % 4;

    return sequence[indexZero].diff * 19 * 19 * 19 +
           sequence[indexOne].diff * 19 * 19 +
           sequence[indexTwo].diff * 19 +
           sequence[indexThree].diff;
}

void updateBananaCount(unordered_map<int, int> &bananaCount, unordered_set<int> &localBananaCount, array<Banana, 4> &sequence, const Banana &banana, int &sequenceIndex, int rounds, long long &maxScore)
{
    if (rounds < 2000 - 3)
    {
        sequence[sequenceIndex] = banana;
        sequenceIndex++;
        sequenceIndex %= 4;

        auto key = generateHash(sequence, sequenceIndex);
        if (localBananaCount.contains(key))
        {
            return;
        }

        bananaCount[key] += banana.bananas;
        localBananaCount.insert(key);

        if (bananaCount[key] > maxScore)
        {
            maxScore = bananaCount[key];
        }
    }
    else
    {
        sequence[sequenceIndex] = banana;
        sequenceIndex++;
    }
}

vector<string> solutionTwo(vector<string> const &input)
{

    unordered_map<int, int> bananaCount;
    auto maxScore = 0ll;

    for (const auto &line : input)
    {
        array<Banana, 4> sequence;

        int sequenceIndex = 0;
        unordered_set<int> localBananaCount;
        auto secret = stoull(line);

        auto rounds = 2000;
        while (rounds--)
        {
            auto lastDigit = secret % 10;
            secret = getNextSecret(secret);
            auto nextLastDigit = secret % 10;
            auto banana = Banana(nextLastDigit, lastDigit - nextLastDigit + 9);

            updateBananaCount(bananaCount, localBananaCount, sequence, banana, sequenceIndex, rounds, maxScore);
        }
    }

    return {to_string(maxScore)};
}
