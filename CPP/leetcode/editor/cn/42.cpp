//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 3079 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int> &h) {
        int l = 0, r = h.size() - 1;
        int rightMax = 0, leftMax = 0;
        int res = 0;

        while (l < r) {
            leftMax = max(h[l], leftMax);
            rightMax = max(h[r], rightMax);

            if (leftMax < rightMax) {
                res += leftMax - h[l];
                l ++;
            } else {
                res += rightMax - h[r];
                r --;
            }
        }
        return res;
    }
    int mono_stk(vector<int>& h) {
        vector<int> stk;
        int res = 0;

        for (int i = 0; i < h.size(); ++i) {
            while (!stk.empty() && h[i] > h[stk.back()]) {
                int t = stk.back();
                stk.pop_back();
                if (stk.empty()) break;
                int width = i - stk.back() - 1;
                res += (min(h[i], h[stk.back()]) - h[t]) * width;
            }
            stk.push_back(i);
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