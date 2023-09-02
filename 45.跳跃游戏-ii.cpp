/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=21910
 *
 * [45] 跳跃游戏 II
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; ) {
            res++;
            if (i + nums[i] >= nums.size() - 1) return res;
            int idx = i + 1;
            for (int j =  idx + 1; j <= i + nums[i]; j++)
                if (j + nums[j] > idx + nums[idx]) idx = j;
            i = idx;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

