/*
 * @lc app=leetcode.cn id=165 lang=cpp
 * @lcpr version=21910
 *
 * [165] 比较版本号
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();

        for (int i = 0, j = 0; i < n || j < m; ) {
            int a = get_num(v1, i);
            int b = get_num(v2, j);
            if (a > b) return 1;
            if (a < b) return -1;
        }
        return 0;
    }

    int get_num(string& s, int& l) {
        int r = l;
        while (r < s.size() && s[r] != '.') r++;
        int res = 0;
        for (int i = l; i < r; i++) res = res * 10 - '0' + s[i];
        l = r + 1;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1.01"\n"1.001"\n
// @lcpr case=end

// @lcpr case=start
// "1.0"\n"1.0.0"\n
// @lcpr case=end

// @lcpr case=start
// "0.1"\n"1.1"\n
// @lcpr case=end

 */

