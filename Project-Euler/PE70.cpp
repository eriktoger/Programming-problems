#include <iostream>
#include <vector>
#include "../Other/Sieve/sieve.h"
using namespace std;
int main(){
    auto primes = generatePrimes(10000000);
    double quotient = 9;
    int answer = 0;
    for(int i = 0; i < primes.size();i++){
        for(int j = i+1; j < primes.size();j++){

            unsigned long long n = primes[i]*primes[j];
            if(n > 10000000){
                break;
            }

            int phiN = (primes[i]-1) * (primes[j]-1);
            string nString = to_string(n);
            string phiNString = to_string(phiN);
            sort(begin(nString),end(nString));
            sort(begin(phiNString),end(phiNString));

            if(phiNString == nString){
                double tempQuotient =  static_cast<double>(n)/phiN;
                if( tempQuotient < quotient ){
                    quotient = tempQuotient;
                    answer = n;
                }
            }
        }
    }
cout << "answer: "<<answer<<endl;

}
