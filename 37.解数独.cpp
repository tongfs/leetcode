/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool row[9][9], col[9][9], block[9][9];

    void solveSudoku(vector<vector<char>>& board) {
        // 这里一定要进入 DFS 之前就定义好初始状态，不能一边递归，一边设置状态
        for (int i = 0; i < 9; i ++ )
            for (int j = 0; j < 9; j ++ )
                if (board[i][j] != '.') {
                    int u = board[i][j] - '1';
                    row[i][u] = col[j][u] = block[i / 3 * 3 + j / 3][u] = true;
                }

        dfs(0, 0, board);
    }

    bool dfs(int x, int y, vector<vector<char>> &board) {
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

