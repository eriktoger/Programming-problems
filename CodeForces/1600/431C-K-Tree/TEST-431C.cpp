#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

void func() {
    string input;
    cin >> input;
    cout << input;
}

TEST_CASE( "Input 3", "Template" ) {
    stringbuf test_input("input", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "input");
}



