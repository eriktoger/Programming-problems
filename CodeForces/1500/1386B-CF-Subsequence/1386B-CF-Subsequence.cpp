#include "1386B-CF-Subsequence.h"

void func(std::istream &is, std::ostream &os) {

    unsigned long long int k;
    cin >> k;
    vector<int> counters(10,1);
    unsigned long long int total = accumulate(counters.begin(), counters.end(),1,multiplies<>());
    string codeforces= "codeforces";
    int index = 0;
    unsigned long long int start = 1;
    while(total < k){
        counters[index % 10]++;
        index++;

        total = accumulate(counters.begin(), counters.end(),start,multiplies<>());
    }

    int i =0;
    for_each(counters.begin(), counters.end(),[&codeforces,i](auto num) mutable{
        cout<< string(num,codeforces[i]);
        i++;
    });



}