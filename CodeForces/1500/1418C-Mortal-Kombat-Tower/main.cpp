#include "main.h"

vector<int> getBosses(std::istream &is, int nrOfBosses)
{
    vector<int> bosses;
    bosses.reserve(nrOfBosses);

    while (nrOfBosses--)
    {
        int boss;
        is >> boss;
        bosses.emplace_back(boss);
    }

    return bosses;
}

bool checkAndResetForZero(int boss, int &zeroCount, int &playerOneFights, int &playerTwoFights, bool &playerOnesTurn)
{
    if (boss == 0)
    {
        ++zeroCount;
        bool mulipleZerosShouldEndOnPlayerOne = zeroCount > 1;
        if (mulipleZerosShouldEndOnPlayerOne)
        {
            playerOneFights = 0;
            playerTwoFights = 0;
            playerOnesTurn = false;
            return true;
        }
    }
    else
    {
        zeroCount = 0;
    }
    return false;
}

void handlePlayerOneTurn(int boss, int &playerOneFights, int &playerTwoFights, bool &playerOnesTurn, int &skips)
{
    if (playerOneFights == 0 && boss == 0)
    {
        playerOneFights++;
    }
    else if (playerOneFights == 1 && boss == 0)
    {
        playerOneFights = 0;
        playerOnesTurn = false;
    }
    else if (playerOneFights == 0 && boss == 1)
    {
        playerOneFights++;
        skips++;
    }
    else if (playerOneFights == 1 && boss == 1)
    {
        playerOneFights = 0;
        playerTwoFights = 1;
        playerOnesTurn = false;
    }
}

void handlePlayerTwoTurn(int boss, int &playerTwoFights, int &playerOneFights, bool &playerOnesTurn)
{
    if (playerTwoFights == 0 && boss == 0)
    {
        playerTwoFights++;
    }
    else if (playerTwoFights == 1 && boss == 0)
    {
        playerTwoFights = 0;
        playerOneFights = 1;
        playerOnesTurn = true;
    }
    else if (playerTwoFights == 0 && boss == 1)
    {
        playerTwoFights++;
    }
    else if (playerTwoFights == 1 && boss == 1)
    {
        playerTwoFights = 0;
        playerOnesTurn = true;
    }
}

void solution(std::istream &is, std::ostream &os)
{
    int testcases;

    is >> testcases;

    while (testcases--)
    {
        int nrOfBosses;
        is >> nrOfBosses;

        auto bosses = getBosses(is, nrOfBosses);

        bool playerOnesTurn = true;
        int playerOneFights = 0;
        int playerTwoFights = 0;
        int skips = 0;
        int zeroCount = 0;

        for (auto boss : bosses)
        {
            if (checkAndResetForZero(boss, zeroCount, playerOneFights, playerTwoFights, playerOnesTurn))
            {
                continue;
            }

            if (playerOnesTurn)
            {
                handlePlayerOneTurn(boss, playerOneFights, playerTwoFights, playerOnesTurn, skips);
            }
            else
            {
                handlePlayerTwoTurn(boss, playerTwoFights, playerOneFights, playerOnesTurn);
            }
        }

        os << skips;
        os << "\n";
    }
}
