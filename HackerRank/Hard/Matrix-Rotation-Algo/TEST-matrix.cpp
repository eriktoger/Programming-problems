#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "Matrix-Rotation-Algo.h"
using namespace std;


TEST_CASE( "Sample Test Case 1", "Template" ) {
    stringbuf test_input("4 4 2\n 1 2 3 4\n5 6 7 8\n 9 10 11 12\n13 14 15 16", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    setUpMatrixRotation();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text==  "3 4 8 12\n2 11 10 16\n1 7 6 15\n5 9 13 14\n");
}
TEST_CASE( "Sample Test Case 2", "Template" ) {
    stringbuf test_input(" 5 4 7\n 1 2 3 4\n7 8 9 10\n 13 14 15 16\n19 20 21 22\n25 26 27 28", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    setUpMatrixRotation();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text==  "28 27 26 25\n22 9 15 19\n16 8 21 13\n10 14 20 7\n4 3 2 1\n");
}

TEST_CASE( "Sample Test Case 2 reverse", "Template" ) {
    stringbuf test_input(" 4 5 7\n 1 2 3 4 7\n8 9 10 13 14\n15 16 19 20 21\n22 25 26 27 28", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    setUpMatrixRotation();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text==  "28 27 26 25 22\n21 10 13 20 15\n14 9 16 19 8\n7 4 3 2 1\n");
}


