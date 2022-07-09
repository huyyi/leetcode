//
// Created by NADPH on 2022/3/5.
//
// 换三张


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n;

int main() {
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    // 最长上升子序列变种，贪心
    vector<int> d;
    d.push_back(nums[0]);
    for(int i = 1; i < n; ++i) {
        if (nums[i] - d.back() > 1) d.push_back(nums[i]);
        else {
            int pos = lower_bound(d.begin(), d.end(), nums[i]) - d.begin();
            if (pos == 0 || nums[i] - d[pos - 1] > 1) d[pos] = nums[i];
        }
    }
    cout << d.size() << endl;
}