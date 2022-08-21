
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int testCases;

    cin >> testCases;

    while (testCases--)
    {
        string start;
        int sumOfDigits;
        cin >> start;
        cin >> sumOfDigits;

        if (isDone(start, sumOfDigits, testCases))
        {
            continue;
        }

        auto smallestNumber = calcStartOfSmallestNumber(start, sumOfDigits);

        appendToSmallestNumber(smallestNumber, start);

        cout << stoull(smallestNumber) - stoull(start);

        if (testCases)
        {
            cout << '\n';
        }
    }
}

bool isDone(const string &start, const int &sumOfDigits, const int &testCases)
{
    int sum = 0;
    for (auto c : start)
    {
        sum += c - '0';
    }
    if (sum <= sumOfDigits)
    {
        cout << 0;
        if (testCases)
        {
            cout << '\n';
        }
        return true;
    }
    return false;
}

string calcStartOfSmallestNumber(const string &start, int &sumOfDigits)
{
    string smallestNumber;

    for (auto c : start)
    {
        int currentInt = c - '0';
        if (currentInt <= (sumOfDigits - 1))
        {
            smallestNumber.push_back(c);
            sumOfDigits -= currentInt;
        }
        else
        {
            break;
        }
    }
    return smallestNumber;
}

void appendToSmallestNumber(string &smallestNumber, const string &start)
{
    int diff = start.size() - smallestNumber.size();
    if (smallestNumber.empty() || smallestNumber[0] == '0')
    {
        smallestNumber = "1" + smallestNumber;
    }
    else
    {
        unsigned long long number = stoull(smallestNumber);
        number++;
        smallestNumber = to_string(number);
    }

    while (diff--)
    {
        smallestNumber.push_back('0');
    }
}