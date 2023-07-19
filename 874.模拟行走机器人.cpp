/*
 * @lc app=leetcode.cn id=874 lang=cpp
 * @lcpr version=21910
 *
 * [874] 模拟行走机器人
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int d = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        unordered_set<int> set;
        for (auto& o : obstacles) set.insert(o[0] * 60001 + o[1]);

        int res = 0;
        int x = 0, y = 0;
        for (auto c : commands) {
            if (c < 0) {
                if (c == -2) d = (d + 3) % 4;
                if (c == -1) d = (d + 1) % 4;
                continue;
            }
            for (int i = 0; i < c; i++) {
                int a = x + dx[d], b = y + dy[d];
                if (set.count(a * 60001 + b)) break;
                x = a, y = b;
                res = max(res, x * x + y * y);
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,-1,3]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [4,-1,4,-2,4]\n[[2,4]]\n
// @lcpr case=end

 */

