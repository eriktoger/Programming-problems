#include "545C-Woodcutters.h"

void woodcutters(std::istream &is, std::ostream &os) {
    int nrOfTrees;
    is >> nrOfTrees;
    vector<treeInfo> trees;
    while (nrOfTrees--) {
        int idx;
        int height;
        is >> idx;
        is >> height;
        trees.emplace_back(treeInfo{idx, height, 0});
    }
    if (trees.empty()) {
        os << 0;
        return;
    }
    int maxFellCount;
    if (trees.size() > 2) {
        maxFellCount = 2;
        trees[0].direction = -1;
        trees[trees.size() - 1].direction = 1;

        for (unsigned i = 1; i < trees.size() - 1; i++) {
            if (trees[i].idx - trees[i].height > trees[i - 1].idx + trees[i - 1].height * trees[i - 1].direction &&
                trees[i].idx - trees[i].height > trees[i - 1].idx) {
                trees[i].direction = -1;
                maxFellCount++;
            } else if (trees[i].idx + trees[i].height <
                       trees[i + 1].idx + trees[i + 1].height * trees[i + 1].direction &&
                       trees[i].idx + trees[i].height <
                       trees[i + 1].idx) {
                trees[i].direction = 1;
                maxFellCount++;
            }
        }
    } else {
        maxFellCount = trees.size();
    }

    cout << maxFellCount;

}

