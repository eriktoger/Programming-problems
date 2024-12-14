#include <regex>
using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_14_H
#define ADVENT_OF_CODE_UTILS_14_H
struct Coordinate
{
    int x;
    int y;
    bool operator==(const Coordinate &other) const
    {
        return x == other.x && y == other.y;
    }
};

constexpr int width = 101;  // 11 for training
constexpr int height = 103; // 7 for training

const regex numbersPattern(R"(p=(-?\d+),(-?\d+)\s+v=(-?\d+),(-?\d+))");

struct Robot
{
    Coordinate position;
    Coordinate direction;
    int quadrant;

    void move(int iterations)
    {
        position.x += (direction.x * iterations);
        position.x %= width;
        if (position.x < 0)
        {
            position.x += width;
        }

        position.y += (direction.y * iterations) + height;
        position.y %= height;
        if (position.y < 0)
        {
            position.y += height;
        }
    }
};

#endif // ADVENT_OF_CODE_UTILS_14_H