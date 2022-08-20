#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

class Subject
{
public:
    int date1;
    int date2;
    bool operator<(const Subject &other) const
    {
        if (date1 == other.date1)
        {
            return date2 < other.date2;
        }
        return (date1 < other.date1);
    }

    Subject(int date1, int date2) : date1(date1), date2(date2) {}
    Subject() = default;
};

void func(std::istream &is = cin, std::ostream &os = cout);

#endif // COMPETITIVE_PROGRAMMING_MAIN_H
