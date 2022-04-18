/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    /* 
     * 相邻数字的最大间距不会小于⌈(Max-Min)/(N-1)⌉
     * 设每个区间的长度为x=⌈(Max-Min)/(N-1)⌉，则区间内的最大间距为x-1，且满足最大间距不出现在区间内部
     */

    struct Seg {
        int min, max;
        bool used;
        Seg(): min(INT_MAX), max(INT_MIN), used(false) {}
    };

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int Min = INT_MAX, Max = INT_MIN;
        for (auto x: nums) Min = min(Min, x), Max = max(Max, x);
        
        if (n < 2 || Min == Max) return 0;

        vector<Seg> segs(n);
        int len = (Max - Min + n - 2) / (n - 1);

        for (auto x: nums) {
            int k = (x - Min) / len;
            segs[k].max = max(segs[k].max, x);
            segs[k].min = min(segs[k].min, x);
            segs[k].used = true;
        }

        int res = 0;
        for (int i = 0, last_max = Min; i < n; i ++ ) {
            auto t = segs[i];
            if (t.used) {
                res = max(res, t.min - last_max);
                last_max = t.max;
            }
        }

        return res;
    }
};
// @lc code=end

