
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int testCases;

    cin >> testCases;

    while (testCases--)
    {
        int size;
        cin >> size;
        size_t subArraySize;
        cin >> subArraySize;
        vector<int> array(size);
        while (size--)
        {
            cin >> array[size];
        }

        set<int> unique(array.begin(), array.end());
        if (unique.size() > subArraySize)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<int> period(unique.begin(), unique.end());
        while (period.size() < subArraySize)
        {
            period.push_back(1);
        }

        cout << array.size() * period.size() << '\n';

        for (size_t i = 0; i < array.size(); i++)
        {
            for (size_t j = 0; j < period.size(); j++)
            {
                cout << period[j] << " ";
            }
        }

        cout << '\n';
    }
}
