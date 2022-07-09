/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include "includes/heads.h"
using namespace std;
// @lc code=start
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(0, head);
        ListNode *cur = &dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *n1 = cur->next;
            ListNode *n2 = n1->next;

            cur->next = n2;
            n1->next = n2->next;
            n2->next = n1;

            cur = cur->next->next;
        }
        return dummy.next;
    }
};
// @lc code=end

