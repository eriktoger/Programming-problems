#include <vector>

using namespace std;
#ifndef COMPETETIVE_PROGRAMMING_980_UNIQUE_PATHS_III_H
#define COMPETETIVE_PROGRAMMING_980_UNIQUE_PATHS_III_H

class Solutions {

private:
    const int START_SQUARE = 1;
    const int END_SQUARE = 2;
    const int FREE_SQUARE = 0;
    const int BLOCKED_SQUARE = -1;
    int steps = 2; //starting square and end square
    int solutions = 0;


    void prepareStep(vector<vector<int>> &, pair<int, int>, vector<pair<int, int> > &, int, int);
    void stepping(vector<vector<int>> &, pair<int, int>, vector<pair<int, int> > &, int, int);

public:
    int uniquePathsIII(vector<vector<int>> &);

};

#endif //COMPETETIVE_PROGRAMMING_980_UNIQUE_PATHS_III_H
