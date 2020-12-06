#ifndef COMPETITIVE_PROGRAMMING_BIGINTEGER_H
#define COMPETITIVE_PROGRAMMING_BIGINTEGER_H

#include <string>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>
class BigInteger {
private:
    std::unique_ptr<std::string> number;
    bool isPositive;
public:
    BigInteger();
    BigInteger(const std::string& n, bool isPos=true);
    std::string getNumber() const;
    bool getIsPositive() const;
    BigInteger operator+(BigInteger const &other) const;
    BigInteger operator-(BigInteger const &other) const;
    BigInteger operator*(BigInteger const &other) const;
    BigInteger operator/(BigInteger const &other) const;
    BigInteger operator%(BigInteger const &other) const;
    bool operator<(BigInteger const &other) const;


};


#endif //COMPETITIVE_PROGRAMMING_BIGINTEGER_H
