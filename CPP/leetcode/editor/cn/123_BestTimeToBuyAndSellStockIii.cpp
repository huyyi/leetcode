//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入：prices = [3,3,5,0,0,3,1,4]
//输出：6
//解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。 
//
// 示例 2： 
//
// 
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3： 
//
// 
//输入：prices = [7,6,4,3,1] 
//输出：0 
//解释：在这个情况下, 没有交易完成, 所以最大利润为 0。 
//
// 示例 4： 
//
// 
//输入：prices = [1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 10⁵ 
// 0 <= prices[i] <= 10⁵ 
// 
// Related Topics 数组 动态规划 👍 910 👎 0

#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划：使用4个状态：第一次买入、第一次卖出、第二次买入、第二次卖出
    int maxProfit(vector<int>& prices) {
        // dp[2]第二次买入初始化为-price[0]意为在第一天买入又卖出再买入（无冷却期）
        array<int, 4> dp{-prices[0], 0, -prices[0], 0};
        for (int i = 1; i < prices.size(); i ++) {
            int buy1 = max(dp[0], - prices[i]);  // 1、前一天已持有，继续持有dp[i-1][0] 2、前一天未持有新买入-price[i] 注意：这是第一次买入，如果写成dp[i-1][1] - price[i]就表示是第二次买入了会导致WA
            int sell1 = max(dp[0] + prices[i], dp[1]);  // 1、前一天持有，今天卖出dp[i-1][0]+price[i] 2、前一天未持有，保持dp[i-1][1]
            int buy2 = max(dp[1] - prices[i], dp[2]);  // 1、前一天已卖出，今天买入 dp[i-1][1] - price[i] 2、前一天已第二次持有dp[i-1][2]
            int sell2 = max(dp[2] + prices[i], dp[3]);  // 1、二次持有卖出dp[i-1][2]+price[i] 2、保持dp[i-1][3]
            dp = {buy1, sell1, buy2, sell2};
        }
        return max(dp[1], dp[3]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{3,3,5,0,0,3,1,4};
    cout << s.maxProfit(test) << endl;
}