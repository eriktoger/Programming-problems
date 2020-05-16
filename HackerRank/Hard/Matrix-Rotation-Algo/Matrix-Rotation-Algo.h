#include <vector>
using namespace std;
#ifndef COMPETETIVE_PROGRAMMING_MATRIX_ROTATION_ALGO_H
#define COMPETETIVE_PROGRAMMING_MATRIX_ROTATION_ALGO_H

struct coord {
    int row;
    int col;
};

int setUpMatrixRotation();
void matrixRotation(vector < vector <int >> &matrix, int rotations);
void printMatrix(vector<vector<int >> &matrix);
void fillLayer( vector <coord> &layer,int steps, int rowChange, int colChange, coord start,int layerIdx);
void changePlaces(vector<vector<int >> &matrix,vector<coord> &layer,int rotations);

#endif //COMPETETIVE_PROGRAMMING_MATRIX_ROTATION_ALGO_H
