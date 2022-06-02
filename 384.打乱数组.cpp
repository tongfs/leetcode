/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    vector<int> backup;

    Solution(vector<int>& nums) {
        backup = nums;
    }
    
    vector<int> reset() {
        return backup;
    }
    
    vector<int> shuffle() {
        auto tmp = backup;
        int n = tmp.size();
        for (int i = 0; i < n; i ++ )
            swap(tmp[i], tmp[i + rand() % (n - i)]);
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

