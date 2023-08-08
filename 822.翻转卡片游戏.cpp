/*
 * @lc app=leetcode.cn id=822 lang=cpp
 * @lcpr version=21910
 *
 * [822] 翻转卡片游戏
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_set<int> set;

        for (int i = 0; i < n; i++)
            if (fronts[i] == backs[i])
                set.insert(fronts[i]);
        
        int res = 2001;
        for (int i = 0; i < n; i++) {
            auto a = fronts[i], b = backs[i];
            if (!set.count(a)) res = min(res, a);
            if (!set.count(b)) res = min(res, b);
        }
        return res % 2001;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,4,7]\n[1,3,4,1,3]\n
// @lcpr case=end

 */

