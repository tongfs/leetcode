/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        // 解法一：转换成字符串
        /* string s = to_string(x);
        return s == string(s.rbegin(), s.rend()); */

        // 解法二：用数字
        int t = x, res = 0;
        while (t) {
            if (res > (INT_MAX - t % 10) / 10) return false;
            res = res * 10 + t % 10;
            t /= 10;
        }
        if (res == x) return true;
        return false;
    }
};
// @lc code=end

