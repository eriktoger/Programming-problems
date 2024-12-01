#include "solutionOne.h"

int calcTotalDiff(vector<int> &leftSide, vector<int> &rightSide)
{
    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());

    int totalDiff = 0;
    for (int i = 0; i < leftSide.size(); i++)
    {
        int diff = abs(leftSide[i] - rightSide[i]);
        totalDiff += diff;
    }
    return totalDiff;
}

vector<string> solutionOne(vector<string> const &input)
{
    vector<int> leftSide;
    vector<int> rightSide;

    splitInput(input, leftSide, rightSide);

    auto totalDiff = calcTotalDiff(leftSide, rightSide);

    vector<string> output{to_string(totalDiff)};
    return output;
}
