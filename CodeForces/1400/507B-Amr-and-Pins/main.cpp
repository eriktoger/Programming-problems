#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    int radius;
    int x1;
    int y1;
    int x2;
    int y2;
    is >> radius;
    is >> x1;
    is >> y1;
    is >> x2;
    is >> y2;
    int distance = ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    int diameter = radius * 2;
    os << distance / diameter + (distance % diameter != 0);
}
