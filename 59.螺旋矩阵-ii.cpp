/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<vector<int>> m(n, vector<int>(n));
        vector<vector<bool>> st(n, vector<bool>(n));
        
        for (int i = 0, x = 0, y = 0, d = 0; i < n * n; i ++ ) {
            st[x][y] = true;
            m[x][y] = i + 1;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= n || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        
        return m;
    }
};
// @lc code=end

