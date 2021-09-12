#include "2.2-Kings.h"
#include <vector>
using namespace std;

// left, upper left, up, upper right, right, down right, down, down left
const vector<Move> adjacentSquares = {{0,  -1},
                                      {-1, -1},
                                      {-1, 0},
                                      {-1, 1},
                                      {0,  1},
                                      {1,  1},
                                      {1,  0},
                                      {1,  -1}};

void shortSolution(std::istream &is, std::ostream &os) {
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;
    int kingsPlaced = 0;

    //Use printBoard with the longer solution to see that
    //the board repeats every 3 rows.
    int clusters = rows / 3;
    int leftOvers = rows % 3;
    int fullRows = clusters * 2;
    int holeRows = clusters;
    if (leftOvers >= 1) {
        holeRows++;
    }
    if (leftOvers == 2) {
        fullRows++;
    }

    kingsPlaced += fullRows * cols;
    int trios = cols / 3;
    kingsPlaced += (trios * 2) * holeRows;

    int squaresLeft = cols % 3;
    if (squaresLeft == 2) {
        kingsPlaced += holeRows;
    }

    cout << kingsPlaced;
}


void func(std::istream &is, std::ostream &os) {
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;

    vector<vector<Square>> board(rows, vector<Square>(cols));
    int kingsPlaced = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int freeSquares = 0;
            bool noSuffocation = true;
            canKingBePlaced(i, j, rows, cols, board, noSuffocation, freeSquares);
            if (freeSquares && noSuffocation) {
                placingKing(freeSquares, board[i][j], kingsPlaced);
                updateBoard(i, j, rows, cols, board);
            }
        }
    }

    cout << kingsPlaced;
}

void canKingBePlaced(const int &i, const int &j, const int &rows, const int &cols, const vector<vector<Square> > &board,
                     bool &noSuffocation, int &freeSquares) {
    for (const auto &move: adjacentSquares) {
        bool insideTheBoard = i + move.i >= 0 && i + move.i < rows && j + move.j >= 0 && j + move.j < cols;
        if (insideTheBoard) {
            bool kingStillHasFreeSquare = board[i + move.i][j + move.j].freeAdjacentSquares > 1 ||
                                          !board[i + move.i][j + move.j].occupied;
            noSuffocation &= kingStillHasFreeSquare;
            bool freeSquare = !board[i + move.i][j + move.j].occupied;
            if (freeSquare) {
                freeSquares++;
            }
        }
    }
}

void placingKing(const int &freeSquares, Square &square, int &kingsPlaced) {
    square.occupied = true;
    square.freeAdjacentSquares = freeSquares;
    kingsPlaced++;
}

void updateBoard(const int &i, const int &j, const int &rows, const int &cols, vector<vector<Square> > &board) {
    for (const auto &move: adjacentSquares) {
        bool insideTheBoard = i + move.i >= 0 && i + move.i < rows && j + move.j >= 0 && j + move.j < cols;
        if (insideTheBoard) {
            bool squareIsOccupied = board[i + move.i][j + move.j].occupied;
            if (squareIsOccupied) {
                board[i + move.i][j + move.j].freeAdjacentSquares--;
            }
        }
    }
}

void printBoard(const vector<vector<Square> > &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j].occupied) {
                cout << "K";
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
}