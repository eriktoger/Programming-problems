#include <vector>
#include <map>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETETIVE_PROGRAMMING_580C_KEFA_AND_PARK_H
#define COMPETETIVE_PROGRAMMING_580C_KEFA_AND_PARK_H


void kefaAndPark(std::istream &is = cin, std::ostream &os = cout);

void
readData(vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit, std::istream &is = cin);

void dfs(int node, int parent, vector<int> &catsInNode, map<int, vector<int> > &adjacencyList, int &catLimit, int &restaurants);

#endif //COMPETETIVE_PROGRAMMING_580C_KEFA_AND_PARK_H
