//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
// Related Topics 数组 动态规划 👍 991 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition2D(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = 0;
        int max_val = 0;
        for (int num : nums) {
            sum += num;
            max_val = max(num, max_val);
        }
        if (max_val > sum || sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));
        for (int i = 0; i <= sum; i ++) {
            dp[0][i] = nums[0] <= i ? nums[0] : 0;
        }

        for (int i = 1; i < nums.size(); i ++) {
            for (int j = 1; j <= sum; j ++) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - nums[i]] + nums[i], dp[i - 1][j]);
                }
            }
        }
        return dp[nums.size()-1][sum] == sum;
    }
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = 0;
        int max_val = 0;
        for (int num : nums) {
            sum += num;
            max_val = max(num, max_val);
        }
        if (max_val > sum || sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = sum; j >= nums[i]; j --) {
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }
        return dp[sum] == sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{1, 5, 11, 5};
    cout << s.canPartition(test) << endl;
}