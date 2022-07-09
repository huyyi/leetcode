//给定一个单链表 L 的头节点 head ，单链表 L 表示为： 
//
// 
//L0 → L1 → … → Ln - 1 → Ln
// 
//
// 请将其重新排列后变为： 
//
// 
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → … 
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：head = [1,2,3,4]
//输出：[1,4,2,3] 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5]
//输出：[1,5,2,4,3] 
//
// 
//
// 提示： 
//
// 
// 链表的长度范围为 [1, 5 * 10⁴] 
// 1 <= node.val <= 1000 
// 
// Related Topics 栈 递归 链表 双指针 👍 787 👎 0


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
    void reorderList(ListNode* head) {
        // p2停在中点点前一个
        ListNode *p1 = head, *p2 = head;
        while (p1 && p1->next) {
            p1 = p1->next->next;
            p2 = p2->next;
        }

        p1 = p2->next;
        p2->next = nullptr;

        ListNode *prev = nullptr, *cur = p1;
        while (cur) {
            if (cur->next == nullptr) p1 = cur;
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        cur = head;
        while (cur && p1) {
            ListNode *next = cur->next;
            cur->next = p1;
            p1 = p1->next;
            cur->next->next = next;
            cur = next;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{1};
    LinkList t(test);
    s.reorderList(t.head);
    cout << t.head->toVec() << endl;
}