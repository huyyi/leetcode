//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。 
//
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bbbab"
//输出：4
//解释：一个可能的最长回文子序列为 "bbbb" 。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出：2
//解释：一个可能的最长回文子序列为 "bb" 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 659 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
        int n = s.size();
        for (int i = 1; i < n; i ++) {
             for (int j = 0; j < n - i; j ++) {
                 if (s[j] != s[j + i]) {
                     dp[j][j + i] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
                 } else if (i == 1) {
                     dp[j][j + i] = 2;
                 } else {
                     dp[j][j + i] = max(dp[j + 1][i + j - 1] + 2, max(dp[j][i + j - 1], dp[j + 1][i + j]));
                 }
//                 cout << j << i + j << dp[j][i + j] << ' ';
             }
//             cout << endl;
        }
        return dp[0][s.size() - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.longestPalindromeSubseq("bbbab") << endl;
}