//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1559 👎 0


#include "includes/heads.h"
#include <queue>
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
    // 递归形式
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return subTreeisSym(root->left, root->right);
    }

    bool subTreeisSym(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr ^ right == nullptr) {
            return false;
        } else if (left->val != right->val) {
            return false;
        }
        return subTreeisSym(left->left, right->right) && subTreeisSym(left->right, right->left);
    }

    // 迭代形式
    bool iterSym(TreeNode *root) {
        queue<TreeNode*> Q{};
        Q.push(root->left);
        Q.push(root->right);
        while (!Q.empty()) {
            TreeNode* left = Q.front(); Q.pop();
            TreeNode* right = Q.front(); Q.pop();

            if (left == nullptr && right == nullptr) {
                continue;
            } else if ((left == nullptr ^ right == nullptr) || left->val != right->val) {
                return false;
            } else {
                Q.push(left->left);
                Q.push(right->right);
                Q.push(left->right);
                Q.push(right->left);
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}