#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "433B-Stones.h"
using namespace std;


TEST_CASE( "Example 1", "Template" ) {
stringbuf test_input("6 6 4 2 7 2 7 3 2 3 6 1 3 4 1 1 6", ios_base::in);
stringbuf test_output(ios_base::out);
streambuf *const cin_buf = cin.rdbuf(&test_input);
streambuf *const cout_buf = cout.rdbuf(&test_output);

stones();

cout.rdbuf(cout_buf);
cin.rdbuf(cin_buf);
string test_output_text = test_output.str();

REQUIRE(test_output_text== "24\n"
                           "9\n"
                           "28\n");
}

TEST_CASE( "Example 2", "Template" ) {
stringbuf test_input("4\n"
                     "\n"
                     "5 5 2 3\n"
                     "\n"
                     "10\n"
                     "\n"
                     "1 2 4\n"
                     "\n"
                     "2 1 4\n"
                     "\n"
                     "1 1 1\n"
                     "\n"
                     "2 1 4\n"
                     "\n"
                     "2 1 2\n"
                     "\n"
                     "1 1 1\n"
                     "\n"
                     "1 3 3\n"
                     "\n"
                     "1 1 3\n"
                     "\n"
                     "1 4 4\n"
                     "\n"
                     "1 2 2", ios_base::in);
stringbuf test_output(ios_base::out);
streambuf *const cin_buf = cin.rdbuf(&test_input);
streambuf *const cout_buf = cout.rdbuf(&test_output);

stones();

cout.rdbuf(cout_buf);
cin.rdbuf(cin_buf);
string test_output_text = test_output.str();

REQUIRE(test_output_text== "10\n"
                           "15\n"
                           "5\n"
                           "15\n"
                           "5\n"
                           "5\n"
                           "2\n"
                           "12\n"
                           "3\n"
                           "5\n");
}

TEST_CASE( "Example 3", "Template" ) {
stringbuf test_input("4\n"
                     "\n"
                     "2 2 3 6\n"
                     "\n"
                     "9\n"
                     "\n"
                     "2 2 3\n"
                     "\n"
                     "1 1 3\n"
                     "\n"
                     "2 2 3\n"
                     "\n"
                     "2 2 3\n"
                     "\n"
                     "2 2 2\n"
                     "\n"
                     "1 1 3\n"
                     "\n"
                     "1 1 3\n"
                     "\n"
                     "2 1 4\n"
                     "\n"
                     "1 1 2", ios_base::in);
stringbuf test_output(ios_base::out);
streambuf *const cin_buf = cin.rdbuf(&test_input);
streambuf *const cout_buf = cout.rdbuf(&test_output);

stones();

cout.rdbuf(cout_buf);
cin.rdbuf(cin_buf);
string test_output_text = test_output.str();

REQUIRE(test_output_text== "5\n"
                           "7\n"
                           "5\n"
                           "5\n"
                           "2\n"
                           "7\n"
                           "7\n"
                           "13\n"
                           "4\n");
}
