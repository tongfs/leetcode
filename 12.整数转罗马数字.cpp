/*
 * @lc app=leetcode.cn id=12 lang=cpp
 * @lcpr version=21910
 *
 * [12] 整数转罗马数字
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string units[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string res;
        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                res += units[i];
                num -= values[i];
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 58\n
// @lcpr case=end

// @lcpr case=start
// 1994\n
// @lcpr case=end

 */
