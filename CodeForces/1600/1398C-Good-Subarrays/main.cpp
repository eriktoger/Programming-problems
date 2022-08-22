
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {

        int arrayLength;
        cin >> arrayLength;
        string array;
        cin >> array;
        map<int, int> prefixSums = {{0, 1}}; // the sum start as zero
        unsigned long long sum = 0;
        int arraySum = 0;
        for (unsigned i = 0; i < array.size(); i++)
        {
            arraySum += array[i] - '0' - 1; // we reduce 1 to compensate for the length
            prefixSums[arraySum]++;
        }

        for (auto &pair : prefixSums)
        {
            // n choose 2, in how many ways can we choose an subarray,
            // it is 2 since we need start and end.
            sum += static_cast<unsigned long long>(pair.second) * (pair.second - 1) / 2;
        }

        cout << sum;

        cout << endl;
    }
}
