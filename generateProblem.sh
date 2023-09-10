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
echo "#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include "\""main.h"\""
#define CATCH_CONFIG_RUNNER
using namespace std;

struct TestCase
{
    string input;
    string output;
};

string callFunc(string input)
{
    stringbuf test_input(input, ios_base::in);
    stringbuf test_output(ios_base::out);
    streambuf *const cin_buf = cin.rdbuf(&test_input);
    streambuf *const cout_buf = cout.rdbuf(&test_output);

    func();

    cout.rdbuf(cout_buf);
    cin.rdbuf(cin_buf);
    return test_output.str();
}

TEST_CASE("\""Input Test"\"", "\""[input][output]"\"")
{
    auto data = GENERATE(TestCase{"\""input"\"", "\""output"\""});

    SECTION("\""Test case "\"" + data.input)
    {
        REQUIRE(callFunc(data.input) == data.output);
    }
}" >> TEST.cpp


touch main.cpp

echo "#include "\""main.h"\""

void func(std::istream &is, std::ostream &os)
{
    int start;

    cin >> start;

    cout << start;
}" >> main.cpp

touch output.cpp

touch CMakeLists.txt 

echo "project($prefix)
cmake_minimum_required(VERSION 3.22)
find_package(Catch2 3 REQUIRED)
add_executable(TEST main.cpp TEST.cpp)
target_link_libraries(TEST PRIVATE Catch2::Catch2WithMain)
add_custom_target(RUN_TEST ALL DEPENDS TEST COMMAND TEST)" >> CMakeLists.txt
