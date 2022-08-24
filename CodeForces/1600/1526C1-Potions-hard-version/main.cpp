
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int nrOfPotions;
    cin >> nrOfPotions;
    vector<int> potions(nrOfPotions);

    unsigned long long int positiveSum = 0;
    map<int, unsigned long long int> positiveSums;

    int potionsConsumed = 0;
    priority_queue<int, vector<int>, greater<int>> negativesConsumed;
    for (int i = 0; i < nrOfPotions; i++)
    {
        int potion;
        cin >> potion;

        if (potion >= 0)
        {
            positiveSum += potion;
            potionsConsumed++;
        }
        else
        {
            if (positiveSum >= abs(potion))
            {
                positiveSum += potion;
                potionsConsumed++;
                negativesConsumed.push(potion);
            }
            else
            {
                while (negativesConsumed.size() > 0 && positiveSum < abs(potion) && potion > negativesConsumed.top())
                {
                    positiveSum -= negativesConsumed.top();
                    negativesConsumed.pop();
                    potionsConsumed--;
                }
                if (positiveSum >= abs(potion))
                {
                    positiveSum += potion;
                    potionsConsumed++;
                    negativesConsumed.push(potion);
                }
            }
        }
    }

    cout << potionsConsumed;
}
