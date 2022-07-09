//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学 二分查找 👍 184 👎 0


#include "includes/heads.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(int n) {
        int k = 9, m = 1;
        while (n / m > k) {
            n -= m * k;
            k *= 10;
            m++;
        }
        int num = n / m + (k / 9) - 1;
        int r = n % m;
        if (!r) return num % 10;
        num ++;
        int res = 0;
        for (int j = 0; j < m - r; j ++) {
            num /= 10;
        }
        res = num % 10;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> test{};
    cout << s.findNthDigit(11) << endl;
}