/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 解法一：用 long long
        /* long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX) return 0;
        if (res < INT_MIN) return 0;
        return res; */

        // 解法二：不用 long long
        int res = 0;
        while (x) {
            if (res > 0 && res > (INT_MAX - res % 10) / 10) return 0;
            if (res < 0 && res < (INT_MIN - res % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
// @lc code=end

