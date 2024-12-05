#include "solutionTwo.h"

bool isPageAfterPageB(const map<string, vector<string>> &firstToLasts, const string &pageA, const string &pageB)
{
    if (!firstToLasts.contains(pageA))
    {
        return false;
    }
    const auto &lastPagesA = firstToLasts.at(pageA);
    return find(lastPagesA.begin(), lastPagesA.end(), pageB) != lastPagesA.end();
}

vector<string> sortPages(const map<string, vector<string>> &firstToLasts, const vector<string> &pages)
{
    auto sortedPages = pages;

    auto sortFirstToLast = [firstToLasts](const string &pageA, const string &pageB)
    {
        return isPageAfterPageB(firstToLasts, pageA, pageB);
    };

    sort(sortedPages.begin(), sortedPages.end(), sortFirstToLast);

    return sortedPages;
}

vector<string> solutionTwo(vector<string> const &inputA, vector<string> const &inputB)
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
        if (!isPagesInCorrectOrder)
        {

            auto sortedPages = sortPages(firstToLasts, pages);

            auto middle = sortedPages.at(sortedPages.size() / 2);
            sum += stoi(middle);
        }
    }

    return {to_string(sum)};
}
