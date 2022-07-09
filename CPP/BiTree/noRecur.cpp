//
// Created by NADPH on 2021/9/23.
//
#include "../leetcode/editor/cn/includes/heads.h"
#include "queue"

using namespace std;

vector<int> PreOrder(TreeNode *root) {
    vector<TreeNode*> help;
    if (!root) {
        return vector<int>{};
    }
    help.push_back(root);
    TreeNode *cur;
    vector<int> res;
    while (!help.empty()) {
        cur = help.back();
        help.pop_back();
        if (cur->right) {
            help.push_back(cur->right);
        }
        if (cur->left) {
            help.push_back(cur->left);
        }
        res.push_back(cur->val);
    }
    return res;
}

vector<int> InOrder(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>{};
    }
    vector<TreeNode*> stack;
    vector<int> res;
    while (!stack.empty() || root != nullptr) {
        if (root != nullptr) {
            stack.push_back(root);
            root = root->left;
        } else {
            root = stack.back();
            res.push_back(root->val);
            stack.pop_back();
            root = root->right;
        }
    }
    return res;
}

vector<int> PosOrder(TreeNode *root) {
    vector<TreeNode*> help;
    if (!root) {
        return vector<int>{};
    }
    help.push_back(root);
    TreeNode *cur;
    vector<int> collect;
    while (!help.empty()) {
        cur = help.back();
        help.pop_back();
        // 先入左再入右
        if (cur->left) {
            help.push_back(cur->left);
        }
        if (cur->right) {
            help.push_back(cur->right);
        }
        collect.push_back(cur->val);
    }
    // collect出栈即为结果
    vector<int> res;
    while (!collect.empty()) {
        res.push_back(collect.back());
        collect.pop_back();
    }
    return res;
}

vector<int> LevelOrder(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>{};
    }
    queue<TreeNode*> nodeQ;
    nodeQ.push(root);
    vector<int> res;
    TreeNode *cur;
    while (!nodeQ.empty()) {
        cur = nodeQ.front();
        nodeQ.pop();
        res.push_back(cur->val);
        if (cur->left != nullptr) {
            nodeQ.push(cur->left);
        }
        if (cur->right != nullptr) {
            nodeQ.push(cur->right);
        }
    }
    return res;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto T = NewTree(nums, 0, 10);
    cout << PreOrder(T) << endl;
    cout << InOrder(T) << endl;
    cout << PosOrder(T) << endl;
    cout << LevelOrder(T) << endl;
}