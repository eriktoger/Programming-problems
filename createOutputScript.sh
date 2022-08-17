#!/bin/bash
path="$1/$2/$3-$4/"
g++ -o createOutput createOutput.cpp -Wall -std=c++17
./createOutput $path
filename="output.cpp"
pathTwo=$path$filename
g++ -o output $pathTwo -Wall -std=c++17
rm createOutput
rm "output"
