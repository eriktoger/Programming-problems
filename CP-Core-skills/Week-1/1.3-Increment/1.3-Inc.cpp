#include "1.3-Inc.h"

void func(std::istream &is, std::ostream &os) {
    string input;
    cin >> input;

    // a lambda
    bool onlyNines = all_of(input.begin(), input.end(), [](const char &c) {
        return c == '9';
    });
    if(onlyNines){
        cout << input.size() +1;
    }else{
        cout << input.size();
    }
}