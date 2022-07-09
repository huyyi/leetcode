/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res{};
        if (root == nullptr) {
            return res;
        }
        vector<int> path{};

        process(root, targetSum, path, res);
        return res;
    }

    void process(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &res) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right ==nullptr) {
            if (target == root->val) {
                res.push_back(path);
            }
            
        }
        
        if (root -> left != nullptr) {
            process(root->left, target - root->val, path, res);
        }
        if (root -> right != nullptr) {
            process(root->right, target - root->val, path, res);
        }
        path.pop_back();
    }
};
// @lc code=end

