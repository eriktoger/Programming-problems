#include "main.h"
#include <vector>

void func(std::istream &is, std::ostream &os)
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int size;
        cin >> size;
        vector<int> numbers(size);
        int largestIndex = 0;
        bool hasZeroOrFive = false;
        bool hasOthers = false;

        readNumbers(numbers, largestIndex, hasZeroOrFive, hasOthers);

        if (hasZeroOrFive && hasOthers)
        {
            cout << "No";
        }
        else if (hasZeroOrFive)
        {
            handleZeroAndFive(numbers);
        }
        else
        {
            handleOthers(numbers, largestIndex);
        }

        if (testCases > 0)
        {
            cout << "\n";
        }
    }
}

int diffTo8(int reminder)
{
    switch (reminder)
    {
    case 1:
        return 1 + 2 + 4;
    case 2:
        return 2 + 4;
    case 3:
        return 3 + 6 + 2 + 4;
    case 4:
        return 4;
    case 6:
        return 6 + 2 + 4;
    case 7:
        return 7 + 4;
    case 8:
        return 0;
    case 9:
        return 9;
    default:
        return 0;
    }
}

void readNumbers(vector<int> &numbers, int &largestIndex, bool &hasZeroOrFive, bool &hasOthers)
{

    for (unsigned i = 0; i < numbers.size(); i++)
    {

        cin >> numbers[i];

        int reminder = numbers[i] % 10;
        numbers[i] += diffTo8(reminder);

        if (numbers[i] > numbers[largestIndex])
        {
            largestIndex = i;
        }

        if (reminder == 0 || reminder == 5)
        {
            hasZeroOrFive = true;
        }
        else
        {
            hasOthers = true;
        }
    }
}

void handleZeroAndFive(vector<int> &numbers)
{
    for (auto &number : numbers)
    {
        if (number % 10 == 5)
        {
            number += 5;
        }
        if (number != numbers[0])
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

void handleOthers(vector<int> &numbers, int largestIndex)
{
    for (auto &number : numbers)
    {
        int n = (numbers[largestIndex] - number) / 20;
        if (number + 20 * n != numbers[largestIndex])
        {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}
