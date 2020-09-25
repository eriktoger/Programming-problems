#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_1336A_LINOVA_H
#define COMPETITIVE_PROGRAMMING_1336A_LINOVA_H

class City {
private:
    int id;
    vector<int> leadsTo;
    int depth;

    set<int> children;
    int last;

public:
    City() {
        id = -1;
        depth = 0;
        last = 0;
    }

    void traverse(int from, int depth, vector<City> &cities,vector <int> visited);


    bool isLeaf() const {
        return leadsTo.size() == 1;
    }

    void setDepth(int newDepth) {
        depth = newDepth;
    }

    void setID(int newID) { id = newID; }

    void addCity(int newCity) { leadsTo.emplace_back(newCity); }

    void calcChildren(vector<City> &cities);

    int getScore() const { return depth - children.size(); }

    int getDepth() const { return depth; }

};

void func(std::istream &is = cin, std::ostream &os = cout);

bool compare(City const &c1, City const &c2);

#endif //COMPETITIVE_PROGRAMMING_1336A_LINOVA_H
