#include "377A-Maze.h"
#include <vector>

void maze(std::istream &is, std::ostream &os) {

    int height;
    int width;
    int walls;
    cin >> height;
    cin >> width;
    cin >> walls;

    vector<vector<char> > map;
    int total = height * width;
    int heightIndex = 0;
    int widthIndex = 0;
    int freeHeight = -1;
    int freeWidth = -1;
    vector<char> tempVec(width);
    int cells = 0;
    while (total--) {
        cin >> tempVec[widthIndex];
        if (tempVec[widthIndex] == '.') {
            freeHeight = heightIndex;
            freeWidth = widthIndex;
            cells++;
        }
        widthIndex++;
        if (widthIndex == width) {
            widthIndex = 0;
            heightIndex++;
            map.emplace_back(tempVec);
        }
    }
    //find first free cell
    int remainingCells = cells - walls;
    int cellCounter = 0;
    traverse(freeHeight, freeWidth, map, height, width, cellCounter, remainingCells);

    for (auto const &vec: map) {
        for (auto const &c : vec) {
            if (c == 'v') {
                cout << '.';
            } else if (c == '.') {
                cout << 'X';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }


}

void traverse(int height, int width, vector<vector<char> > &map, int maxHeight, int maxWidth, int &cellCounter,
              int remainingCells) {
    if (cellCounter == remainingCells) {
        return;
    }
    map[height][width] = 'v'; // v for visited;
    cellCounter++;

    if (height > 0 && map[height - 1][width] == '.') {
        traverse(height - 1, width, map, maxHeight, maxWidth, cellCounter, remainingCells);
    }
    if (height + 1 < maxHeight && map[height + 1][width] == '.') {
        traverse(height + 1, width, map, maxHeight, maxWidth, cellCounter, remainingCells);
    }
    if (width > 0 && map[height][width - 1] == '.') {
        traverse(height, width - 1, map, maxHeight, maxWidth, cellCounter, remainingCells);
    }
    if (width + 1 < maxWidth && map[height][width + 1] == '.') {
        traverse(height, width + 1, map, maxHeight, maxWidth, cellCounter, remainingCells);
    }

}