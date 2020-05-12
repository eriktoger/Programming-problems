#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "980-Unique-Paths-III.h"

using namespace std;

int Solutions::uniquePathsIII(vector<vector<int>> &grid) {
    pair<int, int> square;
    int iLen = grid.size();
    int jLen = grid[0].size();

    for (int i = 0; i < iLen; i++) {
        for (int j = 0; j < jLen; j++) {
            if (grid[i][j] == START_SQUARE) {
                square = make_pair(i, j);
            }
            if (grid[i][j] == FREE_SQUARE) {
                steps++;
            }
        }
    }

    vector<pair<int, int> > visited{square};
    prepareStep(grid, square, visited, iLen, jLen);

    return solutions;
}

void Solutions::prepareStep(vector<vector<int>> &grid, pair<int, int> square, vector<pair<int, int> > &visited, int iLen,
                         int jLen) {

    if (grid[square.first][square.second] == END_SQUARE) {
        if (visited.size() == steps) {
            solutions++;
        }
    }

    square.first++;
    stepping(grid, square, visited, iLen, jLen);
    square.first--;

    square.second++;
    stepping(grid, square, visited, iLen, jLen);
    square.second--;

    square.first--;
    stepping(grid, square, visited, iLen, jLen);
    square.first++;

    square.second--;
    stepping(grid, square, visited, iLen, jLen);
}

void Solutions::stepping(vector<vector<int>> &grid, pair<int, int> square, vector<pair<int, int> > &visited, int iLen,
                            int jLen){
    if (square.first >= 0 && square.first < iLen && square.second >= 0 && square.second < jLen &&
        grid[square.first][square.second] != BLOCKED_SQUARE &&
        !(find(visited.begin(), visited.end(), square) != visited.end())) {

        vector<pair<int, int> > visitedCopy(visited);
        visitedCopy.emplace_back(square);
        prepareStep(grid, square, visitedCopy, iLen, jLen);
    }
}
