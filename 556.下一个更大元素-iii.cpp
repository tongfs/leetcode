/*
 * @lc app=leetcode.cn id=556 lang=cpp
 * @lcpr version=21910
 *
 * [556] 下一个更大元素 III
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        int k = s.size() - 1;
        while (k && s[k - 1] >= s[k]) k--;
        if (!k) return -1;
        
        int t = s.size() - 1;
        while (s[k - 1] >= s[t]) t--;
        swap(s[k - 1], s[t]);
        reverse(s.begin() + k, s.end());

        auto res = stol(s);
        return res > INT_MAX ? -1 : res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 21\n
// @lcpr case=end

 */

