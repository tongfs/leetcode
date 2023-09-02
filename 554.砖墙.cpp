/*
 * @lc app=leetcode.cn id=554 lang=cpp
 * @lcpr version=21910
 *
 * [554] 砖墙
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& line : wall) {
            for (int i = 0, pos = 0; i < line.size() - 1; i++) {
                pos += line[i];
                cnt[pos]++;
            }
        }
        int res = 0;
        for (auto& [k, v] : cnt) res = max(res, v);
        return wall.size() - res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1],[1]]\n
// @lcpr case=end

 */

