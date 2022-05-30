/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

#include "mylib.h"

// @lc code=start
/* 
 * 一般来说有两种做法
 *  1. 归并排序
 *  2. 树状数组（后面再补充）
 */
class Solution {
public:
    vector<int> idx, t, t_idx, res;

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        idx = t = t_idx = res = vector<int>(n);
        for (int i = 0; i < n; i ++ ) idx[i] = i;
        merge_sort(0, n - 1, nums);
        return res;
    }

    void merge_sort(int l, int r, vector<int>& nums) {
        if (l == r) return;

        int mid = l + r >> 1;
        merge_sort(l, mid, nums);
        merge_sort(mid + 1, r, nums);

        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                t[k] = nums[i];
                t_idx[k] = idx[i];
                res[idx[i]] += j - 1 - mid;
                i ++ , k ++ ;
            } else {
                t[k] = nums[j];
                t_idx[k] = idx[j];
                j ++ , k ++ ;
            }
        }

        while (i <= mid) {
            t[k] = nums[i];
            t_idx[k] = idx[i];
            res[idx[i]] += j - 1 - mid;
            i ++ , k ++ ;
        }

        while (j <= r) {
            t[k] = nums[j];
            t_idx[k] = idx[j];
            j ++ , k ++ ;
        }

        for (int i = l, k = 0; i <= r; i ++ , k ++ ) {
            nums[i] = t[k];
            idx[i] = t_idx[k];
        }
    }
};
// @lc code=end

