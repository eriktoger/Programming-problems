#include "sieve.h"
using namespace std;

vector<int> generatePrimes(int limit) {

    vector<int> primeNumbers(limit);
    iota(primeNumbers.begin(), primeNumbers.end(), 0);
    primeNumbers[0] = -1;
    primeNumbers[1] = -1;
    for (auto prime: primeNumbers) {
        if (prime == -1) {
            continue;
        }
        for (int i = prime * prime; i < limit; i += prime) {
            if (i % prime == 0) {
                primeNumbers[i] = -1;
            }
        }
    }
    primeNumbers.erase(std::remove(primeNumbers.begin(), primeNumbers.end(), -1), primeNumbers.end());
    return primeNumbers;
}

