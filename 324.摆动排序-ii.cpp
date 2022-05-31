/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // 找到中位数
        auto mid_ptr = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr;

        // 建立映射
        #define A(i) nums[(i * 2 + 1) % (n | 1)]

        // 三路归并
        for (int i = 0, j = 0, k = n - 1; j <= k; )
            if (A(j) > mid) swap(A(i ++ ), A(j ++ ));
            else if (A(j) < mid) swap(A(j), A(k -- ));
            else j ++ ;
    }
};
// @lc code=end

