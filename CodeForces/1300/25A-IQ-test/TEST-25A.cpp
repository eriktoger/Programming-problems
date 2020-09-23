#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "25A-IQ-test.h"
using namespace std;


TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("5\n"
                         "2 4 7 8 10", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    iqTest();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "3");
}
TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("4\n"
                         "1 2 1 1"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    iqTest();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}
