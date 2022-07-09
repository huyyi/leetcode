//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯 👍 799 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        char path[50];
        process(s, path, 0, 0, 1);
        return res;
    }

    void process(string &s, char path[], int p, int idx, int seg) {
        if (seg == 5) {
            if (p == s.size()) res.emplace_back(path, idx);
            return;
        }
        if (idx > 0) path[idx++] = '.';
        if (s[p] == '0') {
            path[idx++] = s[p++];
            process(s, path, p, idx, seg + 1);
        } else {
            int t = s[p] - '0';
            while (t <= 255) {
                path[idx++] = s[p++];
                process(s, path, p, idx, seg + 1);
                if (p >= s.size()) break;
                t = t * 10 + s[p] - '0';
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.restoreIpAddresses("101023") << endl;
}