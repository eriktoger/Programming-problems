#include "solutionOne.h"

vector<string> solutionOne(vector<string> const &input)
{

    unsigned long long secretsScore = 0;

    for (const auto &line : input)
    {
        auto secret = stoull(line);
        int rounds = 2000;
        while (rounds--)
        {
            secret = getNextSecret(secret);
        }

        secretsScore += secret;
    }
    return {to_string(secretsScore)};
}
