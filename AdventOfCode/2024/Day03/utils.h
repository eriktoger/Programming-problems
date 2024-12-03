#include <vector>
#include <regex>
#include <string>
#include <functional>

long findSum(std::vector<std::string> results);
std::vector<std::string> findMulti(std::vector<std::string> input, std::regex pattern, std::function<void(std::vector<std::string> &, std::smatch, bool &)> filterResults);