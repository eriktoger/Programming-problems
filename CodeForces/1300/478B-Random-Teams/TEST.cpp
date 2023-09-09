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
    auto data = GENERATE(TestCase{"5 1", "10 10"},
                         TestCase{"3 2", "1 1"},
                         TestCase{"6 3", "3 6"},
                         TestCase{"10 6", "4 10"},
                         TestCase{"1000000000 1", "499999999500000000 499999999500000000"});

    SECTION("Test case " + data.input)
    {
        REQUIRE(callFunc(data.input) == data.output);
    }
}