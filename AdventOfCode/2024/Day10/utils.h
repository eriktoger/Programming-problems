#include <iostream>
#include <vector>

using namespace std;

#ifndef ADVENT_OF_CODE_TWO_UTILS_10_H
#define ADVENT_OF_CODE_TWO_UTILS_10_H

struct Coordinate
{
    int row;
    int col;
};

bool isOutOfBound(vector<string> const &input, Coordinate const &currentZone);
bool isFinished(vector<string> const &input, Coordinate const &currentZone);

const vector<Coordinate> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

#endif // ADVENT_OF_CODE_TWO_UTILS_10_H
