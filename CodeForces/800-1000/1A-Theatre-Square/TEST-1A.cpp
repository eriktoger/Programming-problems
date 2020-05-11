#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../../catch.hpp"
#include "1A-Theatre-Square.h"
using namespace  std;


TEST_CASE( "Test #1", "1A-TheatreSquare" ) {
    stringbuf test_input("6 6 4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    theatresquare();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "4");
}

TEST_CASE( "Test #9", "1A-TheatreSquare" ) {
    stringbuf test_input("1000000000 1000000000 1", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    theatresquare();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "1000000000000000000");
}

