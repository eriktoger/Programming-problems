#include "166E-Tetrahedron.h"

void func(std::istream &is, std::ostream &os) {
    int n;
    cin >>n;
    unsigned long long  nrOfD = 1;
    unsigned long long nrOfABC = 0;
    int mod = 1000000007;
    if(n < 2){
        cout << 0;
        return;
    }
    while(n > 2){
        unsigned long long tempABC = nrOfABC;
        nrOfABC = (nrOfD *3 + tempABC *2) % mod;
        nrOfD = tempABC;
        n--;
    }

    unsigned long long answer = (nrOfD*3 + nrOfABC*2) % mod;
    cout << answer;
}