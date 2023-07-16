/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 * @lcpr version=21910
 *
 * [2178] 拆分成最多数目的正偶数之和
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum & 1) return res;

        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 28\n
// @lcpr case=end

 */
