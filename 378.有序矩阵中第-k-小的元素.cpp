/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = INT_MIN, r = INT_MAX;
        while (l < r) {
            int mid = (long)l + r >> 1, cnt = 0;
            for (int i = 0, j = n - 1; i < n; i ++ ) {
                while (j >= 0 && matrix[i][j] > mid) -- j;
                cnt += j + 1;
            }
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

