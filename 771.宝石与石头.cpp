/*
 * @lc app=leetcode.cn id=771 lang=cpp
 * @lcpr version=21910
 *
 * [771] 宝石与石头
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for (auto c : jewels) mask |= 1LL << (c & 63);
        int res = 0;
        for (auto c : stones) res += mask >> (c & 63) & 1;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aA"\n"aAAbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "z"\n"ZZ"\n
// @lcpr case=end

 */

