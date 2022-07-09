//
// Created by NADPH on 2021/12/9.
//

#include "includes/heads.h"
using namespace std;

class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.size() < 1) return res;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> st(n, vector<bool>(m, false));

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int x = 0, y = 0, d = 1;
    for (int k = 0; k < n * m; k ++) {
        res.push_back(matrix[x][y]);
        st[x][y] = true;

        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >=n || b < 0 || b >= m || st[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d];
            b = y + dy[d];
        }
        x = a, y = b;
    }

    return res;
}
};
int main() {
    Solution s;
    vector<vector<int>> test{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout << s.spiralOrder(test) << endl;
}