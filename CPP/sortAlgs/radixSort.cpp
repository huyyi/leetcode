#include "vector"

using namespace std;

int getDigit(int num, int n) {
    auto res = 0;
    for (auto i = n; i > 1; i --) {
        num = num / 10;
    }
    res = num % 10;
    return res;
}

// return a sorted vector of nums[L...R) by radix sort
// digits is the max bit of the max val of nums
// For example:
//      nums = [16, 22, 34, 101]
//      the digits is 3 from max val 101
vector<int> radixSort(vector<int> &nums, int L, int R, int digits) {
    auto radix = 10;
    auto help = vector<int>(nums.size(), 0);
    for (auto d = 1; d <= digits; d ++) {
        auto count = vector<int>(10, 0);
        // 计数第d位上的个数
        for (auto i = L; i < R; i ++) {
            auto j = getDigit(nums[i], d);
            count[j] ++;
        }
        // 前缀和
        for (auto i = 1; i < radix; i ++) {
            count[i] = count[i - 1] + count[i];
        }
        // 基于d位上的值排序
        for (auto i = nums.end() - 1; i != nums.begin() - 1; i --) {
            auto digit = getDigit((*i), d);
            auto j = count[digit];
            help[j - 1] = (*i);
            count[digit] --;
        }
        nums = help;
    }
    return help;
}



int calDigits(vector<int> &nums) {
    // find the max val
    auto maxVal = nums[0];
    for (auto i: nums) {
        maxVal = max(i, maxVal);
    }
    // cal the digits of the max val
    int res = 0;
    for (auto i = 1; maxVal / i != 0; i *= 10) {
        res++;
    }
    return res;
}


int main() {
    auto nums = vector<int>{12, 24, 26, 22, 34, 101};
    auto d = calDigits(nums);
    auto res = radixSort(nums, 0, 6, d);
}