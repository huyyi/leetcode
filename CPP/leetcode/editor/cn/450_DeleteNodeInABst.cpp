//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的
//根节点的引用。 
//
// 一般来说，删除节点可分为两个步骤： 
//
// 
// 首先找到需要删除的节点； 
// 如果找到了，删除它。 
// 
//
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。 
//
// 示例: 
//
// 
//root = [5,3,6,2,4,null,7]
//key = 3
//
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
//
//一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
//
//    5
//   / \
//  4   6
// /     \
//2       7
//
//另一个正确答案是 [5,2,6,null,4,null,7]。
//
//    5
//   / \
//  2   6
//   \   \
//    4   7
// 
// Related Topics 树 二叉搜索树 二叉树 👍 543 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {  // 找到要删除的节点
            if (root->left == nullptr && root->right == nullptr) {   // 是叶子节点，直接删
                delete root;
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {  // 左树不为空，返回左子树，删根
                auto newRoot = root->left;
                delete root;
                return newRoot;
            } else if (root->left == nullptr && root->right != nullptr) {  // 右树不为空，返回右子树，删根
                auto newRoot = root->right;
                delete root;
                return newRoot;
            } else {  // 左右都不为空，左子树接到右子树最左节点的左分支上，父亲节点连右子树
                auto newRoot = root->right;
                TreeNode *mostLeft = newRoot;
                while (mostLeft->left != nullptr) {
                    mostLeft = mostLeft->left;
                }
                mostLeft->left = root->left;
                delete root;
                return newRoot;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}