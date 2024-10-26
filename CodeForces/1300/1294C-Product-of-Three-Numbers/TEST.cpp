#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("6\n"
                            "64\n"
                            "32\n"
                            "97\n"
                            "2\n"
                            "12345\n"
                            "12\n");

    solution(fake_input, test_output);

    EXPECT_EQ("YES\n"
              "2 4 8\n"
              "NO\n"
              "NO\n"
              "NO\n"
              "YES\n"
              "3 5 823\n"
              "NO\n",
              test_output.str());
}
