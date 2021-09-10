#include <vector>
#include <numeric>
#include <iostream>

using namespace ::std;

int main() {

    int limit = 1000000;

    // using eulers totient function
    vector<long int> sieve(limit + 1);
    std::iota(sieve.begin(), sieve.end(), 0);
    long result = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i] == i) {
            for (int j = i; j <= limit; j += i) {
                double di = i;
                sieve[j] = sieve[j]*(1 - 1/di) ;
            }
        }
        result += sieve[i];
    }
    cout << result << endl;
}