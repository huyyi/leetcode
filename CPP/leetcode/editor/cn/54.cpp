//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 矩阵 模拟 👍 977 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    constexpr static int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;

        int x = 0, y = 0, t = 0;
        while (res.size() < n * m) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            int next_x = x + dx[t];
            int next_y = y + dy[t];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || matrix[next_x][next_y] == INT_MIN)
                t = (t + 1) % 4;

            x += dx[t];
            y += dy[t];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}