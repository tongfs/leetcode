/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    // 这道题可以用归并来做，但是时间复杂度会达到 O(n + m)
    // 用二分可以让时间复杂度为 O(log(n + m))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) return find(nums1, 0, nums2, 0, tot / 2 + 1);
        int l = find(nums1, 0, nums2, 0, tot / 2);
        int r = find(nums1, 0, nums2, 0, tot / 2 + 1);
        return (l + r) / 2.0;
    }

    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j)
            return find(nums2, j, nums1, i, k);

        // 边界处理
        // 1. 如果第一个数组为空，直接返回第二个数组的第 k 大数
        if (i == nums1.size()) return nums2[j + k - 1];

        // 2. 如果要找第一个数，则返回两个数组第一个数的最小值
        if (k == 1) return min(nums1[i], nums2[j]);

        int p = min((int)nums1.size(), i + k / 2), q = j + k - k / 2;
        if (nums1[p - 1] > nums2[q - 1])
            return find(nums1, i, nums2, q, k / 2);
        else 
            return find(nums1, p, nums2, j, k - (p - i));
    }
};
// @lc code=end

