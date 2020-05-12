#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void twostrings() {
    string str;
    cin >> str;
    char A = 'A';
    char B = 'B';
    vector<int> indexesAB;
    vector<int> indexesBA;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == B) {
            if (i > 0 && str[i - 1] == A) {
                indexesAB.emplace_back(i);
            }
            if (i < str.length() - 1 && str[i + 1] == A) {
                indexesBA.emplace_back(i);
            }
        }
    }
    if (indexesAB.empty() || indexesBA.empty()) {
        cout << "NO";
        return;
    }
    if (indexesAB.size() == 1 && indexesBA.size() == 1 &&
        (indexesAB[0] == indexesBA[0] || abs(indexesAB[0] - indexesBA[0]) == 2)) {
        cout << "NO";
        return;
    }
    if (indexesAB.size() == 2 && indexesBA.size() == 1 && indexesAB[0] == indexesBA[0] &&
        (indexesAB[1] - indexesAB[0]) == 2) {
        cout << "NO";
        return;
    }

    cout << "YES";

}