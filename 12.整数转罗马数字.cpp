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
        string chars[] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                          "XC", "C",  "CD", "D",  "CM", "M"};
        int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        string res;
        for (int i = 12; i >= 0; i--) {
            while (num >= values[i]) {
                res += chars[i];
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

