/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<int, int> map;
        for (auto& d: dominoes) {
            int x = d[0], y = d[1];
            if (x > y) swap(x, y);
            int k = x * 10 + y;
            res += map[k] ++ ;
        }
        return res;
    }
};
// @lc code=end

