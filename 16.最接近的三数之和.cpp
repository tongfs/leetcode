/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int d = 1e8, res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k] - target;
                if (d > abs(t)) {
                    d = abs(t);
                    res = nums[i] + nums[j] + nums[k];
                }
                if (t > 0) k -- ;
                else j ++ ;
            }
        }
        return res;
    }
};
// @lc code=end

