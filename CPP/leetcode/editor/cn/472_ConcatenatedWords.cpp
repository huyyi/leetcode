//给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。 
//
// 连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses",
//"rat","ratcatdogcat"]
//输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
//解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成; 
//     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成; 
//     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
// 
//
// 示例 2： 
//
// 
//输入：words = ["cat","dog","catdog"]
//输出：["catdog"] 
//
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 10⁴ 
// 0 <= words[i].length <= 1000 
// words[i] 仅由小写字母组成 
// 0 <= sum(words[i].length) <= 10⁵ 
// 
// Related Topics 深度优先搜索 字典树 数组 字符串 动态规划 👍 174 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static const int N = 100010;
    int s[N][26], idx, cnt[N];
    vector<string> res;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &o1, string &o2){return o1.size() < o2.size();});
        memset(s, -1, sizeof s);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
        for (string &word : words) {
            if (check(word, 0)) res.push_back(word);
            else {
                int p = 0;
                for (int i = 0; i < word.size(); i ++) {
                    int u = word[i] - 'a';
                    if (s[p][u] == -1) s[p][u] = ++idx;
                    p = s[p][u];
                    if (i == word.size() - 1) cnt[p] ++;
                }
            }
        }
        return res;
    }

    // 检查单词从l到结尾是否可由其他较短词组合而成
    bool check(string &word, int l) {
        int p = 0;
        for (int i = l; i < word.size(); i ++) {
            int u = word[i] - 'a';
            if (s[p][u] == -1) return false;
            p = s[p][u];
            if (cnt[p] && check(word, i + 1)) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto test = new vector<string>{ "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    cout << s.findAllConcatenatedWordsInADict(*test) << endl;
}