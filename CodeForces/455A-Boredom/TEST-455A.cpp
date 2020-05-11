#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../catch.hpp"
#include "455A-Boredom.h"
using namespace  std;


TEST_CASE( "Test #3", "Template" ) {
    stringbuf test_input("9 1 2 1 3 2 2 2 2 3", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    boredom();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "10");
}
TEST_CASE( "Test #42", "Template" ) {

    string input = "100000";
    for(int i =0;i < 100000; i++){
        input += " 100000";
    }

    stringbuf test_input(input, ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf * const cin_buf = cin.rdbuf(&test_input);
    streambuf * const cout_buf = cout.rdbuf(&test_output);

    boredom();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "10000000000");
}
