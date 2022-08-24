
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        string str;
        cin >> str;

        map<char, vector<int>> chars;
        char number = '0';
        for (int i = 0; i < 10; i++)
        {
            chars.insert({number, vector<int>()});
            number++;
        }
        for (size_t i = 0; i < str.size(); i++)
        {
            chars.at(str[i]).push_back(i);
        }
        size_t longestGood = 0;

        // odd
        number = '0';
        for (int i = 0; i < 10; i++)
        {
            auto size = chars.at(number).size();
            longestGood = max(longestGood, size);
            number++;
        }

        // even
        vector<pair<int, int>> charCombos;
        for (auto &pair1 : chars)
        {

            if (pair1.second.size() == 0)
            {
                continue;
            }
            auto c1 = pair1.first;
            for (auto &pair2 : chars)
            {
                auto c2 = pair2.first;
                if (pair2.second.size() == 0 || c1 == c2)
                {
                    continue;
                }
                charCombos.emplace_back(c1, c2);
            }
        }

        for (auto &pair : charCombos)
        {
            auto c1 = pair.first;
            auto c2 = pair.second;
            auto index1 = chars[c1];
            auto index2 = chars[c2];

            size_t i = 0;
            size_t j = 0;
            bool first = true;
            size_t doubles = 0;
            while (i < index1.size() && j < index2.size())
            {
                if (first)
                {
                    if (index1[i] < index2[j])
                    {
                        first = false;
                        i++;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    if (index2[j] < index1[i])
                    {
                        first = true;
                        j++;
                        doubles++;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            if (index1.back() < index2.back() && !first)
            {
                doubles++;
            }

            longestGood = max(longestGood, doubles * 2);
        }

        cout << str.size() - longestGood << endl;
    }
}
