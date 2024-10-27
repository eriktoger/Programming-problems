#include "main.h"

vector<int> getVector(std::istream &is, int nrOfitems)
{
    vector<int> items;

    while (nrOfitems--)
    {
        int item;
        is >> item;
        items.emplace_back(item);
    }
    return items;
}

void solution(std::istream &is, std::ostream &os)
{
    int nrOfPlayers;
    is >> nrOfPlayers;

    auto lineOne = getVector(is, nrOfPlayers);
    auto lineTwo = getVector(is, nrOfPlayers);

    long long pickFromLineOne = 0;
    long long pickFromLineTwo = 0;
    long long pickFromNoLine = 0;

    int index = 0;
    while (index < nrOfPlayers)
    {
        int playerOne = lineOne[index];
        int playerTwo = lineTwo[index];
        index++;

        long long tempPickFromLineOne = max(pickFromLineTwo + playerOne, pickFromNoLine + playerOne);
        long long tempPickFromLineTwo = max(pickFromLineOne + playerTwo, pickFromNoLine + playerTwo);
        long long tempPickFromNoLine = max(pickFromLineOne, pickFromLineTwo);

        pickFromLineOne = tempPickFromLineOne;
        pickFromLineTwo = tempPickFromLineTwo;
        pickFromNoLine = tempPickFromNoLine;
    }

    long long maxValue = max(pickFromLineOne, pickFromLineTwo);
    maxValue = max(maxValue, pickFromNoLine);

    os << maxValue;
}
