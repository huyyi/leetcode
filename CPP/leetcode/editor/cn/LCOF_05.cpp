//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// Related Topics 字符串 👍 162 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        // 空格占1个空间，替换成%20占3个，需要把后面的数据后移
        string res;
        for (auto const &c : s) {
            if (c != ' ') {
                res.push_back(c);
            }
            else {
                res.append("%20");
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    cout << s.replaceSpace("We are happy") << endl;
}