//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 10⁵ 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 👍 1648 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int needCnt = t.size();
        int minLen = INT_MAX;
        int resL = s.size();

        for (char &c : t) need[c] ++;

        for (int l = 0, r = 0; r < s.size();) {
            // s[r] 是t中的字符
            if (need.find(s[r]) != need.end()) {
                // 还需要一个当前字符
                if (need[s[r]] > 0) needCnt--;
                need[s[r]] --;
            }
            r ++;
            while (l < r && needCnt == 0) {
                // 更新结果
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    resL = l;
                }
                // s[l] 是t中的字符
                if (need.find(s[l]) != need.end()) {
                    // 当前字符刚好够，移除后差一个，needCnt要+1
                    // 小于0的时候表示当前字符冗余了needCnt不需要+1
                    if (need[s[l]] == 0) needCnt++;
                    need[s[l]] ++;
                }
                l++;
            }
        }
        return s.substr(resL, minLen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}