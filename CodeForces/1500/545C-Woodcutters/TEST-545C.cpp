#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "545C-Woodcutters.h"
using namespace std;

TEST_CASE( "Input 1", "Template" ) {
    stringbuf test_input("5\n"
                         "1 2\n"
                         "2 1\n"
                         "5 10\n"
                         "10 9\n"
                         "19 1", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    woodcutters();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "3");
}

TEST_CASE( "Input 2", "Template" ) {
    stringbuf test_input("5\n"
                         "1 2\n"
                         "2 1\n"
                         "5 10\n"
                         "10 9\n"
                         "20 1", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    woodcutters();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "4");
}


void fellTogether(vector<treeInfo> &trees, int &maxFellCount) {
    vector<int> fallenTree;
    for (unsigned i = 1; i < trees.size() - 1; i++) {
        if (trees[i].direction == 's' &&
            trees[i].idx + trees[i].height < (trees[i + 1].idx - trees[i + 1].height)) { // we fell towards
            trees[i].direction = 'r';
            trees[i + 1].direction = 'l';
            maxFellCount += 2;
        }
    }
}
