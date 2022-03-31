/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /* 解法一：将两个数组合并后直接求中位数 */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> nums;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j]) nums.push_back(nums1[i ++ ]);
            else nums.push_back(nums2[j ++ ]);
        }

        while (i < nums1.size()) nums.push_back(nums1[i ++ ]);
        while (j < nums2.size()) nums.push_back(nums2[j ++ ]);
        
        int n = nums.size();
        if (n % 2) return nums[n / 2];
        else return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
    }

    /* 解法二：通过递归，每次减少一半的数据量 */
    /* double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) {
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
        } else {
            int l = find(nums1, 0, nums2, 0, tot / 2);
            int r = find(nums1, 0, nums2, 0, tot / 2 + 1);
            return (l + r) / 2.0;
        }
    }

    //在两个正序数组中找到第 k 大的数
    int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j)
            return find(nums2, j, nums1, i, k);

        // 边界处理：
        // 1. 如果第一个数组是空的，则直接返回第二个数组的第 k 个数
        if (nums1.size() == i) return nums2[j + k - 1];

        // 2. 如果要找第一个数，则返回两个数组第一个数的最小值
        if (k == 1) return min(nums1[i], nums2[j]);

        // 由于 nums1 比较短，所以可能会越界
        int si = min((int)nums1.size(), i + k / 2), sj = j + k - k / 2;
        if (nums1[si - 1] > nums2[sj - 1]) {
            return find(nums1, i, nums2, sj, k - (sj - j));
        } else {
            return find(nums1, si, nums2, j, k - (si - i));
        }
    } */
};
// @lc code=end

