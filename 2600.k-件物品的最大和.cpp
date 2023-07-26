/*
 * @lc app=leetcode.cn id=2600 lang=cpp
 * @lcpr version=21910
 *
 * [2600] K 件物品的最大和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) return k;
        if (k <= numOnes + numZeros) return numOnes;
        return numOnes - (k - numOnes - numZeros);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n0\n4\n
// @lcpr case=end

 */

