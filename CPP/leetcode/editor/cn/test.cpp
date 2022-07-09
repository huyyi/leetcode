//
// Created by NADPH on 2021/9/18.
//

#include "includes/heads.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() < 1 || matrix[0].size() < 1) return res;
        int n = matrix.size();
        int m = matrix[0].size();


        for (int i = 0, j = 0, k = 1; k <= (n + 1) >> 1; i++, j++, k ++) {

            while (j < m - k) {
                res.push_back(matrix[i][j++]);
            }
            while (i < n - k) {
                res.push_back(matrix[i++][j]);
            }
            while (j >= k) {
                res.push_back(matrix[i][j--]);
            }
            while (i >= k) {
                res.push_back(matrix[i--][j]);
            }
        }

        if (n % 2 == 1 && m % 2 == 1) {
            res.push_back(matrix[n / 2][m / 2]);
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> test{{1,2,3},{5,6,7},{9,10,11}};
    cout << s.spiralOrder(test) << endl;
}