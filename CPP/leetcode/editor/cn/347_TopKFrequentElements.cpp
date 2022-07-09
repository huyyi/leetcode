//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 872 👎 0


#include "includes/heads.h"
#include <unordered_map>
#include <queue>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    class Cmper {
    public:
        bool operator() (const pair<int, int> &p1, const pair<int, int>&p2) {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计频率
        unordered_map<int, int> frqMap{};
        for (int num : nums) {
            frqMap[num] ++;
        }


        // 固定容量为K的小顶堆，较大的元素加入堆时较小的元素被推出堆，最后留在堆中的就是K个最大频率
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmper> Q;
        for (auto iter = frqMap.begin(); iter != frqMap.end(); iter ++) {
            Q.push(*iter);
            if(Q.size() > k) {
                Q.pop();
            }
        }
        vector<int> res{};
        for (int i = 0; i < k; i ++) {
            res.push_back(Q.top().first);
            Q.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}