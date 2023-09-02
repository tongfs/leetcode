/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=21910
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) return find(nums1, 0, nums2, 0, tot / 2 + 1);
        int a = find(nums1, 0, nums2, 0, tot / 2);
        int b = find(nums1, 0, nums2, 0, tot / 2 + 1);
        return (a + b) / 2.0;
    }

    int find(vector<int>& nums1, int p, vector<int>& nums2, int q, int k) {
        if (nums1.size() - p > nums2.size() - q)
            return find(nums2, q, nums1, p, k);
        
        if (nums1.size() == p) return nums2[q + k - 1];
        if (k == 1) return min(nums1[p], nums2[q]);

        int i = min(p + k / 2 - 1, int(nums1.size() - 1)), j = q + k - k / 2 - 1;
        if (nums1[i] > nums2[j]) return find(nums1, p, nums2, j + 1, k / 2);
        return find(nums1, i + 1, nums2, q, k - (i - p + 1));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

