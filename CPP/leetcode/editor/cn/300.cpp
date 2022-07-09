//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。 
//
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序
//列。 
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,3,2,3]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2500 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以设计时间复杂度为 O(n²) 的解决方案吗？ 
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗? 
// 
// Related Topics 数组 二分查找 动态规划 👍 2195 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        vector<int> len;
        d.emplace_back(nums[0]);
        len.emplace_back(1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > d.back()) {
                d.emplace_back(nums[i]);
                len.emplace_back(d.size());
            }
            else {
                int pos = lower_bound(d.begin(), d.end(), nums[i]) - d.begin();
                d[pos] = nums[i];
                len.emplace_back(++pos);
            }
        }

        for (int i = nums.size() - 1, k = d.size() - 1; k >= 0; --i) {
            if (len[i] - 1 == k) {
                d[k] = nums[i];
                --k;
            }
        }
        return d;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}