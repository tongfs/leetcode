/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int n, k;
    string path;
    vector<bool> st;

    string getPermutation(int m, int t) {
        // return backtracking(m, t);
        return method2(m, t);
    }

    // 解法一：暴搜
    string backtracking(int _n, int _k) {
        n = _n, k = _k;
        path = string(n, ' ');
        st = vector<bool>(n);

        dfs(0);
        return path;
    }

    // 解法二：计数
    string method2(int m, int t) {
        string res;
        vector<bool> st(m + 1);

        for (int i = 0; i < m; i ++ ) {
            // 要填放第i个数
            int fact = 1;   // 求出i后面有多少种可能
            for (int j = 1; j <= m - i - 1; j ++ ) fact *= j;

            for (int j = 1; j <= m; j ++ ) {
                if (!st[j]) {
                    if (fact < t) t -= fact;
                    else {
                        res += j + '0';
                        st[j] = true;
                        break;
                    }
                }
            }
        }

        return res;
    }

    bool dfs(int u) {
        if (u == n) {
            if ( -- k) return false;
            return true;
        }

        for (int i = 0; i < n; i ++ ) {
            if (!st[i]) {
                st[i] = true;
                path[u] = i + '1';
                if (dfs(u + 1)) return true;
                st[i] = false;
            }
        }

        return false;
    }
};
// @lc code=end

