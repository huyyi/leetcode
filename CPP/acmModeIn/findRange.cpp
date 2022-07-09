#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int x = nums[(l + r) >> 1];
    int i = l;
    int j = r;

    while(i < j) {
        while (nums[i] < x) i++;
        while (nums[j] > x) j--;
        if (i < j) swap(nums[i], nums[j]);
    }
    quickSort(nums, l, j);
    quickSort(nums, j + 1, r);
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    while(n--) {
        cin >> nums[n];
    }

    quickSort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i ++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}