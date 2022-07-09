/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include "includes/heads.h"
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return process(root, 0, targetSum);
    }

    bool process(TreeNode* root, int pathSum, const int &target) {
        if (root->left == nullptr && root->right == nullptr) {
            if (pathSum + root->val == target) {
                return true;
            } else {
                return false;
            }
        }
        bool l = false;
        bool r = false;
        if (root->left != nullptr) {
            l = process(root->left, pathSum + root->val, target);
        }
        if (!l && root->right != nullptr) {
            r = process(root->right, pathSum + root->val, target);
        }
        return  l || r;
    }
};
// @lc code=end

