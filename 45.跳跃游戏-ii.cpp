/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 整体思路是看一下可以跳到的位置中，哪一个位置可以跳得最远
        int cnt = 0;
        for (int i = 0, idx; i < nums.size() - 1; ) {
            cnt ++ ;    // 进入循环说明至少要跳一次
            if (i + nums[i] >= nums.size() - 1) return cnt;
            idx = i + 1;
            for (int j = i + 2; j < nums.size() && j <= i + nums[i]; j ++ )
                if (j + nums[j] > nums[idx] + idx)
                    idx = j;
            i = idx;
        }

        return cnt;
    }
};
// @lc code=end

