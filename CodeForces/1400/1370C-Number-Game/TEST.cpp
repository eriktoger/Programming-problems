#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include "main.h"

TEST(Input_Output, inputoutput) {
    std::ostringstream output;
    stringstream input("7\n1\n2\n3\n4\n5\n6\n12\n");

    solution(input, output);

    EXPECT_EQ(
        "FastestFinger\nAshishgup\nAshishgup\nFastestFinger\nAshishgup\nFastest"
        "Finger\nAshishgup\n",
        output.str());
}

TEST(Input_Output, inputoutput_18) {
    std::ostringstream output;
    stringstream input("1\n18");

    solution(input, output);

       EXPECT_EQ("Ashishgup\n", output.str());
}
