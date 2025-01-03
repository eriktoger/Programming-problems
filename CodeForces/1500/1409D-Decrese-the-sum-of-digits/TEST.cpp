#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("5\n"
                         "2 1\n"
                         "1 1\n"
                         "500 4\n"
                         "217871987498122 10\n"
                         "100000000000000001 1",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "8\n"
                                "0\n"
                                "500\n"
                                "2128012501878\n"
                                "899999999999999999");
}
