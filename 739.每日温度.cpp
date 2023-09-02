/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=21910
 *
 * [739] 每日温度
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> stk;
        vector<int> res(temps.size());
        for (int i = temps.size() - 1; i >= 0; i--) {
            while (stk.size() && temps[i] >= temps[stk.top()]) stk.pop();
            if (stk.size()) res[i] = stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

