/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21909
 *
 * [5] 最长回文子串
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st, len = 0;

        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n; l--, r++) {
                if (s[l] != s[r]) break;
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    st = l;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
                if (s[l] != s[r]) break;
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    st = l;
                }
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
