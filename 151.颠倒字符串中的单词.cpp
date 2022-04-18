/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == ' ') continue;
            int j = k;
            while (i < s.size() && s[i] != ' ') s[k ++ ] = s[i ++ ];
            reverse(s.begin() + j, s.begin() + k);
            s[k ++ ] = ' ';
        }

        k -- ;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
};
// @lc code=end

