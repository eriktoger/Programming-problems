#include "solutionTwo.h"

int computeSimilarity(int acc, const int &left, const map<int, int> &counter)
{
    if (counter.count(left))
    {
        return acc + left * counter.at(left);
    }
    return acc;
}

int calcSimilarity(vector<int> const &leftSide, vector<int> const &rightSide)
{
    std::map<int, int> counter;
    for (auto const &right : rightSide)
    {
        if (counter.contains(right))
        {
            counter[right]++;
        }
        else
        {
            counter.insert({right, 1});
        }
    };

    auto similarityCalculator = [&counter](int acc, const int &left)
    {
        return computeSimilarity(acc, left, counter);
    };

    int totalSimilarity = std::accumulate(leftSide.begin(), leftSide.end(), 0, similarityCalculator);

    return totalSimilarity;
}

vector<string> solutionTwo(vector<string> const &input)
{
    vector<int> leftSide;
    vector<int> rightSide;

    splitInput(input, leftSide, rightSide);
    auto similarity = calcSimilarity(leftSide, rightSide);
    vector<string> output{to_string(similarity)};
    return output;
}
