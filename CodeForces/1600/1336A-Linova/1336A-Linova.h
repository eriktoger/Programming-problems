#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_1336A_LINOVA_H
#define COMPETITIVE_PROGRAMMING_1336A_LINOVA_H

class City {
private:
    int id;
    vector<int> leadsTo;
    int score;
    int depth;
    bool leaf;
public:
    City(int _id);

    void traverse(int from, int depth, map<int, shared_ptr<City>> &cities);

    void calcIsLeaf() {
        leaf = leadsTo.size() == 1;
    }
    bool isLeaf() const{
        return leaf;
    }

    void setScore(int newScore) {
        score = newScore;
    }

    void setDepth(int newDepth) {
        depth = newDepth;
    }

    void addCity(int newCity) { leadsTo.emplace_back(newCity); }

    void penalty(map<int, shared_ptr<City>> &cities);

    int getScore() const { return score; }

    int getDepth() const { return depth; }

};

void func(std::istream &is = cin, std::ostream &os = cout);

bool compare(shared_ptr<City> const &c1, shared_ptr<City> const &c2);

#endif //COMPETITIVE_PROGRAMMING_1336A_LINOVA_H
