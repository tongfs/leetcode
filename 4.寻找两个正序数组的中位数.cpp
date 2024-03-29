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
        int l = find(nums1, 0, nums2, 0, tot / 2);
        int r = find(nums1, 0, nums2, 0, tot / 2 + 1);
        return (l + r) / 2.0;
    }

    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j)
            return find(nums2, j, nums1, i, k);

        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);

        int si = min(i + k / 2 - 1, int(nums1.size()) - 1), sj = j + k - k / 2 - 1;
        if (nums1[si] > nums2[sj])
            return find(nums1, i, nums2, sj + 1, k / 2);
        return find(nums1, si + 1, nums2, j, k - (si + 1 - i));
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

