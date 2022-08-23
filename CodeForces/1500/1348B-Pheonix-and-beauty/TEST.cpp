#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("4\n"
                         "4 2\n"
                         "1 2 2 1\n"
                         "4 3\n"
                         "1 2 2 1\n"
                         "3 2\n"
                         "1 2 3\n"
                         "4 4\n"
                         "4 3 4 2\n",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "8\n"
                                "1 2 1 2 1 2 1 2 \n"
                                "12\n"
                                "1 2 1 1 2 1 1 2 1 1 2 1 \n"
                                "-1\n"
                                "16\n"
                                "2 3 4 1 2 3 4 1 2 3 4 1 2 3 4 1 \n");
}
