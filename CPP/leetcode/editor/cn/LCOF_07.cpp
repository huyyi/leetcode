//输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。 
//
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 569 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "algorithm"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
            return nullptr;
        }
        auto res = process(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return &res;
    }

    TreeNode process(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (preorder.size() == 0 || inorder.size() == 0 || pre_right - pre_left != in_right - in_left) {
            return TreeNode();
        }
        auto root = TreeNode(preorder[pre_right]);

        int len = 0;
        auto inorder_root = index()
        auto left = process(preorder, inorder, pre_left + 1, pre_left + len, in_left, in_left + len);
        auto right = process(preorder, inorder, pre_left + len + 1, pre_right, in_left + len + 1, in_right);
        root.left = &left;
        root.right = &right;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    auto t = vector<int>{3,9,20,15,7};
    auto v = vector<int>{9,3,15,20,7};
    s.buildTree(t, v);
}