#!/bin/bash
year=$1
day=$2
problem=Day$day
executable=TEST_$day

target_folder="$year/$problem"

echo -e "\nadd_subdirectory(\"$target_folder\")" >> CMakeLists.txt

mkdir $target_folder
cp -r "ExampleDay/"* "$target_folder/"
cd $target_folder

echo "#include <string>
const std::string path =\"$target_folder/test_files/\";" > constants.h

touch CMakeLists.txt 

echo "set(CMAKE_CXX_FLAGS \" -g\")

enable_testing()

add_executable($executable TEST.cpp solution.cpp)

target_link_libraries($executable utils)

target_link_libraries($executable GTest::gtest_main)

file(COPY \${CMAKE_CURRENT_SOURCE_DIR}/test_files/ DESTINATION \${CMAKE_BINARY_DIR}/$target_folder/test_files/)" >> CMakeLists.txt

cd ../../build
cmake .. -G "MinGW Makefiles"
cmake --build . 

"./$target_folder/$executable.exe"
