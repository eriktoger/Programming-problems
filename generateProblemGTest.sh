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

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

void solution(std::istream &is = cin, std::ostream &os = cout);

#endif //COMPETITIVE_PROGRAMMING_MAIN_H" >> main.h

touch TEST.cpp
echo "#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "\""main.h"\""

TEST(Input_Output, inputoutput) {
    std::ostringstream test_output;
    stringstream fake_input("\""1"\"");
    
    solution(fake_input, test_output);

    EXPECT_EQ("\""1"\"", test_output.str());
}
" >> TEST.cpp


touch main.cpp

echo "#include "\""main.h"\""

void solution(std::istream &is, std::ostream &os)
{
    int testcases;

    is >> testcases;

    os << testcases;
}" >> main.cpp

touch output.cpp

touch CMakeLists.txt 

echo "cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0135 NEW)
project($prefix)

# Add debugging flags
set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -g\")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "\"""\"" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  TEST
  TEST.cpp
  main.cpp
)

# Specify C++23 standard
target_compile_features(TEST PRIVATE cxx_std_23)

target_link_libraries(
  TEST
  GTest::gtest_main

)

include(GoogleTest)
gtest_discover_tests(TEST)" >> CMakeLists.txt


cmake . -G "MinGW Makefiles"