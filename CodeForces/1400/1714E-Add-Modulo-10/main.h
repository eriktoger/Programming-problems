#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

void func(std::istream &is = cin, std::ostream &os = cout);
int diffTo8(int reminder);
void readNumbers(vector<int> &numbers, int &largestIndex, bool &hasZeroOrFive, bool &hasOthers);
void handleZeroAndFive(vector<int> &numbers);
void handleOthers(vector<int> &numbers, int largestIndex);

#endif // COMPETITIVE_PROGRAMMING_MAIN_H
