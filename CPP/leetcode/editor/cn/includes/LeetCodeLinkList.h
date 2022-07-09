//
// Created by NADPH on 2021/9/18.
//

#ifndef LEETCODE_LEETCODELINKLIST_H
#define LEETCODE_LEETCODELINKLIST_H

#endif //LEETCODE_LEETCODELINKLIST_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    std::vector<int> toVec();
};

std::vector<int> ListNode::toVec() {
    std::vector<int> res;
    ListNode *cur = this;
    while (cur != nullptr) {
        res.push_back(cur->val);
        cur = cur->next;
    }
    return res;
}

class LinkList{
public:
    ListNode *head;

    LinkList():head(nullptr) {}
    LinkList(const std::vector<int> &nums);
    ~LinkList();
};

LinkList::LinkList(const std::vector<int> &nums) {
    auto tummy_head = ListNode(0);
    auto cur = &tummy_head;
    for (auto const &i : nums) {
        auto new_node = new ListNode(i);
        cur->next = new_node;
        cur = cur->next;
    }
    head = tummy_head.next;
}

LinkList::~LinkList() {
    while (head->next != nullptr) {
        auto next = head->next;
        head->next = nullptr;
        delete head;
        head = next;
    }
    delete head;
}