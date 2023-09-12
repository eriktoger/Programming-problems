#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include "main.h"
#define CATCH_CONFIG_RUNNER
using namespace std;

struct TestCase
{
    string input;
    string output;
};

string callFunc(string input)
{
    stringbuf test_input(input, ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    return test_output.str();
}

TEST_CASE("Input Test", "[input][output]")
{
    auto data = GENERATE(TestCase{
                             "5 4\n1 2\n3 4\n5 4\n3 5\n ", "1"},
                         TestCase{"17 15\n"
                                  "1 8\n"
                                  "1 12\n"
                                  "5 11\n"
                                  "11 9\n"
                                  "9 15\n"
                                  "15 5\n"
                                  "4 13\n"
                                  "3 13\n"
                                  "4 3\n"
                                  "10 16\n"
                                  "7 10\n"
                                  "16 7\n"
                                  "14 3\n"
                                  "14 4\n"
                                  "17 6\n",
                                  "2"},
                         TestCase{"4 4\n1 2\n2 3\n1 3\n1 4\n", "0"}, TestCase{"5 4\n2 1\n3 2\n3 4\n5 4\n", "0"});

    SECTION("Test case " + data.input)
    {
        REQUIRE(callFunc(data.input) == data.output);
    }
}
