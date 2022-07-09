//
// Created by NADPH on 2021/12/9.
//
#include "includes/heads.h"
using namespace std;

class Solution {
    static TreeNode *q[1000];
    static int tt;
    static int hh;
public:
    vector<int> levelOrder(TreeNode* root) {
        memset(q, 0, sizeof q);
        tt = -1, hh = 0;
        q[++tt] = root;
        vector<int> res;
        while (hh <= tt) {
            if (q[hh] -> left) q[++tt] = q[hh]->left;
            if (q[hh] -> right) q[++tt] = q[hh] -> right;
            res.push_back(q[hh]->val);
            hh++;
        }
        return res;
    }
};