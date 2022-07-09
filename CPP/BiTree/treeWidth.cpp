//
// Created by NADPH on 2021/9/23.
//

#include "../leetcode/editor/cn/includes/heads.h"
#include "list"

using namespace std;

int treeWidth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    list<TreeNode*> nodeQ;
    nodeQ.push_back(root);
    decltype(nodeQ.size()) maxNodes = 0;

    while (!nodeQ.empty()) {
        // 当前层节点数
        auto curNodes = nodeQ.size();
        maxNodes = max(curNodes, maxNodes);

        // 每出队列一个节点把其子节点加入队列
        for (int i = 0; i < curNodes; i ++ ) {
            auto cur = nodeQ.front();
            nodeQ.pop_front();
            if (cur -> left != nullptr) {
                nodeQ.push_back(cur->left);
            }
            if (cur->right != nullptr) {
                nodeQ.push_back(cur->right);
            }
        }
    }
    return int(maxNodes);
}

int main() {
    int nums[] = {1,3,2,5,3,'#',9};
    auto T = NewTree(nums, 0, 10);
    cout << treeWidth(T) << endl;
}