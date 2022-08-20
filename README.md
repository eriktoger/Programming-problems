Repo for my solved C++ programming problems

Im solving problems from:

CodeForce

- Page: https://codeforces.com/
- My username:eriktoger

Leet code

- Page: https://leetcode.com/
- My username: kire85

Hackerrank

- Page: https://www.hackerrank.com/
- My username: erik_toger

# Create new problem:

- . generateProblem.sh CodeForces 1400 1714E Add-Modulo-10

# Run tests:

- You first need to add catch to catch.hpp
- Go to folder and run: g++ -std=c++20 -o main TEST.cpp main.cpp && ./main
- Or use debugger by pressing F5 (in visual studio code) when you are in the test file. You do need a task.json in .vscode folder.

# Create output file

- The createOutput.cpp creates output for Codeforces
- You need to add a myPath.h file that contains const string myPath = "/path/to/repo";
- You need to generate createOutput: g++ -o createOutput createOutput.cpp -Wall -std=c++20
- run: ./createOutputScript.sh CodeForces 1400 1714E Add-Modulo-10

# Convert input/output from CodeForces

- -copy input/output to addNewLine.txt and run: ./addNewLine.sh
