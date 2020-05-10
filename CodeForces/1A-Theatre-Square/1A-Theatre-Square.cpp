
#include "1A-Theatre-Square.h"
#include <iostream>

void theatresquare() {
    unsigned long long int n, m, a, width, length;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;

    if (n % a == 0) {
        width = n / a;
    } else {
        width = n / a + 1;
    }


    if (m % a == 0) {
        length = m / a;
    } else {
        length = m / a + 1;
    }
    unsigned long long int answer = width * length;
    std::cout << answer;


}