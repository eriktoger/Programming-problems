#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, inputoutput)
{
    std::ostringstream test_output;
    stringstream fake_input("8\n"
                            "8\n"
                            "1 0 1 1 0 1 1 1\n"
                            "5\n"
                            "1 1 1 1 0\n"
                            "7\n"
                            "1 1 1 1 0 0 1\n"
                            "6\n"
                            "1 1 1 1 1 1\n"
                            "1\n"
                            "1\n"
                            "1\n"
                            "0\n"
                            "5\n"
                            "0 0 0 1 1\n"
                            "5\n"
                            "1 0 0 1 1\n");

    solution(fake_input, test_output);

    EXPECT_EQ("2\n"
              "2\n"
              "2\n"
              "2\n"
              "1\n"
              "0\n"
              "0\n"
              "1\n",
              test_output.str());
}
