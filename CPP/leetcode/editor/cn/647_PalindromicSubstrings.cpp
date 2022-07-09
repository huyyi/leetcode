//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。 
//
// 回文字符串 是正着读和倒过来读一样的字符串。 
//
// 子字符串 是字符串中的由连续字符组成的一个序列。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 710 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size() , false));
        int res = 0;
        // 遍历方式：对角线到右上角
        for (int i = 0; i < s.size(); i ++) {
            for (int j = 0; j < s.size() - i; j ++) {
                int m = j + i;
                if (s[j] != s[m]) {
                    continue;
                } else if (m - j <= 1 || dp[j + 1][m - 1]) {
                    dp[j][m] = true;
                    res ++;
                }
                cout << j << m << dp[j][m] << ' ';
            }
            cout << endl;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    // i 控制横纵坐标之间的差值，对角线上差值为0，右上角差值为n-1
    // j 控制横坐标的值，纵坐标加上差值i即可
    cout << s.countSubstrings("aaa") << endl;
}