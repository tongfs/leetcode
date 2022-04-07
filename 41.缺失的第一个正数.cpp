/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // return brute_force(nums);
        return by_sort(nums);
    }

    // 解法一：暴力枚举（空间为 O(n)）
    int brute_force(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num : nums) if (num > 0) set.insert(num);

        int res = 0;
        while (set.count( ++ res));
        return res;
    }

    // 解法二：基数排序（空间为 O(1)）
    int by_sort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            while (nums[i] > 0 && nums[i] <= n && i != nums[i] - 1 && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; i ++ )
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
// @lc code=end

