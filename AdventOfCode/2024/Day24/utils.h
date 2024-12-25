#include <regex>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#ifndef ADVENT_OF_CODE_UTILS_24_H
#define ADVENT_OF_CODE_UTILS_24_H

void runAdder(vector<string> connections, map<string, unsigned long long> &values);
void parseInput(vector<string> const &input, map<string, unsigned long long> &values, vector<string> &connections);
string strip_z(const string &input);
const regex connectionPattern(R"(^(\w+)\s+(XOR|OR|AND)\s+(\w+)\s*->\s*(\w+)$)");
const regex valuePattern(R"(^\s*(\w+):\s*(\S+)\s*$)");

#endif // ADVENT_OF_CODE_UTILS_24_H
