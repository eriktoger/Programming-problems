#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "580C-Kefa-And-Park.h"
using namespace std;



TEST_CASE( "simple input 1", "Template" ) {
    stringbuf test_input("4 1 1 1 0 0 1 2 1 3 1 4", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefaAndPark(cin,cout);

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}

TEST_CASE( "simple input 2 ", "Template" ) {
    ifstream inFile;
    inFile.open("CodeForces/1500/580C-Kefa-And-Park/simpleInput2.txt");
    if (!inFile) {
        REQUIRE_FALSE(true);
    }
    stringbuf test_output(ios_base::out);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefaAndPark(inFile,cout);

    cout.rdbuf(cout_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "2");
}
TEST_CASE( "testcase 9 ", "Template" ) {
    ifstream inFile;
    inFile.open("CodeForces/1500/580C-Kefa-And-Park/testcase9.txt");
    if (!inFile) {
        REQUIRE_FALSE(true);
    }
    stringbuf test_output(ios_base::out);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    kefaAndPark(inFile,cout);

    cout.rdbuf(cout_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "7");
}


