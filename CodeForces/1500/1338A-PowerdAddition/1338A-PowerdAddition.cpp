
#include "1338A-PowerdAddition.h"

using namespace std;

void powAdd(std::istream &is, std::ostream &os) {

    int testCases;
    cin >> testCases;

    while (testCases--) {
        vector<int> numbers;
        int length;
        cin >> length;
        int last = -1000000000;
        int maxSeconds = 0;
        while (length--) {
            int num;
            cin >> num;
            if(num < last){
                int seconds = (int) log2(last -num) + 1;
                num = last;
                maxSeconds = max(maxSeconds, seconds);
            }
            last = num;
        }


        cout << maxSeconds << '\n';

    }

}