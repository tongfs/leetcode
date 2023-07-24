/*
 * @lc app=leetcode.cn id=面试题 01.01 lang=cpp
 * @lcpr version=21910
 *
 * [面试题 01.01] 判定字符是否唯一
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0;
        for (auto c : astr) {
            int u = c - 'a';
            if (mask & (1 << u)) return false;
            mask |= 1 << u;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

