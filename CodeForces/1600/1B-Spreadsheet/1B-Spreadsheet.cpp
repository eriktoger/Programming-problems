#include "1B-Spreadsheet.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

void spreadSheet() {
    int testCases;
    cin >> testCases;


    while (testCases--) {
        string coordinate;
        cin >> coordinate;
        if (isExcel(coordinate)) {
            convertFromExcel(coordinate);

        } else {
            convertToExcel(coordinate);
        }

    }


}

bool isExcel(string coordinate) {

    if (coordinate[0] != 'R') {
        return true;
    }

    size_t found = coordinate.find('C');
    return isdigit(coordinate[found - 1]) == 0;


}

void convertFromExcel(string coordinate) {
    std::size_t digitIdx = coordinate.find_first_of("123456789");
    string row = coordinate.substr(0, digitIdx);
    string col = coordinate.substr(digitIdx);

    int rowSize = row.size();
    int sum = 0;
    for (int i = rowSize - 1; i >= 0; i--) {
        int rowInt = row[i];
        rowInt -= 64;
        rowInt *= pow(26, rowSize - i - 1);
        sum += rowInt;
    }

    cout << 'R' << col << 'C' << sum << '\n';

}

void convertToExcel(string coordinate) {
    std::size_t C_Idx = coordinate.find('C');
    string row = coordinate.substr(1, C_Idx - 1);
    string col = coordinate.substr(C_Idx + 1);
    string colStr = convert10to26(stoi(col));
    cout << colStr << row << '\n';
}

string convert10to26(int num) {
    string base26 = "";
    while (num > 0) {
        int temp = num % 26;
        num /= 26;
        if (temp == 0){
            temp = 26;
            num--;
        }
        char c = temp + 64;
        base26 += c;
    }
    reverse(base26.begin(), base26.end());
    return base26;

}