#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

class City
{
public:
    int parent = -1;
    long long int distance = 0;
    vector<int> children;
    long long int descendants = 0;
    City() = default;
    City(int parent, int distance) : parent(parent), distance(distance) {}
    long long int calcHappiness() const
    {
        return distance - descendants;
    }

    bool operator>(const City &other) const
    {
        return (calcHappiness() > other.calcHappiness());
    }
};

class Road
{
public:
    int parent;
    int child;
};

void func(std::istream &is = cin, std::ostream &os = cout);
vector<int> orderLeafs(const map<int, vector<int>> &leafsMap);
void updateDescendants(vector<int> &leafsVector, vector<City> &cities_array);
void generateCities(map<int, vector<int>> &unsorted_roads, vector<City> &cities_array);
void readRoads(int nrOfRoads, map<int, vector<int>> &unsorted_roads);
long long operator+(long long i, const City &c);

#endif // COMPETITIVE_PROGRAMMING_MAIN_H
