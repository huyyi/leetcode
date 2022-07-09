//
// Created by NADPH on 2021/12/9.
//

#include "includes/heads.h"
using namespace std;


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int z = nums[0];
        for (int i = 1; i < nums.size(); i++) z ^= nums[i];

        int k = 0;
        while (!(z >> k & 1)) k ++;

        int a = 0;
        for (int x : nums) {
            if (x >> k & 1) a ^= x;
        }
        return {a, z ^ a};
    }
};

int main() {
    Solution s;
    vector<int> test{4, 1, 4, 6};
    cout << s.singleNumbers(test) << endl;
}