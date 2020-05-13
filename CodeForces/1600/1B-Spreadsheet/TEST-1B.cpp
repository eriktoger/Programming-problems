#include "1B-Spreadsheet.h"

#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"

using namespace std;

TEST_CASE("R23C55 is not excel", "Template") {
    REQUIRE_FALSE(isExcel("R23C55"));
}

TEST_CASE("BC23 is excel", "Template") {
    REQUIRE(isExcel("BC23"));
}

TEST_CASE("RC23 is excel", "Template") {
    REQUIRE(isExcel("RC23"));
}

TEST_CASE("BC23 to R23C55", "Template") {

    stringbuf test_output(ios_base::out);
    streambuf *const cout_buf = cout.rdbuf(&test_output);
    convertFromExcel("BC23");

    cout.
            rdbuf(cout_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "R23C55\n");
}

TEST_CASE("R23C55 to BC23", "Template") {

    stringbuf test_output(ios_base::out);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    convertToExcel("R23C55");

    cout.rdbuf(cout_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "BC23\n");
}

TEST_CASE("55 to BC", "Template") {

    convert10to26(677);

    REQUIRE(convert10to26(55) == "BC");
}

TEST_CASE("Example", "Template") {
    stringbuf test_input("2\nR23C55\nBC23", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    spreadSheet();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "BC23\nR23C55\n");
}

TEST_CASE("R228C494 to RZ228 ", "Template") {
    stringbuf test_input("1\nR228C494", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    spreadSheet();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text == "RZ228\n");
}


