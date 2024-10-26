#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, inputoutput1)
{
    std::ostringstream test_output;
    stringstream fake_input("27");

    solution(fake_input, test_output);

    EXPECT_EQ("22", test_output.str());
}

TEST(Input_Output, inputoutput2)
{
    std::ostringstream test_output;
    stringstream fake_input("4545");

    solution(fake_input, test_output);

    EXPECT_EQ("4444", test_output.str());
}

TEST(Input_Output, inputoutput3)
{
    std::ostringstream test_output;
    stringstream fake_input("9");

    solution(fake_input, test_output);

    EXPECT_EQ("9", test_output.str());
}

TEST(Input_Output, inputoutput4)
{
    std::ostringstream test_output;
    stringstream fake_input("91730629");

    solution(fake_input, test_output);

    EXPECT_EQ("91230320", test_output.str());
}
