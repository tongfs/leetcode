/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 * @lcpr version=21910
 *
 * [1281] 整数的各位积和之差
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n) {
            int t = n % 10;
            product *= t;
            sum += t;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 234\n
// @lcpr case=end

// @lcpr case=start
// 4421\n
// @lcpr case=end

 */

