#include <regex>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_23_H
#define ADVENT_OF_CODE_UTILS_23_H

map<string, set<string>> generateNodes(vector<string> const &input);
const std::regex pattern("([a-z]{2})-([a-z]{2})");

#endif // ADVENT_OF_CODE_UTILS_23_H
