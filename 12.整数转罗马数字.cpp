/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string res;

        // 解法一：
        /* int nums[] = {1, 5, 10, 50, 100, 500, 1000};
        char chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        int cnt[7];
        for (int i = 6; i >= 0; i -- ) {
            cnt[i] = num / nums[i];
            num %= nums[i];
        }

        for (int i = 0; i < cnt[6]; i ++ ) res += chars[6];
        for (int i = 5; i > 0; i -= 2) {
            if (cnt[i - 1] == 4) {
                res += chars[i - 1];
                res += chars[i + cnt[i]];
            } else {
                for (int j = 0; j < cnt[i]; j ++ ) res += chars[i];
                for (int j = 0; j < cnt[i - 1]; j ++ ) res += chars[i - 1];
            }
        } */

        // 解法二：y总模拟
        int values[] = {
            1000,
            900, 500, 400, 100,
            90, 50, 40, 10,
            9, 5, 4, 1
        };

        string units[] = {
            "M",
            "CM", "D", "CD", "C",
            "XC", "L", "XL", "X",
            "IX", "V", "IV", "I"
        };

        for (int i = 0; i < 13; i ++ ) {
            while (num >= values[i]) {
                num -= values[i];
                res += units[i];
            }
        }

        return res;
    }
};
// @lc code=end

