//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
// Related Topics 树 广度优先搜索 二叉树 👍 580 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        int last = 0;

        while(!q.empty()) {
            last = q.size();
            res.emplace_back(vector<int>(last));
            for (int i = 0; i < last; ++i) {
                auto t = q.front();
                q.pop();
                if (reverse) {
                    res.back()[last - i - 1] = t->val;
                } else {
                    res.back()[i] = t->val;
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    int t[]{3,9,20,'#','#',15,7};
    TreeNode *test = NewTree(t, 0, 10);
    s.zigzagLevelOrder(test);
}