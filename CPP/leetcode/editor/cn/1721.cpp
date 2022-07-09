//给你链表的头节点 head 和一个整数 k 。 
//
// 交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
//输出：[7,9,6,6,8,7,3,0,9,5]
// 
//
// 示例 3： 
//
// 
//输入：head = [1], k = 1
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：head = [1,2], k = 1
//输出：[2,1]
// 
//
// 示例 5： 
//
// 
//输入：head = [1,2,3], k = 2
//输出：[1,2,3]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目是 n 
// 1 <= k <= n <= 10⁵ 
// 0 <= Node.val <= 100 
// 
// Related Topics 链表 双指针 👍 43 👎 0


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
    ListNode* swapNodes(ListNode* head, int k) {
        int idx = 0;
        ListNode dummy(-1, head);
        ListNode *s = &dummy, *f = &dummy;
        ListNode *xPre;
        while (f) {
            if (idx == k - 1) xPre = f;
            f = f->next;
            idx ++;
            if (idx > k + 1) s = s->next;
        }
        nodeSwap(xPre, s);
        return dummy.next;
    }

private:
    void nodeSwap(ListNode *xPre, ListNode *yPre) {
        if (!xPre || !yPre) return;
        ListNode *x = xPre->next, *y = yPre->next;
        if (!x || !y || x == y) return;
        if (x->next == y) {
            ListNode *next = y->next;
            xPre->next = y;
            y->next = x;
            x->next = next;
        } else if (y->next == x) {
            ListNode *next = x->next;
            yPre->next = x;
            x->next = y;
            y->next = next;
        } else {
            ListNode *xNext = x->next, *yNext = y->next;
            xPre->next = y;
            yPre->next = x;
            y->next = xNext;
            x->next = yNext;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{1};
    cout << s.swapNodes(LinkList(test).head, 1)->toVec() << endl;
}