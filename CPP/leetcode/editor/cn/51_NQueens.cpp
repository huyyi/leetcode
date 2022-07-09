//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 数组 回溯 👍 1053 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> res{};
    void putOne(vector<pair<int, int>> &used, int row, int n) {
        if (used.size() == n) {
            vector<string> tmp{};
            for (auto point : used) {
                string a(n, '.');
                a[point.second] = 'Q';
                tmp.emplace_back(a);
            }
            res.emplace_back(tmp);
        }

        for (int i = 0; i < n; i ++) {
            bool flag = false;
            for (auto point : used) {
                if (point.second == i || abs(point.first - row) == abs(point.second -  i)) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            used.emplace_back(row, i);
            putOne(used, row + 1, n);
            used.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int>> used{};
        putOne(used, 0, n);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.solveNQueens(4);
}