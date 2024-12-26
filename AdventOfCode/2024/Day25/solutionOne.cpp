#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    vector<vector<vector<bool>>> locks;
    vector<vector<vector<bool>>> keys;
    vector<vector<bool>> part;

    for (const auto &line : input)
    {
        if (line.empty())
        {
            if (part[0][0])
            {
                locks.push_back(part);
            }
            else
            {
                keys.push_back(part);
            }

            part.clear();
        }
        else
        {
            vector<bool> row;
            for (const auto &c : line)
            {
                row.push_back(c == '#');
            }
            part.push_back(row);
        }
    }

    if (part[0][0])
    {
        locks.push_back(part);
    }
    else
    {
        keys.push_back(part);
    }

    int keyCount = 0;
    for (size_t i = 0; i < locks.size(); i++)
    {
        for (size_t j = 0; j < keys.size(); j++)
        {
            const auto &lock = locks[i];
            const auto &key = keys[j];
            auto keysMatch = true;
            for (size_t row = 0; row < lock.size(); row++)
            {
                for (size_t col = 0; col < lock[row].size(); col++)
                {
                    auto lockPin = lock[row][col];
                    auto keyPin = key[row][col];
                    auto overlap = lockPin && keyPin;
                    keysMatch = !overlap;

                    if (!keysMatch)
                    {
                        break;
                    }
                }
                if (!keysMatch)
                {
                    break;
                }
            }
            if (keysMatch)
            {
                keyCount++;
            }
        }
    }

    return {to_string(keyCount)};
}
