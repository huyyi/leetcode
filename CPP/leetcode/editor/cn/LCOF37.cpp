//
// Created by NADPH on 2021/12/9.
//

// 节点数 <= 1e5 节点值 <= +-1000
#include "includes/heads.h"
using namespace std;
class Codec {
    string s;
    int idx = 0;
public:
    // 按先序遍历序列化为字符串，空格分隔，空节点用#表示
    string serialize(TreeNode* root) {
        dfs(root);
        return s;
    }

    void dfs(TreeNode *root) {
        if (!root) {
            s.append("# ");
        }
        else {
            s.append(to_string(root->val));
            s.append(" ");
            dfs(root->left);
            dfs(root->right);
        }

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
        return rebuile(data);
    }

    TreeNode* rebuile(const string &data) {
        if (data.size() && data[idx] == ' ') idx ++;
        if (idx >= data.size() || data[idx] == '#') {
            idx ++;
            return nullptr;
        }
        int val = 0;
        bool m = false;
        if (data[idx] == '-') {
            m = true;
            idx ++;
        }
        while (data[idx] != ' ') {
            val *= 10;
            val += (data[idx++] - '0');
        }
        if (m) val = -val;
        auto root = new TreeNode(val);
        root->left = rebuile(data);
        root->right = rebuile(data);
        return root;
    }
};

int main() {
    Codec c;
    int test[]{0, 0, 0, 0, '#', '#', 1, '#', '#', '#', 2};
    auto tree = NewTree(test, 0, 10);
    string s = c.serialize(tree);
    cout << s << endl;
    auto re = c.deserialize(s);
    puts("!");
    return 0;
}