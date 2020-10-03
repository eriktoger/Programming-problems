#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "276C-Little-Girl.h"

using namespace std;

TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("3 3\n"
                         "5 3 2\n"
                         "1 2\n"
                         "2 3\n"
                         "1 3", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "25");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("5 3\n"
                         "5 2 4 1 3\n"
                         "1 5\n"
                         "2 3\n"
                         "2 3"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "33");
}
