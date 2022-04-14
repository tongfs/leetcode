/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            while (i < j && !check(s[i])) i ++ ;
            while (i < j && !check(s[j])) j -- ;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }

    bool check(char c) {
        return isdigit(c) || isalpha(c);
    }
};
// @lc code=end

