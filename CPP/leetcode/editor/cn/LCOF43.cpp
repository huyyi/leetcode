//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。 
//
// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 12
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 13
//输出：6 
//
// 
//
// 限制： 
//
// 
// 1 <= n < 2^31 
// 
//
// 注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/ 
// Related Topics 递归 数学 动态规划 👍 255 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
        vector<int> bits;
        while (n) bits.push_back(n % 10), n /= 10;

        int res = 0;
        for (int i = bits.size() - 1; i >= 0; i --) {
            int left = 0, right = 0, k = 1;
            // 第i位左侧的值，“ab”
            for (int j = bits.size() - 1; j > i; j --) left *= 10, left += bits[j];
            // 第i位右侧的值，“def”
            for (int j = i - 1; j >= 0; j --) right *= 10, right += bits[j], k *= 10;
            // c取1
            res += left * k;
            // c为1，有right + 1种
            if (bits[i] == 1) res += right + 1;
            // c大于等于2，有k种
            if (bits[i] >= 2) res += k;
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