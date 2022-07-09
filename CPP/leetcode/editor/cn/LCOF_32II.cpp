//
// Created by NADPH on 2021/12/9.
//

#include "includes/heads.h"
using namespace std;

class Solution {
    TreeNode *q[1010];
    int tt;
    int hh;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        memset(q, 0, sizeof q);
        tt = -1, hh = 0;
        if (root) q[++tt] = root;
        vector<vector<int>> res;
        int layer = tt - hh + 1;
        int next_layer = 0;
        vector<int> l;
        while (hh <= tt) {
            while (layer --) {
                if (q[hh] -> left) {
                    q[++tt] = q[hh]->left;
                    next_layer ++;
                }
                if (q[hh] -> right) {
                    q[++tt] = q[hh] -> right;
                    next_layer ++;
                }
                l.push_back(q[hh]->val);
                hh++;
            }
            layer = next_layer;
            next_layer = 0;
            res.emplace_back(l);
            l.clear();
        }
        return res;
    }
};