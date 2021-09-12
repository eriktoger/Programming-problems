#include "misc.h"

string getAnswer(const string &input, const function<void(std::istream &, std::ostream &)>& solution) {
    stringbuf test_input(input, ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    solution(cin, cout);

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();
    return test_output_text;
}