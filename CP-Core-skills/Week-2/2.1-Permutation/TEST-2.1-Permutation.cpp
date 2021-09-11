#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "2.1-Permutation.h"

using namespace std;

TEST_CASE("Input 1", "Template") {
    stringbuf test_input("3\n"
                         "0 1 2\n"
                         "1 0 4\n"
                         "2 4 0\n", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2 1 3");
}

TEST_CASE("Input 2", "Template") {
    stringbuf test_input("4\n"
                         "0 1 1 1\n"
                         "1 0 1 1\n"
                         "1 1 1 0\n"
                         "1 1 1 0\n", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "1 2 3 4");
}

TEST_CASE("Input 3", "Case 13") {
    stringbuf test_input("9\n"
                         "0 24 9 16 64 24 24 9 1\n"
                         "24 0 36 1 1 4 9 49 81\n"
                         "9 36 0 24 64 16 9 24 16\n"
                         "16 1 24 0 49 24 16 1 9\n"
                         "64 1 64 49 0 4 9 4 24\n"
                         "24 4 16 24 4 0 9 81 99\n"
                         "24 9 9 16 9 9 0 1 36\n"
                         "9 49 24 1 4 81 1 0 49\n"
                         "1 81 16 9 24 99 36 49 0\n"
                         , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "6 5 2 4 8 7 3 1 9");
}