#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include "common.h"

using namespace std;

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

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate rightDirection = {0, 1};
constexpr Coordinate leftDirection = {0, -1};

constexpr array<Coordinate, 2> rowNeighbours = {leftDirection, rightDirection};
constexpr array<Coordinate, 2> colNeighbours = {upDirection, downDirection};

constexpr array<Coordinate, 4> directions = {leftDirection, rightDirection, upDirection, downDirection};

vector<Coordinate> findConnectedPlots(vector<string> const &input, unordered_map<string, bool> &alreadyVisited, int row, int col, string key, char currentAreaToken);