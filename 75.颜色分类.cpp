/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums);
    }

    // 解法一：计数排序
    void count_sort(vector<int>& nums) {
        int hash[3] = {};
        for (auto num : nums) hash[num] ++ ;
        for (int i = 0, k = 0; i < 3; i ++ )
            while (hash[i] -- )
                nums[k ++ ] = i;
    }

    // 解法二：三路快排
    void quick_sort(vector<int>& a) {
        for (int i = 0, j = 0, k = a.size() - 1; i <= k; ) {
            if (!a[i]) swap(a[i ++ ], a[j ++ ]);
            else if (a[i] == 2) swap(a[i], a[k -- ]);
            else i ++ ;
        }
    }
};
// @lc code=end

