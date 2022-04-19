/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        auto t = ' ' + s + ' ' + string(s.rbegin(), s.rend());
        
        vector<int> ne(t.size());
        for (int i = 2, j = 0; i < t.size(); i ++ ) {
            while (j && t[i] != t[j + 1]) j = ne[j];
            if (t[i] == t[j + 1]) j ++ ;
            ne[i] = j;
        }

        int len = ne[t.size() - 1];
        auto right = s.substr(len);
        return string(right.rbegin(), right.rend()) + s;
    }
};
// @lc code=end

