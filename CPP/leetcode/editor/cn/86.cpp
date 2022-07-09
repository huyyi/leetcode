//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。 
//
// 你应当 保留 两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [2,1], x = 2
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 200] 内 
// -100 <= Node.val <= 100 
// -200 <= x <= 200 
// 
// Related Topics 链表 双指针 👍 525 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode dummy(INT_MIN, head);
        ListNode *gh = &dummy, *prev = nullptr;

        // 找第一个大于等于x的节点
        while (gh && gh->val < x) {
            prev = gh;
            gh = gh->next;
        }

        if (!gh) return head;
        ListNode *cur = gh;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *next = cur->next->next;

                cur->next->next = gh;
                prev->next = cur->next;
                prev = prev->next;
                cur->next = next;
            } else {
                cur = cur->next;
            }
            if (!cur) break;
        }
        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{1,4,3,0,2,5,2};
    LinkList t(test);
    cout << s.partition(t.head, 3)->toVec() << endl;
}