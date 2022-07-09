/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    typedef vector<int>::iterator iter;
private:
    TreeNode* process(iter inorderBegin, iter inorderEnd, iter postorderBegin, iter postorderEnd) {
        // 空节点
        if (inorderEnd == inorderBegin) {
            return nullptr;
        } else if (inorderEnd - inorderBegin == 1) {  // 叶子节点
            TreeNode* res = new TreeNode(*inorderBegin);
            return res;
            
        }

        TreeNode* root = new TreeNode(*(postorderEnd - 1));  // 后序的最后一个元素是根

        auto rootInorder = find(inorderBegin, inorderEnd, root->val);

        int leftTreeSize = rootInorder - inorderBegin;

        root->left = process(inorderBegin, rootInorder, postorderBegin, postorderBegin + leftTreeSize);
        root->right = process(rootInorder + 1, inorderEnd, postorderBegin + leftTreeSize, postorderEnd - 1);
        return root;
    }
public:
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return process(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> test{9,3,15,20,7};
    vector<int> test1{9,15,7,20,3};
    s.buildTree(test, test1);
}