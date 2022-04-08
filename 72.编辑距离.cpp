/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        a = ' ' + a, b = ' ' + b;

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        
        for (int i = 0; i <= n; i ++ ) f[i][0] = i;
        for (int i = 0; i <= m; i ++ ) f[0][i] = i;

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1; 
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
            }

        return f[n][m];
    }
};
// @lc code=end

