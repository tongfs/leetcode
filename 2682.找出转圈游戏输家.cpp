/*
 * @lc app=leetcode.cn id=2682 lang=cpp
 * @lcpr version=21910
 *
 * [2682] 找出转圈游戏输家
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> st(n);
        for (int i = 1, cur = 0; !st[cur]; i++) {
            st[cur] = true;
            cur = (cur + i * k) % n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) if (!st[i]) res.push_back(i + 1);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n4\n
// @lcpr case=end

 */

