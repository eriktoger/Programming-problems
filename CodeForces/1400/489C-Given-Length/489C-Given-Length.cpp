#include "489C-Given-Length.h"

void func(std::istream &is, std::ostream &os) {

    int m, s;
    cin >> m;
    cin >> s;
    if (m == 1 && s == 0) {
        cout << "0 0";
        return;
    }

    if (s == 0 || m * 9 < s) {
        cout << "-1 -1";
        return;
    }

    string minVal = calcMin(m, s);
    string maxVal = calcMax(m, s);

    cout << minVal << " " << maxVal;

}

string calcMin(int m, int s) {

    int nrOfNines = (s - 1) / 9;
    char rest = '0' + ((s - 1) % 9);
    string nines = nrOfNines > 0 ? string(nrOfNines, '9') : "";
    string zeros = (m - nrOfNines - 1) > 0 ? string(m - nrOfNines - 1, '0') : "";
    string answer = zeros + string(1, rest) + nines;
    answer[0] = answer[0] + 1;

    return answer;

}

string calcMax(int m, int s) {

    int nrOfNines = s / 9;
    char rest = '0' + (s % 9);
    string nines = nrOfNines > 0 ? string(nrOfNines, '9') : "";
    if (m == nrOfNines) {
        return nines;
    }

    string zeros = (m - nrOfNines - 1) > 0 ? string(m - nrOfNines - 1, '0') : "";
    string answer = nines + string(1, rest) + zeros;

    return answer;
}