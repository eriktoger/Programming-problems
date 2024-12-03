#include "solutionTwo.h"

const std::regex multiPattern(R"(mul\((\d+),(\d+)\)|do\(\)|don\'t\(\))");

void filterResults(std::vector<std::string> &results, std::smatch match, bool &isEnabled)
{
    if (match[0] == "do()")
    {
        isEnabled = true;
    }
    else if (match[0] == "don't()")
    {
        isEnabled = false;
    }
    else if (isEnabled)
    {
        results.push_back(match[0]);
    }
}

vector<string> solutionTwo(vector<string> const &input)
{
    auto results = findMulti(input, multiPattern, filterResults);
    auto sum = findSum(results);

    return {to_string(sum)};
}
