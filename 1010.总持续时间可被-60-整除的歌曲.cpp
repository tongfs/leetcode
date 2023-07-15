/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 * @lcpr version=21909
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        unordered_map<int, int> map;
        for (auto x : time) {
            int t = (x - 1) % 60 + 1;
            if (map.count(60 - t)) {
                res += map[60 - t];
            }
            map[t % 60]++;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [30,20,150,100,40]\n
// @lcpr case=end

// @lcpr case=start
// [60,60,60]\n
// @lcpr case=end

 */
