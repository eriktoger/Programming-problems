#include "utils.h"
using namespace std;

std::vector<std::string> findMulti(vector<string> input, std::regex pattern, std::function<void(std::vector<std::string> &, std::smatch, bool &)> filterResults)
{
    std::smatch match;
    std::vector<std::string> results;
    bool isEnabled = true;
    for (auto line : input)
    {
        auto searchStart = line.cbegin();

        while (std::regex_search(searchStart, line.cend(), match, pattern))
        {
            filterResults(results, match, isEnabled);
            searchStart = match.suffix().first;
        }
    }

    return results;
}

long findSum(vector<string> results)
{
    long sum = 0;
    for (auto result : results)
    {
        regex digitsPattern(R"(\d+)");
        smatch match;
        vector<int> numbers;
        auto searchStart = result.cbegin();

        while (regex_search(searchStart, result.cend(), match, digitsPattern))
        {
            numbers.push_back(stol(match[0]));
            searchStart = match.suffix().first;
        }

        sum += numbers[0] * numbers[1];
    }

    return sum;
}