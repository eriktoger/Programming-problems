#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_337A_MAZE_H
#define COMPETITIVE_PROGRAMMING_337A_MAZE_H

void maze(std::istream &is = cin, std::ostream &os = cout);

void traverse(int freeHeight, int freeWidth, vector<vector<char> > &map, int maxHeight, int maxWidth, int& cellCounter, int remainingCells );

#endif //COMPETITIVE_PROGRAMMING_337A_MAZE_H
