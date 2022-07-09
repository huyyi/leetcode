//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
//
// 说明： 
//
// 
// 所有数字都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
// 
//
// 示例 2: 
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
// 
// Related Topics 数组 回溯 👍 365 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> path{};
    vector<vector<int>> res{};
    int pathSum = 0;

    void backtrack(int k, int n) {
        if (path.size() == k) {
            // push_back 执行的是拷贝
            if (pathSum == n) {
                res.push_back(path);
            }
            return;
        }


        int prev = 0;
        if (!path.empty()) {
            prev = path.back();
        }
        for (int i = prev + 1; i <= 9 - k + path.size() + 1; i ++) {
            // 现在path中有m个元素，要留k-m-1个元素，于是结束的位置是9-k+m+1
            if (pathSum + i > n) {
                return;
            }
            path.push_back(i);
            pathSum += i;
            backtrack(k, n);
            pathSum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}