#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_2A_WINNER_H
#define COMPETITIVE_PROGRAMMING_2A_WINNER_H

class Person {
private:
    int score;
    map<int, int> scoreMap;
public:
    Person() : score(0) {}

    void changeScore(int val, int currentRound) {
        score += val;
        if (!scoreMap.count(score)) {
            scoreMap[score] = currentRound;
        }
    }

    int getScore() const { return score; }

    int getRound() const {
        int minRound = 1000;
        for (auto const &pair: scoreMap) {
            if (pair.first >= score) {
                minRound = min(minRound, pair.second);
            }
        }
        return minRound;
    }

    bool operator<(Person const &p) const {
        if (score == p.getScore()) {
            return getRound() > p.getRound();
        }
        return score < p.getScore();
    }
};

void func(std::istream &is = cin, std::ostream &os = cout);

#endif //COMPETITIVE_PROGRAMMING_2A_WINNER_H
