
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {

        int target;
        int multiplier;
        int adder;

        cin >> target;
        cin >> multiplier;
        cin >> adder;

        if (isInSet(target, multiplier, adder))
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }

        if (testCases)
        {
            cout << "\n";
        }
    }
}

bool isInSet(int target, int multiplier, int adder)
{

    if (adder == 1)
    {
        return true;
    }

    if (multiplier == 1)
    {
        return target % adder == 1;
    }

    long long int start = 1;
    if ((target - start) % adder == 0)
    {
        return true;
    }

    while (start <= target && start > 0)
    {
        if (start == target)
        {
            return true;
        }

        start *= multiplier;

        if (start <= target && (target - start) % adder == 0)
        {
            return true;
        }
    }
    return false;
}