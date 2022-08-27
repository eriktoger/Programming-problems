#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("BBBSSC\n"
                         "6 4 1\n"
                         "1 2 3\n"
                         "4\n",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "2");
}

TEST_CASE("Input 2", "First")
{
    stringbuf test_input("BBC\n"
                         "1 10 1\n"
                         "1 10 1\n"
                         "21\n",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "7");
}
TEST_CASE("Input 3", "First")
{
    stringbuf test_input("BSC\n"
                         "1 1 1\n"
                         "1 1 3\n"
                         "1000000000000\n",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "200000000001");
}

TEST_CASE("Input 5", "First")
{
    stringbuf test_input("BSC\n"
                         "3 5 6\n"
                         "7 3 9\n"
                         "100\n",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "10");
}

TEST_CASE("Input 22", "First")
{
    stringbuf test_input("C\n"
                         "100 100 100\n "
                         "1 1 1\n"
                         "1000000000000\n ",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "1000000000100");
}
