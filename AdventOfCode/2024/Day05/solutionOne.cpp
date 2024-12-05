#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &inputA, vector<string> const &inputB)
{
    auto pageOrders = splitOnDelimiter(inputA, "|");

    map<string, vector<string>> firstToLasts;

    for (auto const &pageOrder : pageOrders)
    {
        auto firstPage = pageOrder[0];
        auto lastPage = pageOrder[1];
        firstToLasts[firstPage].emplace_back(lastPage);
    }

    auto pagesToPrint = splitOnDelimiter(inputB, ",");

    int sum = 0;

    for (auto const &pages : pagesToPrint)
    {
        bool isPagesInCorrectOrder = isCorrectOrder(firstToLasts, pages);
        if (isPagesInCorrectOrder)
        {
            auto middle = pages.at(pages.size() / 2);
            sum += stoi(middle);
        }
    }

    return {to_string(sum)};
}
