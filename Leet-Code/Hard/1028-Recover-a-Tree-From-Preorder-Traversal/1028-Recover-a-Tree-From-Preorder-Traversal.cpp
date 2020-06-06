#include "1028-Recover-a-Tree-From-Preorder-Traversal.h"

TreeNode *Solution::recoverFromPreorder(const string &S) {

    parseStringToTreeList(S);
    int val = treeList[0].val;
    auto root = new TreeNode{val, nullptr, nullptr};

    traverseTree(root, 0, 1, treeList.size());

    return root;
}

void Solution::parseStringToTreeList(const string &S) {

    int dashes = 0;
    string nr;

    for (auto c: S) {
        if (c != '-') {
            nr += c;
        } else {
            if (!nr.empty()) {
                treeList.emplace_back(preNode{dashes, stoi(nr)});
                nr = "";
                dashes = 0;
            }
            dashes++;
        }
    }
    if (!nr.empty()) {
        treeList.emplace_back(preNode{dashes, stoi(nr)});
    }

}

void Solution::traverseTree(TreeNode *node, int depth, int lower, int upper) {
    vector<int> children;
    for (int i = lower; i < upper; i++) {
        if (treeList[i].dashes == depth + 1) {
            children.emplace_back(i);
            if (children.size() == 2) {
                break;
            }
        }
    }

    if (children.size() == 2) {
        node->left = new TreeNode{treeList[children[0]].val, nullptr, nullptr};
        node->right = new TreeNode{treeList[children[1]].val, nullptr, nullptr};

        traverseTree(node->left, depth + 1, lower + 1, children[1]);
        traverseTree(node->right, depth + 1, children[1] + 1, upper);
    }
    if (children.size() == 1) {
        node->left = new TreeNode{treeList[children[0]].val, nullptr, nullptr};
        node->right = nullptr;
        traverseTree(node->left, depth + 1, lower + 1, upper);
    }
}
