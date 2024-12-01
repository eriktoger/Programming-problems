#include "solution.h"

vector<string> solutionTwo(vector<string> const &input)
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

    std::map<int, int> counter;
    for (auto const &right : rightSide)
    {
        if (counter.count(right))
        {
            counter[right]++;
        }
        else
        {
            counter.insert({right, 1});
        }
    };

    long long totalSimilarity = 0;
    for (auto const &left : leftSide)
    {
        if (counter.count(left))
        {
            totalSimilarity += (left * counter[left]);
        }
    };

    vector<string> output{to_string(totalSimilarity)};
    return output;
}
