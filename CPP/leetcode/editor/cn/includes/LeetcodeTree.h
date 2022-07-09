//
// Created by NADPH on 2021/9/18.
//

#ifndef LEETCODE_LEETCODETREE_H
#define LEETCODE_LEETCODETREE_H

#endif //LEETCODE_LEETCODETREE_H
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};


TreeNode *NewTree(int *a, int i, int n) {
    if (i >= n || a[i] == '#') {
        return nullptr;
    }
    auto root = new TreeNode(a[i]);
    root->left = NewTree(a, i * 2 + 1, n);
    root->right = NewTree(a, i * 2 + 2, n);
    return root;
}