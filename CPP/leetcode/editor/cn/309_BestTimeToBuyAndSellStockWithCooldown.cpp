//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 数组 动态规划 👍 939 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 持有状态还是只有一个
    // 未持有的状态是包含冷冻期这个状态的，注意：虽然题目说冷冻期为1天，但是在卖出的当天也不能买入
    // 因此有三个状态：1、持有股票 2、未持有，在冷冻期内 3、未持有，非冷冻期
    // 持有股票有两个来源：1->1: 继续持有；3->1：在非冷冻期买入股票
    // 在冷冻期内：1、今天卖出 2、昨天卖出
    // 非冷冻期：从冷冻期转入
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];  // 持有状态
        int not_freeze = 0;  // 未持有状态，昨天卖出
        int freeze = 0;

        for (int i = 1; i < prices.size(); i ++) {
            int new_hold = max(hold, not_freeze - prices[i]);
            int new_not_freeze = freeze;
            int new_freeze = max(hold + prices[i], freeze);
            hold = new_hold;
            not_freeze = new_not_freeze;
            freeze = new_freeze;
        }
        return freeze;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}