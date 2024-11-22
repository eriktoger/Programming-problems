#include "main.h"

void solution(std::istream &is, std::ostream &os)
{
    int piles;
    is >> piles;

    vector<int> wormsInEachPile;
    wormsInEachPile.reserve(piles);

    while (piles--)
    {
        int count;
        is >> count;
        wormsInEachPile.emplace_back(count);
    }
    vector<int> wormsIndex{0};
    int wormCount = 0;
    for (auto worms : wormsInEachPile)
    {
        wormCount += worms;
        wormsIndex.emplace_back(wormCount);
    }

    int juciyWorms;
    is >> juciyWorms;
    while (juciyWorms--)
    {
        int juciyWormIndex;
        is >> juciyWormIndex;

        size_t currentIndex = wormsIndex.size() / 2;
        int floor = 0;
        int ceiling = wormsIndex.size() - 1;
        while (true)
        {
            if (currentIndex == 0)
            {
                os << "1\n";
                break;
            }
            if (currentIndex == wormsIndex.size() - 1)
            {

                os << wormsIndex.size() - 1;
                os << "\n";
                break;
            }

            int currentWorm = wormsIndex[currentIndex];
            if (juciyWormIndex > wormsIndex[currentIndex - 1] && juciyWormIndex <= wormsIndex[currentIndex])
            {
                os << currentIndex;
                os << "\n";
                break;
            }

            if (juciyWormIndex > currentWorm)
            {
                floor = currentIndex + 1;
            }
            else
            {
                ceiling = currentIndex - 1;
            }
            currentIndex = (floor + ceiling) / 2;
        }
    }
}
