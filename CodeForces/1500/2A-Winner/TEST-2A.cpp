#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "2A-Winner.h"
using namespace std;



TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("3\n"
                         "mike 3\n"
                         "andrew 5\n"
                         "mike 2", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "andrew");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("3\n"
                         "andrew 3\n"
                         "andrew 2\n"
                         "mike 5", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "andrew");
}

TEST_CASE( "Input 6", "Template" ) {
    stringbuf test_input("15\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf 681\n"
                         "\n"
                         "zhahpvqiptvksnbjkdvmknb -74\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf 661\n"
                         "\n"
                         "jpdwmyke 474\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf -547\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf 600\n"
                         "\n"
                         "zhahpvqiptvksnbjkdvmknb -11\n"
                         "\n"
                         "jpdwmyke 711\n"
                         "\n"
                         "bjmj 652\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf -1000\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf -171\n"
                         "\n"
                         "bjmj -302\n"
                         "\n"
                         "aawtvezfntstrcpgbzjbf 961\n"
                         "\n"
                         "zhahpvqiptvksnbjkdvmknb 848\n"
                         "\n"
                         "bjmj -735"
                        , ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "aawtvezfntstrcpgbzjbf");
}
