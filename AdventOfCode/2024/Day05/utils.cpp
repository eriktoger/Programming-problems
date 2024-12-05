#include "utils.h"

bool isCorrectOrder(const map<string, vector<string>> &firstToLasts, const vector<string> &pages)
{
    for (size_t i = 0; i < pages.size() - 1; i++)
    {
        for (size_t j = i + 1; j < pages.size(); j++)
        {
            auto firstPage = pages[i];
            auto lastPage = pages[j];
            if (!firstToLasts.contains(lastPage))
            {
                continue;
            }

            auto lastPages = firstToLasts.at(lastPage);
            bool isLastBeforeFirst = find(lastPages.begin(), lastPages.end(), firstPage) != lastPages.end();
            if (isLastBeforeFirst)
            {
                return false;
            }
        }
    }
    return true;
}