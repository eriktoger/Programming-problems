#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "580B-Kefa-&-Company.h"
using namespace std;


TEST_CASE( "Test case 1", "nr 1" ) {
    stringbuf test_input("4 5\n"
                         "75 5\n"
                         "0 100\n"
                         "150 20\n"
                         "75 1", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefa();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "100");
}
TEST_CASE( "Test case #", "nr 2" ) {
    stringbuf test_input("5 100\n"
                         "0 7\n"
                         "11 32\n"
                         "99 10\n"
                         "46 8\n"
                         "87 54"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefa();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "111");
}
TEST_CASE( "Test case 3", "nr 2" ) {
    stringbuf test_input("5 1\n"
                         "\n"
                         "5 9\n"
                         "\n"
                         "2 10\n"
                         "\n"
                         "8 5\n"
                         "\n"
                         "18 12\n"
                         "\n"
                         "1 1"

                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefa();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "12");
}
TEST_CASE( "Test case 8", "nr 2" ) {
    stringbuf test_input("4 2\n"
                         "\n"
                         "10909234 9\n"
                         "\n"
                         "10909236 8\n"
                         "\n"
                         "10909237 10\n"
                         "\n"
                         "10909235 98"


                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefa();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "107");
}
