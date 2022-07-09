//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1467 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    queue<pair<int, int>> q;
    int res = 0;
public:

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != '1') continue;
                q.push({i, j});
                process(grid);
            }
        }

        // for (int i = 0; i < grid.size(); ++i) {
        //     for (int j = 0; j < grid[0].size(); ++j) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        return res;
    }

private:
    void process(vector<vector<char>>& grid) {
        res ++;
        int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (grid[x][y] != '1') continue;
            grid[x][y] = '0';
            for (int i = 0; i < 4; i ++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size()) continue;
                if (grid[a][b] == '1') q.push({a, b});
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}