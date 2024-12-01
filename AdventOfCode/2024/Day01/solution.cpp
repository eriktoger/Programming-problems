#include "solution.h"

vector<string> solution(vector<string> const &input)
{
    vector<int> leftSide;
    vector<int> rightSide;

    for (auto const &line : input)
    {
        stringstream ss(line);
        string word;
        bool isLeft = true;
        while (ss >> word)
        {
            if (isLeft)
            {
                leftSide.push_back(stoi(word));
                isLeft = false;
            }
            else
            {
                rightSide.push_back(stoi(word));
                isLeft = true;
            }
        }
    }
    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());
    long long totalDiff = 0;
    for (int i = 0; i < leftSide.size(); i++)
    {
        int diff = abs(leftSide[i] - rightSide[i]);
        totalDiff += diff;
    }

    vector<string> output{to_string(totalDiff)};
    return output;
}
