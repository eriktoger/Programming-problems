
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "common.h"

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_19_H
#define ADVENT_OF_CODE_UTILS_19_H

constexpr int partialFind = 1;
constexpr int fullFind = 2;
constexpr int bothFinds = 3;

bool canTowelBeMade(const unordered_map<string, int> &towelPatternsLookup, unordered_set<string> &completeTowels, unordered_set<string> &partialIncompleteTowels, const string &towel, string currentPattern, int towelIndex);
unordered_map<string, int> generateOneTowelPatternsLookup(vector<string> const &input, string towel);
unordered_set<string> calcCompleteTowels(vector<string> const &input);

#endif // ADVENT_OF_CODE_UTILS_19_H