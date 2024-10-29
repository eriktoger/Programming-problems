#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("2 4\n"
                            "1 6 3 5\n"
                            "1 4\n"
                            "3 4\n"
                            "1 2\n"
                            "1 2\n");

    solution(fake_input, test_output);

    EXPECT_EQ("1\n"
              "3\n"
              "3\n"
              "3\n",
              test_output.str());
}

TEST(Input_Output, inputoutput_2)
{
    std::ostringstream test_output;
    stringstream fake_input("2 1\n"
                            "1 2 3 4\n"
                            "1 1\n");

    solution(fake_input, test_output);

    EXPECT_EQ("4\n", test_output.str());
}
