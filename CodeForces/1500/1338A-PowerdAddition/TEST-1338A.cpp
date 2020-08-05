#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "1338A-PowerdAddition.h"

using namespace std;

TEST_CASE("simple input 1", "Template") {
    stringbuf test_input("3\n"
                         "4\n"
                         "1 7 6 5\n"
                         "5\n"
                         "1 2 3 4 5\n"
                         "2\n"
                         "0 -4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    powAdd(cin, cout);

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "2\n"
                                "0\n"
                                "3\n");
}

TEST_CASE("Test 3 ", "Template") {
    stringbuf test_input("10\n"
                         "2\n"
                         "-4 4\n"
                         "5\n"
                         "2 3 2 -6 -5\n"
                         "5\n"
                         "-9 -2 -2 7 -5\n"
                         "5\n"
                         "5 -10 2 -9 -5\n"
                         "4\n"
                         "2 -1 -3 -4\n"
                         "8\n"
                         "-4 -2 -10 0 0 -5 1 -8\n"
                         "3\n"
                         "4 5 -3\n"
                         "3\n"
                         "-7 -10 -1\n"
                         "5\n"
                         "4 -7 -6 10 9\n"
                         "7\n"
                         "6 -2 -5 1 0 -2 9\n", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    powAdd(cin, cout);

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "0\n"
                                "4\n"
                                "4\n"
                                "4\n"
                                "3\n"
                                "4\n"
                                "4\n"
                                "2\n"
                                "4\n"
                                "4\n");
}