#include "utils.h"

bool increasingComparison(int current, int last)
{
    return current > last && current - last <= 3;
}

bool decreasingComparison(int current, int last)
{
    return current < last && last - current <= 3;
}