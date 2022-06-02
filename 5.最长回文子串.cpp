/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res;

        for (int i = 0; i < s.size(); i ++ ) {
            // odd
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++ ;
            if (r - l - 1 > res.size()) res = s.substr(l + 1, r - l - 1);

            // even
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++ ;
            if (r - l - 1 > res.size()) res = s.substr(l + 1, r - l - 1);
        }

        return res;
    }
};
// @lc code=end

