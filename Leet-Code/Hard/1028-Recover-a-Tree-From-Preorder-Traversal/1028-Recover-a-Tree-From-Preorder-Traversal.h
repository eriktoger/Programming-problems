

#include <string>
#include <vector>
#include <utility>
using namespace std;
#ifndef COMPETITIVE_PROGRAMMING_1028_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H
#define COMPETITIVE_PROGRAMMING_1028_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

struct preNode {
    int dashes;
    int val;
};

class Solution {

    vector<preNode> treeList;
public:
    TreeNode *recoverFromPreorder(const string& S);
private:
    void parseStringToTreeList(const string& S);

    void traverseTree( TreeNode *node, int depth, int lower, int upper);
};

#endif //COMPETITIVE_PROGRAMMING_1028_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H
