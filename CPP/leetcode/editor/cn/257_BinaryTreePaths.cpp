//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 
//
// 叶子节点 是指没有子节点的节点。 
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 深度优先搜索 字符串 二叉树 👍 588 👎 0


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        if (root->left != nullptr) {
            process(res, to_string(root->val), root->left);
        }
        if (root->right != nullptr) {
            process(res, to_string(root->val), root->right);
        }
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string(root->val));
        }
        return res;
    }

    void process(vector<string> &res, const string& path, TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            if (!path.empty()) {
                res.push_back(path + "->" + to_string(node->val));
            }
            return;
        }
        if (node->left != nullptr) {
            process(res, path + "->" + to_string(node->val), node->left);
        }
        if (node->right != nullptr) {
            process(res, path + "->" + to_string(node->val), node->right);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}