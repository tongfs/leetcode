/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j ++ ) {
            if (nums[i] != nums[j])
                nums[ ++ i] = nums[j];
        }
        return i + 1;
    }
};
// @lc code=end

