#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, example_1)
{
    std::ostringstream test_output;
    stringstream fake_input("1\n"
                            "3 1\n"
                            "2 1\n"
                            "3 1\n");

    solution(fake_input, test_output);

    EXPECT_EQ("Ashish\n", test_output.str());
}

TEST(Input_Output, example_2)
{
    std::ostringstream test_output;
    stringstream fake_input("1\n"
                            "3 2\n"
                            "1 2\n"
                            "1 3\n");

    solution(fake_input, test_output);

    EXPECT_EQ("Ayush\n", test_output.str());
}

TEST(Input_Output, example_4)
{
    std::ostringstream test_output;
    stringstream fake_input("10\n"
                            "3 3\n"
                            "3 2\n"
                            "1 2\n"
                            "8 8\n"
                            "5 6\n"
                            "3 4\n"
                            "8 1\n"
                            "5 2\n"
                            "2 4\n"
                            "2 1\n"
                            "7 4\n"
                            "4 1\n"
                            "1 2\n"
                            "4 3\n"
                            "3 1\n"
                            "6 5\n"
                            "3 4\n"
                            "4 2\n"
                            "4 6\n"
                            "4 5\n"
                            "5 1\n"
                            "6 2\n"
                            "1 3\n"
                            "2 5\n"
                            "6 4\n"
                            "4 2\n"
                            "4 1\n"
                            "8 1\n"
                            "7 5\n"
                            "7 6\n"
                            "4 2\n"
                            "8 3\n"
                            "2 8\n"
                            "1 8\n"
                            "1 7\n"
                            "6 1\n"
                            "4 1\n"
                            "2 1\n"
                            "1 3\n"
                            "1 6\n"
                            "5 1\n"
                            "8 2\n"
                            "5 1\n"
                            "2 4\n"
                            "3 6\n"
                            "1 2\n"
                            "6 8\n"
                            "6 1\n"
                            "7 3\n"
                            "3 2\n"
                            "2 1\n"
                            "3 2\n"
                            "3 2\n"
                            "2 1\n"
                            "2 3\n");

    solution(fake_input, test_output);

    EXPECT_EQ("Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ayush\n"
              "Ashish\n"
              "Ashish\n",
              test_output.str());
}