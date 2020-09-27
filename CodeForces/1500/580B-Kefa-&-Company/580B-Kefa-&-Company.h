#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_580B_KEFA_COMPANY_H
#define COMPETITIVE_PROGRAMMING_580B_KEFA_COMPANY_H


class Friend {
private:
    int money;
    int friendship;
public:
    Friend(int m, int f) : money(m), friendship(f) {}

    bool operator<(Friend const &f2) const { return money < f2.money; }

    int getMoney() const { return money; }

    int getFriendship() const { return friendship; }
};

void kefa(std::istream &is = cin, std::ostream &os = cout);

#endif //COMPETITIVE_PROGRAMMING_580B_KEFA_COMPANY_H
