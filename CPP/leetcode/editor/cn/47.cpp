//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 👍 933 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        process(nums);
        return res;
    }

    void process(vector<int>& nums) {
        if (path.size() == nums.size()) res.emplace_back(path);
        else {
            for (int i = 0; i < used.size(); ++i) {
                if (!used[i]) {
                    if (i > 0 && !used[i - 1] && nums[i] == nums[i - 1]) continue;
                    path.push_back(nums[i]);
                    used[i] = true;
                    process(nums);
                    used[i] = false;
                    path.pop_back();
                }
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