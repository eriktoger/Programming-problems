#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "1336A-Linova.h"

using namespace std;


TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("7 4\n"
                         "1 2\n"
                         "1 3\n"
                         "1 4\n"
                         "3 5\n"
                         "3 6\n"
                         "4 7", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "7");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("4 1\n"
                         "1 2\n"
                         "1 3\n"
                         "2 4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}

TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("8 5\n"
                         "7 5\n"
                         "1 7\n"
                         "6 1\n"
                         "3 7\n"
                         "8 3\n"
                         "2 1\n"
                         "4 5", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "9");
}

TEST_CASE( "Input 5", "Template" ) {
    stringbuf test_input("20 7\n"
                         "\n"
                         "9 7\n"
                         "\n"
                         "3 7\n"
                         "\n"
                         "15 9\n"
                         "\n"
                         "1 3\n"
                         "\n"
                         "11 9\n"
                         "\n"
                         "18 7\n"
                         "\n"
                         "17 18\n"
                         "\n"
                         "20 1\n"
                         "\n"
                         "4 11\n"
                         "\n"
                         "2 11\n"
                         "\n"
                         "12 18\n"
                         "\n"
                         "8 18\n"
                         "\n"
                         "13 2\n"
                         "\n"
                         "19 2\n"
                         "\n"
                         "10 9\n"
                         "\n"
                         "6 13\n"
                         "\n"
                         "5 8\n"
                         "\n"
                         "14 1\n"
                         "\n"
                         "16 13", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "38");
}

TEST_CASE( "Input my own", "Template" ) {
    stringbuf test_input("5 3\n"
                         "1 2\n"
                         "2 3\n"
                         "3 4\n"
                         "3 5\n"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "6");
}
TEST_CASE( "Input my own 2", "Template" ) {
    stringbuf test_input("6 4\n"
                         "1 2\n"
                         "2 3\n"
                         "3 4\n"
                         "4 5\n"
                         "4 6\n"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "8");
}