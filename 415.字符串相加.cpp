/*
 * @lc app=leetcode.cn id=415 lang=cpp
 * @lcpr version=21910
 *
 * [415] 字符串相加
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res;
        int n = num1.size(), m = num2.size();
        for (int i = 0, t = 0; i < n || i < m || t; i++) {
            if (i < n) t += num1[i] - '0';
            if (i < m) t += num2[i] - '0';
            res += t % 10 + '0';
            t /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"123"\n
// @lcpr case=end

// @lcpr case=start
// "456"\n"77"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n"0"\n
// @lcpr case=end

 */

