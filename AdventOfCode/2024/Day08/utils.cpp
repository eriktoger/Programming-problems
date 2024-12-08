#include "utils.h"

bool isInBounds(vector<string> const &input, int row, int col)
{
    return row >= 0 && row < input.size() && col >= 0 && col < input[0].size();
}
