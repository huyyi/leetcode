//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。 
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
// Related Topics 数学 双指针 枚举 👍 351 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int sum = 0;
        vector<vector<int>> res;
        for (int i = 1, j = 1; i < target; i ++) {
            sum += i;
            while (j <= i && sum > target) {
                sum -= j ++;
            }
            if (sum == target) {
                vector<int> tmp(i - j + 1);
                for (int k = j, m = 0; k <= i; k ++) tmp[m++] = k;
                res.emplace_back(tmp);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    s.findContinuousSequence(9);
}