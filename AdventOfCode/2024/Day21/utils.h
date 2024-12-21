#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "common.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_21_H
#define ADVENT_OF_CODE_UTILS_21_H

vector<string> solver(vector<string> const &input, int nrOfDirPadBots);
vector<string> solverWithCache(vector<string> const &input, int nrOfDirPadBots);

struct Coordinate
{
    int row;
    int col;
    bool operator==(const Coordinate &other) const
    {
        return row == other.row && col == other.col;
    }
};

string findShortestPathInstructions(const unordered_map<char, Coordinate> &positions, char startButton, char endButton);

string generateCacheKey(char startToken, char endToken);

/*
    +---+---+---+
    | 7 | 8 | 9 |
    +---+---+---+
    | 4 | 5 | 6 |
    +---+---+---+
    | 1 | 2 | 3 |
    +---+---+---+
        | 0 | A |
        +---+---+
        */
const unordered_map<char, Coordinate> numPadPositions{
    {'7', {0, 0}},
    {'8', {0, 1}},
    {'9', {0, 2}},
    {'4', {1, 0}},
    {'5', {1, 1}},
    {'6', {1, 2}},
    {'1', {2, 0}},
    {'2', {2, 1}},
    {'3', {2, 2}},
    {'0', {3, 1}},
    {'A', {3, 2}},
};

/*
    +---+---+
    | ^ | A |
+---+---+---+
| < | v | > |
+---+---+---+
*/
const unordered_map<char, Coordinate> dirPadPositions{
    {'^', {0, 1}},
    {'A', {0, 2}},
    {'<', {1, 0}},
    {'v', {1, 1}},
    {'>', {1, 2}},
};

struct DirPadRobot
{
    char currentButton;

    string moveDirPad(char targetButton)
    {

        auto instructions = findShortestPathInstructions(dirPadPositions, currentButton, targetButton);
        instructions += "A";
        currentButton = targetButton;

        return instructions;
    }

    string getInstructions(string previousInstructions)
    {

        string instructions;
        for (auto instruction : previousInstructions)
        {
            instructions += moveDirPad(instruction);
        }

        return instructions;
    }
};

struct NumPadRobot
{

    char currentButton;
    vector<DirPadRobot> dirPadRobots;
    vector<unordered_map<string, unsigned long long>> cachedDirPadLengths;

    unsigned long long moveNumPadWithCache(char targetButton)
    {
        auto instructions = findShortestPathInstructions(numPadPositions, currentButton, targetButton);
        instructions += "A";
        auto totalLength = 0ull;
        auto dirPadCurrentButton = 'A';
        for (auto token : instructions)
        {
            auto key = generateCacheKey(dirPadCurrentButton, token);
            auto finalCacheLevel = cachedDirPadLengths.size() - 1;
            auto length = cachedDirPadLengths[finalCacheLevel].at(key);
            dirPadCurrentButton = token;
            totalLength += length;
        }
        currentButton = targetButton;
        return totalLength;
    }

    unsigned long long getInstructionsWithCache(string code)
    {
        auto totalLength = 0ull;
        for (auto c : code)
        {
            totalLength += moveNumPadWithCache(c);
        }
        return totalLength;
    }

    string moveNumPad(char targetButton)
    {
        auto instructions = findShortestPathInstructions(numPadPositions, currentButton, targetButton);
        instructions += "A";
        currentButton = targetButton;
        for (auto &dirPadRobot : dirPadRobots)
        {
            instructions = dirPadRobot.getInstructions(instructions);
        }

        return instructions;
    }

    string getInstructions(string code)
    {
        string instructions;
        for (auto c : code)
        {
            instructions += moveNumPad(c);
        }
        return instructions;
    }
};
#endif // ADVENT_OF_CODE_UTILS_21_H