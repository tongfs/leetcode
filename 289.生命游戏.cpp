/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include "mylib.h"

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                int live = -board[i][j];
                for (int a = max(0, i - 1); a <= min(n - 1, i + 1); a ++ ) {
                    for (int b = max(0, j - 1); b <= min(m - 1, j + 1); b ++ ) {
                        live += board[a][b] & 1;
                    }
                }
                int res;
                if (board[i][j]) {
                    if (live < 2 || live > 3) res = 0;
                    else res = 1;
                } else {
                    if (live == 3) res = 1;
                    else res = 0;
                }
                board[i][j] |= res << 1;
            }
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                board[i][j] >>= 1;
    }
};
// @lc code=end

