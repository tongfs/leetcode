/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res;
        for (int len = max(0, k - m); len <= min(n , k); len ++ ) {
            auto subseq1 = max_subsequence(nums1, len);
            auto subseq2 = max_subsequence(nums2, k - len);
            auto nums = merge(subseq1, subseq2);
            res = max(res, nums);
        }
        return res;
    }

    vector<int> max_subsequence(vector<int>& nums, int len) {
        vector<int> stk;
        int t = nums.size() - len;
        for (int i = 0; i < nums.size(); i ++ ) {
            while (stk.size() && stk.back() < nums[i] && t) stk.pop_back(), t -- ;
            stk.push_back(nums[i]);
        }
        while (stk.size() != len) stk.pop_back();
        return stk;
    }

    vector<int> merge(vector<int>& seq1, vector<int>& seq2) {
        vector<int> res;
        int n = seq1.size(), m = seq2.size();

        int i = 0, j = 0;
        while (i < n && j < m)
            if (cmp(seq1, i, seq2, j)) res.push_back(seq1[i ++ ]);
            else res.push_back(seq2[j ++ ]);

        while (i < n) res.push_back(seq1[i ++ ]);
        while (j < m) res.push_back(seq2[j ++ ]);

        return res;
    }

    bool cmp(vector<int>& seq1, int i, vector<int>& seq2, int j) {
        int n = seq1.size(), m = seq2.size();
        while (i < n && j < m)
            if (seq1[i] > seq2[j]) return true;
            else if (seq1[i] < seq2[j]) return false;
            else i ++ , j ++ ;

        return i != n;
    }
};
// @lc code=end

