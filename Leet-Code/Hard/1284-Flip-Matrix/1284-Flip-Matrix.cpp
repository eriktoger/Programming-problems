#include "1284-Flip-Matrix.h"

int Solution::minFlips(vector<vector<int>> &mat) {
    int answer = -1;

    vector<vector<int>> flipped;
    flipped.resize(mat.size(), vector<int>(mat[0].size(), 0));

    int flips = pow(2, mat.size() * mat[0].size());
    while (flips--) {
        iteration(flips, answer, mat);
    }
    return answer;
}

void Solution::iteration(int flips, int &answer, vector<vector<int>> mat) {

    int maybeAnswer = 0;
    Coord coord{0, 0};
    while (flips) {
        if (flips % 2 == 1) {
            flip(coord.col, coord.row, mat);
            maybeAnswer++;
        }
        coord.col++;
        if (coord.col >= mat[0].size()) {
            coord.col = 0;
            coord.row++;
        }
        flips /= 2;
    }

    if (onlyZeros(mat)) {
        if (answer == -1) {
            answer = maybeAnswer;
        } else {
            answer = min(answer, maybeAnswer);
        }
    }
}

bool Solution::onlyZeros(vector<vector<int>> &mat) {
    for (unsigned i = 0; i < mat.size(); i++) {
        for (unsigned j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void Solution::flip(int col, int row, vector<vector<int>> &mat) {

    vector<Coord> coordsToFlip = {Coord{col, row}};
    if (col - 1 >= 0) {
        coordsToFlip.emplace_back(Coord{col - 1, row});
    }
    if (col + 1 < mat[0].size()) {
        coordsToFlip.emplace_back(Coord{col + 1, row});
    }
    if (row - 1 >= 0) {
        coordsToFlip.emplace_back(Coord{col, row - 1});
    }
    if (row + 1 < mat.size()) {
        coordsToFlip.emplace_back(Coord{col, row + 1});
    }

    for (auto coord : coordsToFlip) {
        mat[coord.row][coord.col] = (mat[coord.row][coord.col] + 1) % 2;
    }

}