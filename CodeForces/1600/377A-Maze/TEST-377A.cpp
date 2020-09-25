#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "377A-Maze.h"
using namespace std;


TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("3 4 2\n"
                         "#..#\n"
                         "..#.\n"
                         "#...", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    maze();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "#.X#\n"
                               "X.#.\n"
                               "#...\n");
}
