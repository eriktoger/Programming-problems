#include "1.4-SF.h"

void func(std::istream &is, std::ostream &os) {

    string c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;

    if (c1[1] != c2[1] || c2[1] != c3[1] || c3[1] != c4[1] || c4[1] != c5[1]) {
        cout << "NO";
        return;
    }

    string values = {c1[0], c2[0], c3[0], c4[0], c5[0]};
    // T J Q K A  is : ; < =  0 or >
    char ace = values.find('2') != string::npos ? '1' : '>';
    for (auto &c : values) {
        switch (c) {
            case 'T':
                c = ':';
                break;
            case 'J':
                c = ';';
                break;
            case 'Q':
                c = '<';
                break;
            case 'K':
                c = '=';
            case 'A':
                c = ace;
            default:
                break;
        }
    }

    sort(values.begin(), values.end());
    if (values[0] + 1 == values[1] && values[1] + 1 == values[2] && values[2] + 1 == values[3] &&
        values[3] + 1 == values[4]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}