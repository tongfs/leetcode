/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=21910
 *
 * [8] 字符串转换整数 (atoi)
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        while (k < s.size() && s[k] == ' ') k++;

        int sign = 1;
        if (s[k] == '-') sign = -1, k++;
        else if (s[k] == '+') k++;

        int res = 0;
        while (k < s.size() && isdigit(s[k])) {
            int u = s[k] - '0';
            if (res > (INT_MAX - u) / 10)
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            res = res * 10 + u;
            k++;
        }
        return res * sign;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// "   -42"\n
// @lcpr case=end

// @lcpr case=start
// "4193 with words"\n
// @lcpr case=end

 */

