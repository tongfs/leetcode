/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys(1, 1);
        for (int i = 0, j = 0, k = 0; uglys.size() < n; ) {
            int t = min(uglys[i] * 2, min(uglys[j] * 3, uglys[k] * 5));
            uglys.push_back(t);
            if (t == uglys[i] * 2) i ++ ;
            if (t == uglys[j] * 3) j ++ ;
            if (t == uglys[k] * 5) k ++ ;
        }
        return uglys[n - 1];
    }
};
// @lc code=end

