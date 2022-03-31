/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int k = 0;

        // 先去掉前导空格
        while (k < s.size() && s[k] == ' ') k ++ ;
        if (k == s.size()) return 0;

        // 确定正负号
        int sign = 1;
        if (s[k] == '-') sign = -1, k ++ ;
        else if (s[k] == '+') k ++ ;

        // 解法一：用 long long
        /* long long res = 0;
        while (k < s.size() && isdigit(s[k])) {
            res = res * 10 + s[k] - '0';
            k ++ ;
            if (res > INT_MAX) break;
        }

        res *= sign;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN; */

        // 解法二：不用 long long
        int res = 0;
        while (k < s.size() && isdigit(s[k])) {
            int x = s[k] - '0';
            if (res > (INT_MAX - x) / 10) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            };

            res = res * 10 + x;
            k ++ ;
        }

        res *= sign;
        return res;
    }
};
// @lc code=end

