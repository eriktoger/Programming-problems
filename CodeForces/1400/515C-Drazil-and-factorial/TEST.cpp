#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("4\n"
                         "1234",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "33222");
}

TEST_CASE("Input 2", "First")
{
    stringbuf test_input("3\n"
                         "555",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "555");
}

TEST_CASE("Input 3", "First")
{
    stringbuf test_input("15\n"
                         "012345781234578",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "7777553333222222222222");
}
