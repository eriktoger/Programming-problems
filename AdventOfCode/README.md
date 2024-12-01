# Get started

- mkdir build
- cd build
- cmake .. -G "MinGW Makefiles"
- cmake --build .
- ./generateDay 2024 01 # To generate more days
- ./runSingleDay 2024 01 # To copy changes in test_files and run tests.
- Change in launch.json to enable debug
  - "cwd": "${workspaceFolder}/AdventOfCode/build",
  - "program": "${workspaceFolder}/AdventOfCode/build/2024/Day01/TEST_01",
- Set standard to c++23
- Search for @ext:ms-vscode.cpptools cpp standard in settings
