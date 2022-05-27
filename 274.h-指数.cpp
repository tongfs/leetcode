/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = citations.size(); i; i -- )
            if (citations[i - 1] >= i)
                return i;
        return 0;
    }
};
// @lc code=end

