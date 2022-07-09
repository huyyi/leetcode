//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 回溯 👍 849 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> res{};
    vector<string> slices{};

    static bool isPalindrome(const string &s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l ++;
                r --;
            } else {
                return false;
            }
        }
        return true;
    }

    void backtrack(int start, const string &s) {
        if (start >= s.size()) {
            res.push_back(slices);
            return;
        }
        for (int i = 1; i <= s.size() - start; i ++) {
            string tmp = s.substr(start, i);
            if (isPalindrome(tmp)) {
                slices.push_back(tmp);
                backtrack(start + i, s);
                slices.pop_back();
            } else {
                continue;
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto res = s.partition("aab");
}