//给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。 
//
// 每一步，你可以从下标 i 跳到下标： 
//
// 
// i + 1 满足：i + 1 < arr.length 
// i - 1 满足：i - 1 >= 0 
// j 满足：arr[i] == arr[j] 且 i != j 
// 
//
// 请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。 
//
// 注意：任何时候你都不能跳到数组外面。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
//输出：3
//解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
// 
//
// 示例 2： 
//
// 输入：arr = [7]
//输出：0
//解释：一开始就在最后一个元素处，所以你不需要跳跃。
// 
//
// 示例 3： 
//
// 输入：arr = [7,6,9,6,9,6,9,7]
//输出：1
//解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
// 
//
// 示例 4： 
//
// 输入：arr = [6,1,9]
//输出：2
// 
//
// 示例 5： 
//
// 输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 5 * 10^4 
// -10^8 <= arr[i] <= 10^8 
// 
// Related Topics 广度优先搜索 数组 哈希表 👍 152 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    queue<int> q;
    unordered_map<int, vector<int>> map;
    vector<bool> st;
    vector<int> dist;
public:
    int minJumps(vector<int>& arr) {
        st = vector<bool>(arr.size() + 1, false);
        st[0] = true;
        dist = vector<int>(arr.size() + 1, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (!map[arr[i]].empty() && map[arr[i]].back() + 1 == i && map[arr[i]].back() - 1 >= 0 && arr[map[arr[i]].back() - 1] == arr[i]) map[arr[i]].pop_back();
            map[arr[i]].push_back(i);
        }

        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            int v = arr[t];
            q.pop();

            for (auto it = map[arr[t]].begin(); it != map[arr[t]].end(); it ++) {
                int j = *it;
                if (!st[j]) {
                    st[j] = true;
                    dist[j] = min(dist[j], dist[t] + 1);
                    if (j == arr.size() - 1) return dist[j];
                    q.push(j);
                }
            }
            map.erase(arr[t]);

            if (t - 1 > 0 && !st[t - 1]) {
                st[t - 1] = true;
                dist[t - 1] = min(dist[t - 1], dist[t] + 1);
                q.push(t - 1);
            }

            if (t + 1 < arr.size() && !st[t + 1]) {
                st[t + 1] = true;
                dist[t + 1] = min(dist[t + 1], dist[t] + 1);
                if (t + 1 == arr.size() - 1) return dist[t + 1];
                q.push(t + 1);
            }
        }
        return dist[arr.size() - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{100,-23,-23,404,100,23,23,23,3,404};
    cout << s.minJumps(test) << endl;
}