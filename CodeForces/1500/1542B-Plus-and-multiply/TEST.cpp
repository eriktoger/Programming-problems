#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "main.h"

using namespace std;

TEST_CASE("Input 1", "First")
{
    stringbuf test_input("5\n"
                         "24 3 5\n"
                         "10 3 6\n"
                         "2345 1 4\n"
                         "19260817 394 485\n"
                         "19260817 233 264",
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
                                "No\n"
                                "Yes");
}

TEST_CASE("Input 2", "First")
{
    stringbuf test_input("30\n"
                         "621071631 43 24\n"
                         "795162205 46 28\n"
                         "834658879 36 45\n"
                         "678600049 5 45\n"
                         "134554597 35 48\n"
                         "75636380 9 38\n"
                         "141504991 37 25\n"
                         "160253597 8 36\n"
                         "768093662 48 46\n"
                         "105226637 47 24\n"
                         "53730825 41 18\n"
                         "504196144 21 50\n"
                         "979063791 4 3\n"
                         "826107259 38 48\n"
                         "966658995 23 1\n"
                         "261950054 22 16\n"
                         "631804787 1 21\n"
                         "689430516 9 18\n"
                         "663143161 19 45\n"
                         "816632191 2 35\n"
                         "347323813 10 20\n"
                         "782870857 27 23\n"
                         "732879002 46 14\n"
                         "489572161 13 36\n"
                         "38087464 27 48\n"
                         "872279571 18 3\n"
                         "606322042 22 37\n"
                         "117083763 29 3\n"
                         "574596481 12 14\n"
                         "815441578 25 33",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "Yes\n"
                                "Yes\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "Yes\n"
                                "No\n"
                                "No\n"
                                "Yes\n"
                                "Yes\n"
                                "No\n"
                                "Yes\n"
                                "No\n"
                                "No\n"
                                "No\n"
                                "No");
}

TEST_CASE("Input 3", "First")
{
    stringbuf test_input("1\n"
                         "782870857 27 23",
                         ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "No");
}