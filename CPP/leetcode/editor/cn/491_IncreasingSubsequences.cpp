//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。 
//
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,4,3,2,1]
//输出：[[4,4]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
// Related Topics 位运算 数组 哈希表 回溯 👍 349 👎 0


#include "includes/heads.h"
#include <unordered_set>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res{};
    vector<int> path{};
    unordered_set<int> used{};


    void backtrack(const vector<int> &nums, int start) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        for (int i = start; i < nums.size(); i ++) {
            if ((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end()) {
                continue;
            }
            path.push_back(nums[i]);
            used.insert(nums[i]);
            backtrack(nums, i + 1);
            used.erase(nums[i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{4, 6, 7, 7};
    s.findSubsequences(test);
}