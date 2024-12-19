#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{
    auto completeTowels = calcCompleteTowels(input);
    return {to_string(completeTowels.size())};
}
