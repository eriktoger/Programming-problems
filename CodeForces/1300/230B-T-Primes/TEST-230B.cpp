#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "230B-T-Primes.h"
#include <functional>
#include "../../../Testing/misc.h"

using namespace std;


TEST_CASE("Solution") {
    auto[input, expected] =
    GENERATE(table<string, string>({
                                           {"3\n 4 5 6",                 "YES\nNO\nNO\n"},
                                           {"10\n 10 9 8 7 6 5 4 3 2 1", "NO\n"
                                                                         "YES\n"
                                                                         "NO\n"
                                                                         "NO\n"
                                                                         "NO\n"
                                                                         "NO\n"
                                                                         "YES\n"
                                                                         "NO\n"
                                                                         "NO\n"
                                                                         "NO\n"},
                                           {"1\n999966000289",           "YES\n"},
                                           {"1\n976197352729",           "NO\n"}
                                   }));

    auto answer = getAnswer(input, &func);

    INFO("Input: " + input);
    REQUIRE(expected == answer);

}