#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Case_1, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("ahhellllloou");

    solution(fake_input, test_output);

    EXPECT_EQ("YES\n", test_output.str());
}

TEST(Case_2, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("hlelo");

    solution(fake_input, test_output);

    EXPECT_EQ("NO\n", test_output.str());
}