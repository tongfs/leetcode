/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1, x2, n1 = 0, n2 = 0;
        for (auto x: nums) {
            if (n1 && x == x1) n1 ++ ;
            else if (n2 && x == x2) n2 ++ ;
            else if (!n1) x1 = x, n1 ++ ;
            else if (!n2) x2 = x, n2 ++ ;
            else n1 -- , n2 -- ;
        }

        n1 = n2 = 0;
        for (auto x: nums) {
            if (x == x1) n1 ++ ;
            else if (x == x2) n2 ++ ;
        }

        int n = nums.size();
        vector<int> res;
        if (n1 > n / 3) res.push_back(x1);
        if (n2 > n / 3) res.push_back(x2);

        return res;
    }
};
// @lc code=end

