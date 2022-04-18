/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0, j = n - 1, s; i < j; ) {
            if ((s = numbers[i] + numbers[j]) != target)
                if (s > target) j -- ;
                else i ++ ;
            else return {i + 1, j + 1};
        }
        return {};
    }
};
// @lc code=end

