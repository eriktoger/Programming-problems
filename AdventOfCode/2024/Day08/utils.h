#include <string>
#include <string>
#include <vector>

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_08_H
#define ADVENT_OF_CODE_UTILS_08_H

struct Coordinate
{
    size_t row;
    size_t col;
};

bool isInBounds(vector<string> const &input, int row, int col);

#endif // ADVENT_OF_CODE_UTILS_08_H