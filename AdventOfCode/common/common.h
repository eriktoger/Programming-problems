#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

#ifndef ADVENT_OF_CODE_COMMON_H
#define ADVENT_OF_CODE_COMMON_H

vector<string> fromFileToVector(string fileName);
vector<vector<string>> splitLinesToWords(vector<string> const &input);
vector<vector<string>> splitOnDelimiter(vector<string> const &input, const string &delimiter);
vector<vector<int>> splitLinesToInt(vector<string> const &input);
vector<vector<long long>> splitLinesToLL(vector<string> const &input);
void fromVectorToFile(string fileName, vector<string> const &input);

template <typename T, typename Converter>
std::vector<std::vector<T>> splitLinesToNumbers(
    const std::vector<std::string> &input,
    Converter converter)
{
    std::vector<std::vector<T>> result;
    for (const auto &line : input)
    {
        std::vector<T> temp;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word)
        {
            temp.emplace_back(converter(word));
        }
        result.emplace_back(temp);
    }
    return result;
}

#endif // ADVENT_OF_CODE_COMMON_H