#include "Matrix-Rotation-Algo.h"
#include <iostream>
#include <vector>

using namespace std;

//this is only to set up the tests. Hackerrank only wants the code in matrixRotation
int setUpMatrixRotation() {

    int cols, rows, rotations;
    cin >> rows;
    cin >> cols;
    cin >> rotations;
    vector<vector<int >> matrix;
    for (int i = 0; i < rows; i++) {
        vector<int> row;
        for (int j = 0; j < cols; j++) {
            int num;
            cin >> num;
            row.emplace_back(num);
        }
        matrix.emplace_back(row);
    }
    matrixRotation(matrix, rotations);
    printMatrix(matrix);

    return 0;
}

void matrixRotation(vector<vector<int >> &matrix, int rotations) {

    int c = matrix[0].size();
    int r = matrix.size();
    bool isVertical = r > c;
    int verticalSteps = isVertical ? r - c : 0;
    int horizontalSteps = isVertical ? 0 : c - r;

    int layerIdx = 0;
    int startCoord = min(c, r) / 2 - layerIdx - 1;
    while (startCoord >= 0) {

        layerIdx++;

        // go down
        coord start{startCoord, startCoord};
        vector<coord> layer{start};
        fillLayer(layer, verticalSteps, 1, 0, start, layerIdx);

        // going right
        start.row += (verticalSteps + 2 * layerIdx) - 1;
        fillLayer(layer, horizontalSteps, 0, 1, start, layerIdx);

        //going upp
        start.col += (horizontalSteps + 2 * layerIdx) - 1;
        fillLayer(layer, verticalSteps, -1, 0, start, layerIdx);


        // going left
        start.row -= (verticalSteps + 2 * layerIdx) - 1;
        fillLayer(layer, horizontalSteps-1, 0, -1, start, layerIdx);


        changePlaces(matrix,layer,rotations);
        startCoord--;
    }
}

void fillLayer(vector<coord> &layer, int steps, int rowChange, int colChange, coord start, int layerIdx) {
    for (int i = 1; i < (steps + 2 * layerIdx); i++) {
        coord square{start.row + i * rowChange, start.col + i * colChange};
        layer.emplace_back(square);
    }
}

void changePlaces(vector<vector<int >> &matrix,vector<coord> &layer,int rotations){
    int layerLength = layer.size();
    vector<int> newValues(layerLength);
    for (int i = 0; i < layerLength; i++) {
        int idx = (i + rotations) % layerLength;
        newValues[idx] = matrix[layer[i].row][layer[i].col];
    }
    for (int i = 0; i < layerLength; i++) {
        matrix[layer[i].row][layer[i].col] = newValues[i];
    }
}

void printMatrix(vector<vector<int >> &matrix) {
    for (auto &row : matrix) {
        for (int j = 0; j < row.size(); j++) {
            cout << row[j];
            if (j != row.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}