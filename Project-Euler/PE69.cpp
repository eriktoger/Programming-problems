#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>
#include "../Other/Sieve/sieve.h"

using namespace std;


map<int, int> findPrimeFactors(int current, vector<int> &primes);

void updateAnswer(int current, double &quotient, int &n, map<int, int> const &primeFactors);

int main() {
    int limit = 1000000;
    vector<int> v = generatePrimes(limit);
    int current = 1;
    double quotient = 0;
    int n = 0;

    while (current < limit) {
        map<int, int> primeFactors = findPrimeFactors(current, v);
        updateAnswer(current, quotient, n, primeFactors);
        current++;
    }
    cout << "Answer: " << n << endl;

}

map<int, int> findPrimeFactors(int current, vector<int> &primes) {
    map<int, int> primeFactors;
    int idx = 0;
    while (current >= primes.at(idx)) {

        int prime = primes.at(idx);
        if (current % prime == 0) {
            current /= prime;
            primeFactors[prime] = primeFactors.contains(prime) ? primeFactors.at(prime) + 1 : 1;
        } else {
            idx++;
        }
    }
    return primeFactors;
}

void updateAnswer(int current, double &quotient, int &n, map<int, int> const &primeFactors) {
    double phiN = 1;
    for (auto pair: primeFactors) {
        phiN *= (pow(pair.first, pair.second - 1)) * (pair.first - 1);
    }

    double tempQuotient = current / phiN;
    if (tempQuotient > quotient) {
        quotient = tempQuotient;
        n = current;
    }
}
