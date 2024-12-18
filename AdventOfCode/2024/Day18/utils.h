#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <array>
#include <string>
#include <tuple>
#include <climits>
#include <queue>
#include <regex>
#include "common.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_18_H
#define ADVENT_OF_CODE_UTILS_18_H

int solver(const vector<vector<char>> &grid, int width, int height);

struct Coordinate
{
    int row;
    int col;

    bool operator==(const Coordinate &other) const
    {
        return row == other.row && col == other.col;
    }
    bool operator<(const Coordinate &other) const
    {
        if (row == other.row)
        {
            return col < other.col;
        }

        return row < other.row;
    }
};

struct State
{
    int cost;
    Coordinate coordinate;
    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate rightDirection = {0, 1};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate leftDirection = {0, -1};

constexpr array<Coordinate, 4> directions = {upDirection, rightDirection, downDirection, leftDirection};

constexpr char wallToken = '#';
constexpr char freeToken = '.';

const regex coordinatePattern("^([0-9]+),([0-9]+)$");

struct Board
{
    vector<vector<char>> grid;
    int width;
    int height;
    vector<Coordinate> coordinates;
};

Board generateBoard(const vector<string> &input);

#endif // ADVENT_OF_CODE_UTILS_18_H