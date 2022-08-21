#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

void func(std::istream &is = cin, std::ostream &os = cout);
bool isDone(const string &start, const int &sumOfDigits, const int &testCases);
string calcStartOfSmallestNumber(const string &start, int &sumOfDigits);
void appendToSmallestNumber(string &smallestNumber, const string &start);

#endif // COMPETITIVE_PROGRAMMING_MAIN_H
