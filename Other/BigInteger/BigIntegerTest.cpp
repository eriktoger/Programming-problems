#define CATCH_CONFIG_MAIN

#include "../../catch.hpp"
#include "BigInteger.h"

using namespace std;


TEST_CASE("Less than1", "1 < 1") {

    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("1", true);

    REQUIRE((b1 < b2) == false);
}

TEST_CASE("Less than2", "1 < 2") {

    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("2", true);

    REQUIRE((b1 < b2) == true);
}

TEST_CASE("Less than3", "2 < 1") {

    BigInteger b1 = BigInteger("2", true);
    BigInteger b2 = BigInteger("1", true);

    REQUIRE((b1 < b2) == false);
}


TEST_CASE("Less than4", "11 < 9") {

    BigInteger b1 = BigInteger("11", true);
    BigInteger b2 = BigInteger("9", true);

    REQUIRE((b1 < b2) == false);
}

TEST_CASE("Less than5", "9 < 11") {

    BigInteger b1 = BigInteger("9", true);
    BigInteger b2 = BigInteger("11", true);

    REQUIRE((b1 < b2) == true);
}

TEST_CASE("Less than6", "9 < -11") {

    BigInteger b1 = BigInteger("9", true);
    BigInteger b2 = BigInteger("11", false);

    REQUIRE((b1 < b2) == false);
}

TEST_CASE("Less than7", "-9 < 5") {

    BigInteger b1 = BigInteger("9", false);
    BigInteger b2 = BigInteger("5", true);

    REQUIRE((b1 < b2) == true);
}

TEST_CASE("add same sign 1", " 1 + 1 = 2") {
    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("1", true);
    auto b3 = b1 + b2;
    REQUIRE(b3.getNumber() == "2");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("add same sign 2", " -1 + -1 = -2") {
    BigInteger b1 = BigInteger("1", false);
    BigInteger b2 = BigInteger("1", false);
    auto b3 = b1 + b2;
    REQUIRE(b3.getNumber() == "2");
    REQUIRE(b3.getIsPositive() == false);
}

TEST_CASE("add same sign 3", " 95 + 6 = 101") {
    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("1", true);
    auto b3 = b1 + b2;
    REQUIRE(b3.getNumber() == "2");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("add same sign 4", " 999 + 2 = 1001") {
    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("1", true);
    auto b3 = b1 + b2;
    REQUIRE(b3.getNumber() == "2");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("add same sign 5", " 74394 + 4834 = 79228") {
    BigInteger b1 = BigInteger("74394", true);
    BigInteger b2 = BigInteger("4834", true);
    auto b3 = b1 + b2;
    REQUIRE(b3.getNumber() == "79228");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("subtract a negativ", " 10 - (-2) = 12") {
    BigInteger b1 = BigInteger("10", true);
    BigInteger b2 = BigInteger("2", false);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "12");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("subtract a negativ from a negative", " -10 - (-2) = -8") {
    BigInteger b1 = BigInteger("10", false);
    BigInteger b2 = BigInteger("2", false);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "8");
    REQUIRE(b3.getIsPositive() == false);
}

TEST_CASE("subtract a positiv 1", " 7 - 5 = 2") {
    BigInteger b1 = BigInteger("7", true);
    BigInteger b2 = BigInteger("2", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "5");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("subtract a positiv 2", " 100 - 1 = 99") {
    BigInteger b1 = BigInteger("100", true);
    BigInteger b2 = BigInteger("1", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "99");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("subtract a positiv 3", " - 20 - 89 = -109") {
    BigInteger b1 = BigInteger("20", false);
    BigInteger b2 = BigInteger("89", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "109");
    REQUIRE(b3.getIsPositive() == false);
}

TEST_CASE("subtract a positiv 4", " 20 - 89 = -69") {
    BigInteger b1 = BigInteger("20", true);
    BigInteger b2 = BigInteger("89", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "69");
    REQUIRE(b3.getIsPositive() == false);
}

TEST_CASE("subtract a positiv 5", " 52485236 - 654785 = 51830451") {
    BigInteger b1 = BigInteger("52485236", true);
    BigInteger b2 = BigInteger("654785", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "51830451");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("subtract a positiv 6", " 52485236 - 65478511 = -12993275") {
    BigInteger b1 = BigInteger("52485236", true);
    BigInteger b2 = BigInteger("65478511", true);
    auto b3 = b1 - b2;
    REQUIRE(b3.getNumber() == "12993275");
    REQUIRE(b3.getIsPositive() == false);
}

TEST_CASE("multiplication 1", " 1 * 1 = 1") {
    BigInteger b1 = BigInteger("1", true);
    BigInteger b2 = BigInteger("1", true);
    auto b3 = b1 * b2;
    REQUIRE(b3.getNumber() == "1");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("multiplication 2", " 12 × 34 = 408") {
    BigInteger b1 = BigInteger("12", true);
    BigInteger b2 = BigInteger("34", true);
    auto b3 = b1 * b2;
    REQUIRE(b3.getNumber() == "408");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("multiplication 3", " 75214 × 63256 = 4757736784") {
    BigInteger b1 = BigInteger("75214", true);
    BigInteger b2 = BigInteger("63256", true);
    auto b3 = b1 * b2;
    REQUIRE(b3.getNumber() == "4757736784");
    REQUIRE(b3.getIsPositive() == true);
}
TEST_CASE("division 1", " 12 / 3 = 4") {
    BigInteger b1 = BigInteger("12", true);
    BigInteger b2 = BigInteger("3", true);
    auto b3 = b1 / b2;
    REQUIRE(b3.getNumber() == "4");
    REQUIRE(b3.getIsPositive() == true);
}

TEST_CASE("division 2", " 852457 / 6525 = 130") {
    BigInteger b1 = BigInteger("852457", true);
    BigInteger b2 = BigInteger("6525", true);
    auto b3 = b1 / b2;
    REQUIRE(b3.getNumber() == "130");
    REQUIRE(b3.getIsPositive() == true);
}