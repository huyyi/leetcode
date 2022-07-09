//
// Created by Jinkin Huang on 2022/3/4.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;

int main() {
    cin >> n >> t;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        nums[i] = i;
    }

    while (t) {
        next_permutation(nums.begin() + 1, nums.end());
        int i = 1;
        while (i <= n && nums[i] != i) i++;
        if (i > n) {
            for (int m = 1; m <= n; m ++) cout << nums[m] << ' ';
            cout << endl;
            t--;
        }
    }
    return 0;
}