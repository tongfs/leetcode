/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=21910
 *
 * [6] N 字形变换
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int d = numRows * 2 - 2;
        string res;
        for (int i = 0; i < numRows; i++) {
            if (!i || i == numRows - 1) {
                for (int j = i; j < s.size(); j += d)
                    res += s[j];
            } else {
                for (int j = i, k = d - i; j < s.size(); j += d, k += d) {
                    res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

