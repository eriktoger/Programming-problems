#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    string line = input[0];
    array<int, 340000> parsedLine;

    size_t arrayIndex = 0;
    array<int, 100000> freeSpace;

    size_t freeSpacePointer = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        bool isFile = i % 2 == 0;
        size_t fileName = isFile ? i / 2 : -1;
        size_t length = stoi(line.substr(i, 1));

        for (size_t j = 0; j < length; j++)
        {
            parsedLine[arrayIndex] = fileName;
            if (!isFile)
            {
                freeSpace[freeSpacePointer++] = arrayIndex;
            }
            arrayIndex++;
        }
    }

    size_t freeSpaceLimit = freeSpacePointer;
    freeSpacePointer = 0;
    for (int i = arrayIndex - 1; i >= 0; i--)
    {
        if (parsedLine[i] == -1)
        {
            continue;
        }
        if (freeSpacePointer >= freeSpaceLimit || freeSpace[freeSpacePointer] >= i)
        {
            break;
        }

        parsedLine[freeSpace[freeSpacePointer++]] = parsedLine[i];
        parsedLine[i] = -1;
    }

    long long sum = 0;
    for (size_t i = 0; i < parsedLine.size(); i++)
    {
        if (parsedLine[i] == -1)
        {
            break;
        }
        sum += parsedLine[i] * i;
    }
    cout << sum << endl;
    return {to_string(sum)};
}
