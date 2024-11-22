#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"
#include <vector>

TEST(Input_Output, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("5\n"
                            "2 7 3 4 9\n"
                            "3\n"
                            "1 25 11\n");

    solution(fake_input, test_output);

    EXPECT_EQ("1\n"
              "5\n"
              "3\n",
              test_output.str());
}
