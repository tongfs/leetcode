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
        int n = s.size();
        string res;

        for (int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
            if (r - l - 1 > res.size())
                res = s.substr(l + 1, r - l - 1);
        }

        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
            if (r - l - 1 > res.size())
                res = s.substr(l + 1, r - l - 1);
        }

        return res;
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
