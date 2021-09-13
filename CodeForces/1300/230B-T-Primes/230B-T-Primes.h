#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_230B_T_PRIMES_H
#define COMPETITIVE_PROGRAMMING_230B_T_PRIMES_H

void func(std::istream &is = cin, std::ostream &os = cout);

vector<bool> generatePrimeFlags(int limit);

bool isPrimeSquare(long long p, const vector<bool> &primeFlags);


#endif //COMPETITIVE_PROGRAMMING_230B_T_PRIMES_H
