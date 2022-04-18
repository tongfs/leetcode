/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();

        int i = 0, j = 0;
        while (i < n || j < m) {
            int a = get_num(v1, i);
            int b = get_num(v2, j);
            if (a > b) return 1;
            else if (a < b) return -1;
        }

        return 0;
    }

    int get_num(string& s, int &l) {
        int r = l;
        while (r < s.size() && s[r] != '.') r ++ ;
        int res = 0;
        for (int i = l; i < r; i ++ ) res = res * 10 - '0' + s[i];
        l = r + 1;
        return res;
    }
};
// @lc code=end

