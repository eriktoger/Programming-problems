using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_15_H
#define ADVENT_OF_CODE_UTILS_15_H
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

constexpr char upToken = '^';
constexpr char rightToken = '>';
constexpr char downToken = 'v';
constexpr char leftToken = '<';
constexpr char freeToken = '.';
constexpr char wallToken = '#';
constexpr char robotToken = '@';
constexpr char boxToken = 'O';
constexpr char leftBoxToken = '[';
constexpr char rightBoxToken = ']';

constexpr Coordinate upDirection = {-1, 0};
constexpr Coordinate rightDirection = {0, 1};
constexpr Coordinate downDirection = {1, 0};
constexpr Coordinate leftDirection = {0, -1};

#endif // ADVENT_OF_CODE_UTILS_15_H