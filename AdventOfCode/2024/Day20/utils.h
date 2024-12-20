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

#ifndef ADVENT_OF_CODE_UTILS_20_H
#define ADVENT_OF_CODE_UTILS_20_H

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
constexpr char startToken = 'S';
constexpr char endToken = 'E';

const regex coordinatePattern("^([0-9]+),([0-9]+)$");

vector<vector<int>> solver(const vector<string> &input, Coordinate startCoordinate, int timeToBeat, char stopToken);
vector<Coordinate> getStartEndCoordinates(vector<string> const &input);
unsigned long long getTotalSavedSteps(std::unordered_map<int, int> nrOfStepsSaved);

#endif // ADVENT_OF_CODE_UTILS_20_H