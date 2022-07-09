/**
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。 

 

 示例 1： 

 
输入：head = [1,2,2,1]
输出：true
 

 示例 2： 

 
输入：head = [1,2]
输出：false
 

 

 提示： 

 
 链表中节点数目在范围[1, 10⁵] 内 
 0 <= Node.val <= 9 
 

 

 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
 Related Topics 栈 递归 链表 双指针 👍 1124 👎 0

*/

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
    static bool isPalindrome(ListNode* head) {
        // 快慢指针找中点
        auto fast = head;
        auto slow = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // 反转后半
        auto mid = slow -> next;
        fast = mid;
        slow = nullptr;
        while (fast != nullptr) {
            ListNode *next = fast->next;
            fast->next = slow;
            slow = fast;
            fast = next;
        }

        // 逐个比对
        fast = head;
        while (slow != nullptr && fast != nullptr) {
            if (fast -> val != slow -> val) {
                return false;
            }
            fast = fast -> next;
            slow = slow -> next;
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    auto nums = vector<int>{1, 2, 3, 1};
    auto list = FromArray(nums);
    cout << Solution::isPalindrome(list) << endl;
}