#include <vector>
#include <string>
#include "common.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_17_H
#define ADVENT_OF_CODE_UTILS_17_H

vector<int> getInstructions(vector<string> const &input);
vector<int> solver(vector<string> const &input, const std::vector<int> &instructions, unsigned long long registerA, unsigned long long registerB, unsigned long long registerC);

#endif // ADVENT_OF_CODE_UTILS_17_H