#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, Example1)
{
    std::ostringstream test_output;
    stringstream fake_input(
        "5\n"
        "9 3 5 7 3\n"
        "5 8 1 4 5\n");

    solution(fake_input, test_output);

    EXPECT_EQ("29", test_output.str());
}

TEST(Input_Output, Example2)
{
    std::ostringstream test_output;
    stringstream fake_input(
        "3\n"
        "1 2 9\n"
        "10 1 1\n");

    solution(fake_input, test_output);

    EXPECT_EQ("19", test_output.str());
}

TEST(Input_Output, Example3)
{
    std::ostringstream test_output;
    stringstream fake_input(
        "1\n"
        "7\n"
        "4\n");

    solution(fake_input, test_output);

    EXPECT_EQ("7", test_output.str());
}
