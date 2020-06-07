#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "489B-Bersu-Ball.h"

TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("4\n"
                         "1 4 6 2\n"
                         "5\n"
                         "5 1 5 7 9", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    ball();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "3");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("4\n"
                         "1 2 3 4\n"
                         "4\n"
                         "10 11 12 13", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    ball();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "0");
}

TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("5\n"
                         "1 1 1 1 1\n"
                         "3\n"
                         "1 2 3 ", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    ball();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}
