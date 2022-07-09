//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
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
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// Related Topics 链表 双指针 分治 排序 归并排序 👍 1457 👎 0


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
    ListNode* sortList(ListNode* head) {
//        return mergesort(head);
        return mergeTop(head, nullptr);
    }

private:
    ListNode* mergesort(ListNode *head) {
        ListNode dummy(-1, head), *tt;
        ListNode *cur = head;

        int len = 0;
        while (cur) {
            len ++;
            cur = cur->next;
        }

        for (int i = 1; i < len; i <<= 1) {
            cur = dummy.next, tt = &dummy;

            while (cur) {
                ListNode *l1 = cur;
                // 要断开连接，要停在l2前，走i-1步
                for (int j = 0; j < i - 1 && cur->next; ++j)
                    cur = cur->next;

                ListNode *l2 = cur->next;
                cur->next = nullptr;
                cur = l2;
                for (int j = 0; j < i - 1 && cur && cur->next; ++j)
                    cur = cur->next;

                ListNode *ne = nullptr;
                if (cur) {
                    ne = cur->next;
                    cur->next = nullptr;
                }

                ListNode *t = merge(l1, l2);
                tt->next = t;
                while (tt->next) {
                    tt = tt->next;
                }
                cur = ne;
            }
        }
        return dummy.next;
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode head(-1), *tt = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tt->next = l1;
                l1 = l1->next;
            } else {
                tt->next = l2;
                l2 = l2->next;
            }
            tt = tt->next;
        }
        if (l1) tt->next = l1;
        if (l2) tt->next = l2;
        return head.next;
    }

    ListNode* quicksort(ListNode *head, ListNode *end) {
        if (head == end || head->next == end) return head;
        ListNode *hh = head, *tt = head, *cur = head->next;

        // cur != end 左闭右开
        while (cur != end) {
            ListNode *ne = cur->next;
            if (cur->val < head->val) {
                cur->next = hh;
                hh = cur;
            } else {
                tt->next = cur;
                tt = cur;
            }
            cur = ne;
        }
        tt->next = end;
        ListNode *l = quicksort(hh, head);
        head->next = quicksort(head->next, end);
        // 为什么l是排序后链表的头？
        // l来自深度优先，每次都是划分后的右半，自然就是最小的元素
        return l;
    }

// 链表归并自顶向下
ListNode *mergeTop(ListNode *st, ListNode *ed) {
    if (st == ed) return st;
    if (st->next == ed) {
        st->next = nullptr;
        return st;
    }
    ListNode *mid = st, *f = st;
    while (f != ed) {
        f = f->next;
        mid = mid->next;
        if (f != ed) f = f->next;
    }
    ListNode *l = mergeTop(st, mid);
    ListNode *r = mergeTop(mid, ed);

    return merge(l, r);
}
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{-1,5,3,4,0};
    cout << s.sortList(LinkList(test).head)->toVec() << endl;
}