#!/bin/bash

path="CodeForces/1500/1338A-PowerdAddition/"
g++ -o createOutput createOutput.cpp -Wall -std=c++14
./createOutput $path
filename="output.cpp"
pathTwo=$path$filename
g++ -o output $pathTwo -Wall -std=c++14
rm createOutput
rm "output"
