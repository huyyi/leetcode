//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例 1: 
//
// 
//输入：s = "abaccdeff"
//输出：'b'
// 
//
// 示例 2: 
//
// 
//输入：s = "" 
//输出：' '
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 队列 哈希表 字符串 计数 👍 161 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char firstUniqChar(string s) {
        deque<char> q;
        vector<int> a(26, 0);

        for (char b : s) {
            int j = b - 'a';
            if (!a[j]) q.push_back(b);
            a[j] ++;
            while (!q.empty() && a[q.front() - 'a'] > 1) q.pop_front();
        }
        if (!q.empty()) return q.front();
        else return ' ';
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.firstUniqChar("leetcode") << endl;
}