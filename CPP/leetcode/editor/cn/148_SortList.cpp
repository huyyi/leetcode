//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 进阶： 
//
// 
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
// Related Topics 链表 双指针 分治 排序 归并排序 👍 1406 👎 0


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
private:
    ListNode* merge(ListNode *p1, ListNode *p2) {
        auto h = new ListNode(-1);
        auto cur = h;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if (p1) {
            cur->next = p1;
        }
        if (p2) {
            cur->next = p2;
        }
        return h->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int length = 0;
        auto cur = head;
        while (cur) {
            cur = cur->next;
            length ++;
        }

        auto dummy = new ListNode(-1, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            auto prev = dummy, cur = dummy->next;
            while (cur) {
                auto h1 = cur;
                for (int i = 1; i < subLength && cur->next; i++) {
                    cur = cur->next;
                }
                auto h2 = cur->next;
                cur->next = nullptr;
                cur = h2;
                for (int i = 1; i < subLength && cur && cur->next; i++) {
                    cur = cur->next;
                }
                ListNode *next = nullptr;
                if (cur) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                auto merged = merge(h1, h2);
                prev->next = merged;
                while (prev->next) {
                    prev = prev->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s. << endl;
}