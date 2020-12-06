#include "BigInteger.h"

using std::make_unique;
using std::unique_ptr;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

BigInteger::BigInteger() {
    number = make_unique<string>("0");
    isPositive = true;
}

BigInteger::BigInteger(const std::string &n, bool isPos) {
    number = make_unique<string>(n);
    isPositive = isPos;
}


std::string BigInteger::getNumber() const {
    return *number;
}

bool BigInteger::getIsPositive() const {
    return isPositive;
}

BigInteger BigInteger::operator+(BigInteger const &other) const {


    auto shorter = this->number->size() < other.number->size() ? this->getNumber() : other.getNumber();
    auto longer = this->number->size() >= other.number->size() ? this->getNumber() : other.getNumber();

    //deals with number of same sign
    if (this->isPositive == other.isPositive) {
        int rest = 0;
        char const ZERO = '0'; //maybe move to header
        string answer;
        int diff = longer.size() - shorter.size();
        for (int i = shorter.size() - 1; i >= 0; i--) {
            int s = shorter.at(i) - ZERO;
            int l = longer.at(diff + i) - ZERO;
            int sum = s + l + rest;
            rest = sum / 10;
            sum %= 10;
            char c = ZERO + sum;
            answer += c;
        }
        int i = longer.size() - shorter.size() - 1;
        for (; i >= 0; i--) {
            int l = longer.at(i) - ZERO;
            int sum = l + rest;
            rest = sum / 10;
            sum %= 10;
            char c = ZERO + sum;
            answer += c;
        }
        if (rest == 1) {
            answer += '1';
        }
        reverse(begin(answer), end(answer));
        return BigInteger(answer, this->isPositive);
    }

    if (!other.isPositive) {
        BigInteger bigInteger = BigInteger(other.getNumber(), !other.getIsPositive());
        return *this - bigInteger;
    } else {
        BigInteger bigInteger = BigInteger(this->getNumber(), !this->getIsPositive());
        return other - bigInteger;
    }


}

BigInteger BigInteger::operator-(BigInteger const &other) const {

    // a - -b -> a + b and -a --b -> -a +b -> (in op+)  b - a
    // -a - b ->  -a + -b
    if (!other.getIsPositive() || !this->getIsPositive()) {
        BigInteger bigInteger = BigInteger(other.getNumber(), !other.getIsPositive());
        return *this + bigInteger;
    }
    // a - b  = -(b-a)
    if (*this < other) {
        auto bigInteger = other - *this;
        bigInteger.isPositive = !bigInteger.isPositive;
        return bigInteger;
    }
    auto longer = this->getNumber();
    auto shorter = other.getNumber();
    auto diff = longer.size() - shorter.size();
    auto padding = string(diff, '0');
    shorter = padding + shorter; //maybe do this above as well
    string answer;
    char const ZERO = '0'; //maybe move to header
    char const BEFORE_ZERO = '/';
    int i = longer.size() - 1;
    for (; i >= 0; i--) {

        if (longer.at(i) == BEFORE_ZERO) {
            longer.at(i - 1) = longer.at(i - 1) - 1;
            longer.at(i) = '9';
        }

        int s = shorter.at(i) - ZERO;
        int l = longer.at(i) - ZERO;
        if (l < s) {
            longer.at(i - 1) = longer.at(i - 1) - 1;
            l += 10;
        }
        auto differance = l - s;
        char c = ZERO + differance;
        answer += c;

    }

    reverse(begin(answer), end(answer));
    int trailingZeros = 0;
    for (const char &c : answer) {
        if (c == ZERO) {
            trailingZeros++;
        } else {
            break;
        }
    }
    answer.erase(0, trailingZeros);
    return BigInteger(answer, this->isPositive);

}

BigInteger BigInteger::operator*(BigInteger const &other) const {

    // grade school algorithm, used for smaller numbers.
    // maybe factor out to multi(a,b) and used as base case for Karatsuba

    auto shorter = this->number->size() < other.number->size() ? this->getNumber() : other.getNumber();
    auto longer = this->number->size() >= other.number->size() ? this->getNumber() : other.getNumber();
    char const ZERO = '0'; //maybe move to header
    BigInteger bigInteger = BigInteger("0", true);
    int counter = 0;
    for (int i = longer.size() - 1; i >= 0; i--) {
        int tens = 0;
        vector<string> answers;
        for (int j = shorter.size() - 1; j >= 0; j--) {
            int l = longer.at(i) - ZERO;
            int s = shorter.at(j) - ZERO;
            int product = l * s + tens;
            tens = product / 10;
            product %= 10;
            answers.emplace_back(to_string(product));
        }
        if (tens != 0) {
            answers.emplace_back(to_string(tens));
        }
        BigInteger temp = BigInteger("0", true);
        string padding = string(counter, '0');
        for (const auto &num: answers) {
            temp = temp + BigInteger(num + padding, true);
            padding += "0";
        }
        bigInteger = bigInteger + temp;
        counter++;

    }

    bigInteger.isPositive = this->isPositive == other.isPositive;
    return bigInteger;

}

BigInteger BigInteger::operator/(BigInteger const &other) const {
    // use subtraction repeatatly.
    if (*this < other.getNumber()) {
        return BigInteger("0");
    }
    BigInteger counter = BigInteger("0");
    BigInteger zero = BigInteger("0");
    BigInteger current = BigInteger(this->getNumber());
    while (true) {

        if ( (current - other) < zero) {
            if(current.getNumber() == other.getNumber()){
                counter = counter + BigInteger("1");
            }
            break;
        }
        current = current - other;
        counter = counter + BigInteger("1");
    }
    counter.isPositive = this->isPositive == other.isPositive;
    return counter;

}

BigInteger BigInteger::operator%(BigInteger const &other) const {}

bool BigInteger::operator<(BigInteger const &other) const {

    if (this->isPositive && !other.isPositive) {
        return false;
    }

    if (!this->isPositive && other.isPositive) {
        return true;
    }

    if (this->number->size() > other.number->size()) {
        return false;
    }

    if (this->number->size() < other.number->size()) {
        return true;
    }

    auto &one = *this->number;
    auto &two = *other.number;
    for (int i = 0; i < one.size(); i++) {

        if (one.at(i) < two.at(i)) {
            return true;
        }

        if (one.at(i) > two.at(i)) {
            return false;
        }

    }

    return false;
}
