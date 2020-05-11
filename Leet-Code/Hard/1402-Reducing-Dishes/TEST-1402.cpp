#define CATCH_CONFIG_MAIN
#include "1402-Reducing-Dishes.h"
#include "../../../catch.hpp"
#include <vector>
using namespace std;


TEST_CASE( "Example 1", "Template" ) {
    vector <int> satisfaction {-1,-8,0,5,-9};
    int answer = maxSatisfaction(satisfaction);
    REQUIRE(answer == 14);
}
TEST_CASE( "Example 2", "Template" ) {
    vector <int> satisfaction {4,3,2};
    int answer = maxSatisfaction(satisfaction);
    REQUIRE(answer == 20);
}
TEST_CASE( "Example 3", "Template" ) {
    vector <int> satisfaction {-1,-4,-5};
    int answer = maxSatisfaction(satisfaction);
    REQUIRE(answer == 0);
}
TEST_CASE( "Example 4", "Template" ) {
    vector <int> satisfaction {-2,5,-1,0,3,-3};
    int answer = maxSatisfaction(satisfaction);
    REQUIRE(answer == 35);
}



