//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
// Related Topics 数组 回溯 👍 706 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    typedef vector<int>::iterator iter;
    vector<vector<int>> res{};
    vector<int> path{};
    int pathSum = 0;

    void backtrack(iter begin, iter end, int n) {
        if (pathSum == n) {
            res.push_back(path);
            return;
        }
        for (auto i = begin; i != end; i ++) {
            if (i != begin && *i == *(i - 1)) {
                continue;
            }
            if (pathSum + *i > n) {
                return;
            }
            path.push_back(*i);
            pathSum += *i;
            backtrack(i+1, end, n);
            pathSum -= *i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates.begin(), candidates.end(), target);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}