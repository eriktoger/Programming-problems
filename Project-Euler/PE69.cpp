#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

vector<int> generatePrimes();

map<int, int> findPrimeFactors(int current, vector<int> &primes);

void updateAnswer(int current, double &quotient, int &n, map<int, int> const &primeFactors);

int main() {
    vector<int> v = generatePrimes();
    int limit = 1000000;
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

vector<int> generatePrimes() {
    vector<int> primes(1000000);
    iota(begin(primes), end(primes), 2);

    int index = 0;
    while (index < primes.size()) {
        int p = primes[index];
        primes.erase(std::remove_if(primes.begin(),
                               primes.end(),
                               [p](int x) { return x != p && x % p == 0; }),
                primes.end());
        index++;
    }
    return primes;
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