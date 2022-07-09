//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
// Related Topics 数组 二分查找 分治 👍 4995 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();;
        int a = findKth(nums1, nums2, (n + m + 1) / 2);
        int b = findKth(nums1, nums2, (n + m + 2) / 2);
        return (a + b) / 2.0;
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int left1 = 0, left2 = 0;

        while (left1 < n && left2 < m) {
            if (k == 1) {
                if (left1 < n && left2 < m) return min(nums1[left1], nums2[left2]);
                return left1 < n ? nums1[left1] : nums2[left2];
            }
            // 两个向后跳 k / 2 - 1步
            int p1 = min(left1 + (k / 2 - 1), n - 1);
            int p2 = min(left2 + (k / 2 - 1), m - 1);

            if (nums1[p1] <= nums2[p2]) {
                int ll = p1 - left1 + 1;  // p1到left1都不可能为第k小的数
                k -= ll;
                left1 = p1 + 1;
            } else {
                int ll = p2 - left2 + 1;
                k -= ll;
                left2 = p2 + 1;
            }
        }
        if (left1 < n) return nums1[left1 + k - 1];
        return nums2[left2 + k - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test1{1};
    vector<int> test2{2};
    cout << s.findKth(test1, test2, 1) << endl;
}