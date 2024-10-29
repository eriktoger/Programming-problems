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

# Run tests on Windows (With google test)

- Download the zip files-extract them and move to Program files and add the path to .bashrc
  - Install g++
    - I used x86_64-14.2.0-release-win32-seh-ucrt-rt_v12-rev0.7z
    - export PATH="$PATH:/c/Program Files/mingw64/bin"
  - Install Cmake
    - I used cmake-3.30.5-windows-x86_64.zip
    - export PATH="$PATH:/c/Program Files/cmake/bin"
- Add the files from Example-vscode to .vscode
- Change the program to your current code problem path.
- Build and run tests (navigate to the folder for your code problem): cmake --build . && ./Test.exe
- Go to TEST.cpp, a breakpoint and press F5 to see that the debugger stops at a breakpoint.
- Make sure that vector/arrays/maps work, otherwise you might need to install python
- The path to my repo for "Create output file" looks like this:
  - std::string myPath = "C:\\Users\\etoger\\repos\\other\\Programming-problems";

# Create output file

- The createOutput.cpp creates output for Codeforces
- You need to add a myPath.h file that contains: string myPath = "/path/to/repo";
- You need to build generateOutput: g++ -o generateOutput generateOutput.cpp -Wall -std=c++20
- run: ./generateOutput CodeForces 1400 1714E Add-Modulo-10

# Convert input/output from CodeForces

- -copy input/output to addNewLine.txt and run: ./addNewLine.sh
