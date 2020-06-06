#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "1028-Recover-a-Tree-From-Preorder-Traversal.h"

using namespace std;


TEST_CASE("Example 1", "Template") {
    Solution sol;
    TreeNode *root = sol.recoverFromPreorder("1-2--3--4-5--6--7");

    REQUIRE(root->left->right->val == 4);
    REQUIRE(root->right->left->val == 6);
}

TEST_CASE("Example 2", "Template") {
    Solution sol;
    TreeNode *root = sol.recoverFromPreorder("1-2--3---4-5--6---7");

    REQUIRE(root->left->left->left->val == 4);
    REQUIRE(root->right->left->left->val == 7);
}

TEST_CASE("Example 3", "Template") {
    Solution sol;
    TreeNode *root = sol.recoverFromPreorder("1-401--349---90--88");

    REQUIRE(root->left->left->left->val == 90);
    REQUIRE(root->left->right->val == 88);
}



