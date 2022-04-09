/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1, j = m - 1, k = n - 1;
        while (j >= 0 && k >= 0)
            if (nums1[j] <= nums2[k]) nums1[i -- ] = nums2[k -- ];
            else nums1[i -- ] = nums1[j --];

        while (k >= 0) nums1[i -- ] = nums2[k -- ];
    }
};
// @lc code=end

