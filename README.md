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

- ./generateProblem.sh CodeForces 1400 1714E Add-Modulo-10

# Run tests:

- You first need to install Catch2.
- Go to folder and run: cmake . && make
- cmake . is only needed once
- Or use debugger by pressing F5 (in visual studio code) when you are in the test file. You do need a task.json in .vscode folder.
- And also update launch.json: "program": "${workspaceFolder}/CodeForces/1400/507B-Amr-and-Pins/TEST",

# Create output file

- The createOutput.cpp creates output for Codeforces
- You need to add a myPath.h file that contains: string myPath = "/path/to/repo";
- You need to build generateOutput: g++ -o generateOutput generateOutput.cpp -Wall -std=c++20
- run: ./generateOutput CodeForces 1400 1714E Add-Modulo-10

# Convert input/output from CodeForces

- -copy input/output to addNewLine.txt and run: ./addNewLine.sh
