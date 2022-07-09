
//English description is not available for the problem. Please switch to 
//Chinese. 
// Related Topics 数组 二分查找 分治 矩阵 👍 460 👎 0

#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        auto n = matrix.size();
        auto m = matrix[0].size();

        int cur_row = n - 1;
        int cur_col = 0;
        while (cur_row >= 0 && cur_col < m ) {
            if (matrix[cur_row][cur_col] == target) {
                return true;
            } else if (target > matrix[cur_row][cur_col]) {
                cur_col ++;
            } else {
                cur_row --;
            }
        }
        return false;
    };
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    auto test_case = vector<vector<int>> {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
    };
    Solution s;
    cout << s.findNumberIn2DArray(test_case, 20) << endl;
}