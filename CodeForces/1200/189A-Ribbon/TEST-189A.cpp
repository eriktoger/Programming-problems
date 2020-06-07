#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "189A-Ribbon.h"
using namespace std;

TEST_CASE( "Example 1", "Template" ) {
    stringbuf test_input("5 5 3 2", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    ribbon();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}
TEST_CASE( "Example 2", "Template" ) {
    stringbuf test_input("7 5 5 2", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    ribbon();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}



