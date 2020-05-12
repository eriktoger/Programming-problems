#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "980-Unique-Paths-III.h"
#include <utility>
#include <vector>

using namespace std;

int func() {
    return 0;
}

TEST_CASE("Example 1", "Template") {
    Solutions sol;
    vector<vector<int> > grid{{1, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 2, -1}};

    int answer = sol.uniquePathsIII(grid);

    REQUIRE(answer == 2);
}

TEST_CASE("Example 2", "Template") {
    Solutions sol;
    vector<vector<int> > grid{{1, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 2}};

    int answer = sol.uniquePathsIII(grid);

    REQUIRE(answer == 4);
}

TEST_CASE("Example 3", "Template") {
    Solutions sol;
    vector<vector<int> > grid{{0, 1},
                              {2, 0,},
    };

    int answer = sol.uniquePathsIII(grid);

    REQUIRE(answer == 0);
}



