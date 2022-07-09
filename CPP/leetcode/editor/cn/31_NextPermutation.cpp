//实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须 原地 修改，只允许使用额外常数空间。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[1,2,3]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1,5]
//输出：[1,5,1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
// Related Topics 数组 双指针 👍 1454 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;

        // 从右往左找降序
        while (i > 0 && nums[i - 1] < nums[i]) i --;
        //  整个数组从左到右降序，已经是最大排列，整个颠倒
        if(i == 0) reverse(nums.begin(), nums.end());
        int j = i - 1;
        int k = nums.size() - 1;
        while (k > j && nums[k] > nums[j]) k --;
        swap(nums[k], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{2, 1, 3};
    s.nextPermutation(test);
    cout << test << endl;
}