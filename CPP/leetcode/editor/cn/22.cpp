//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 👍 2368 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int n;
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        char path[20];
        process(path, 0, 0);
        return res;
    }

    void process(char path[], int l, int r) {
        if (l + r == 2 * n) res.emplace_back(path);
        else {
            if (l < n) {
                path[l + r + 1] = '(';
                process(path, l + 1, r);
            }
            if (r < l) {
                path[l + r + 1] = ')';
                process(path, l, r + 1);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}