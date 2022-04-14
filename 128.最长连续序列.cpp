/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for (int x : nums) S.insert(x);

        int res = 0;
        for (int x : nums) {
            if (S.count(x) && !S.count(x - 1)) {
                int t = 1;
                for (int i = x + 1; ; i ++ )
                    if (S.count(i)) t ++ , S.erase(i);
                    else break;
                res = max(res, t);
            }
        }

        return res; 
    }
};
// @lc code=end

