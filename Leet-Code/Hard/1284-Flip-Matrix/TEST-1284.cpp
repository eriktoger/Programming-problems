#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "1284-Flip-Matrix.h"

using namespace std;

TEST_CASE("Example 1", "Template") {
    Solution sol;
    vector<vector<int>> mat = {{0, 0},
                               {0, 1}};
    int answer = sol.minFlips(mat);

    REQUIRE(answer == 3);
}

TEST_CASE("Example 2", "Template") {
    Solution sol;
    vector<vector<int>> mat = {{0}};
    int answer = sol.minFlips(mat);

    REQUIRE(answer == 0);
}

TEST_CASE("Example 3", "Template") {
    Solution sol;
    vector<vector<int>> mat = {{1, 1, 1},
                               {1, 0, 1},
                               {0, 0, 0}};
    int answer = sol.minFlips(mat);

    REQUIRE(answer == 6);
}

TEST_CASE("Example 4", "Template") {
    Solution sol;
    vector<vector<int>> mat = {{1, 0, 0},
                               {1, 0, 0}};
    int answer = sol.minFlips(mat);

    REQUIRE(answer == -1);
}
