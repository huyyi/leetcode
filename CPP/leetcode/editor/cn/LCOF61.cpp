//从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，
//可以看成任意数字。A 不能视为 14。 
//
// 
//
// 示例 1: 
//
// 
//输入: [1,2,3,4,5]
//输出: True 
//
// 
//
// 示例 2: 
//
// 
//输入: [0,0,1,2,5]
//输出: True 
//
// 
//
// 限制： 
//
// 数组长度为 5 
//
// 数组的数取值为 [0, 13] . 
// Related Topics 数组 排序 👍 183 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int mi = -1, mx = -1, z = 0;
        vector<bool> a(14, false);
        for (int num : nums) {
            if (num == 0) {
                z ++;
                continue;
            }
            if (mi == -1 || num < mi) mi = num;
            if (mx == -1 || num > mx) mx = num;
            if (mx - mi > 5) return false;
            if (a[num]) return false;
            a[num] = true;
        }
        return mx - mi > 5;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}