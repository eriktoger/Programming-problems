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
        for (long int i = prime * prime; i < limit; i += prime) {
            if (i % prime == 0) {
                primeNumbers[i] = -1;
            }
        }
    }
    primeNumbers.erase(std::remove(primeNumbers.begin(), primeNumbers.end(), -1), primeNumbers.end());
    return primeNumbers;
}

vector<bool> generatePrimeFlags(int limit) {

    vector<bool> primeFlags(limit, true);
    primeFlags[0] = false;
    primeFlags[1] = false;
    for (long long i = 2; i < limit; i++) {
        if (primeFlags[i] ) {
            for (long long j = i * i; j < limit; j += i) {
                primeFlags[j] = false;
            }
        }
    }
    return primeFlags;
}
