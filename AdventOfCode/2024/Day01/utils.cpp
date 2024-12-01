#include "utils.h"

void splitInput(vector<string> const &input, vector<int> &leftSide, vector<int> &rightSide)
{
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
}