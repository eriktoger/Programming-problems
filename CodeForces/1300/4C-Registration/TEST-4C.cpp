#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "4C-Registration.h"

using namespace std;


TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("4\n"
                         "abacaba\n"
                         "acaba\n"
                         "abacaba\n"
                         "acab", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "OK\n"
                               "OK\n"
                               "abacaba1\n"
                               "OK\n");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input(
                         "6\n"
                         "first\n"
                         "first\n"
                         "second\n"
                         "second\n"
                         "third\n"
                         "third\n"
                        , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "OK\n"
                               "first1\n"
                               "OK\n"
                               "second1\n"
                               "OK\n"
                               "third1\n");
}
