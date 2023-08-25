/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21910
 *
 * [5] 最长回文子串
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st, len = 0;

        for (int i = 0; i < n; i++) {
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if (r - l + 1 > len)
                    st = l, len = r - l + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if (r - l + 1 > len)
                    st = l, len = r - l + 1;
            }
        }

        return s.substr(st, len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

