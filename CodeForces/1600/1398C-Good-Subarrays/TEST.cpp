#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("3\n"
                         "3\n"
                         "120\n"
                         "5\n"
                         "11011\n"
                         "6\n"
                         "600005",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "3\n"
                                "6\n"
                                "1");
}
