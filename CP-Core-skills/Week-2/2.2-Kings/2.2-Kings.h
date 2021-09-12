#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_2_2_KINGS_H
#define COMPETITIVE_PROGRAMMING_2_2_KINGS_H
struct Square {
    bool occupied = false;
    int freeAdjacentSquares = 0;
};
struct Move {
    int i;
    int j;
};

void func(std::istream &is = cin, std::ostream &os = cout);

void canKingBePlaced(const int &i, const int &j, const int &rows, const int &cols, const vector<vector<Square> > &board,
                     bool &noSuffocation, int &freeSquares);

void placingKing(const int &freeSquares, Square &square, int &kingsPlaced);

void updateBoard(const int &i, const int &j, const int &rows, const int &cols,  vector<vector<Square> > &board);

void printBoard( const vector<vector<Square> > &board);

void shortSolution(std::istream &is = cin, std::ostream &os = cout);


#endif //COMPETITIVE_PROGRAMMING_2_2_KINGS_H
