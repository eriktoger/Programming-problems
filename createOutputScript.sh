#!/bin/bash

path="CodeForces/1500/580B-Kefa-&-Company/"
g++ -o createOutput createOutput.cpp -Wall -std=c++17
./createOutput $path
filename="output.cpp"
pathTwo=$path$filename
g++ -o output $pathTwo -Wall -std=c++17
rm createOutput
rm "output"
