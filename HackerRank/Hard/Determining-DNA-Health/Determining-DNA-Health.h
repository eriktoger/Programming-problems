using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <functional>
#include <map>
#include <queue>
#include <list>
#include <cstring>
#include <cstdio>

#ifndef COMPETITIVE_PROGRAMMING_DETERMINING_DNA_HEALTH_H
#define COMPETITIVE_PROGRAMMING_DETERMINING_DNA_HEALTH_H

struct healthAndIndex {
    int health;
    int idx;
};
struct strandInfo {
    int start;
    int end;
    string strand;
};

void dna();

void
readData(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, vector<strandInfo> &strands, int &longestGene);

void readDataFromFile(unordered_map<string, vector<healthAndIndex>> &genesAndHealth,vector <string> &genes, vector<strandInfo> &strands,
                      int &longestGene,string &path);

void calcHealth(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
                unsigned long long int &max, unsigned long long int &min, int &longestGene);

void
calcHealthReverse(unordered_map<string, vector<healthAndIndex>> &genesAndHealth, strandInfo &strand,
                  unsigned long long int &maxNr, unsigned long long int &minNr,
                  int &longestGene);

#endif //COMPETITIVE_PROGRAMMING_DETERMINING_DNA_HEALTH_H
