//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 栈 递归 链表 双指针 👍 190 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int length = 0;
        auto cur = head;
        while (cur != nullptr) {
            length ++;
            cur = cur->next;
        }
        vector<int> res(length, 0);
        cur = head;
        while (cur != nullptr) {
            length --;
            res[length] = cur->val;
            cur = cur->next;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    LinkList test_case(vector<int>{1, 3, 2});
    cout << s.reversePrint(test_case.head) << endl;
}