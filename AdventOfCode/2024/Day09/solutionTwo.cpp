#include "solutionTwo.h"

struct Data
{
    int index;
    int length;
};

vector<string> solutionTwo(vector<string> const &input)
{
    string line = input[0];
    array<int, 340000> parsedLine;
    parsedLine.fill(-1);

    size_t arrayIndex = 0;
    array<int, 100000> freeSpace;

    size_t freeSpacePointer = 0;

    map<int, Data> fileToLength;
    for (size_t i = 0; i < line.size(); i++)
    {
        bool isFile = i % 2 == 0;
        size_t fileName = isFile ? i / 2 : -1;
        size_t length = stoi(line.substr(i, 1));

        if (isFile)
        {
            fileToLength[fileName] = Data(arrayIndex, length);
        }

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
    arrayIndex--;
    auto lastNumber = parsedLine[arrayIndex];
    auto length = fileToLength[lastNumber];

    for (auto it = fileToLength.rbegin(); it != fileToLength.rend(); it++)
    {
        auto key = it->first;
        auto value = it->second;

        int lengthCounter = 0;
        int swappyIndex = -1;

        for (int i = 0; i < value.index; i++)
        {

            if (parsedLine[i] == -1)
            {
                lengthCounter++;
            }
            else
            {
                lengthCounter = 0;
            }

            if (lengthCounter == value.length)
            {
                swappyIndex = i - value.length + 1;
                break;
            }
        }

        if (swappyIndex != -1)
        {
            for (int i = 0; i < value.length; i++)
            {
                parsedLine[swappyIndex + i] = key;
                parsedLine[value.index + i] = -1;
            }
        }
    }

    long long sum = 0;
    for (size_t i = 0; i < arrayIndex; i++)
    {
        if (parsedLine[i] == -1)
        {
            continue;
        }
        sum += parsedLine[i] * i;
    }

    return {to_string(sum)};
}
