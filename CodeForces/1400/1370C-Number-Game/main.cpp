#include <cmath>

#include "main.h"

bool checkIfPrime(int number) {
    if (number < 2) {
        return false;
    }

    auto squareRoot = sqrt(number);
    for (int i = 2; i <= squareRoot; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

const string A = "Ashishgup\n";
const string F = "FastestFinger\n";

void solution(std::istream &is, std::ostream &os) {
    int t;

    is >> t;

    while (t--) {
        int number;
        is >> number;

        // A loses on 1 sine there is no move
        if (number == 1) {
            os << F;
            continue;
        }

        // A wins on 2 since there is only one move
        if (number == 2) {
            os << A;
            continue;
        }

        // A wins on odd since odd / odd = 1 and F loses
        if (number % 2 == 1) {
            os << A;
            continue;
        }

        int numberOfTwos = 0;
        while (number % 2 == 0) {
            number /= 2;
            numberOfTwos++;
        }

        // A loses if there is no odd numbers
        // Since the only move is -1 which makes number odd.
        if (number == 1) {
            os << F;
            continue;
        }

        // A loses if number is 2 * p
        // Since dividing with p makes i 2 which is a loss for A
        // and -1 makes i odd which also loses
        if (numberOfTwos == 1 && checkIfPrime(number)) {
            os << F;
        } else {
            os << A;
        }
    }
}
