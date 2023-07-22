/*
 * @lc app=leetcode.cn id=860 lang=cpp
 * @lcpr version=21910
 *
 * [860] 柠檬水找零
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;
        for (auto bill : bills) {
            if (bill == 5) {
                a++;
            } else if (bill == 10) {
                if (a) a--, b++;
                else return false;
            } else {
                if (a >= 1 && b >= 1) a--, b--;
                else if (a >= 3) a -= 3;
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,5,5,10,20]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,10,10,20]\n
// @lcpr case=end

 */
