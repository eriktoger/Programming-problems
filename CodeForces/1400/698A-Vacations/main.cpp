
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int nrOfDays;
    cin >> nrOfDays;
    vector<int> days;

    readDays(days, nrOfDays);
    int restDays = calcRestDays(days);
    cout << restDays;
}

void readDays(vector<int> &days, int nrOfDays)
{
    int threes = 0;
    for (int i = 0; i < nrOfDays; i++)
    {
        int day;
        cin >> day;
        if (day == 3)
        {
            threes++;
        }
        else
        {
            if (threes > 0)
            {
                if (threes % 2 == 1)
                {
                    days.push_back(3);
                }
                threes = 0;
            }
            days.push_back(day);
        }
    }
}

int calcRestDays(vector<int> &days)
{
    int restDays = 0;
    int lastDay = -1;
    for (size_t i = 0; i < days.size(); i++)
    {
        int currentDay = days[i];

        switch (currentDay)
        {
        case 0:
            restDays++;
            lastDay = 0;
            break;
        case 1:
        case 2:
            if (lastDay == currentDay)
            {
                restDays++;
                lastDay = 0;
            }
            else
            {
                lastDay = currentDay;
            }
            break;
        case 3:
            if (lastDay == 1)
            {
                lastDay = 2;
            }
            else if (lastDay == 2)
            {
                lastDay = 1;
            }
            else
            {
                lastDay = 3;
            }
            break;
        default:
            break;
        }
    }
    return restDays;
}
