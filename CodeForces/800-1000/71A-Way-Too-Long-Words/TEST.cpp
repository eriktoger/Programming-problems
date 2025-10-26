#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "main.h"

TEST(Input_Output, inputoutput) {
    std::ostringstream test_output;

    stringstream fake_input("4\nword\nlocalization\ninternationalization\npneumonoultramicroscopicsilicovolcanoconiosis");
    
    solution(fake_input, test_output);

    EXPECT_EQ("word\nl10n\ni18n\np43s\n", test_output.str());
}

