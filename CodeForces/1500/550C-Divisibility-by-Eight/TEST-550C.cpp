#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "500C-Divisibility-by-Eight.h"
using namespace std;

void func() {
    string input;
    cin >> input;
    cout << input;
}

TEST_CASE( "Input 3454", "Template" ) {
    stringbuf test_input("3454", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    divisibility();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "YES\n344");
}
TEST_CASE( "Input 10", "Template" ) {
    stringbuf test_input("10", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    divisibility();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "YES\n0");
}
TEST_CASE( "Input 111111", "Template" ) {
    stringbuf test_input("111111", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    divisibility();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "NO");
}
TEST_CASE( "Input 3111111111111111111111411111111111111111111141111111441", "Template" ) {
    stringbuf test_input("3111111111111111111111411111111111111111111141111111441", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    divisibility();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "YES\n311111111111111111111141111111111111111111114111111144");
}



