#!/bin/bash
site=$1
diffculty=$2
prefix=$3
name=$4
folder=$prefix-$name


cd "$site/$diffculty"
mkdir $folder
cd $folder

touch main.h

echo "#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

void func(std::istream &is = cin, std::ostream &os = cout);

#endif //COMPETITIVE_PROGRAMMING_MAIN_H" >> main.h

touch TEST.cpp
echo "#define CATCH_CONFIG_MAIN
#include "\""../../../catch.hpp"\""
#include "\""main.h"\""

using namespace std;


TEST_CASE( "\""Input 1"\"", "\""First"\"" ) {
    stringbuf test_input("\"""\"", ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    string test_output_text = test_output.str();

    REQUIRE(test_output_text== "\"""\"");
}" >> TEST.cpp



touch main.cpp

echo "
#include "\""main.h"\""

void func(std::istream &is, std::ostream &os)
{
    int start;

    cin >> start;

    cout << start;
}" >> main.cpp

touch output.cpp
