//给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。 
//
// 
//
// 示例： 
//
// 输入: "sea", "eat"
//输出: 2
//解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
// 
//
// 
//
// 提示： 
//
// 
// 给定单词的长度不超过500。 
// 给定单词中的字符只含有小写字母。 
// 
// Related Topics 字符串 动态规划 👍 338 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // word1 和 word2 相同子序列的最长长度
    // dp[i][j]: word1以i-1结尾与word2以j-1结尾相同子序列的最长长度
    // 递推：i-1与j-1相同：[i-1][j-1] + 1
    //      i-1与j-1不同：[i-1][j-1]
    // 初始化：[i][0] 与 [0][j] 都是 0， 空字符串相同子序列长度为0；
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 1; i < word1.size() + 1; i ++) {
            for (int j = 1; j < word2.size() + 1; j++){
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
                }
            }
        }
        return word1.size() + word2.size() - dp[word1.size()][word2.size()] * 2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}