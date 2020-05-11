#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../catch.hpp"
#include "4A-WaterMelon.h"
using namespace  std;


TEST_CASE( "Input 3", "4A-WaterMelon" ) {
    stringbuf test_input("3", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    watermelon();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "NO");
}

TEST_CASE( "Input 2", "4A-WaterMelon" ) {
    stringbuf test_input("2", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    watermelon();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "NO");
}

TEST_CASE( "Input 4", "4A-WaterMelon" ) {
    stringbuf test_input("4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    watermelon();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "YES");
}


