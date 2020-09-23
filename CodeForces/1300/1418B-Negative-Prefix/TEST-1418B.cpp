#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "1418B-Negative-Prefix.h"
using namespace std;

void func() {
    string input;
    cin >> input;
    cout << input;
}

TEST_CASE( "Input 1", "example" ) {
    stringbuf test_input("5\n"
                         "3\n"
                         "1 3 2\n"
                         "0 0 0\n"
                         "4\n"
                         "2 -3 4 -1\n"
                         "1 1 1 1\n"
                         "7\n"
                         "-8 4 -2 -6 4 7 1\n"
                         "1 0 0 0 1 1 0\n"
                         "5\n"
                         "0 1 -4 6 3\n"
                         "0 0 0 1 1\n"
                         "6\n"
                         "-1 7 10 4 -8 -1\n"
                         "1 0 0 0 0 1", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    negPrefix();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "1 2 3\n"
                               "2 -3 4 -1\n"
                               "-8 -6 1 4 4 7 -2\n"
                               "-4 0 1 6 3\n"
                               "-1 4 7 -8 10 -1");
}
