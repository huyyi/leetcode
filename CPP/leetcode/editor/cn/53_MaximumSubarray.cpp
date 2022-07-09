//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：nums = [-1]
//输出：-1
// 
//
// 示例 5： 
//
// 
//输入：nums = [-100000]
//输出：-100000
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
// Related Topics 数组 分治 动态规划 👍 3887 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> nums;
    int find(int l, int r) {
        if (l >= r) return nums[l];
        int mid = l + r >> 1;
        int left = find(l, mid);
        int right = find(mid + 1, r);

        int max_left = 0;
        for (int i = mid, sum = 0; i <= r; ++i) {
            sum += nums[i];
            max_left = max(max_left, sum);
        }
        int max_right = 0;
        for (int i = mid - 1, sum = 0; i >= l ; --i) {
            sum += nums[i];
            max_right = max(max_right, sum);
        }
        return max(left, max(right, max_left + max_right));
    }
public:
    // DP
//    int maxSubArray(vector<int>& _nums) {
//        nums = _nums;
//        int last = nums[0];
//        int res = last;
//        for (int i = 1; i < nums.size(); i ++) {
//            last = max(nums[i] + last, nums[i]);
//            res = max(res, last);
//        }
//        return res;
//    }
    int maxSubArray(vector<int>& _nums) {
        nums = _nums;
        return find(0, nums.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(test) << endl;
}