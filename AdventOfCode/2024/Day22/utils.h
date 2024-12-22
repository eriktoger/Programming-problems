#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "common.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_22_H
#define ADVENT_OF_CODE_UTILS_22_H

unsigned long long mixing(unsigned long long secret, unsigned long long result);

unsigned long long pruning(unsigned long long secret);

unsigned long long getNextSecret(unsigned long long secret);

#endif // ADVENT_OF_CODE_UTILS_22_H