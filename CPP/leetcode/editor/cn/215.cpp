//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 1453 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
int find(vector<int>& nums, int k) {
    int n = nums.size();
    int target = n - k + 1; // 如果求第k个最大，就是排序后的第n-k-1个元素
    int l = 0, r = n - 1;
    while (l < r) {
        int i = l - 1, j = r + 1;
        int mid = nums[(l + r) >> 1];
        while (i < j) {
            do i ++; while (nums[i] < mid);
            do j --; while (nums[j] > mid);
            if (i < j) swap(nums[i], nums[j]);
        }
        int sl = j - l + 1;
        if (sl >= target) {
            r = j;
        } else {
            l = j + 1;
            target = target - sl;
        }
    }
    return nums[l];
}
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(test, 2) << endl;
}