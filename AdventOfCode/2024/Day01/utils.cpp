#include "utils.h"
#include "common.h"

void splitInput(vector<string> const &input, vector<int> &leftSide, vector<int> &rightSide)
{
    auto splitInput = splitLinesToWords(input);
    for (auto const &words : splitInput)
    {
        leftSide.emplace_back(stoi(words[0]));
        rightSide.emplace_back(stoi(words[1]));
    }
}