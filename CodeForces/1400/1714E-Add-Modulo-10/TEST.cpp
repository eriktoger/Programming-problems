#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("10\n"
                         "2\n"
                         "6 11\n"
                         "3\n"
                         "2 18 22\n"
                         "5\n"
                         "5 10 5 10 5\n"
                         "4\n"
                         "1 2 4 8\n"
                         "2\n"
                         "4 5\n"
                         "3\n"
                         "93 96 102\n"
                         "2\n"
                         "40 6\n"
                         "2\n"
                         "50 30\n"
                         "2\n"
                         "22 44\n"
                         "2\n"
                         "1 5\n",
                         ios_base::in);

    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "Yes\n"
                                "No\n"
                                "Yes\n"
                                "Yes\n"
                                "No\n"
                                "Yes\n"
                                "No\n"
                                "No\n"
                                "Yes\n"
                                "No");
}
