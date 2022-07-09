//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。 
//
// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。 
//
// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//输出：3
//解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//输出：0
//解释：所有 1 都在边界上或可以到达边界。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 500 
// grid[i][j] 的值为 0 或 1 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 117 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    constexpr static int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
    int n, m;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            dfs(0, i, grid);
            dfs(n - 1, i, grid);
        }

        for (int i = 1; i < n - 1; i ++) {
            dfs(i, 0, grid);
            dfs(i, m - 1, grid);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) res ++;
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] != 1) return;
        grid[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int xn = x + dx[i];
            int yn = y + dy[i];

            if (xn >= 0 && xn < n && yn >= 0 && yn < m && grid[xn][yn] == 1) {
                dfs(xn, yn, grid);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> grid{{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << s.numEnclaves(grid) << endl;
}