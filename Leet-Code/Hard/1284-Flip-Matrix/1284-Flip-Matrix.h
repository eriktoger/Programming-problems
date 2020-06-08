#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_1284_FLIP_MATRIX_H
#define COMPETITIVE_PROGRAMMING_1284_FLIP_MATRIX_H

class Solution {

    struct Coord{
        int col;
        int row;
    };
private:
    void iteration(int iterations,int &answer,vector<vector<int>> mat);
    void flip(int col, int row, vector<vector<int>> &mat);
    bool onlyZeros( vector<vector<int>> &mat);

public:
    int minFlips(vector<vector<int>> &mat);
};


#endif //COMPETITIVE_PROGRAMMING_1284_FLIP_MATRIX_H
