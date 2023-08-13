/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=21910
 *
 * [37] 解数独
 */
#include "mylib.h"
// @lc code=start
class Solution {
public:
    bool row[9][9], col[9][9], block[9][9];

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int u = board[i][j] - '1';
                    row[i][u] = col[j][u] = block[i / 3 * 3 + j / 3][u] = true;
                }
            }
        }

        dfs(0, 0, board);
    }

    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;

        if (board[x][y] != '.') return dfs(x, y + 1, board);

        for (int i = 0; i < 9; i++) {
            if (!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]) {
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = block[x / 3 * 3 + y / 3][i] = true;
                if (dfs(x, y + 1, board)) return true;
                row[x][i] = col[y][i] = block[x / 3 * 3 + y / 3][i] = false;
                board[x][y] = '.';
            }
        }

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

