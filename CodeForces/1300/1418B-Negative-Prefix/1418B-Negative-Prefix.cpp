#include "1418B-Negative-Prefix.h"

void negPrefix(std::istream &is, std::ostream &os) {

    int testCases;
    cin >> testCases;

    while (testCases--) {

        int size;
        cin >> size;
        vector<int> numbers(size);
        vector<bool> numberIsLocked(size);
        int num;
        for (int i = 0; i < size; i++) {
            cin >> num;
            numbers[i] = num;
        }
        vector<int> notLocked;
        for (int i = 0; i < size; i++) {
            cin >> num;
            numberIsLocked[i] = num;
            if (!num) {
                notLocked.emplace_back(numbers[i]);
            }
        }
        sort(notLocked.begin(), notLocked.end(), greater<int>());

        auto it = notLocked.begin();
        for (int i = 0; i < size; i++) {
            if (!numberIsLocked[i]) {
                numbers[i] = *it;
                it++;
            }
        }
        for (int i = 0; i < size; i++) {
            cout << numbers[i];
            if (i < (size - 1)) {
                cout << ' ';
            }
        }
        if (testCases != 0) {
            cout << endl;
        }

    }

}