/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (int i = 0; i < columnTitle.size(); i ++ )
            res = res * 26 - 'A' + columnTitle[i] + 1;
        return res;
    }
};
// @lc code=end

