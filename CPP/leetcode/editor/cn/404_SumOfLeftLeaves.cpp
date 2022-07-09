//计算给定二叉树的所有左叶子之和。 
//
// 示例： 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 
//
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 348 👎 0


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
    typedef pair<TreeNode*, bool> Node;

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<Node> Q;
        int res = 0;
        Q.push(Node(root, false));
        while (!Q.empty()) {
            Node cur = Q.front(); Q.pop();
            if (cur.first->left != nullptr) {
                Q.push(Node(cur.first->left, true));
            }
            if (cur.first->right != nullptr) {
                Q.push(Node(cur.first->right, false));
            }
            if (cur.second && cur.first->left == nullptr && cur.first->right == nullptr) {
                res += cur.first->val;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}