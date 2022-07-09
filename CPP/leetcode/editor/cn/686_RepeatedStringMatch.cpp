//给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。 
//
// 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。 
//
// 
//
// 示例 1： 
//
// 输入：a = "abcd", b = "cdabcdab"
//输出：3
//解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
// 
//
// 示例 2： 
//
// 输入：a = "a", b = "aa"
//输出：2
// 
//
// 示例 3： 
//
// 输入：a = "a", b = "a"
//输出：1
// 
//
// 示例 4： 
//
// 输入：a = "abc", b = "wxyz"
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= a.length <= 10⁴ 
// 1 <= b.length <= 10⁴ 
// a 和 b 由小写英文字母组成 
// 
// Related Topics 字符串 字符串匹配 👍 210 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> ne;
public:
    int repeatedStringMatch(string a, string b) {
        ne = vector<int>(b.size() + 1);
        int n = a.size();
        for (int i = 2, j = 0; i < b.size(); i++) {
            while (j && b[i] != b[j + 1]) j = ne[j];
            if (b[i] == b[j + 1]) j ++;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i - j <= a.size(); i = ++i) {
            while (j && a[i % n] != b[j + 1]) j = ne[j];
            if (a[i % n] == b[j + 1]) j ++;
            if (j + 1 == b.size()) return i - b.size() + 2;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.repeatedStringMatch("abcd", "cdabcdab") << endl;
}