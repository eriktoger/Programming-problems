
#include "main.h"

struct Potion
{
    int index;
    int value;
    bool consumed = false;
    int previousPositive;
    Potion(int index, int value, int previousPositive) : index(index), value(value), previousPositive(previousPositive) {}
    bool operator>(Potion const &other) const
    {
        return value > other.value;
    }
};

void func(std::istream &is, std::ostream &os)
{
    int nrOfPotions;
    cin >> nrOfPotions;
    vector<int> potions(nrOfPotions);

    unsigned long long int positiveSum = 0;
    map<int, unsigned long long int> positiveSums;
    vector<Potion> negatives;
    int previousPositive = -1;
    for (int i = 0; i < nrOfPotions; i++)
    {
        cin >> potions[i];
        if (potions[i] >= 0)
        {
            positiveSum += potions[i];
            positiveSums.insert({i, positiveSum});
            previousPositive = i;
        }
        else
        {
            if (positiveSums.size() != 0)
                negatives.emplace_back(i, potions[i], previousPositive);
        }
    }

    sort(negatives.begin(), negatives.end(), greater<Potion>());

    int potionsConsumed = positiveSums.size();
    for (auto &negative : negatives)
    {
        if (positiveSums.at(negative.previousPositive) >= -negative.value)
        {
            potionsConsumed++;
            auto iter = positiveSums.rbegin();
            int negVal = negative.value;

            int lastSum = iter->second;
            while (iter != positiveSums.rend())
            {

                if (negative.previousPositive > iter->first)
                {
                    negVal += lastSum - iter->second;
                    if (negVal > 0)
                    {
                        break;
                    }
                }
                lastSum = iter->second;
                iter->second += negVal;
                iter++;
            }
        }
    }
    cout << potionsConsumed;
}
