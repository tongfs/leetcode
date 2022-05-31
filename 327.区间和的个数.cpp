/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int lower, upper;
    vector<long> sum, t;

    int countRangeSum(vector<int>& nums, int _lower, int _upper) {
        int n = nums.size();
        lower = _lower, upper = _upper;
        sum = t = vector<long>(n + 1);
        for (int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + nums[i - 1];
        return merge_sort(0, n);
    }

    int merge_sort(int l, int r) {
        if (l == r) return 0;

        int mid = l + r >> 1;
        int res = merge_sort(l, mid) + merge_sort(mid + 1, r);

        for (int i = l, st = mid + 1, ed = mid + 1; i <= mid; i ++ ) {
            while (st <= r && sum[st] - sum[i] < lower) st ++ ;
            while (ed <= r && sum[ed] - sum[i] <= upper) ed ++ ;
            res += ed - st;
        }

        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r)
            if (sum[i] <= sum[j]) t[k ++ ] = sum[i ++ ];
            else t[k ++ ] = sum[j ++ ];
        
        while (i <= mid) t[k ++ ] = sum[i ++ ];
        while (j <= r) t[k ++ ] = sum[j ++ ];

        for (int i = l, j = 0; i <= r; i ++ , j ++ ) sum[i] = t[j];

        return res;
    }
};
// @lc code=end

