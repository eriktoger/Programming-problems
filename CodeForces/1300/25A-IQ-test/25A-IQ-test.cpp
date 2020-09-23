#include "25A-IQ-test.h"

void iqTest(std::istream &is, std::ostream &os) {

    int numbers;
    cin >> numbers;
    int index = 1;
    int odds = 0;
    int evens = 0;
    int oddIndex = 0;
    int evenIndex = 0;
    while (numbers--) {
        int number;
        cin >> number;
        if (number % 2 == 0) {
            evens++;
            if (evenIndex == 0) {
                evenIndex = index;
            }
        } else {
            odds++;
            if (oddIndex == 0) {
                oddIndex = index;
            }
        }

        if(odds > 1 && evenIndex != 0){
            cout << evenIndex;
            return;
        }
        if(evens > 1 && oddIndex !=0){
            cout << oddIndex;
            return;
        }

        index++;

    }
}