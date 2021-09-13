#include "230B-T-Primes.h"
#include <algorithm>

void func(std::istream &is, std::ostream &os) {

    auto primeFlags = generatePrimeFlags(1000000);
    int numbers;
    cin >> numbers;
    while (numbers--) {
        long long number;
        cin >> number;
        if (number == 4) {
            cout << "YES" << endl;
        } else if (number % 2 == 0) {
            cout << "NO" << endl;
        } else if (isPrimeSquare(number, primeFlags)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

bool isPrimeSquare(long long p, const vector<bool> &primeFlags) {
    double sqrt_p = sqrt(p);
    return sqrt_p == int(sqrt_p) && primeFlags[sqrt_p];
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
