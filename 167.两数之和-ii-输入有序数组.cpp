/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=21910
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 1, j = numbers.size();
        while (numbers[i - 1] + numbers[j - 1] != target) {
            if (numbers[i - 1] + numbers[j - 1] > target) j--;
            else i++;
        }
        return {i, j};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
