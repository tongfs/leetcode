/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return dp(s1, s2);
    }

    // 解法一：动态规划
    /*
     * 状态表示：f[i][j][k]: 是否存在将 s1[i,i+k-1] 转化成 s2[j,j+k-1] 的方案（k为区间长度）
     */
    bool dp(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n + 1)));

        for (int k = 1; k <= n; k ++ )
            for (int i = 0; i + k - 1 < n; i ++ )
                for (int j = 0; j + k - 1 < n; j ++ )
                    if (k == 1) f[i][j][k] = s1[i] == s2[j];
                    else
                        for (int u = 1; u < k; u ++ )
                            if (f[i][j][u] && f[i + u][j + u][k - u] ||
                                f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                    f[i][j][k] = true;
                                    break;
                                }

        return f[0][0][n];
    }

    // 解法二：暴搜（现在在LC上会TLE，复杂度为O(5^n)）
    bool brute_force(string s1, string s2) {
        if (s1 == s2) return true;

        string a1 = s1, a2 = s2;
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        if (a1 != a2) return false;

        int n = s1.size();
        for (int i = 1; i < n; i ++ ) {
            if (brute_force(s1.substr(0, i), s2.substr(0, i)) &&
                brute_force(s1.substr(i), s2.substr(i)))
                return true;
            if (brute_force(s1.substr(0, i), s2.substr(n - i)) &&
                brute_force(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }

        return false;
    }
};
// @lc code=end

