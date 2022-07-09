//给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。 
//
//
// 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。 
//
//
// 
// 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。 
// 
//
// 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。 
//
// 
//
// 示例 1： 
//
// 
//输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//输出：["JFK","MUC","LHR","SFO","SJC"]
// 
//
// 示例 2： 
//
// 
//输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL",
//"SFO"]]
//输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
//解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= tickets.length <= 300 
// tickets[i].length == 2 
// fromi.length == 3 
// toi.length == 3 
// fromi 和 toi 由大写英文字母组成 
// fromi != toi 
// 
// Related Topics 深度优先搜索 图 欧拉回路 👍 462 👎 0


#include "includes/heads.h"
#include <unordered_set>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> res{};
    vector<string> path{};

    bool DFS(const vector<vector<string>>& tickets, vector<bool>& visited, int used) {
        if (used == tickets.size()) {
            res = path;
            return true;
        }
        if (path.empty()) {
            path.emplace_back("JFK");
        }
        for (int i = 0; i < tickets.size(); i ++) {
            if (!path.empty() && tickets[i][0] == path.back()) {
                if (visited[i]) {
                    continue;
                }
                path.push_back(tickets[i][1]);
                visited[i] = true;
                if (DFS(tickets, visited, used + 1)) {
                    return true;
                }
                visited[i] = false;
                path.pop_back();
            }
        }
        return false;
    }

    static bool comparatorLess(const vector<string>& v1, const vector<string>& v2) {
        return v1[1] < v2[1];
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        sort(tickets.begin(), tickets.end(), comparatorLess);
        DFS(tickets, used, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<string>> test{{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    s.findItinerary(test);
}