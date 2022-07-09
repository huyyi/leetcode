//有 n 个网络节点，标记为 1 到 n。 
//
// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， 
//wi 是一个信号从源节点传递到目标节点的时间。 
//
// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 1
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 2
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= n <= 100 
// 1 <= times.length <= 6000 
// times[i].length == 3 
// 1 <= ui, vi <= n 
// ui != vi 
// 0 <= wi <= 100 
// 所有 (ui, vi) 对都 互不相同（即，不含重复边） 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 最短路 堆（优先队列） 👍 460 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    const static int INC = 0x3f3f3f3f;
    vector<vector<int>> g;
    vector<int> dist;
    vector<bool> st;
    int n, k;

    int dijkstra() {
        dist = vector<int>(n + 1, INC);
        st = vector<bool>(n + 1, false);
        dist[k] = 0;
        for (int i = 0; i < n-1; ++i) {
            int t = -1;
            for (int j = 1; j <= n; j ++) {
                if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
            }
            st[t] = true;

            for (int j = 1; j <= n; j ++) 
                dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res >= INC / 2 ? -1 : res;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int _n, int _k) {
        n = _n, k = _k;
        g = vector<vector<int>>(n + 1, vector<int>(n+1, INC));
        for (const auto &t : times) {
            int a = t[0], b = t[1], c = t[2];
            g[a][b] = min(g[a][b], c);
        }
        return dijkstra();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> test{{2,1,1},{2,3,1},{3,4,1}};
    cout << s.networkDelayTime(test, 4, 2) << endl;
}