#!/bin/bash
path="$1/$2/$3-$4/"
./createOutput $path
filename="output.cpp"
pathTwo=$path$filename
g++ -o output $pathTwo -Wall -std=c++20
rm "output"
