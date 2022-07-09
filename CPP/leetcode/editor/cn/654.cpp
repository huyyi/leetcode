/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
private:
    TreeNode* fromIter(vector<int>::iterator l, vector<int>::iterator r) {
        if (r == l) {
            return nullptr;
        }
        auto rootVal = max_element(l, r);

        TreeNode *root = new TreeNode(*rootVal);
        root->left = fromIter(l, rootVal);
        root->right = fromIter(rootVal + 1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        
        return fromIter(nums.begin(), nums.end());
    }
};
// @lc code=end

