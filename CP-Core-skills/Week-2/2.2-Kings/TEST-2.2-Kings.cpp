#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "2.2-Kings.h"
#include <functional>
#include "../../../Testing/misc.h"

using namespace std;



TEST_CASE("Solution") {

    auto[input, expected] =
    GENERATE(table<string, string>({
                                           {"1 2\n",   "1"},
                                           {"3 3\n",   "8"},
                                           {"2 99\n",  "165"},
                                           {"1 99\n",  "66"},
                                           {"51 51\n", "2312"},
                                           {"50 50\n", "2211"},
                                           {"3 100\n", "266"},
                                           {"1 1\n",   "0"},
                                   }));
    SECTION("Short") {
        auto answer = getAnswer(input, &shortSolution);

        INFO("Input: " + input);
        REQUIRE(expected == answer);
    }

    SECTION("Long") {
        auto answer = getAnswer(input, &func);

        INFO("Input: " + input);
        REQUIRE(expected == answer);
    }
}
