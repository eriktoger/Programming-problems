#include <array>
using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_16_H
#define ADVENT_OF_CODE_UTILS_16_H
struct Coordinate
{
    int row;
    int col;

    Coordinate operator+=(const Coordinate &other)
    {
        row += other.row;
        col += other.col;
        return *this;
    }

    Coordinate operator+(const Coordinate &other) const
    {

        return Coordinate(row + other.row, col + other.col);
    }

    bool operator==(const Coordinate &other) const
    {
        return row == other.row && col == other.col;
    }
};

struct CoordinateHash
{
    std::size_t operator()(const Coordinate &ans) const
    {
        return std::hash<int>()(ans.row) * 31 + std::hash<int>()(ans.col);
    }
};

constexpr char wallToken = '#';
constexpr char startToken = 'S';
constexpr char endToken = 'E';

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate rightDirection = {0, 1};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate leftDirection = {0, -1};

constexpr array<Coordinate, 4> directions = {upDirection, rightDirection, downDirection, leftDirection};

#endif // ADVENT_OF_CODE_UTILS_16_H