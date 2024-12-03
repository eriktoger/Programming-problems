#include "solutionOne.h"

const std::regex multiPattern(R"(mul\((\d+),(\d+)\))");

void filterSimpleResults(std::vector<std::string> &results, std::smatch match, bool &isEnabled)
{
    results.push_back(match[0]);
}

vector<string> solutionOne(vector<string> const &input)
{
    auto results = findMulti(input, multiPattern, filterSimpleResults);
    auto sum = findSum(results);

    return {to_string(sum)};
}
