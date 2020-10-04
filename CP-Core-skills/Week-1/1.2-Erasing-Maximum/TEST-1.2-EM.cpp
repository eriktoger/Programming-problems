#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "1.2-EM.h"

using namespace std;


TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("3\n"
                         "1 3 2", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "1 2 ");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("7\n"
                         "4 1 4 2 4 3 4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "4 1 4 2 3 4 ");
}

