/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=21910
 *
 * [13] 罗马数字转整数
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && map[s[i]] < map[s[i + 1]]) res -= map[s[i]];
            else res += map[s[i]];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "IV"\n
// @lcpr case=end

// @lcpr case=start
// "IX"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */

