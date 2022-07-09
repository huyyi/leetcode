//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 2099 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        // dp[i][j] w1以i-1结尾与w2以j-1结尾子串的最小编辑距离
        vector<vector<int>> dp(n + 1, vector(m + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (w1[i - 1] == w2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    // dp[i][j] 有三个来源，增删改
                    // 每次只修改一个字符，那么可以是w1删一个、w2删一个（等价w1加一个）、w1改为和w2一样
                    // dp[i-1][j] w1以i-2结尾与w2以j-1相同，w1删去[i-1]
                    // dp[i][j-1] w1以i-1结尾与w2以j-2相同，w2删去[j-1]
                    // dp[i-1][j-1] w1以i-2结尾与w2以j-2相同，w1改一个
                    dp[i][j] = min(dp[i][j-1], dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    dp[i][j] ++;
                }
            }
        }
        return dp[n + 1][m + 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}